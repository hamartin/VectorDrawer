/*
 * OBJECTS.H
 */

#ifndef __OBJECTS_H__
#define __OBJECTS_H__

#include <cmath>
#include <iostream>
#include <SDL2/SDL.h>
#include <vector>

class Objects;
class Point;
class Vector;

typedef std::vector<Point> point_vec_t;
typedef std::vector<Point>::iterator pointiter_vec_t;
typedef std::vector<Vector> vector_vec_t;
typedef std::vector<Vector>::iterator vectoriter_vec_t;

class Objects {
public:
    int x, y, z;
    void setPoint(Point *p);
protected:
    Objects(SDL_Renderer *renderer, const int &x, const int &y, const int &z);
    void print();

    SDL_Renderer *renderer;
private:
};

class Point : public Objects {
public:
    Point(SDL_Renderer *renderer, const int &x, const int &y, const int &z) : Objects(renderer, x, y, z) {}
    Point *addVector(Vector *v);
    Point *rotateXY(const int &degrees);
    Point *rotateYZ(const int &degrees);
    Point *rotateXZ(const int &degrees);
    Point *scale(const float &x, const float &y, const float &z);
    Point *subtractVector(Vector *v);
    Vector *subtractPoint(Point *p);
    void addToCanvas();
    void print();
protected:
private:
};

class Vector : public Objects {
public:
    Vector(SDL_Renderer *renderer, const int &x, const int &y, const int &z) : Objects(renderer, x, y, z) {}
    Vector *addVector(Vector *v);
    Vector *rotateXY(const int &degrees);
    Vector *rotateYZ(const int &degrees);
    Vector *rotateXZ(const int &degrees);
    Vector *scale(const float &x, const float &y, const float &z);
    Vector *subtractVector(Vector *v);
    void print();
protected:
private:
};

#endif
