//
// VECTOR.CPP
//

#include <iostream>
#include "vector.h"

void Vector::debug()
{
    std::cout << "Vector:\n";
    Coords::debug();
}

void Vector::print()
{
    Coords::print();
}

Vector *Vector::addVectorToVector(Vector *v)
{
    Vector *ve = new Vector(this->renderer, this->x + v->x, this->y + v->y);
    return ve;
}

Vector *Vector::subtractVectorFromVector(Vector *v)
{
    Vector *ve = new Vector(this->renderer, this->x - v->x, this->y - v->y);
    return ve;
}
