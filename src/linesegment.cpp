/*
 * LINESEGMENT.CPP
 */

#include "linesegment.h"

Linesegment::Linesegment(SDL_Renderer *renderer, const int &sx, const int &sy, const int &sz, const int &ex, const int &ey, const int &ez)
{
    this->renderer = renderer;
    this->sx = sx; this->sy = sy; this->sz = sz;
    this->ex = ex; this->ey = ey; this->ez = ez;
    this->pointsInSegment();
}

Linesegment *Linesegment::rotateXY(const int &degrees)
{
    double radian = (degrees * M_PI)/180;
    double s = sin(radian);
    double c = cos(radian);
    double sx = this->sx * c - this->sy * s;
    double sy = this->sx * s + this->sy * c;
    double ex = this->ex * c - this->ey * s;
    double ey = this->ex * s + this->ey * c;
    double sz = this->sz; double ez = this->ex;
    Linesegment *l = new Linesegment(this->renderer, lround(sx), lround(sy),
            lround(sz), lround(ex), lround(ey), lround(ez));
    return l;
}

Linesegment *Linesegment::scale(const float &x, const float &y, const float &z)
{
    Linesegment *l = new Linesegment(this->renderer, this->sx *= x, this->sy *= y, this->sz *= z, this->ex *= x, this->ey *= y, this->ez *= z);
    return l;
}

void Linesegment::addToCanvas(const int &x, const int &y)
{
    for(pointiter_vec_t p = this->seg.begin(); p != this->seg.end(); p++) {
        (*p).addToCanvas(x, y);
    }
}

void Linesegment::pointsInSegment()
{
    this->seg.clear();

    float x1 = this->sx; float y1 = this->sy;
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
            this->seg.push_back(Point(this->renderer, y, x, this->sz));
        } else {
            this->seg.push_back(Point(this->renderer, x, y, this->sz));
        }

        error -= dy;
        if(error < 0) {
            y += ystep;
            error += dx;
        }
    }
}

void Linesegment::setPoint(const int &sx, const int &sy, const int &sz, const int &ex, const int &ey, const int &ez)
{
    this->sx = sx; this->ex = ex;
    this->sy = sy; this->ey = ey;
    this->sz = sz; this->ez = ez;
    this->pointsInSegment();
}
