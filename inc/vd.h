/*
 * VD.H
 */

#ifndef __VD_H__
#define __VD_H__

#include <iostream>
#include <SDL2/SDL.h>
#include <string>

#include "camera.h"
#include "variables.h"

int main();

SDLC *initSDL();

void logCritical(std::string err);
void start(SDLC *c);

#endif
