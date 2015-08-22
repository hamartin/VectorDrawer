/*
 * CAMERA.CPP
 */

#include "camera.h"

Camera::Camera(SDL_Renderer *renderer,
        SDL_Event *event,
        const int &xMin,
        const int &xMax,
        const int &yMin,
        const int &yMax,
        const int &zMin,
        const int &zMax)
{
    this->renderer = renderer;
    this->event = event;
    this->xMin = xMin; this->xMax = xMax;
    this->yMin = yMin; this->yMax = yMax;
    this->zMin = zMin; this->zMax = zMax;
}

void Camera::draw()
{
    SDL_RenderPresent(this->renderer);
}

void Camera::drawWithCulling()
{
    SDL_RenderClear(this->renderer);
    for(pointiter_vec_t p = this->points.begin(); p != points.end(); p++) {
        if((*p).z < this->zMax && (*p).z > this->zMin &&
           (*p).y < this->yMax && (*p).y > this->yMin &&
           (*p).x < this->xMax && (*p).x > this->xMin) {
            (*p).addToCanvas();
        }
    }
    this->draw();
}

void Camera::drawWithoutCulling()
{
    SDL_RenderClear(this->renderer);
    for(pointiter_vec_t p = this->points.begin(); p != points.end(); p++) {
        (*p).addToCanvas();
    }
    for(linesegmentiter_vec_t l = this->linesegments.begin(); l != linesegments.end(); l++) {
        (*l).addToCanvas();
    }
    this->draw();
}

void Camera::start()
{
    bool quit = false;

    for(int i = 0; i <= 100; ++i) {
        Point *p = new Point(this->renderer, i, i, i);
        points.push_back(*p);
        Linesegment *l = new Linesegment(this->renderer, i, i, i, i+100, i+100, i+100);
        linesegments.push_back(*l);
    }

    while(!quit) {
        while(SDL_PollEvent(this->event) != 0) {
            if(event->type == SDL_QUIT || event->key.keysym.scancode == SDL_SCANCODE_Q || event->key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
                quit = true;
            } else if(event->key.keysym.scancode == SDL_SCANCODE_D) {
                this->drawWithoutCulling();
            } else if(event->key.keysym.scancode == SDL_SCANCODE_C) {
                this->drawWithCulling();
            } else if(event->key.keysym.scancode == SDL_SCANCODE_A) {
                for(pointiter_vec_t p = points.begin(); p != points.end(); p++) {
                    Point *pnew = (*p).scale(0.5, 0.5, 0.5);
                    (*p).setPoint(pnew->x, pnew->y, pnew->z);
                    delete pnew;
                }
            } else if(event->key.keysym.scancode == SDL_SCANCODE_S) {
                for(pointiter_vec_t p = points.begin(); p != points.end(); p++) {
                    Point *pnew = (*p).scale(2, 2, 2);
                    (*p).setPoint(pnew->x, pnew->y, pnew->z);
                    delete pnew;
                }
            } else if(event->key.keysym.scancode == SDL_SCANCODE_R) {
                for(pointiter_vec_t p = points.begin(); p != points.end(); p++) {
                    Point *pnew = (*p).rotateXY(15);
                    (*p).setPoint(pnew->x, pnew->y, pnew->z);
                    delete pnew;
                }
            }
        }
    }
}
