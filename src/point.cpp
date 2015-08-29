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

point_t *Point::getPoint()
{
    return p;
}

void Point::rotate(const int degrees)
{
    Point::rotate((double)degrees);
}

void Point::rotate(const float degrees)
{
    Point::rotate((double)degrees);
}

void Point::rotate(const double degrees)
{
    double radian = (degrees * M_PI)/180;
    double s = sin(radian);
    double c = cos(radian);
    p->x = (int)(p->x * c + p->y * -s);
    p->y = (int)(p->x * s + p->y * c);
}
