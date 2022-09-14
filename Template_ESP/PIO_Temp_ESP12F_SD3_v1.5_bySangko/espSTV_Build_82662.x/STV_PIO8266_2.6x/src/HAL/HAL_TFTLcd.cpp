#include "HAL.h"

void TFTLcd_Init()
{
  /*背光*/
  pinMode(LCD_BL_PIN, OUTPUT);
  analogWrite(LCD_BL_PIN, 1023 - (LCD_BL_PWM * 10));
  
  /*屏幕*/
  tft.begin();
  //tft.invertDisplay(isInvertColor); //反转所有显示颜色：1反转，0正常
  tft.setRotation(LCD_Rotation);
  tft.fillScreen(bgColor);//清屏
  tft.setTextColor(SublineYellow, bgColor);
}