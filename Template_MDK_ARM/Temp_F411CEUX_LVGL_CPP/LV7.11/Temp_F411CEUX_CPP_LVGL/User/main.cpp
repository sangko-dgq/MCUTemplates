/*********************
 
 *      MAIN

 *********************/
#include "User/HAL/HAL.h"
#include "User/APP/APP.h"
#include "User/MID/MID.h"
#include "MillisTaskManager/MillisTaskManager.h"

/**********************************************************************************************/

/*���������*/
static MillisTaskManager millisTaskManager;
/*CPUռ����(DEBUG��)*/
float CPU_Usage;
/*��̬CPUռ���ʻ�ȡ*/
static void CPU_UsageUpdate()
{
    CPU_Usage = millisTaskManager.GetCPU_Usage();
}
/*����ע��*/
static void TaskRegister()
{
	/*������ע��*/
    millisTaskManager.Register(APP::LV_Update, 1);                //Lvgl----1ms
	millisTaskManager.Register(HAL::Update,10);
    millisTaskManager.Register(HAL::Scanf_Button, 10);                //�����¼��������----10ms
    //millisTaskManager.Register(Power_AutoShutdownUpdate, 100);       //�Զ��ػ��������----100ms
    millisTaskManager.Register(CPU_UsageUpdate, 1000);                 //CPUռ���ʼ������----1s
	
	#if USE_USART_1
	millisTaskManager.Register(MID::Usart_Order_Task, 10);        //����ָ��
	#endif
}

/**********************************************************************************************/

/*Setup*/	
static void Setup(void)
{
	HAL::Init();
	APP::Init();
	TaskRegister();
}
/*Loop*/
static void Loop(void)
{
	/*�������������*/
    millisTaskManager.Running(millis());
}
/*main*/
int main(void)
{   	
	Delay_Init();	
	Setup();
	for(;;) Loop();
}

