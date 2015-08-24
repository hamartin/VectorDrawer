/*
 * POINT.CPP
 */

#include <iostream>
#include "point.h"

Point::Point(SDL_Renderer *renderer, const point_t &p) : Object(p)
{
    this->renderer = renderer;
}

Point *Point::addVector(Vector *v)
{
    point_t newp(this->ox + v->x, this->oy + v->y, this->oz + v->z);
    Point *p = new Point(this->renderer, newp);
    return p;
}

Point *Point::rotateXY(const int &degrees)
{
    double radian = (degrees * M_PI)/180;
    double s = sin(radian);
    double c = cos(radian);
    int x = lround(this->ox * c - this->oy * s);
    int y = lround(this->ox * s + this->oy * c);
    int z = lround(this->oz);
    point_t newp(x, y, z);
    Point *p = new Point(this->renderer, newp);
    return p;
}

Point *Point::rotateYZ(const int &degrees)
{
    double radian = (degrees * M_PI)/180;
    double s = sin(radian);
    double c = cos(radian);
    int x = lround(this->ox);
    int y = lround(this->oy * c + this->oz * -s);
    int z = lround(this->oy * s + this->oz * c);
    point_t newp(x, y, z);
    Point *p = new Point(this->renderer, newp);
    return p;
}

Point *Point::rotateXZ(const int &degrees)
{
    double radian = (degrees * M_PI)/180;
    double s = sin(radian);
    double c = cos(radian);
    int x = lround(this->ox * c + this->oz * s);
    int y = lround(this->oy);
    int z = lround(this->ox * -s + this->oz * c);
    point_t newp(x, y, z);
    Point *p = new Point(this->renderer, newp);
    return p;
}

Point *Point::scale(const float &x, const float &y, const float &z)
{
    point_t newp(lround(this->ox *= x), lround(this->oy *= y), lround(this->oz *= z));
    Point *p = new Point(this->renderer, newp);
    return p;
}

Point *Point::subtractVector(Vector *v)
{
    point_t newp(this->ox - v->x, this->oy - v->y, this->oz - v->z);
    Point *p = new Point(this->renderer, newp);
    return p;
}

Vector *Point::subtractPoint(Point *p)
{
    Vector *v = new Vector(this->renderer, this->ox - p->ox, this->oy - p->oy, this->oz - p->oz);
    return v;
}

void Point::addToCanvas()
{
    SDL_RenderDrawPoint(this->renderer, this->ox, this->oy);
}

void Point::print()
{
    std::cout << "Point:\n";
    std::cout << "X: " << this->ox << std::endl;
    std::cout << "Y: " << this->oy << std::endl;
    std::cout << "Z: " << this->oz << std::endl;
}

void Point::setPoint(const point_t &p)
{
    this->ox = p.x; this->oy = p.y; this->oz = p.z;
}

void Point::setPoint(Point *p)
{
    this->ox = p->ox; this->oy = p->oy; this->oz = p->oz;
}
