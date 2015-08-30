/*
 * CIRCLE.H
 */

#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include "point.h"
#include "variables.h"

class Circle {
public:
    Circle(Point *origin, const unsigned int radius);
    ~Circle();
    point_vec_t *getPoints();
    void calculateCircle();
    void print();
private:
    Point *p;
    unsigned int radius;
    point_vec_t *points;
};

typedef std::vector<Circle *> circle_vec_t;
typedef std::vector<Circle *>::iterator circleit_vec_t;

#endif
