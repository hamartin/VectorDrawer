/*
 * VD.H
 */

#ifndef __VD_H__
#define __VD_H__

#include <iostream>
#include <string>
#include "linesegment.h"
#include "point.h"
#include "variables.h"

int main();
sdlc *initSDL();
void logCritical(std::string err);
void start(sdlc *container);

#endif
