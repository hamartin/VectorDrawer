/*
 * VD.H
 */

#ifndef __VD_H__
#define __VD_H__

#include <iostream>
#include <SDL2/SDL.h>
#include <string>
#include "camera.h"

class VD {
public:
    VD();
    ~VD();
    void start();

protected:

private:
    bool initSDL();

    unsigned int screen_width, screen_height;

    SDL_DisplayMode *current;
    SDL_Event *event;
    SDL_Renderer *renderer;
    SDL_Window *window;
    Camera *camera;
};

int main();
void logCritical(std::string err);

/*
#include <iostream>
#include <SDL2/SDL.h>
#include <string>
#include <vector>
#include "vector.h"
#include "point.h"

typedef std::vector<Point> point_vec_t;
typedef std::vector<Point>::iterator pointiter_vec_t;
typedef std::vector<Vector> vector_vec_t;
typedef std::vector<Vector>::iterator vectoriter_vec_t;

class VectorDrawer {
public:
    VectorDrawer(const std::string &TITLE);
    ~VectorDrawer();
    void begin();
    void debug();
    void print();
    void redraw();
    bool init();
    bool initObjects();
private:
    unsigned int SCREEN_WIDTH;
    unsigned int SCREEN_HEIGHT;
    std::string TITLE;

    Camera          *camera;
    SDL_DisplayMode *current;
    SDL_Event       *event;
    SDL_Renderer    *renderer;
    SDL_Window      *window;

    point_vec_t      points;
    pointiter_vec_t  pointsiter;
    vector_vec_t     vectors;
    vectoriter_vec_t vectorsiter;
};
*/

#endif
