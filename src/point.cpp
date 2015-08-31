/*
 * POINT.CPP
 */

#include "point.h"

// Initialising shared variable.
unsigned int Point::IDPointIt = 0;

Point::Point(point_t *p)
{
    ID = ++IDPointIt;
    this->p = p;
}

Point::Point(const int x, const int y)
{
    ID = ++IDPointIt;
    point_t *p = new point_t(x, y);
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

void Point::print()
{
    std::cout << "Point: " << ID << "\n\tX: " << p->x << "\n\tY: " << p->y << std::endl;
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
    int x, y;

    if(origin) {
        x = (int)lround(((p->x - origin->x) * c) - ((p->y - origin->y) * s)) + origin->x;
        y = (int)lround(((p->x - origin->x) * s) + ((p->y - origin->y) * c)) + origin->y;
    } else {
        x = (int)lround((p->x * c) - (p->y * s));
        y = (int)lround((p->x * s) + (p->y * c));
    }

    p->x = x;
    p->y = y;
}
