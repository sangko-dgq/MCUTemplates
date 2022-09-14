
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


//�����Ż�FPS��	
//1. ��������Ӳ��SPI
//2. DMA
//3. ֱ�Ӳ����Ĵ������ؼ����ݴ��봦����̣����üĴ�����̣�
//4. �����߲���PCB/ר����Ļ������	
	
	
}
#endif