
#include "Display.h"
#include "HAL/HAL.h"

TaskHandle_t handleTaskLvgl;
void TaskLvglUpdate(void* parameter)
{
    ulTaskNotifyTake(pdTRUE, portMAX_DELAY);

    for (;;)
    {
        lv_task_handler();
        delay(5);
    }
}


/**
  * @brief  显示初始化
  * @param  无
  * @retval 无
  */
void Port_Init()
{
    /* lvgl init */
    lv_init();
    lv_port_disp_init();
    lv_port_indev_init();
    // lv_fs_if_init();

    // Update display in parallel thread.
    xTaskCreate(
        TaskLvglUpdate,
        "LvglThread",
        20000,
        NULL,
        3,
        &handleTaskLvgl);

    Serial.println("Lvgl: initialized");
    
    /* 背光渐亮 */
    HAL::Backlight_SetGradual(1000, 1000); 
    
}
