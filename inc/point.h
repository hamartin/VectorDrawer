/*
 * POINT.H
 */

#ifndef __POINT_H__
#define __POINT_H__

#include <cmath>
#include <SDL2/SDL.h>
#include <vector>
#include "vector.h"
#include "object.h"

class Point : public Object {
public:
    Point(SDL_Renderer *renderer, const point_t &p) : Object(renderer, p) {}
    Point *addVector(Vector *v);
    Point *rotateXY(const int &degrees);
    Point *rotateYZ(const int &degrees);
    Point *rotateXZ(const int &degrees);
    Point *scale(const float &x, const float &y, const float &z);
    Point *subtractVector(Vector *v);
    Vector *subtractPoint(Point *p);
    void addToCanvas();
    void print();
    void setPoint(const point_t &p);
    void setPoint(Point *p);
protected:
private:
};

typedef std::vector<Point> point_vec_t;
typedef std::vector<Point>::iterator pointiter_vec_t;

#endif
