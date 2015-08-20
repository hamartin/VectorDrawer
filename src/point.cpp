//
// POINT.CPP
//

#include <iostream>
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

void Point::setPointToPoint(const int &a, const int &b, const int &c)
{
    this->xptp = a; this->yptp = b; this->zptp = c;
}

Point *Point::addVectorToPoint(Vector *v)
{
    Point *p = new Point(this->renderer, this->x + v->x, this->y + v->y, this->z + v->z);
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
