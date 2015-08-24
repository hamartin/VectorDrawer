/*
 * LINESEGMENT.H
 */

#ifndef __LINESEGMENT_H__
#define __LINESEGMENT_H__

#include <cmath>
#include <SDL2/SDL.h>
#include <vector>
#include "point.h"
#include "object.h"

class Linesegment : public Object {
public:
    Linesegment(SDL_Renderer *renderer, const point_t &s, const point_t &e);
    Linesegment *rotateXY(const int &degrees);
    Linesegment *scale(const float &x, const float &y, const float &z);
    void addToCanvas();
    void pointsInSegment();
    void setPoint(const point_t &s, const point_t &e);
    int ex, ey, ez;
protected:
private:
    SDL_Renderer *renderer;
    point_vec_t seg;
    pointiter_vec_t segiter;
};

typedef std::vector<Linesegment> linesegment_vec_t;
typedef std::vector<Linesegment>::iterator linesegmentiter_vec_t;

#endif
