#include "../ScreenManager.h"
lv_obj_t* MainScrTopBar;
lv_obj_t* MenuScrTopBar;

///----MAIN SCREEN
void BuildTopBar(uint8_t screen_index)
{
    //chose left icon
    switch (screen_index)
    {
    case 0:
        MainScrTopBar = lcreate(MainScreen, obj_t);
        lsize(MainScrTopBar, SCR_W, 24);//size
        lpos(MainScrTopBar, 0, 0);//pos
        lbgc_m(MainScrTopBar, gray);//bgc
        lopa(MainScrTopBar, 0);//opa
        lradius(MainScrTopBar, 0);//radius
        lborder_w_m(MainScrTopBar, 0);//border width
        break;
    case 1:
        MenuScrTopBar = lcreate(MenuScreen, obj_t);
        lsize(MenuScrTopBar, SCR_W, 24);
        lpos(MenuScrTopBar, 0, 0);
        lbgc_m(MenuScrTopBar, gray);
        lopa(MenuScrTopBar, 0);//opa
        lradius(MenuScrTopBar, 0);
        lborder_w_m(MenuScrTopBar, 0);
        break;
    default:
        break;
    }
    //COM
}
