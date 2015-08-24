/*
 * OBJECT.CPP
 */

#include "object.h"

Object::Object(SDL_Renderer *renderer, point_t p)
{
    this->renderer = renderer;
    this->ox = p.x; this->oy = p.y; this->oz = p.z;
}
