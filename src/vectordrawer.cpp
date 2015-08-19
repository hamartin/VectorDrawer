//
// VECTORDRAWER.CPP
//

#include "vectordrawer.h"

VectorDrawer::VectorDrawer(const std::string &TITLE)
{
    this->current  = NULL;
    this->event    = NULL;
    this->renderer = NULL;
    this->window   = NULL;

    this->TITLE = TITLE;

    if(!this->init())
        return; // Die
    if(!this->initObjects())
        return; // Die
}

VectorDrawer::~VectorDrawer()
{
    delete this->current;
    delete this->event;
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}

void VectorDrawer::begin()
{
    for(int i = 0; i < 50000; i++) {
        points.push_back(Point(this->renderer, i % this->SCREEN_WIDTH, i % this->SCREEN_HEIGHT));
    }
    for(pointsiter = points.begin(); pointsiter != points.end(); ++pointsiter) {
        //pointsiter->addToCanvas();
        pointsiter->print();
    }

    bool quit = false;
    while(!quit) {
        while(SDL_PollEvent(this->event) != 0) {
            if(event->type == SDL_QUIT || event->key.keysym.scancode == SDL_SCANCODE_Q)
                quit = true;
            //this->print();
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

bool VectorDrawer::init()
{
    char err[200]; err[0] = 0;

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        sprintf(err, "SDL could not initialise! SDL_ERROR: %s\n", SDL_GetError());
        SDL_LogCritical(SDL_LOG_CATEGORY_ERROR, err);
        return false;
    } else {
        return true;
    }
}

bool VectorDrawer::initObjects()
{
    char err[200]; err[0] = 0;

    this->event = new SDL_Event;
    this->current = new SDL_DisplayMode;
    SDL_GetCurrentDisplayMode(0, this->current);
    this->SCREEN_WIDTH = this->current->w; this->SCREEN_HEIGHT = this->current->h;
    this->window = SDL_CreateWindow(this->TITLE.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, this->SCREEN_WIDTH, this->SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if(this->window == NULL) {
        sprintf(err, "Window could not be created! SDL_Error: %s\n", SDL_GetError());
    } else if(this->renderer == NULL) {
        sprintf(err, "Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
    } else if(this->event == NULL) {
        sprintf(err, "SDL Event object could not be created! SDL_Error: %s\n", SDL_GetError());
    } else if(this->current == NULL) {
        sprintf(err, "SDL current displaymode failed! SDL_Error: %s\n", SDL_GetError());
    } else {
        return true;
    }

    SDL_LogCritical(SDL_LOG_CATEGORY_ERROR, err);
    return false;
}
