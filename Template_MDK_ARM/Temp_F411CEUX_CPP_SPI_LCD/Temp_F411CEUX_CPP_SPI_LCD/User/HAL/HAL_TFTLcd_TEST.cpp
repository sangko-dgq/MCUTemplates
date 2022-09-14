/*********************
 
 *      TFTLcd Drive By "Adafruit_ST7789.h"

 *********************/

#include "User\HAL\HAL.h"
#include "Adafruit_ST7789.h"

/**
  * @brief  将一个值限制在一个范围内
  * @param  x:被限制的值(任意类型)
  * @param  min:最小值(任意类型)
  * @param  max:最大值(任意类型)
  * @retval 无
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
    /*PWM初始化，1000级，20K频率*/
    PWM_Init(TFT_BLK_Pin, 1000, 20000);

	 /*背光关闭*/
    Backlight_SetValue(0);
    
    /*屏幕初始化*/
    screen.begin();
    screen.setRotation(0);
    screen.fillScreen(screen.Red);
	
	/*背光开启*/
    Backlight_SetValue(1000);
}
void HAL::LCD_Shine()
{
	screen.fillScreen(screen.Blue);
	delay_ms(1000);
	screen.fillScreen(screen.Yellow);
	delay_ms(1000);
}

