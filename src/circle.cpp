/*
 * CIRCLE.CPP
 */

#include "circle.h"

unsigned int Circle::IDCircleIt = 0;

Circle::Circle(Point *origin, const unsigned int radius)
{
    ID = ++IDCircleIt;
    p = origin;
    this->radius = radius;
    points = new point_vec_t;
    calculateCircle();
}

Circle::Circle(point_t *origin, const unsigned int radius)
{
    ID = ++IDCircleIt;
    p = new Point(origin);
    this->radius = radius;
    points = new point_vec_t;
    calculateCircle();
}

Circle::Circle(const int x, const int y, const unsigned int radius)
{
    ID = ++IDCircleIt;
    p = new Point(x, y);
    this->radius = radius;
    points = new point_vec_t;
    calculateCircle();
}

Circle::~Circle()
{
    delete p;
    delete points;
}

point_vec_t *Circle::getPoints()
{
    return points;
}

unsigned int Circle::getRadius()
{
    return radius;
}

void Circle::calculateCircle()
{
    if(p == NULL)
        return;
    points->clear();

    int f = 1 - radius;
    int ddFx = 1;
    int ddFy = -2 * radius;
    int x = 0;
    int y = radius;

    // Algorith doesn't account for the farthest points.
    point_t *pt = p->getPoint();
    points->push_back(new Point(new point_t(pt->x, pt->y + radius)));
    points->push_back(new Point(new point_t(pt->x, pt->y - radius)));
    points->push_back(new Point(new point_t(pt->x + radius, pt->y)));
    points->push_back(new Point(new point_t(pt->x - radius, pt->y)));

    // Generate circle.
    while(x < y) {
        if(f >= 0) {
            y--;
            ddFy += 2;
            f += ddFy;
        }
        x++;
        ddFx += 2;
        f += ddFx;

        // Build our current arc.
        points->push_back(new Point(new point_t(pt->x + x, pt->y + y)));
        points->push_back(new Point(new point_t(pt->x - x, pt->y + y)));
        points->push_back(new Point(new point_t(pt->x + x, pt->y - y)));
        points->push_back(new Point(new point_t(pt->x - x, pt->y - y)));
        points->push_back(new Point(new point_t(pt->x + y, pt->y + x)));
        points->push_back(new Point(new point_t(pt->x - y, pt->y + x)));
        points->push_back(new Point(new point_t(pt->x + y, pt->y - x)));
        points->push_back(new Point(new point_t(pt->x - y, pt->y - x)));
    }
}

void Circle::changeRadius(const unsigned int radius)
{
    this->radius = radius;
    calculateCircle();
}

void Circle::print()
{
    std::cout << "Circle: " << ID << "\n\tRadius: " << radius << std::endl;
    p->print();
    std::cout << "Number of points in circle: " << points->size() << std::endl;
}
