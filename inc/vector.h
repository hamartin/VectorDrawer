//
// VECTOR.H
//

#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <SDL2/SDL.h>
#include "coords.h"

class Vector: public Coords {
public:
    Vector(SDL_Renderer *renderer, const int &a = 0, const int &b = 0, const int &c = 0): Coords(renderer, a, b, c) {}
    void debug();
    void print();
    Vector *addVectorToVector(Vector *v);
    Vector *subtractVectorFromVector(Vector *v);
};

#endif
