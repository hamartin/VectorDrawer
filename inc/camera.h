/*
 * CAMERA.H
 */

#ifndef __CAMERA_H__
#define __CAMERA_H__

#include <SDL2/SDL.h>
#include "linesegment.h"
#include "point.h"
#include "vector.h"

class Camera {
public:
    Camera(SDL_Renderer *renderer,
            SDL_Event *event,
            const int &xMin,
            const int &xMax,
            const int &yMin,
            const int &yMax,
            const int &zMin,
            const int &zMax);
    void start();
protected:
private:
    void draw();
    void drawWithCulling();
    void drawWithoutCulling();
    void increaseSize();
    void rotateXY();
    void scale(const float &x, const float &y, const float &z);

    SDL_Renderer *renderer;
    SDL_Event *event;

    point_vec_t points;
    pointiter_vec_t pointsiter;
    vector_vec_t vectors;
    vectoriter_vec_t vectorsiter;
    linesegment_vec_t linesegments;
    linesegmentiter_vec_t linesegmentsiter;

    int xMin, xMax, yMin, yMax, zMin, zMax;
};

#endif
