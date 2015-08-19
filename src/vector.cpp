//
// VECTOR.CPP
//

#include <iostream>
#include "vector.h"

Vector::Vector(SDL_Renderer *renderer, const int &a, const int &b, const int &origina, const int &originb) : Coords(renderer, a, b)
{
    this->ox = origina;
    this->oy = originb;
}

void Vector::debug()
{
    std::cout << "Vector:\n";
    std::cout << "OX: " << this->ox << std::endl;
    std::cout << "OY: " << this->oy << std::endl;
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
