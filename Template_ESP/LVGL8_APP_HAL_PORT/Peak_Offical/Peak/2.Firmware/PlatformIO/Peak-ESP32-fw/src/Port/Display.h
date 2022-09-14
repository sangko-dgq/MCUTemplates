
#ifndef __DISPLAY_H
#define __DISPLAY_H

#include "App/Configs/Config.h"
#include "lvgl.h"
#include "TFT_eSPI.h"


typedef TFT_eSPI SCREEN_CLASS;

void Port_Init();
void DisplayFault_Init(SCREEN_CLASS* scr);
void lv_port_disp_init(SCREEN_CLASS* scr);
void lv_fs_if_init();
void lv_port_indev_init();

extern TaskHandle_t handleTaskLvgl;

#endif
