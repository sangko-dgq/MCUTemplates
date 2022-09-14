/*********************
 
 *      MAIN

 *********************/
#include "User/HAL/HAL.h"

/*Setup*/	
static void Setup(void)
{
	HAL_Init();
}
/*Loop*/
static void Loop(void)
{
	digitalWrite(LED_TEST,HIGH);
	delay_ms(500);
	digitalWrite(LED_TEST,LOW);
	delay_ms(500);
}
/*main*/
int main(void)
{   	
	Delay_Init();	
	Setup();
	for(;;) Loop();
}

