#include <SDL2/SDL.h>
#include <iostream>
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
    SDL_SetRenderDrawBlendMode(renderer, (a == 255) ? SDL_BLENDMODE_NONE : SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_RenderDrawPoint(renderer, x, y);
    return 0;
}

int draw_point_RGBA_weight(SDL_Renderer *renderer, int x, int y, int r, int g, int b, int a, Uint32 weight)
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

    Uint32 erracc = 0, intshift = 32 - AAbits;

    draw_point_RGBA(renderer, x1, y1, r, g, b, a);
    if ( dy > dx )
    {
        Uint32 erradj = ((dx<<16) / dy) << 16;
        int x1pxdir = x1 + xdir;
        while ( --dy )
        {
            Uint32 erracctmp = erracc;
            erracc += erradj;
            if ( erracc <= erracctmp )
            {
                x1 = x1pxdir;
                x1pxdir += xdir;
            }
            y1 += 1;

            Uint32 wgt = (erracc>>intshift) & 255;
            draw_point_RGBA_weight(renderer, x1, y1, r, g, b, a, 255-wgt);
            draw_point_RGBA_weight(renderer, x1pxdir, y1, r, g, b, a, wgt);
        }
    }
    else
    {
        Uint32 erradj = ((dy<<16) / dx) << 16;
        int y1pxdir = y1 + 1;
        while ( --dx )
        {
            Uint32 erracctmp = erracc;
            erracc += erradj;
            if ( erracc <= erracctmp )
            {
                y1 = y1pxdir;
                y1pxdir += 1;
            }
            x1 += xdir;

            Uint32 wgt = (erracc>>intshift) & 255;
            draw_point_RGBA_weight(renderer, x1, y1, r, g, b, a, 255-wgt);
            draw_point_RGBA_weight(renderer, x1, y1pxdir, r, g, b, a, wgt);
        }
    }

    draw_point_RGBA(renderer, x2, y2, r, g, b, a);

    return 0;
}

int draw_hands(SDL_Renderer *renderer, double rawtime)
{
    int x = SIZE/2, y = SIZE/2;
    time_t tmp_t = rawtime;
    struct tm *timeinfo = localtime(&tmp_t);
    rawtime -= tmp_t;
    double deg_sec = (timeinfo->tm_sec+rawtime)/60*M_PI*2;
    double deg_min = (double)(timeinfo->tm_min)/60*M_PI*2+deg_sec/60;
    double deg_hour = (double)(timeinfo->tm_hour%12)/12*M_PI*2+deg_min/12;

    draw_smooth_line(renderer, x, y, x+sin(deg_sec)*SECOHAND, y-cos(deg_sec)*SECOHAND, 255, 0, 0, 255);
    draw_smooth_line(renderer, x, y, x+sin(deg_min)*MINUHAND, y-cos(deg_min)*MINUHAND, 0, 0, 0, 255);
    draw_smooth_line(renderer, x, y, x+sin(deg_hour)*HOURHAND, y-cos(deg_hour)*HOURHAND, 0, 0, 0, 255);
    return 0;
}

void update(SDL_Renderer *renderer, double rawtime)
{
    int center = SIZE/2, clock_size = center*0.95;
    draw_circle(renderer, center, center, clock_size, 255, 255, 255, 255);
    for ( int i = 0; i < 60; ++i )
    {
        double deg = (double)i/60*M_PI*2;
        if ( i%5 == 0 )
            draw_smooth_line(renderer,
                             center+sin(deg)*(clock_size-14), center-cos(deg)*(clock_size-14),
                             center+sin(deg)*clock_size, center-cos(deg)*clock_size,
                             0, 0, 0, 255);
        else
            draw_smooth_line(renderer,
                             center+sin(deg)*(clock_size-6), center-cos(deg)*(clock_size-6),
                             center+sin(deg)*clock_size, center-cos(deg)*clock_size,
                             0, 0, 0, 255);
    }
    draw_hands(renderer, rawtime);
    draw_circle(renderer, center, center, clock_size*0.03, 0, 0, 0, 255);
    
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
    double rawtime = time(NULL);
    clock_t t = clock();
    while ( !quit )
    {
        while( SDL_PollEvent(&e) )
        {
            switch( e.type )
            {
                case SDL_KEYDOWN:
                {
                    string keyname = SDL_GetKeyName(e.key.keysym.sym);
                    if ( keyname == "Right" )
                        rawtime += 2;
                    else if ( keyname == "Left" )
                        rawtime -= 2;
                    else if ( keyname == "Up" )
                        rawtime += 45;
                    else if ( keyname == "Down" )
                        rawtime -= 45;
                    break;
                }
                case SDL_QUIT:
                    quit = 1; break;
            }
        }
        update(renderer, rawtime+(double)(clock()-t)/CLOCKS_PER_SEC);
        SDL_Delay(20);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
