/*
 * VECTOR.CPP
 */

#include <iostream>
#include "vector.h"

Vector::Vector(SDL_Renderer *renderer, const int &x, const int &y, const int &z)
{
    this->renderer = renderer;
    this->x = x; this->y = y; this->z = z;
}

Vector *Vector::addVector(Vector *v)
{
    Vector *vnew = new Vector(this->renderer, this->x + v->x, this->y + v->y, this->z + v->z);
    return vnew;
}

Vector *Vector::rotateXY(const int &degrees)
{
    double radian = (degrees * M_PI)/180;
    double x = this->x * cos(radian) + this->y * -sin(radian);
    double y = this->x * sin(radian) + this->y * cos(radian);
    double z = this->z;
    Vector *v = new Vector(this->renderer, x, y, z);
    return v;
}

Vector *Vector::rotateYZ(const int &degrees)
{
    double radian = (degrees * M_PI)/180;
    double x = this->x;
    double y = this->y * cos(radian) + this->z * -sin(radian);
    double z = this->y * sin(radian) + this->z * cos(radian);
    Vector *v = new Vector(this->renderer, x, y, z);
    return v;
}

Vector *Vector::rotateXZ(const int &degrees)
{
    double radian = (degrees * M_PI)/180;
    double x = this->x * cos(radian) + this->z * sin(radian);
    double y = this->y;
    double z = this->x * -sin(radian) + this->z * cos(radian);
    Vector *v = new Vector(this->renderer, x, y, z);
    return v;
}

Vector *Vector::scale(const float &x, const float &y, const float &z)
{
    Vector *vnew = new Vector(this->renderer, this->x *= x, this->y *= y, this->z *= z);
    return vnew;
}

Vector *Vector::subtractVector(Vector *v)
{
    Vector *vnew = new Vector(this->renderer, this->x - v->x, this->y - v->y, this->z - v->z);
    return vnew;
}

void Vector::print()
{
    std::cout << "Vector:\n";
    std::cout << "X: " << this->x << std::endl;
    std::cout << "Y: " << this->y << std::endl;
    std::cout << "Z: " << this->z << std::endl;
}
