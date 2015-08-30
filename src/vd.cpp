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

#ifdef DEBUG
    SDL_LogSetAllPriority(SDL_LOG_PRIORITY_WARN);
#endif

    start(container);

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

void draw(SDL_Renderer *renderer, point_vec_t *points)
{
    for(pointit_vec_t p = points->begin(); p != points->end(); p++) {
        point_t *dp = (*p)->getPoint();
        SDL_RenderDrawPoint(renderer, dp->x, dp->y);
    }
}

void render(SDL_Renderer *renderer)
{
    SDL_RenderPresent(renderer);
}

void logCritical(std::string err)
{
    err += std::string(" SDL ERROR: ") + std::string(SDL_GetError()) + std::string("\n");
    SDL_LogCritical(SDL_LOG_CATEGORY_ERROR, err.c_str());
}

void start(sdlc *container)
{
    bool quit = false;
#ifdef DEBUG
    int xmax = container->current->w;
    int ymax = container->current->h;
#endif

    point_vec_t *points = new point_vec_t;

    points->push_back(new Point(new point_t(100, 100)));
    points->push_back(new Point(new point_t(200, 100)));
    points->push_back(new Point(new point_t(100, 200)));
    points->push_back(new Point(new point_t(50, 100)));
    points->push_back(new Point(new point_t(200, 75)));
    points->push_back(new Point(new point_t(200, 400)));
    points->push_back(new Point(new point_t(150, 700)));
    points->push_back(new Point(new point_t(35, 75)));

    while(!quit) {
        while(SDL_PollEvent(container->event) != 0) {
            if(container->event->key.keysym.scancode == SDL_SCANCODE_D) {
                SDL_RenderClear(container->renderer);
                draw(container->renderer, points);
                render(container->renderer);
            } else if(container->event->key.keysym.scancode == SDL_SCANCODE_C) {
                SDL_RenderClear(container->renderer);
                render(container->renderer);
            } else if(container->event->key.keysym.scancode == SDL_SCANCODE_R) {
                SDL_RenderClear(container->renderer);
                draw(container->renderer, points);
                render(container->renderer);
            } else if(container->event->type == SDL_QUIT ||
                    container->event->key.keysym.scancode == SDL_SCANCODE_Q ||
                    container->event->key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
                quit = true;
#ifdef DEBUG
            } else if(container->event->type == SDL_WINDOWEVENT && container->event->window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
                xmax = container->current->w;
                ymax = container->current->h;
                std::cout << "XMAX: " << xmax << "\nYMAX: " << ymax << std::endl;
#endif
            }
        }
    }

    delete points;
}
