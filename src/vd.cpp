#include <string>
#include "vectordrawer.h"

int main()
{
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;
    std::string TITLE("Vector Drawer");
    
    VectorDrawer vd(TITLE, SCREEN_WIDTH, SCREEN_HEIGHT);
#ifdef DEBUG
    vd.debug();
#endif
    if(vd.init()) {
        vd.begin();
    }

    return 0;
//                    Point *p = new Point(renderer, 100, 100);
//                    p->print();
//                    SDL_UpdateWindowSurface(window);
//                    SDL_Delay(10000);
}
