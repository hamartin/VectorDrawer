/*
 * OBJECT.H
 */

#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <SDL2/SDL.h>

typedef struct point_t
{
    int x;
    int y;
    int z;
    point_t(const int &tx, const int &ty, const int &tz) {
        x = tx; y = ty; z = tz;
    }
} point_t;

class Object {
public:
    Object(SDL_Renderer *renderer, point_t p);

    int ox, oy, oz;
protected:
    SDL_Renderer *renderer;
private:
};

#endif
