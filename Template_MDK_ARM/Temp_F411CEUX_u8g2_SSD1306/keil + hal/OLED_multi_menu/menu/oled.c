#include "oled.h"
#include "menu.h"
#include "menu_triggle.h"
#include "u8g2_use.h"

u8g2_t u8g2;
uint8_t func_index = 0; //初始显示欢迎界面
uint8_t last_index = 127; //last初始为无效值
void (*current_operation_index)();

void oled_init(void)
{
  Key_test_init();
  u8g2Init(&u8g2);
}

void oled_triggle_update(void)
{
	if(KET_TEST_Sta == GPIO_PIN_RESET)
	{
			HAL_Delay(10);//消抖
			if(KET_TEST_Sta == GPIO_PIN_RESET )
			{
				func_index = pageIndex[func_index].enter;
				while(!KET_TEST_Sta);//松手检测(不松开的话，就死循环阻塞等待检测到恢复高电平，不继续执行)
			}
	}	

		/* 映射到具体显示 */
	if (func_index != last_index)
	{
			current_operation_index = pageIndex[func_index].current_operation;
			
			u8g2_ClearBuffer(&u8g2); 
			(*current_operation_index)();//执行当前操作函数
			u8g2_SendBuffer(&u8g2);
			
			last_index = func_index;
	}
}