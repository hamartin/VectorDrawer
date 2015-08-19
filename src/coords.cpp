//
// COORDS.CPP
//

#include <iostream>
#include "coords.h"

Coords::Coords(SDL_Renderer *renderer, const int &a, const int &b, const int &c)
{
    this->renderer = renderer;               // This class does not accept responsebility for this pointer.
    this->x = a; this->y = b; this->z = c;
}

void Coords::debug()
{
    std::cout << "X: " << this->x << std::endl;
    std::cout << "Y: " << this->y << std::endl;
    std::cout << "Z: " << this->z << std::endl;
}

void Coords::print()
{
    SDL_RenderPresent(this->renderer);
}