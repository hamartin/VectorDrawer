/*
 * VD.CPP
 */

#include "vd.h"

int main()
{
    int err = 0;
    std::cout << "Starting VD\n";

    // Initialising.
    SDLC *sdlc = NULL;
    try {
        sdlc = initSDL();
    } catch (int e) {
        std::cerr << "Initialising failed: " << err << std::endl;
        err = e;
    }

    // Starting app if init finished without errors.
    if(err == 0) {
#ifdef DEBUG
        SDL_LogSetAllPriority(SDL_LOG_PRIORITY_WARN);
#endif
        start(sdlc);
    }

    // Cleaning up before exit.
    delete sdlc;
    std::cout << "Bye bye!\n";
    return 0;
}

SDLC *initSDL()
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

    return new SDLC(renderer, event, current, window);
}

void start(SDLC *c)
{
    bool quit = false;
    int xmax = c->current->w;
    int ymax = c->current->h;

    while(!quit) {
        while(SDL_PollEvent(c->event) != 0) {
            if(c->event->key.keysym.scancode == SDL_SCANCODE_A) {
                for(int i = 0; i < 1000; i++) {
                    if(i > xmax || i > ymax)
                        continue;
                    point_t p(i, i);
                    point_t o(i, i+100);
                    addPointToCanvas(c->renderer, &p);
                    addPointToCanvas(c->renderer, &o);
                }
            } else if(c->event->key.keysym.scancode == SDL_SCANCODE_C) {
                clear(c->renderer);
            } else if(c->event->key.keysym.scancode == SDL_SCANCODE_D) {
                render(c->renderer);
            } else if(c->event->type == SDL_QUIT ||
                      c->event->key.keysym.scancode == SDL_SCANCODE_Q ||
                      c->event->key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
                quit = true;
            } else if(c->event->type == SDL_WINDOWEVENT && c->event->window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
                xmax = c->current->w;
                ymax = c->current->h;
            }

        }
    }
}

void logCritical(std::string err)
{
    err += std::string(" SDL_ERROR: ") + std::string(SDL_GetError()) + std::string("\n");
    SDL_LogCritical(SDL_LOG_CATEGORY_ERROR, err.c_str());
}
