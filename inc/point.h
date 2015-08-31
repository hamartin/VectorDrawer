/*
 * POINT.H
 */

#ifndef __POINT_H__
#define __POINT_H__

#include <cmath>
#include <iostream>
#include <vector>
#include "variables.h"

class Point {
public:
    Point(point_t *p);
    Point(const int x, const int y);
    ~Point();
    point_t *getPoint();
    void print();
    void rotate(const int degrees, point_t *origin = NULL);
    void rotate(const float degrees, point_t *origin = NULL);
    void rotate(const double degrees, point_t *origin = NULL);

    unsigned int ID;
private:
    point_t *p;
    static unsigned int IDPointIt;
};

typedef std::vector<Point *> point_vec_t;
typedef std::vector<Point *>::iterator pointit_vec_t;

#endif
