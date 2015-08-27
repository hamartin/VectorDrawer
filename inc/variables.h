/*
 * VARIABLES.H
 */

#ifndef __VARIABLES_H__
#define __VARIABLES_H__

#include <SDL2/SDL.h>

typedef struct SDLC
{
    SDL_Renderer *renderer;
    SDL_Event *event;
    SDL_DisplayMode *current;
    SDL_Window *window;
    SDLC(SDL_Renderer *r, SDL_Event *e, SDL_DisplayMode *c, SDL_Window *w)
    {
        current = c;
        event = e;
        renderer = r;
        window = w;
    }
    ~SDLC()
    {
        delete current;
        delete event;
        if(renderer)
            SDL_DestroyRenderer(renderer);
        if(window)
            SDL_DestroyWindow(window);
    }
} SDLC;

typedef struct point_t
{
    int x;
    int y;
    point_t(int nx, int ny)
    {
        x = nx;
        y = ny;
    }
} point_t;

#endif
