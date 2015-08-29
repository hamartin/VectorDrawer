/*
 * POINT.H
 */

#ifndef __POINT_H__
#define __POINT_H__

#include "variables.h"

class Point {
public:
    Point(point_t *p);
    ~Point();
private:
    point_t *p;
};

#endif
