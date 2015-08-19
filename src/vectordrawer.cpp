//
// VECTORDRAWER.CPP
//

#include "vectordrawer.h"

VectorDrawer::VectorDrawer(const std::string &TITLE, const unsigned int &SCREEN_WIDTH, const unsigned int &SCREEN_HEIGHT)
{
    this->SCREEN_WIDTH = SCREEN_WIDTH;
    this->SCREEN_HEIGHT = SCREEN_HEIGHT;
    this->TITLE = TITLE;

    this->window = NULL;
    this->renderer = NULL;
    this->event = NULL;
}

VectorDrawer::~VectorDrawer()
{
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}

bool VectorDrawer::init()
{
    bool ret = false;
    char err[200]; err[0] = 0;

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        sprintf(err, "SDL coult not initialise! SDL_ERROR: %s\n", SDL_GetError());
    } else {
        this->window = SDL_CreateWindow(this->TITLE.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, this->SCREEN_WIDTH, this->SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        this->event = new SDL_Event;
        if(this->window == NULL) {
            sprintf(err, "Window could not be created! SDL_Error: %s\n", SDL_GetError());
        } else if(this->renderer == NULL) {
            sprintf(err, "Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        } else if(this->event == NULL) {
            sprintf(err, "SDL Event object could not be created! SDL_Error: %s\n", SDL_GetError());
        } else {
            ret = true;
        }
    }

    if(strlen(err) != 0) {
        SDL_LogCritical(SDL_LOG_CATEGORY_ERROR, err);
    }
    return ret;
}

void VectorDrawer::begin()
{
    for(int i = 0; i < 3000; i++) {
        points.push_back(Point(this->renderer, i % 640, i % 480));
    }
    for(pointsiter = points.begin(); pointsiter != points.end(); ++pointsiter) {
        pointsiter->addToCanvas();
    }

    bool quit = false;
    while(!quit) {
        while(SDL_PollEvent(this->event) != 0) {
            if(event->type == SDL_QUIT || event->key.keysym.scancode == SDL_SCANCODE_Q)
                quit = true;
            this->print();
        }
    }
}

void VectorDrawer::debug()
{
    SDL_LogSetAllPriority(SDL_LOG_PRIORITY_WARN);
}

void VectorDrawer::print()
{
    SDL_RenderPresent(this->renderer);
}
