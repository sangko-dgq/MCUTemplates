#include <Arduino.h>

void setup()
{
  pinMode(PA12, OUTPUT);
}

void loop()
{
  digital_io_toggle(GPIOA, GPIO_PIN_12);
  delay(100);
}