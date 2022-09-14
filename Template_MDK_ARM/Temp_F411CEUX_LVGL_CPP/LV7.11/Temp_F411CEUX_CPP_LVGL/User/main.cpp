/*********************
 
 *      MAIN

 *********************/
#include "User/HAL/HAL.h"
#include "User/APP/APP.h"
#include "User/MID/MID.h"
#include "MillisTaskManager/MillisTaskManager.h"

/**********************************************************************************************/

/*任务调度器*/
static MillisTaskManager millisTaskManager;
/*CPU占用率(DEBUG用)*/
float CPU_Usage;
/*动态CPU占用率获取*/
static void CPU_UsageUpdate()
{
    CPU_Usage = millisTaskManager.GetCPU_Usage();
}
/*任务注册*/
static void TaskRegister()
{
	/*多任务注册*/
    millisTaskManager.Register(APP::LV_Update, 1);                //Lvgl----1ms
	millisTaskManager.Register(HAL::Update,10);
    millisTaskManager.Register(HAL::Scanf_Button, 10);                //按键事件监控任务----10ms
    //millisTaskManager.Register(Power_AutoShutdownUpdate, 100);       //自动关机监控任务----100ms
    millisTaskManager.Register(CPU_UsageUpdate, 1000);                 //CPU占用率监控任务----1s
	
	#if USE_USART_1
	millisTaskManager.Register(MID::Usart_Order_Task, 10);        //串口指令
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
	/*运行任务调度器*/
    millisTaskManager.Running(millis());
}
/*main*/
int main(void)
{   	
	Delay_Init();	
	Setup();
	for(;;) Loop();
}

