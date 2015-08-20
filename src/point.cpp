//
// POINT.CPP
//

#include <iostream>
#include <cmath>
#include "point.h"

void Point::debug()
{
    std::cout << "Point:\n";
    Coords::debug();
}

void Point::print()
{
    this->addToCanvas();
    Coords::print();
}

void Point::addToCanvas()
{
    SDL_RenderDrawPoint(this->renderer, this->x, this->y);
}

void Point::setPointToPoint(Point *p)
{
    this->x = p->x; this->y = p->y; this->z = p->z;
}

Point *Point::addVectorToPoint(Vector *v)
{
    Point *p = new Point(this->renderer, this->x + v->x, this->y + v->y, this->z + v->z);
    return p;
}

Point *Point::rotateXY(const int &degrees)
{
    double radian = (degrees * M_PI)/180;
    double x = this->x * cos(radian) + this->y * -sin(radian);
    double y = this->x * sin(radian) + this->y * cos(radian);
    double z = this->z;
    Point *v = new Point(this->renderer, x, y, z);
    return v;
}

Point *Point::rotateYZ(const int &degrees)
{
    double radian = (degrees * M_PI)/180;
    double x = this->x;
    double y = this->y * cos(radian) + this->z * -sin(radian);
    double z = this->y * sin(radian) + this->z * cos(radian);
    Point *v = new Point(this->renderer, x, y, z);
    return v;
}

Point *Point::rotateXZ(const int &degrees)
{
    double radian = (degrees * M_PI)/180;
    double x = this->x * cos(radian) + this->z * sin(radian);
    double y = this->y;
    double z = this->x * -sin(radian) + this->z * cos(radian);
    Point *v = new Point(this->renderer, x, y, z);
    return v;
}

Point *Point::scale(const float &a, const float &b, const float &c)
{
    Point *p = new Point(this->renderer, this->x *= a, this->y *= b, this->z *= c);
    return p;
}

Point *Point::subtractVectorFromPoint(Vector *v)
{
    Point *p = new Point(this->renderer, this->x - v->x, this->y - v->y, this->z - v->z);
    return p;
}

Vector *Point::subtractPointFromPoint(Point *p)
{
    Vector *v = new Vector(this->renderer, this->x - p->x, this->y - p->y, this->z - p->z);
    return v;
}
