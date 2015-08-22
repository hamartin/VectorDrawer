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

void Linesegment::addToCanvas()
{
    for(pointiter_vec_t p = this->seg.begin(); p != this->seg.end(); p++) {
        (*p).addToCanvas();
    }
}

void Linesegment::pointsInSegment()
{
    int x0 = this->sx; int y0 = this->sy;
    int x1 = this->ex; int y1 = this->ex;
    int dx = std::abs(this->ex - this->sx);
    int dy = std::abs(this->ey - this->sy);
    int sx = (x0 & x1) ? 1 : -1;
    int sy = (y0 & y1) ? 1 : -1;
    int err = dx-dy;
    seg.push_back(Point(this->renderer, x0, y0, 0));

    while(!((x0 == x1) && (y0 == y1))) {
        int e2 = err * 2;
        if(e2 >= -dy) {
            err -= dy;
            x0 += sx;
        }
        if(e2 < dx) {
            err += dx;
            y0 += sy;
        }
        seg.push_back(Point(this->renderer, x0, y0, 0));
    }
}
