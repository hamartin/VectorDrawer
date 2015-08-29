/*
 * VD.CPP
 */

#include "vd.h"

int main()
{
    std::cout << "Starting VD.\n";

    // Initialising SDL.
    sdlc *container = NULL;
    try {
        container = initSDL();
    } catch (int err) {
        std::cerr << "Initialising failed: " << err << std::endl;
        return err;
    }

    // Cleaning up before exit.
    delete container;
    std::cout << "Bye bye!\n";
    return 0;
}

sdlc *initSDL()
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        logCritical("SDL could not initialise!");
        throw 1;
    }

    SDL_DisplayMode *current = new SDL_DisplayMode;
    if(SDL_GetCurrentDisplayMode(0, current) != 0) {
        logCritical("SDL could not get display mode for video display!");
        throw 2;
    }

    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    if(SDL_CreateWindowAndRenderer(0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP, &window, &renderer) != 0) {
        logCritical("SDL could not initialise window and renderer!");
        throw 3;
    }

    SDL_Event *event = new SDL_Event;
    if(current != NULL && window != NULL && renderer != NULL && event != NULL) {
        return new sdlc(renderer, event, current, window);
    } else {
        logCritical("Something unexplained happened!");
        throw 4;
    }
}

void logCritical(std::string err)
{
    err += std::string(" SDL ERROR: ") + std::string(SDL_GetError()) + std::string("\n");
    SDL_LogCritical(SDL_LOG_CATEGORY_ERROR, err.c_str());
}
