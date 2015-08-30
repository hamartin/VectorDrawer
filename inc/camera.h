/*
 * CAMERA.H
 */

#ifndef __CAMERA_H__
#define __CAMERA_H__

#include <SDL2/SDL.h>
#include "circle.h"
#include "linesegment.h"
#include "point.h"
#include "variables.h"

class Camera {
public:
    Camera(sdlc *container);
    ~Camera();
    void start();
private:
    void changeRadiusOnCircles(const unsigned int radius);
    void clear();
    void drawAndRender();
    void render();
    void rotate(const int degrees);

    sdlc *container;
    point_vec_t *points;
    ls_vec_t *linesegments;
    circle_vec_t *circles;
};

#endif
