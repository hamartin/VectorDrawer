/*
 * POINT.CPP
 */

#include "point.h"

Point::Point(point_t *p)
{
    this->p = p;
}

Point::~Point()
{
    delete p;
}
