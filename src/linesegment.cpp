/*
 * LINESEGMENT.CPP
 */

#include "linesegment.h"

Linesegment::Linesegment(SDL_Renderer *renderer, const point_t &s, const point_t &e) : Object(renderer, s)
{
    this->ex = e.x; this->ey = e.y; this->ez = e.z;
    this->pointsInSegment();
}

Linesegment *Linesegment::rotateXY(const int &degrees)
{
    double radian = (degrees * M_PI)/180;
    double si = sin(radian);
    double co = cos(radian);
    int sx = lround(this->ox * co - this->oy * si);
    int sy = lround(this->ox * si + this->oy * co);
    int sz = lround(this->oz);
    point_t s(sx, sy, sz);
    int ex = lround(this->ex * co - this->ey * si);
    int ey = lround(this->ex * si + this->ey * co);
    int ez = lround(this->ez);
    point_t e(ex, ey, ez);
    Linesegment *l = new Linesegment(this->renderer, s, e);
    return l;
}

Linesegment *Linesegment::scale(const float &x, const float &y, const float &z)
{
    point_t s(this->ox *= x, this->oy *= y, this->oz *= z);
    point_t e(this->ex *= x, this->ey *= y, this->ez *= z);
    Linesegment *l = new Linesegment(this->renderer, s, e);
    return l;
}

void Linesegment::addToCanvas()
{
    for(pointiter_vec_t p = this->seg.begin(); p != this->seg.end(); p++) {
        (*p).addToCanvas();
    }
}

void Linesegment::pointsInSegment()
{
    this->seg.clear();

    float x1 = this->ox; float y1 = this->oy;
    float x2 = this->ex; float y2 = this->ey;

    const bool steep = (fabs(y2 - y1) > fabs(x2 - x1));
    if(steep) {
        std::swap(x1, y1);
        std::swap(x2, y2);
    }

    if(x1 > x2) {
        std::swap(x1, x2);
        std::swap(y1, y2);
    }

    const float dx = x2 - x1;
    const float dy = fabs(y2 - y1);

    float error = dx / 2.0f;
    const int ystep = (y1 < y2) ? 1 : -1;
    int y = (int)y1;

    const int maxX = (int)x2;

    for(int x = (int)x1; x < maxX; x++) {
        if(steep) {
            point_t newp(y, x, this->oz);
            this->seg.push_back(Point(this->renderer, newp));
        } else {
            point_t newp(x, y, this->oz);
            this->seg.push_back(Point(this->renderer, newp));
        }

        error -= dy;
        if(error < 0) {
            y += ystep;
            error += dx;
        }
    }
}

void Linesegment::setPoint(const point_t &s, const point_t &e)
{
    this->ox = s.x; this->ex = e.x;
    this->oy = s.y; this->ey = e.y;
    this->oz = s.z; this->ey = e.z;
    this->pointsInSegment();
}
