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

/*������ʼ��*/
void HAL::Button_Init()
{
	pinMode(BTN_UP_Pin, INPUT_PULLUP); //Ĭ������ģʽ ����ģʽ�������͵�ƽ������
    BTN_UP.EventAttach(Button_EventHander);
}
/*�������*/
static void HAL::Scanf_Button()
{
    BTN_UP.EventMonitor(!digitalRead(BTN_UP_Pin)); //NEW:�͵�ƽ
}



