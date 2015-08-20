//
// VECTOR.H
//

#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <SDL2/SDL.h>
#include "coords.h"

class Vector: public Coords {
public:
    Vector(SDL_Renderer *renderer, const int &a, const int &b, const int &c) : Coords(renderer, a, b, c) {}
    void debug();
    void print();
    void addToCanvas();
    Vector *addVectorToVector(Vector *v);
    Vector *subtractVectorFromVector(Vector *v);
    Vector *rotateXY(const int &degrees);
    Vector *rotateYZ(const int &degrees);
    Vector *rotateXZ(const int &degrees);
    Vector *scale(const int &a, const int &b, const int &c);
};

#endif
