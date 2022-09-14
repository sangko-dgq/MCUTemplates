/*****************************
*            APP
*****************************/
#include "User/APP/APP.h"


/*实现页面阻塞延时，且保持lvgl更新*/
void AppDelay(uint32_t ms)
{
    uint32_t lastTime = millis();
    while(millis() - lastTime <= ms)
    {
        lv_task_handler();
    }
}

void APP::Init()
{
	/*lvgl初始化*/
    lv_init();
    lv_port_disp_init();
	
	/*主题初始化*/
    lv_theme_t * th = lv_theme_material_init(
        LV_COLOR_WHITE, 
        LV_COLOR_RED,
        0,
        &lv_font_montserrat_16,
        &lv_font_montserrat_16,
        &lv_font_montserrat_16,
        &lv_font_montserrat_16
    );
    lv_theme_set_act(th);
	
	/*运行Lvgl页面*/
	APP::lv_ex_spinbox_1();
	
	//ScreenManager();

}

void APP::LV_Update()
{
   lv_task_handler();
}



