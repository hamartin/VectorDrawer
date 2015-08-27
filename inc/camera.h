/*
 * CAMERA.H
 */

#ifndef __CAMERA_H__
#define __CAMERA_H__

#include <SDL2/SDL.h>
#include <vector>

#include "variables.h"

/*
 * Functions
 */

void addPointToCanvas(SDL_Renderer *renderer, point_t *p);
void clear(SDL_Renderer *renderer);
void render(SDL_Renderer *renderer);

#endif
