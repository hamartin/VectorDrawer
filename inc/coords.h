//
// COORDS.H
//

#ifndef __COORDS_H__
#define __COORDS_H__

#include <SDL2/SDL.h>

class Coords {
protected:
    Coords(SDL_Renderer* renderer, const int &a, const int &b, const int &c);
    void debug();
    void print();
public:
    SDL_Renderer *renderer;
    int x, y, z;
    int xptp, yptp, zptp;
};

#endif
