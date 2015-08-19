#include <string>
#include "vectordrawer.h"

int main()
{
    std::string TITLE("Vector Drawer");
    
    VectorDrawer vd(TITLE);
#ifdef DEBUG
    vd.debug();
#endif
    vd.begin();

    return 0;
}
