#include <SDL2/SDL.h>
#include <cstdio>
#include <ctime>
#include <algorithm>
using namespace std;

#define SIZE 640
#define HOURHAND 120
#define MINUHAND 220
#define SECOHAND 240
#define AAbits 8

int draw_point_RGBA(SDL_Renderer *renderer, int x, int y, int r, int g, int b, int a)
{
    int result = 0;
    result |= SDL_SetRenderDrawBlendMode(renderer, (a == 255) ? SDL_BLENDMODE_NONE : SDL_BLENDMODE_BLEND);
    result |= SDL_SetRenderDrawColor(renderer, r, g, b, a);
    result |= SDL_RenderDrawPoint(renderer, x, y);
    return result;
}

int draw_point_RGBA_weight(SDL_Renderer *renderer, int x, int y, int r, int g, int b, int a, int weight)
{
    int ax = (a*weight)>>8;
    if ( ax > 255 )
        a = 255;
    else
        a = ax & 0x000000ff;
    return draw_point_RGBA(renderer, x, y, r, g, b, a);
}

int draw_circle(SDL_Renderer *renderer, int x, int y, int radius, int r, int g, int b, int a)
{
    double deg_0 = 0;
    double deg_90 = M_PI/2;
    double deg_step = deg_90 / (radius*4);
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    while ( radius-- )
    {
        double curr_deg = deg_0;
        while ( curr_deg < deg_90 )
        {
            int offset_x = cos(curr_deg)*radius,
                offset_y = sin(curr_deg)*radius;
            SDL_RenderDrawPoint(renderer, x+offset_x, y+offset_y);
            SDL_RenderDrawPoint(renderer, x+offset_x, y-offset_y);
            SDL_RenderDrawPoint(renderer, x-offset_x, y+offset_y);
            SDL_RenderDrawPoint(renderer, x-offset_x, y-offset_y);
            curr_deg += deg_step;
        }
    }
    return 0;
}

int draw_smooth_line(SDL_Renderer *renderer, int x1, int y1, int x2, int y2, int r, int g, int b, int a)
{
    if ( y1 > y2 )
    {
        swap(x1, x2);
        swap(y1, y2);
    }

    int dx = x2-x1, dy = y2-y1;

    int xdir;
    if ( dx >= 0 )
        xdir = 1;
    else
        xdir = -1, dx = -dx;

    if ( dx == 0 || dy == 0 || dx == dy )
    {
        SDL_SetRenderDrawColor(renderer, r, g, b, a);
        return SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
    }

    int result = 0, erracc = 0;
    int intshift = 32 - AAbits;

    result |= draw_point_RGBA(renderer, x1, y1, r, g, b, a);
    if ( dy > dx )
    {
        int erradj = ((dx<<16) / dy) << 16;
        int x1pxdir = x1 + xdir;
        while ( --dy )
        {
            int erracctmp = erracc;
            erracc += erradj;
            if ( erracc <= erracctmp )
            {
                x1 = x1pxdir;
                x1pxdir += xdir;
            }
            y1 += 1;

            int wgt = (erracc>>intshift) & 255;
            result |= draw_point_RGBA_weight(renderer, x1, y1, r, g, b, a, 255-wgt);
            result |= draw_point_RGBA_weight(renderer, x1pxdir, y1, r, g, b, a, wgt);
        }
    }
    else
    {
        int erradj = ((dy<<16) / dx) << 16;
        int y1pxdir = y1 + 1;
        while ( --dx )
        {
            int erracctmp = erracc;
            erracc += erradj;
            if ( erracc <= erracctmp )
            {
                y1 = y1pxdir;
                y1pxdir += 1;
            }
            x1 += xdir;

            int wgt = (erracc>>intshift) & 255;
            result |= draw_point_RGBA_weight(renderer, x1, y1, r, g, b, a, 255-wgt);
            result |= draw_point_RGBA_weight(renderer, x1, y1pxdir, r, g, b, a, wgt);
        }
    }

    result |= draw_point_RGBA(renderer, x2, y2, r, g, b, a);

    return result;
}

int draw_hands(SDL_Renderer *renderer, struct tm *timer)
{
    int x = SIZE/2, y = SIZE/2;
    double deg_sec = (double)(timer->tm_sec)/60*M_PI*2;
    double deg_min = (double)(timer->tm_min)/60*M_PI*2;
    double deg_hour = (double)(timer->tm_hour%12)/12*M_PI*2+deg_min/12;

    draw_smooth_line(renderer, x, y, x+sin(deg_sec)*SECOHAND, y-cos(deg_sec)*SECOHAND, 255, 0, 0, 255);
    draw_smooth_line(renderer, x, y, x+sin(deg_min)*MINUHAND, y-cos(deg_min)*MINUHAND, 0, 0, 0, 255);
    draw_smooth_line(renderer, x, y, x+sin(deg_hour)*HOURHAND, y-cos(deg_hour)*HOURHAND, 0, 0, 0, 255);
    return 0;
}

void update(SDL_Renderer *renderer)
{
    SDL_RenderClear(renderer);
    time_t rawtime = time(NULL);
    struct tm *timer = localtime(&rawtime);

    draw_circle(renderer, SIZE/2, SIZE/2, SIZE/2*0.95, 255, 255, 255, 255);
    for ( int i = 0; i < 12; ++i )
    {
        double deg = (double)i/12*M_PI*2;
        draw_smooth_line(renderer, SIZE/2+sin(deg)*((SIZE/2)*0.95-10), SIZE/2-cos(deg)*((SIZE/2)*0.95-10),
                                   SIZE/2+sin(deg)*(SIZE/2)*0.95, SIZE/2-cos(deg)*((SIZE/2)*0.95),
                                   0, 0, 0, 255);
    }
    draw_hands(renderer, timer);
    draw_circle(renderer, SIZE/2, SIZE/2, SIZE/2*0.03, 0, 0, 0, 255);
    
    SDL_RenderPresent(renderer);
    return;
}

int main(int argc, char *argv[])
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    SDL_Init(SDL_INIT_EVERYTHING);

    window = SDL_CreateWindow("Clock", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              SIZE, SIZE, SDL_WINDOW_OPENGL);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Event e;
    int quit = 0;
    while ( !quit )
    {
        while( SDL_PollEvent(&e) != 0 )
        {
            if ( e.type == SDL_QUIT )
                quit = 1;
        }
        update(renderer);
        SDL_Delay(20);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
