/*
 * VECTOR.H
 */

#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <cmath>
#include <SDL2/SDL.h>
#include <vector>

class Vector {
public:
    Vector(SDL_Renderer *renderer, const int &x, const int &y, const int &z);
    Vector *addVector(Vector *v);
    Vector *rotateXY(const int &degrees);
    Vector *rotateYZ(const int &degrees);
    Vector *rotateXZ(const int &degrees);
    Vector *scale(const float &x, const float &y, const float &z);
    Vector *subtractVector(Vector *v);
    void print();

    int x, y, z;
protected:
private:
    SDL_Renderer *renderer;
};

typedef std::vector<Vector> vector_vec_t;
typedef std::vector<Vector>::iterator vectoriter_vec_t;

#endif
