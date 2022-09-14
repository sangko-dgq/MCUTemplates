/*****************************
*            APP
*****************************/
#include "User/APP/APP.h"


/*ʵ��ҳ��������ʱ���ұ���lvgl����*/
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
	/*lvgl��ʼ��*/
    lv_init();
    lv_port_disp_init();
	
	/*�����ʼ��*/
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
	
	/*����Lvglҳ��*/
	APP::lv_ex_spinbox_1();
	
	//ScreenManager();

}

void APP::LV_Update()
{
   lv_task_handler();
}



