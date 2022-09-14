#include "bsp_led.h"




void LED_GPIO_Config()
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(LED_G_GPIO_CLK, ENABLE);
	GPIO_InitStruct.GPIO_Pin = LED_G_GPIO_Pin;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LED_G_GPIO_Port, &GPIO_InitStruct);
	
}
/*
void LED_Ctrl(uint8_t bit_p)
{
	switch (bit_p)
	{
		case 0 :
		    GPIO_SetBits(LED_G_GPIO_Port, LED_G_GPIO_Pin);
		    break;
		case 1:
			  GPIO_ResetBits(LED_G_GPIO_Port, LED_G_GPIO_Pin);
		    break; 
	}
}
*/