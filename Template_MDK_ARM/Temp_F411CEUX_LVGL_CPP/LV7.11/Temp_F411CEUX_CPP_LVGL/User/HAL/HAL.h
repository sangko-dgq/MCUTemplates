
/*********************

 *      HAL_H

 *********************/
#ifndef _HAL_H
#define _HAL_H

#include "CommonMacro/CommonMacro.h"
#include "Arduino.h"
#include "User/HAL_Config.h"
#include "delay.h"

#include "lvgl.h"
#include "Libs/LVGL_ExMethods/lv_obj_ext_func.h"

#include "User/MID/MID.h"

#include "Adafruit_ST7789.h"
typedef Adafruit_ST7789 SCREEN_CLASS;
extern SCREEN_CLASS screen;


namespace HAL
{
void Init(void);
void Update(void);

/*HAL_LED_TEST*/
void LED_TEST_Init(void);

/*HAL_TftLcd*/
void LCD_Init(void);
void LCD_Shine(void);

/*FPS_DEBUG*/
#if USE_FPS_DEBUG
void Display_FPSTest();
#endif

/*Button*/
void Button_Init();
void Scanf_Button();
	
/*POWER*/
void Power_Shutdown();
void Power_ON();
}


/*HAL_Backlight*/
void Backlight_Init();
void Backlight_SetGradual(uint16_t target, uint16_t time);
uint16_t Backlight_GetValue();
void Backlight_SetValue(int16_t val);
uint16_t Backlight_GetBKP();	
#endif