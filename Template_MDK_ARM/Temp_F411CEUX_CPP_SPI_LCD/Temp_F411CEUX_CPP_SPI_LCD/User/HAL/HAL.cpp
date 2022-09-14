
/*********************
 
 *      HAL

 *********************/
#include "User\HAL\HAL.h"

void HAL::Init()
{
	HAL::LED_TEST_Init();
	HAL::LCD_Init();
}
void HAL::Update()
{
	
}