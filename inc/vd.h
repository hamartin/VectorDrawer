/*
 * VD.H
 */

#ifndef __VD_H__
#define __VD_H__

#include <SDL2/SDL.h>
#include <string>
#include "point.h"
#include "variables.h"

#ifdef DEBUG
#include <iostream>
#endif

int main();
sdlc *initSDL();
void draw(SDL_Renderer *renderer, point_vec_t *points);
void render(SDL_Renderer *renderer);
void logCritical(std::string err);
void start(sdlc *container);

#endif
