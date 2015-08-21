/*
 * VD.H
 */

#ifndef __VD_H__
#define __VD_H__

#include <iostream>
#include <SDL2/SDL.h>
#include <string>
#include "camera.h"

class VD {
public:
    VD();
    ~VD();
    void start();

protected:

private:
    bool initSDL();

    unsigned int screen_width, screen_height;

    SDL_DisplayMode *current;
    SDL_Event *event;
    SDL_Renderer *renderer;
    SDL_Window *window;
    Camera *camera;
};

int main();
void logCritical(std::string err);

#endif
