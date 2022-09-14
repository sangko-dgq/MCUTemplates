
#include "stm32f10x.h"

typedef unsigned int uint32_t; //32bits

static void LED_init()
{
	/*
	    点亮PB0的LED
	 */
	
	/* 打开 GPIOB 端口对应的时钟*/
	* (uint32_t*)0x40021018 |= 1 << 3;
	/* 配置IO为输出模式 */
	* (uint32_t*)0x40010c00 |= 1 << (4*0); //PB0.mode = output
	/* ODR寄存器的第0位复为0 */
	* (uint32_t*)0x40010c0c &=~ (1 << 0); //PB0 = 0
	
	/*
	
	GPIOx_ODR : GPIO output data register  
	地址偏移 : 相对于0x4001-0C00 偏移 0Ch  (0x0C)
	0x4001-0C00为GPIOB_BASE
	绝对地址: 0x4001-0C00 + 0x0C = 0x4001-0C0C
	
	理解: https://blog.csdn.net/jcyd_123/article/details/103694252
	
	*/
	
}

int main()
{
	LED_init();
	for(;;)
  {
		
  }
}

void SystemInit(void)
{
	
}

