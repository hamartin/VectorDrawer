/*
 * LINESEGMENT.H
 */

#ifndef __LINESEGMENT_H__
#define __LINESEGMENT_H__

#include <cmath>
#include <SDL2/SDL.h>
#include <vector>
#include "point.h"

class Linesegment {
public:
    Linesegment(SDL_Renderer *renderer,
            const int &sx,
            const int &sy,
            const int &sz,
            const int &ex,
            const int &ey,
            const int &ez);
    Linesegment *rotateXY(const int &degrees);
    Linesegment *scale(const float &x, const float &y, const float &z);
    void addToCanvas(const int &x = 0, const int &y = 0);
    void pointsInSegment();
    void setPoint(const int &sx,
            const int &sy,
            const int &sz,
            const int &ex,
            const int &ey,
            const int &ez);
    int sx, sy, sz, ex, ey, ez;
protected:
private:
    SDL_Renderer *renderer;
    point_vec_t seg;
    pointiter_vec_t segiter;
};

typedef std::vector<Linesegment> linesegment_vec_t;
typedef std::vector<Linesegment>::iterator linesegmentiter_vec_t;

#endif
