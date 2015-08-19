//
// VECTOR.H
//

#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <SDL2/SDL.h>
#include "coords.h"

class Vector: public Coords {
public:
    Vector(SDL_Renderer *renderer, const int &a, const int &b, const int &origina = 0, const int &originb = 0);
    void debug();
    void print();
    Vector *addVectorToVector(Vector *v);
    Vector *subtractVectorFromVector(Vector *v);
    int ox, oy;
};

#endif
