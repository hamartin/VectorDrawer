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
        if((*p).oz < this->zMax && (*p).oz > this->zMin &&
           (*p).oy < this->yMax && (*p).oy > this->yMin &&
           (*p).ox < this->xMax && (*p).ox > this->xMin) {
            (*p).addToCanvas();
        }
    }
    for(linesegmentiter_vec_t l = this->linesegments.begin(); l != linesegments.end(); l++) {
        if((*l).oz <= this->zMax && (*l).oz >= this->zMin &&
           (*l).ez <= this->zMax && (*l).ez >= this->zMin &&
           (*l).oy <= this->yMax && (*l).oy >= this->yMin &&
           (*l).ey <= this->yMax && (*l).ey >= this->yMin &&
           (*l).ox <= this->xMax && (*l).ox >= this->xMin &&
           (*l).ex <= this->xMax && (*l).ex >= this->xMin) {
            (*l).addToCanvas();
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

void Camera::scale(const float &x, const float &y, const float &z)
{
    for(pointiter_vec_t p = points.begin(); p != points.end(); p++) {
        Point *pnew = (*p).scale(x, y, z);
        point_t newp(pnew->ox, pnew->oy, pnew->oz);
        (*p).setPoint(newp);
        delete pnew;
    }
    for(linesegmentiter_vec_t l = linesegments.begin(); l != linesegments.end(); l++) {
        Linesegment *lnew = (*l).scale(x, y, z);
        point_t s(lnew->ox, lnew->oy, lnew->oz);
        point_t e(lnew->ex, lnew->ey, lnew->ez);
        (*l).setPoint(s, e);
        delete lnew;
    }
}

void Camera::rotateXY()
{
    for(pointiter_vec_t p = this->points.begin(); p != this->points.end(); p++) {
        Point *pnew = (*p).rotateXY(15);
        point_t newp(pnew->ox, pnew->oy, pnew->oz);
        (*p).setPoint(newp);
        delete pnew;
    }
    for(linesegmentiter_vec_t l = this->linesegments.begin(); l != this->linesegments.end(); l++) {
        Linesegment *lnew = (*l).rotateXY(15);
        point_t s(lnew->ox, lnew->oy, lnew->oz);
        point_t e(lnew->ex, lnew->ey, lnew->ez);
        (*l).setPoint(s, e);
        delete lnew;
    }
}

void Camera::start()
{
    bool quit = false;

    /*for(int i = 0; i <= 100; i++) {
        Point *p = new Point(this->renderer, i,i,i);
        points.push_back(*p);
    }*/

    point_t s(0, 0, 0);
    point_t e(100, 0, 0);
    Linesegment *l = new Linesegment(this->renderer, s, e);
    linesegments.push_back(*l);
    e.x = -100;
    l = new Linesegment(this->renderer, s, e);
    linesegments.push_back(*l);
    e.x = 0; e.y = 100;
    l = new Linesegment(this->renderer, s, e);
    linesegments.push_back(*l);
    e.y = -100;
    l = new Linesegment(this->renderer, s, e);
    linesegments.push_back(*l);
    e.x = 100; e.y = 100;
    l = new Linesegment(this->renderer, s, e);
    linesegments.push_back(*l);
    e.x = -100; e.y = -100;
    l = new Linesegment(this->renderer, s, e);
    linesegments.push_back(*l);
    e.y = 100;
    l = new Linesegment(this->renderer, s, e);
    linesegments.push_back(*l);
    e.x = 100; e.y = -100;
    l = new Linesegment(this->renderer, s, e);
    linesegments.push_back(*l);

    while(!quit) {
        while(SDL_PollEvent(this->event) != 0) {
            if(event->type == SDL_QUIT || event->key.keysym.scancode == SDL_SCANCODE_Q || event->key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
                quit = true;
            } else if(event->key.keysym.scancode == SDL_SCANCODE_D) {
                this->drawWithoutCulling();
            } else if(event->key.keysym.scancode == SDL_SCANCODE_C) {
                this->drawWithCulling();
            } else if(event->key.keysym.scancode == SDL_SCANCODE_A) {
                this->scale(0.5, 0.5, 0.5);
            } else if(event->key.keysym.scancode == SDL_SCANCODE_S) {
                this->scale(2, 2, 2);
            } else if(event->key.keysym.scancode == SDL_SCANCODE_R) {
                this->rotateXY();
            }
        }
    }
}
