/*
 * LINESEGMENT.CPP
 */

#include "linesegment.h"

Linesegment::Linesegment(Point *start, Point *end)
{
    this->start = start;
    this->end = end;
    points = new point_vec_t;
    calculateLine();
}

Linesegment::Linesegment(const int sx, const int sy, const int ex, const int ey)
{
    point_t *sp = new point_t(sx, sy);
    Point *spoint = new Point(sp);
    point_t *ep = new point_t(ex, ey);
    Point *epoint = new Point(ep);
    Linesegment(spoint, epoint);
}

Linesegment::Linesegment(point_t *sp, point_t *ep)
{
    Point *spoint = new Point(sp);
    Point *epoint = new Point(ep);
    Linesegment(spoint, epoint);
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
    std::cout << "Linesegment:\n";
    start->print();
    end->print();
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
