
/*********************
 
 *      HAL

 *********************/
#include "User\HAL\HAL.h"

/*Ӳ����ʼ��*/
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

/*Ӳ���ӿ�������ظ���*/
void HAL::Update()
{
	
}






