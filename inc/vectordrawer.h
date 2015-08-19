//
// VECTORDRAWER.H
//

#ifndef __VECTORDRAWER_H__
#define __VECTORDRAWER_H__

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
    VectorDrawer(const std::string &TITLE, const unsigned int &SCREEN_WIDTH=640, const unsigned int &SCREEN_HEIGHT=480);
    ~VectorDrawer();
    bool init();
    void begin();
    void debug();
    void print();
private:
    unsigned int SCREEN_WIDTH;
    unsigned int SCREEN_HEIGHT;
    std::string TITLE;

    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event *event;

    point_vec_t points;
    pointiter_vec_t pointsiter;
    vector_vec_t vectors;
    vectoriter_vec_t vectorsiter;
};

#endif
