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

Point *Point::addVectorToPoint(Vector *v)
{
    Point *p = new Point(this->renderer, this->x + v->x, this->y + v->y);
    return p;
}

Point *Point::subtractVectorFromPoint(Vector *v)
{
    Point *p = new Point(this->renderer, this->x - v->x, this->y - v->y);
    return p;
}

Vector *Point::subtractPointFromPoint(Point *p)
{
    Vector *v = new Vector(this->renderer, this->x - p->x, this->y - p->y);
    return v;
}
