/*************************************************
         @FILE StartupScreen.c
 ************************************************/
#include "ScreenManager.h"
lv_obj_t* StartupScreen;
lv_obj_t* LOGO;
lv_obj_t* AnimLine_L;
lv_obj_t* AnimLine_R;

lv_obj_t* tempVoidObj; //���ÿն�������ʱ
static void tempVoidAnim();

void LOGO_anim_start();


void BuildStartupScreen()
{
    StartupScreen = lcreate(lv_scr_act(), obj_t);
    lsize(StartupScreen, SCR_W, SCR_H);
    lbgc_m(StartupScreen, fullblack);
    lborder_w_m(StartupScreen, 0);
    lradius(StartupScreen, 0);
    lalign(StartupScreen, lv_scr_act(), LV_ALIGN_CENTER, 0, 0);

    //AnimLine_L
    AnimLine_L = lcreate(StartupScreen, obj_t);
    lsize(AnimLine_L, SCR_W/3, 6);
    lbgc_m(AnimLine_L, softred);
    lborder_w_m(AnimLine_L, 0);
    lradius(AnimLine_L, 10);
    lalign(AnimLine_L, StartupScreen, LV_ALIGN_CENTER,-lget(AnimLine_L, w_val) /2 + 2, 12);

    //AnimLine_R
    AnimLine_R = lcreate(StartupScreen, obj_t);
    lsize(AnimLine_R, SCR_W/3, 6);
    lbgc_m(AnimLine_R, softred);
    lborder_w_m(AnimLine_R, 0);
    lradius(AnimLine_R, 10);
    lalign(AnimLine_R, StartupScreen, LV_ALIGN_IN_RIGHT_MID, - lget(AnimLine_L, w_val)/2 - 2, 12);

    //LOGO
    LOGO = lcreate(StartupScreen, label_t);
    lalign(LOGO, StartupScreen, LV_ALIGN_CENTER, -22, -6);
    lfont(LOGO, &Sarasa_Mono_SC_regular_16, softwhite);
    ltext(LOGO, "UStaWatch");

    lv_obj_set_hidden(LOGO, true);
//
//    lanimed_cb(AnimLine_L, lv_obj_set_width, 450, 0, SCR_W/3, lv_anim_path_linear, LOGO_anim_start);
//    lanimed_cb(AnimLine_R, lv_obj_set_width, 450, 0,  SCR_W/3, lv_anim_path_linear, LOGO_anim_start);

    //����λ�÷ֱ���������󣬴���������
    //AnimLine_L
    lv_obj_t* mask_L = lcreate(StartupScreen, obj_t);
    lsize(mask_L, SCR_W/2 +20, lget(AnimLine_L, h_val));
    lbgc_m(mask_L, fullblack);
    lborder_w_m(mask_L, 0);
    lradius(mask_L, 0);
    lalign(mask_L, StartupScreen, LV_ALIGN_CENTER,0, 12);

    //AnimLine_R
    lv_obj_t* mask_R = lcreate(StartupScreen, obj_t);
    lsize(mask_R, SCR_W/2 +20, lget(AnimLine_L, h_val) + 2);
    lbgc_m(mask_R, fullblack);
    lborder_w_m(mask_R, 0);
    lradius(mask_R, 0);
    lalign(mask_R, StartupScreen, LV_ALIGN_CENTER, 0, 12);

    printf("[mask_L]%d\r\n", lget(mask_L, x_val)); //24
    printf("[mask_R]%d\r\n", lget(mask_R, x_val));  //24

    //tempVoidObj
    tempVoidObj = lcreate(StartupScreen, obj_t);
    lalign(tempVoidObj, StartupScreen, LV_ALIGN_OUT_BOTTOM_MID, 0, 1000);  //�ŵ������˶���ʵ�ֽӰ���ʱ

    lanimed_cb(mask_L, lv_obj_set_x, 800, 24, -SCR_W + 50, lv_anim_path_linear, LOGO_anim_start);
    lanimed_cb(mask_R, lv_obj_set_x, 800, 24,  SCR_W, lv_anim_path_linear, LOGO_anim_start);

    lanimed_cb(LOGO, lv_obj_set_y, 1250, 138, 106, lv_anim_path_linear, tempVoidAnim);
}
void LOGO_anim_start()
{
    lv_obj_set_hidden(LOGO, false);
}

static void tempVoidAnim()
{
    lanimed_cb(tempVoidObj, lv_obj_set_width, 700, 0, 0, lv_anim_path_linear, loadMainScreen);
}

void loadMainScreen()
{
    lscr(MainScreen);
    lanim(MainScrTopBar, lv_obj_set_y, 650, -20, 0, lv_anim_path_linear); //MainScrTopBar::Anim
    isMainScreen = 1;
    isMenuScreen = 0;
}







