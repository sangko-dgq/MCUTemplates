#ifndef BSP_LED_H
#define BSP_LED_H

#include "stm32f10x.h" /* 寄存器映射接口文件*/
void LED_GPIO_Config(void);
	
#define LED_G_GPIO_Pin GPIO_Pin_0
#define LED_G_GPIO_Port GPIOB
#define LED_G_GPIO_CLK RCC_APB2Periph_GPIOB

/*带参数的宏定义函数*/
#define LED_ON(p) \
do{ \
    if(p) GPIO_ResetBits(LED_G_GPIO_Port, LED_G_GPIO_Pin); \
    else GPIO_SetBits(LED_G_GPIO_Port, LED_G_GPIO_Pin); \
}while(0) \



#endif

