#include "HAL.h"

TFT_eSPI tft = TFT_eSPI();


void HAL::Display_Init()
{
    /* LCD init */
    tft.init();
    tft.setRotation(0); /*@tag 设置屏幕方向*/
    tft.fillScreen(TFT_BLACK);

    Serial.println("LCD: initialized");
}