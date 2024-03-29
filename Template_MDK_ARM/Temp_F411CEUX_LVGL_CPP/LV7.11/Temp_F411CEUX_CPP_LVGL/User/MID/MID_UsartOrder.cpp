#include "MID.h"
#include "Arduino.h"
#include "User/HAL_Config.h"

void MID::Usart_Order_Task()
{
#if USE_USART_1

    while (Serial.available())
    {
        // Serial.println("Please Input");
        String ret = Serial.readStringUntil((char)"\r\n");
        //Serial.println("[IN:]" + ret);
        if(ret == "LED_TEST\r\n")
        {
            togglePin(LED_TEST);
        } else if(ret == "POWER_OFF\r\n")
        {
            HAL::Power_Shutdown();
        } else if(ret == "POWER_ON\r\n")
        {
            HAL::Power_ON();
        }
    }
#endif
	
	
}