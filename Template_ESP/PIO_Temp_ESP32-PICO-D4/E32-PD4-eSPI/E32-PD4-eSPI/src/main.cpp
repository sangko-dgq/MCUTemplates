#include <Arduino.h>
#include "TFT_eSPI.h"

void setup()
{
  TFT_eSPI tft = TFT_eSPI();
  
  tft.init();
  tft.setRotation(0);
  tft.fillScreen(TFT_YELLOW);
}
void loop()
{
  
}