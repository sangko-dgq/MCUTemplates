
/*********************
 
 *      HAL

 *********************/
#include "User\HAL\HAL.h"

/*硬件初始化*/
void HAL::Init()
{
	/*USART1*/
	#if USE_USART_1
	Serial.begin(Baud_U1);
	#endif
	
	/*LED*/
	HAL::LED_TEST_Init();
	
	/*LCD*/
	HAL::LCD_Init();
	

}

/*硬件接口数据相关更新*/
void HAL::Update()
{
	
}






