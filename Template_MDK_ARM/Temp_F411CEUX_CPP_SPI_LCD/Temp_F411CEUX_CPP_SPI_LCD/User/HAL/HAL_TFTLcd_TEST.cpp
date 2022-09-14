/*********************
 
 *      TFTLcd Drive By "Adafruit_ST7789.h"

 *********************/

#include "User\HAL\HAL.h"
#include "Adafruit_ST7789.h"

/**
  * @brief  ��һ��ֵ������һ����Χ��
  * @param  x:�����Ƶ�ֵ(��������)
  * @param  min:��Сֵ(��������)
  * @param  max:���ֵ(��������)
  * @retval ��
  */
#define __LimitValue(x,min,max) ((x)=constrain((x),(min),(max)));

SCREEN_CLASS screen(TFT_CS_Pin, TFT_DC_Pin, TFT_RST_Pin);

void Backlight_SetValue(int16_t val)
{
    __LimitValue(val, 0, 1000);
    analogWrite(TFT_BLK_Pin, val);
}


void HAL::LCD_Init()
{
    /*PWM��ʼ����1000����20KƵ��*/
    PWM_Init(TFT_BLK_Pin, 1000, 20000);

	 /*����ر�*/
    Backlight_SetValue(0);
    
    /*��Ļ��ʼ��*/
    screen.begin();
    screen.setRotation(0);
    screen.fillScreen(screen.Red);
	
	/*���⿪��*/
    Backlight_SetValue(1000);
}
void HAL::LCD_Shine()
{
	screen.fillScreen(screen.Blue);
	delay_ms(1000);
	screen.fillScreen(screen.Yellow);
	delay_ms(1000);
}

