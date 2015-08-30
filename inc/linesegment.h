/*
 * LINESEGMENT.H
 */

#ifndef __LINESEGMENT_H__
#define __LINESEGMENT_H__

#include "point.h"

class Linesegment {
public:
    Linesegment(Point *start, Point *end);
    ~Linesegment();
    point_vec_t *getPoints();
    void calculateLine();
    void print();
    void rotate(const int degrees, point_t *origin = NULL);
    void rotate(const float degrees, point_t *origin = NULL);
    void rotate(const double degrees, point_t *origin = NULL);
private:
    Point *start;
    Point *end;
    point_vec_t *points;
};

typedef std::vector<Linesegment *> ls_vec_t;
typedef std::vector<Linesegment *>::iterator lsit_vec_t;

#endif
