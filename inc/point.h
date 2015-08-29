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
    void rotate(const int degrees);
    void rotate(const float degrees);
    void rotate(const double degrees);
private:
    point_t *p;
};

#endif
