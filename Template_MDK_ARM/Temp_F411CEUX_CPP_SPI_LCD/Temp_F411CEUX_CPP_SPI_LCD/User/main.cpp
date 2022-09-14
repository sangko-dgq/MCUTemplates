/*********************
 
 *      MAIN

 *********************/
#include "User/HAL/HAL.h"

/*Setup*/	
static void Setup(void)
{
	HAL::Init();
}
/*Loop*/
static void Loop(void)
{
//	digitalWrite(LED_TEST,HIGH);
//	delay_ms(200);
//	digitalWrite(LED_TEST,LOW);
//	delay_ms(200);
	
	HAL::LCD_Shine();
}
/*main*/
int main(void)
{   	
	Delay_Init();	
	Setup();
	for(;;) Loop();
}

