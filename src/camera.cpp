/*
 * CAMERA.CPP
 */

#include "camera.h"

void addPointToCanvas(SDL_Renderer *renderer, point_t *p)
{
    SDL_RenderDrawPoint(renderer, p->x, p->y);
}

void clear(SDL_Renderer *renderer)
{
    SDL_RenderClear(renderer);
}

void render(SDL_Renderer *renderer)
{
    SDL_RenderPresent(renderer);
}
