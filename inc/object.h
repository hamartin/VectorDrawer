/*
 * OBJECT.H
 */

#ifndef __OBJECT_H__
#define __OBJECT_H__

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
    Object(point_t p);

    int ox, oy, oz;
protected:
private:
};

#endif
