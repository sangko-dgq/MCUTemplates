/*********************
 
 *      HAL_Button

 *********************/
#include "User/HAL/HAL.h"
#include "ButtonEvent/ButtonEvent.h"


static ButtonEvent BTN_UP;

static void Button_EventHander(ButtonEvent* btn, int event)
{
    if(btn == &BTN_UP)
    {
        if(event == ButtonEvent::EVENT_ButtonClick)
        {
            MID::BTN_UP_Click_EventCB();
        }
        else if(event == ButtonEvent::EVENT_ButtonLongPressed)
        {
            HAL::Power_Shutdown();
        }
    }
}

/*按键初始化*/
void HAL::Button_Init()
{
	pinMode(BTN_UP_Pin, INPUT_PULLUP); //默认上拉模式 输入模式（即：低电平驱动）
    BTN_UP.EventAttach(Button_EventHander);
}
/*按键检测*/
static void HAL::Scanf_Button()
{
    BTN_UP.EventMonitor(!digitalRead(BTN_UP_Pin)); //NEW:低电平
}



