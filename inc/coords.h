//
// COORDS.H
//

#ifndef __COORDS_H__
#define __COORDS_H__

#include <SDL2/SDL.h>

class Coords {
protected:
    Coords(SDL_Renderer* renderer, const int &a = 0, const int &b = 0);
    void debug();
    void print();
public:
    SDL_Renderer *renderer;
    int x;
    int y;
};

#endif
