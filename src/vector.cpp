//
// VECTOR.CPP
//

#include <iostream>
#include <cmath>
#include "vector.h"

void Vector::debug()
{
    std::cout << "Vector:\n";
    Coords::debug();
}

void Vector::print()                                                             
{                                                                               
    this->addToCanvas();                                                        
    Coords::print();                                                            
}                                                                               

void Vector::addToCanvas()                                                       
{                                                                               
    SDL_RenderDrawPoint(this->renderer, this->x, this->y);                      
} 

Vector *Vector::addVectorToVector(Vector *v)
{
    Vector *ve = new Vector(this->renderer, this->x + v->x, this->y + v->y, this->z + v->z);
    return ve;
}

Vector *Vector::subtractVectorFromVector(Vector *v)
{
    Vector *ve = new Vector(this->renderer, this->x - v->x, this->y - v->y, this->z - v->z);
    return ve;
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

Vector *Vector::scale(const int &a, const int &b, const int &c)
{
    Vector *v = new Vector(this->renderer, this->x *= a, this->y *= b, this->z *= c);
    return v;
}
