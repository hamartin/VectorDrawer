/*
 * VD.CPP
 */

#include "vd.h"

VD::VD()
{
    this->current = NULL;
    this->event = NULL;
    this->renderer = NULL;
    this->window = NULL;
    this->camera = NULL;

    if(!this->initSDL())
        std::cerr << "Something went wrong. Check logs for more details.\n";

    this->camera = new Camera(this->renderer, this->event, 0, this->current->w , 0, this->current->h, 0, 100);
}

VD::~VD()
{
    delete this->camera;
    delete this->current;
    delete this->event;
    if(this->renderer != NULL)
        SDL_DestroyRenderer(this->renderer);
    if(this->window != NULL)
        SDL_DestroyWindow(this->window);
    SDL_Quit();
}

bool VD::initSDL()
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        logCritical("SDL could not initialise!");
        return false;
    }

    this->current = new SDL_DisplayMode;
    if(SDL_GetCurrentDisplayMode(0, this->current) != 0) {
        logCritical("SDL could not get display mode for video display!");
        return false;
    }
    // This must be done before initialising window and renderer.
    this->screen_width = this->current->w;
    this->screen_height = this->current->h;

    if(SDL_CreateWindowAndRenderer(0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP, &this->window, &this->renderer) != 0) {
        logCritical("SDL could not initialise window and/or renderer!");
        return false;
    }

    this->event = new SDL_Event;

    return true;
}

void VD::start()
{
    if(this->camera)
        this->camera->start();
}

int main()
{
    VD vd;
#ifdef DEBUG
    SDL_LogSetAllPriority(SDL_LOG_PRIORITY_WARN);
#endif
    vd.start();

    return 0;
}

void logCritical(std::string err)
{
    err += std::string(" SDL_ERROR: ") + std::string(SDL_GetError()) + std::string("\n");
    SDL_LogCritical(SDL_LOG_CATEGORY_ERROR, err.c_str());
    std::cerr << err;
}
