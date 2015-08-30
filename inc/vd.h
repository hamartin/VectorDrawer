/*
 * VD.H
 */

#ifndef __VD_H__
#define __VD_H__

#include <SDL2/SDL.h>
#include <string>
#include "circle.h"
#include "linesegment.h"
#include "point.h"
#include "variables.h"

#ifdef DEBUG
#include <iostream>
#endif

int main();
sdlc *initSDL();
void changeRadiusOnCircles(circle_vec_t *circles, const unsigned int size);
void draw(SDL_Renderer *renderer, point_vec_t *points, ls_vec_t *linesegments, circle_vec_t *circles);
void logCritical(std::string err);
void render(SDL_Renderer *renderer);
void rotate(point_vec_t *points, ls_vec_t *linesegments, const int degrees);
void start(sdlc *container);

#endif
