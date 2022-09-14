
#include "User/HAL/HAL.h"

void HAL::LED_TEST_Init()
{
	//GPIOx_Init(GPIOA, GPIO_Pin_12, OUTPUT, GPIO_Low_Speed, H);
	pinMode(LED_TEST, OUTPUT);
	digitalWrite(LED_TEST, HIGH);
}


