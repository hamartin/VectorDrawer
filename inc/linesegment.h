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
private:
    Point *start;
    Point *end;
    point_vec_t *points;
};

typedef std::vector<Linesegment *> ls_vec_t;
typedef std::vector<Linesegment *>::iterator lsit_vec_t;

#endif
