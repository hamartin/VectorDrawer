/*
 * CAMERA.CPP
 */

#include "camera.h"

Camera::Camera(sdlc *container)
{
    points = new point_vec_t;
    linesegments = new ls_vec_t;
    circles = new circle_vec_t;

    // We take over the responsebility for this pointer.
    this->container = container;

    points->push_back(new Point(new point_t(100,100)));
    linesegments->push_back(new Linesegment(new Point(200, 200), new Point(300,300)));
    circles->push_back(new Circle(new Point(400, 400), 50));
}

Camera::~Camera()
{
    delete points;
    delete linesegments;
    delete circles;

    // We have taken over the responsebility for this pointer.
    delete container;
}

void Camera::changeRadiusOnCircles(const unsigned int radius)
{
    clear();
    unsigned int rad;
    for(circleit_vec_t cit = circles->begin(); cit != circles->end(); cit++) {
        rad = (*cit)->getRadius();
        (*cit)->changeRadius(rad+=radius);
    }
    drawAndRender();
}

void Camera::clear()
{
    SDL_RenderClear(container->renderer);
}

void Camera::drawAndRender()
{
    clear();
    for(pointit_vec_t pit = points->begin(); pit != points->end(); pit++) {
        point_t *pt = (*pit)->getPoint();
        SDL_RenderDrawPoint(container->renderer, pt->x, pt->y);
    }
    for(lsit_vec_t lit = linesegments->begin(); lit != linesegments->end(); lit++) {
        point_vec_t *ps = (*lit)->getPoints(); 
        for(pointit_vec_t pit = ps->begin(); pit != ps->end(); pit++) {
            point_t *pt = (*pit)->getPoint();
            SDL_RenderDrawPoint(container->renderer, pt->x, pt->y);
        }
    }
    for(circleit_vec_t cit = circles->begin(); cit != circles->end(); cit++) {
        point_vec_t *ps = (*cit)->getPoints();
        for(pointit_vec_t pit = ps->begin(); pit != ps->end(); pit++) {
            point_t *pt = (*pit)->getPoint();
            SDL_RenderDrawPoint(container->renderer, pt->x, pt->y);
        }
    }
    render();
}

void Camera::render()
{
    SDL_RenderPresent(container->renderer);
}

void Camera::rotate(const int degrees)
{
    clear();
    for(pointit_vec_t pit = points->begin(); pit != points->end(); pit++) {
        (*pit)->rotate(degrees);
    }
    for(lsit_vec_t lit = linesegments->begin(); lit != linesegments->end(); lit++) {
        (*lit)->rotate(degrees);
    }
    drawAndRender();
}

void Camera::start()
{
    bool quit = false;
    SDL_Event *event = container->event;

    while(!quit)
    {
        while(SDL_PollEvent(event) != 0)
        {
            if(event->key.keysym.scancode == SDL_SCANCODE_D) {
                drawAndRender();
            } else if(event->key.keysym.scancode == SDL_SCANCODE_C) {
                clear();
                render();
            } else if(event->key.keysym.scancode == SDL_SCANCODE_F) {
                changeRadiusOnCircles(2);
            } else if(event->key.keysym.scancode == SDL_SCANCODE_G) {
                changeRadiusOnCircles(-2);
            } else if(event->key.keysym.scancode == SDL_SCANCODE_R) {
                rotate(1);
            } else if(event->type == SDL_QUIT ||
                    event->key.keysym.scancode == SDL_SCANCODE_Q ||
                    event->key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
                quit = true;
            }
        }

    }
}
