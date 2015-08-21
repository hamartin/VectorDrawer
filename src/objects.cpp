/*
 * OBJECTS.CPP
 */

#include "objects.h"

/*
 * Objects class
 */

Objects::Objects(SDL_Renderer *renderer, const int &x, const int &y, const int &z)
{
    this->renderer = renderer;
    this->x = x; this->y = y; this->z = z;
}

void Objects::print()
{
    std::cout << "X: " << this->x << std::endl;
    std::cout << "Y: " << this->y << std::endl;
    std::cout << "Z: " << this->z << std::endl;
}

void Objects::setPoint(Point *p)
{
    this->x = p->x; this->y = p->y; this->z = p->z;
}

/*
 * Point class
 */

Point *Point::addVector(Vector *v)
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
    Point *p = new Point(this->renderer, x, y, z);
    return p;
}

Point *Point::rotateYZ(const int &degrees)
{
    double radian = (degrees * M_PI)/180;
    double x = this->x;
    double y = this->y * cos(radian) + this->z * -sin(radian);
    double z = this->y * sin(radian) + this->z * cos(radian);
    Point *p = new Point(this->renderer, x, y, z);
    return p;
}

Point *Point::rotateXZ(const int &degrees)
{
    double radian = (degrees * M_PI)/180;
    double x = this->x * cos(radian) + this->z * sin(radian);
    double y = this->y;
    double z = this->x * -sin(radian) + this->z * cos(radian);
    Point *p = new Point(this->renderer, x, y, z);
    return p;
}

Point *Point::scale(const float &x, const float &y, const float &z)
{
    Point *p = new Point(this->renderer, this->x *= x, this->y *= y, this->z *= z);
    return p;
}

Point *Point::subtractVector(Vector *v)
{
    Point *p = new Point(this->renderer, this->x - v->x, this->y - v->y, this->z - v->z);
    return p;
}

Vector *Point::subtractPoint(Point *p)
{
    Vector *v = new Vector(this->renderer, this->x - p->x, this->y - p->y, this->z - p->z);
    return v;
}

void Point::addToCanvas()
{
    SDL_RenderDrawPoint(this->renderer, this->x, this->y);
}

void Point::print()
{
    std::cout << "Point:\n";
    Objects::print();
}

/*
 * Vector class
 */

void Vector::print()
{
    std::cout << "Vector:\n";
    Objects::print();
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
