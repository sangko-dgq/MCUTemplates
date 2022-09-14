#include "User/HAL/HAL.h"


/**
  * @brief  ҳ��������ʱ��������lvgl����
  */
void LvDelay(uint32_t ms)
{
    uint32_t lastTime = lv_tick_get();
    
    while(lv_tick_elaps(lastTime) <= ms)
    {
        lv_task_handler();
    }
}


void HAL::Power_Shutdown()
{
    //Backlight_SetGradual(0, 500);
	
	for(int v = Backlight_GetValue(); v >= 0; v-=5)
	{
		Backlight_SetValue(v);
		LvDelay(5); //����
	}
	
    LvDelay(500); /*�����ǻ���lvgl��������ʱ������delay_ms*/
    digitalWrite(POWER_EN_Pin, LOW);
}

void HAL::Power_ON()
{
	digitalWrite(POWER_EN_Pin, HIGH);
	LvDelay(500);
	for(int v = Backlight_GetValue(); v <= 1000; v+=5)
	{
		Backlight_SetValue(v);
		LvDelay(5); 
	}
}

