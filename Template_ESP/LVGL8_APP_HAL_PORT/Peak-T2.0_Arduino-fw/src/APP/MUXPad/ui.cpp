// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.0.5
// LVGL VERSION: 8.2
// PROJECT: BT_UX_Game

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_SCRStartup;
lv_obj_t * ui_Bar1;
lv_obj_t * ui_Label1;
lv_obj_t * ui_labelInitInfo;
lv_obj_t * ui_SCRMain;
lv_obj_t * ui_SCRMenu;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "#error LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////

///////////////////// SCREENS ////////////////////
void ui_SCRStartup_screen_init(void)
{

    // ui_SCRStartup

    ui_SCRStartup = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_SCRStartup, LV_OBJ_FLAG_SCROLLABLE);

    // ui_Bar1

    ui_Bar1 = lv_bar_create(ui_SCRStartup);
    lv_bar_set_range(ui_Bar1, 0, 100);
    lv_bar_set_value(ui_Bar1, 25, LV_ANIM_OFF);

    lv_obj_set_width(ui_Bar1, 163);
    lv_obj_set_height(ui_Bar1, 10);

    lv_obj_set_x(ui_Bar1, 7);
    lv_obj_set_y(ui_Bar1, 13);

    lv_obj_set_align(ui_Bar1, LV_ALIGN_CENTER);

    // ui_Label1

    ui_Label1 = lv_label_create(ui_SCRStartup);

    lv_obj_set_width(ui_Label1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Label1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Label1, 0);
    lv_obj_set_y(ui_Label1, -21);

    lv_obj_set_align(ui_Label1, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Label1, "UXPad");

    lv_obj_set_style_text_font(ui_Label1, &lv_font_montserrat_26, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_labelInitInfo

    ui_labelInitInfo = lv_label_create(ui_SCRStartup);

    lv_obj_set_width(ui_labelInitInfo, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_labelInitInfo, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_labelInitInfo, -37);
    lv_obj_set_y(ui_labelInitInfo, 30);

    lv_obj_set_align(ui_labelInitInfo, LV_ALIGN_CENTER);

    lv_label_set_text(ui_labelInitInfo, "Init imu ok");

    lv_obj_set_style_text_color(ui_labelInitInfo, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_labelInitInfo, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

}
void ui_SCRMain_screen_init(void)
{

    // ui_SCRMain

    ui_SCRMain = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_SCRMain, LV_OBJ_FLAG_SCROLLABLE);

}
void ui_SCRMenu_screen_init(void)
{

    // ui_SCRMenu

    ui_SCRMenu = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_SCRMenu, LV_OBJ_FLAG_SCROLLABLE);

}

void ui_init_muxpad(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_SCRStartup_screen_init();
    ui_SCRMain_screen_init();
    ui_SCRMenu_screen_init();
    lv_disp_load_scr(ui_SCRStartup);
}
