/*
 * OBJECT.CPP
 */

#include "object.h"

Object::Object(point_t p)
{
    this->ox = p.x; this->oy = p.y; this->oz = p.z;
}
