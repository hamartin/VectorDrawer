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

void Point::rotate(const int degrees, point_t *origin)
{
    Point::rotate((double)degrees, origin);
}

void Point::rotate(const float degrees, point_t *origin)
{
    Point::rotate((double)degrees, origin);
}

void Point::rotate(const double degrees, point_t *origin)
{
    double radian = (degrees * M_PI)/180;
    double s = sin(radian);
    double c = cos(radian);

    int x;
    int y;

    if(origin) {
        x = (int)((p->x - origin->x) * c - (p->y - origin->y) * s);
        y = (int)((p->y - origin->y) * s + (p->y - origin->y) * c);
        p->x = x + origin->x;
        p->y = y + origin->y;
    } else {
        p->x = (int)(p->x * c - p->y * s);
        p->y = (int)(p->x * s + p->y * c);
    }
}
