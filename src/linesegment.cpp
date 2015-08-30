/*
 * LINESEGMENT.CPP
 */

#include "linesegment.h"

Linesegment::Linesegment(Point *start, Point *end)
{
    this->start = start;
    this->end = end;
    points = new point_vec_t;
    calculateLine();
}

Linesegment::~Linesegment()
{
    delete start;
    delete end;
    delete points;
}

point_vec_t *Linesegment::getPoints()
{
    return points;
}

void Linesegment::calculateLine()
{
    if(start == NULL || end == NULL)
        return;

    points->clear();
    
}

void Linesegment::print()
{
    std::cout << "Linesegment:\n";
    start->print();
    end->print();
}
