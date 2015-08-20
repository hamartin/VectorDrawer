//
// POINT.H
//

#ifndef __POINT_H__
#define __POINT_H__

#include <SDL2/SDL.h>
#include "coords.h"
#include "vector.h"

class Point: public Coords {
public:
    Point(SDL_Renderer *renderer, const int &a, const int &b, const int &c): Coords(renderer, a, b, c) {}
    void debug();
    void print();
    void addToCanvas();
    void setPointToPoint(const int &a, const int &b, const int &c);
    Point  *addVectorToPoint(Vector *v);
    Point  *subtractVectorFromPoint(Vector *v);
    Vector *subtractPointFromPoint(Point *p);
};

#endif
