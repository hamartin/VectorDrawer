/*
 * LINESEGMENT.CPP
 */

#include "linesegment.h"

unsigned int Linesegment::IDLinesegmentIt = 0;

Linesegment::Linesegment(Point *start, Point *end)
{
    ID = ++IDLinesegmentIt;
    this->start = start;
    this->end = end;
    points = new point_vec_t;
    calculateLine();
}

Linesegment::Linesegment(int sx, int sy, int ex, int ey)
{
    ID = ++IDLinesegmentIt;
    this->start = new Point(sx, sy);
    this->end = new Point(ex, ey);
    points = new point_vec_t;
    calculateLine();
}

Linesegment::Linesegment(point_t *sp, point_t *ep)
{
    ID = ++IDLinesegmentIt;
    this->start = new Point(sp);
    this->end = new Point(ep);
    points = new point_vec_t;
    calculateLine();
}

Linesegment::~Linesegment()
{
    delete start;
    delete end;
    delete points;
}

point_vec_t *Linesegment::getPoints()
{
    return points;
}

void Linesegment::calculateLine()
{
    if(start == NULL || end == NULL)
        return;
    points->clear();

    point_t *ps = start->getPoint();
    point_t *pe = end->getPoint();

    double x1 = ps->x; double y1 = ps->y;
    double x2 = pe->x; double y2 = pe->y;

    const bool steep = (fabs(y2 - y1) > fabs(x2 - x1));
    if(steep) {
        std::swap(x1, y1);
        std::swap(x2, y2);
    }

    if(x1 > x2) {
        std::swap(x1, x2);
        std::swap(y1, y2);
    }

    const double dx = x2 - x1;
    const double dy = fabs(y2 - y1);

    double error = dx / 2.0f;
    const int ystep = (y1 < y2) ? 1 : -1;
    int y = (int)y1;
    const int maxX = (int)x2;

    for(int x = (int)x1; x < maxX; x++) {
        if(steep) {
            points->push_back(new Point(new point_t(y, x)));
        } else {
            points->push_back(new Point(new point_t(x, y)));
        }

        error -= dy;
        if(error < 0) {
            y +=ystep;
            error += dx;
        }
    }
}

void Linesegment::print()
{
    std::cout << "Linesegment: " << ID << std::endl;
    start->print();
    end->print();
    std::cout << "Number of points in segment: " << points->size() << std::endl;
}

void Linesegment::rotate(const int degrees, point_t *origin)
{
    Linesegment::rotate((double)degrees, origin);
}

void Linesegment::rotate(const float degrees, point_t *origin)
{
    Linesegment::rotate((double)degrees, origin);
}

void Linesegment::rotate(const double degrees, point_t *origin)
{
    if(origin) {
        end->rotate(degrees, origin);
    } else {
        point_t *ps = start->getPoint();
        end->rotate(degrees, ps);
    }
    calculateLine();
}
