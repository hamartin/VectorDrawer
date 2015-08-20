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
    void setPointToPoint(Point *p);
    Point  *addVectorToPoint(Vector *v);
    Point  *rotateXY(const int &degrees);
    Point  *rotateYZ(const int &degrees);
    Point  *rotateXZ(const int &degrees);
    Point  *scale(const float &a, const float &b, const float &c);
    Point  *subtractVectorFromPoint(Vector *v);
    Vector *subtractPointFromPoint(Point *p);
};

#endif
