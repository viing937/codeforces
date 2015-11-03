#include <SDL2/SDL.h>
#include <stdio.h>
#include <time.h>

#define SIZE 320
#define HOURHAND 60 
#define MINUHAND 100
#define SECOHAND 120

void draw_circle(SDL_Renderer *renderer, int x, int y, int r)
{
    double deg_0 = 0;
    double deg_90 = M_PI/2;
    double deg_step = deg_90 / (r*4);
    while ( r-- )
    {
        double curr_deg = deg_0;
        while ( curr_deg < deg_90 )
        {
            int offset_x = cos(curr_deg)*r,
                offset_y = sin(curr_deg)*r;
            SDL_RenderDrawPoint(renderer, x+offset_x, y+offset_y);
            SDL_RenderDrawPoint(renderer, x+offset_x, y-offset_y);
            SDL_RenderDrawPoint(renderer, x-offset_x, y+offset_y);
            SDL_RenderDrawPoint(renderer, x-offset_x, y-offset_y);
            curr_deg += deg_step;
        }
    }
    return;
}

void draw_hands(SDL_Renderer *renderer, struct tm *timer)
{
    int x = SIZE/2, y = SIZE/2;
    double deg_sec = (double)(timer->tm_sec)/60*M_PI*2;
    double deg_min = (double)(timer->tm_min)/60*M_PI*2+deg_sec/12;
    double deg_hour = (double)(timer->tm_hour%12)/12*M_PI*2+deg_min/12;

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawLine(renderer, x, y, x+sin(deg_sec)*SECOHAND, y-cos(deg_sec)*SECOHAND);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawLine(renderer, x, y, x+sin(deg_min)*MINUHAND, y-cos(deg_min)*MINUHAND);
    SDL_RenderDrawLine(renderer, x, y, x+sin(deg_hour)*HOURHAND, y-cos(deg_hour)*HOURHAND);
    return;
}

void update(SDL_Renderer *renderer)
{
    SDL_RenderClear(renderer);
    time_t rawtime = time(NULL);
    struct tm *timer = localtime(&rawtime);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    draw_circle(renderer, SIZE/2, SIZE/2, SIZE/2*0.95);
    draw_hands(renderer, timer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    draw_circle(renderer, SIZE/2, SIZE/2, SIZE/2*0.03);
    
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
