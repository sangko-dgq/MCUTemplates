
/*********************

 *      HAL_H

 *********************/
#ifndef _HAL_H
#define _HAL_H

#include "Arduino.h"
#include "User/HAL_Config.h"
#include "delay.h"

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


//合理优化FPS？	
//1. 尽量采用硬件SPI
//2. DMA
//3. 直接操作寄存器（关键数据代码处理过程，采用寄存器编程）
//4. 数据线采用PCB/专用屏幕连接线	
	
	
}
#endif