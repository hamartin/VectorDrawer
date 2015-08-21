/*
 * CAMERA.H
 */

#ifndef __CAMERA_H__
#define __CAMERA_H__

#include <SDL2/SDL.h>
#include "objects.h"

class Camera {
public:
    Camera(SDL_Renderer *renderer,
            SDL_Event *event,
            const unsigned int &xMin,
            const unsigned int &xMax,
            const unsigned int &yMin,
            const unsigned int &yMax,
            const unsigned int &zMin,
            const unsigned int &zMax);
    void start();
protected:
private:
    void draw();
    void redraw();

    SDL_Renderer *renderer;
    SDL_Event *event;

    point_vec_t points;
    pointiter_vec_t pointsiter;
    vector_vec_t vectors;
    vectoriter_vec_t vectorsiter;

    unsigned int xMin, xMax, yMin, yMax, zMin, zMax;
};

#endif
