/*
 * CAMERA.CPP
 */

#include "camera.h"

Camera::Camera(SDL_Renderer *renderer,
        SDL_Event *event,
        const unsigned int &xMin,
        const unsigned int &xMax,
        const unsigned int &yMin,
        const unsigned int &yMax,
        const unsigned int &zMin,
        const unsigned int &zMax)
{
    this->renderer = renderer;
    this->event = event;
    this->xMin = xMin; this->xMax = xMax;
    this->yMin = yMin; this->yMax = yMax;
    this->zMin = zMin; this->zMax = zMax;
}

void Camera::start()
{
    bool quit = false;                                                             
                                                                                
    for(int i = 0; i <= 100; ++i) {                                             
        Point *p = new Point(this->renderer, (this->xMax/2) + i, (this->yMax/2) + i, i);                          
        points.push_back(*p);                                                   
    }                                                                           
                                                                                
    while(!quit) {                                                              
        while(SDL_PollEvent(this->event) != 0) {                                
            if(event->type == SDL_QUIT || event->key.keysym.scancode == SDL_SCANCODE_Q || event->key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
                quit = true;                                                    
            } else if(event->key.keysym.scancode == SDL_SCANCODE_D) {           
                this->redraw();                                                 
            } else if(event->key.keysym.scancode == SDL_SCANCODE_A) {           
                for(pointiter_vec_t p = points.begin(); p != points.end(); p++) {
                    Point *pnew = (*p).scale(0.5, 0.5, 0.5);                    
                    (*p).setPoint(pnew);                                 
                    delete pnew;                                                
                }                                                               
            } else if(event->key.keysym.scancode == SDL_SCANCODE_S) {           
                for(pointiter_vec_t p = points.begin(); p != points.end(); p++) {
                    Point *pnew = (*p).scale(2, 2, 2);                          
                    (*p).setPoint(pnew);                                 
                    delete pnew;                                                
                }                                                               
            } else if(event->key.keysym.scancode == SDL_SCANCODE_R) {           
                for(pointiter_vec_t p = points.begin(); p != points.end(); p++) {
                    Point *pnew = (*p).rotateXY(15);                            
                    (*p).setPoint(pnew);                                 
                    delete pnew;                                                
                }                                                               
            }                                                                   
        }                                                                       
    } 
}

void Camera::draw()
{
    SDL_RenderPresent(this->renderer);
}

void Camera::redraw()
{
    SDL_RenderClear(this->renderer);
    for(pointiter_vec_t p = this->points.begin(); p != points.end(); p++) {
        (*p).addToCanvas(); 
    }
    this->draw();
}
