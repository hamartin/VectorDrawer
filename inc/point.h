/*
 * POINT.H
 */

#ifndef __POINT_H__
#define __POINT_H__

#include <cmath>
#include "variables.h"

class Point {
public:
    Point(point_t *p);
    ~Point();
    point_t *getPoint();
    void rotate(const int degrees, point_t *origin = NULL);
    void rotate(const float degrees, point_t *origin = NULL);
    void rotate(const double degrees, point_t *origin = NULL);
private:
    point_t *p;
};

#endif
