
#ifndef __DISPLAY_H
#define __DISPLAY_H

#include "HAL/HAL.h"
#include "HAL/Config/Config.h"
#include "lvgl.h"


#define INIT_DONE() \
do{                 \
    xTaskNotifyGive(handleTaskLvgl); \
}while(0) \


extern lv_indev_t * indev_encoder;

void Port_Init();
void lv_port_disp_init();
void lv_fs_if_init();
void lv_port_indev_init();

extern TaskHandle_t handleTaskLvgl;

#endif
