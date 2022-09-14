
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
    static SCREEN_CLASS screen;

    /* 屏幕初始化 */
    screen.begin();
    screen.setRotation(0);
    screen.fillScreen(TFT_BLACK);

    /* lvgl初始化 */
    lv_init();
    lv_port_disp_init(&screen);
    lv_port_indev_init();
    // lv_fs_if_init();

    // Update display in parallel thread.
    xTaskCreate(
        TaskLvglUpdate,
        "LvglThread",
        20000,
        nullptr,
        configMAX_PRIORITIES - 1,
        &handleTaskLvgl);

    /* 背光渐亮 */
    HAL::Backlight_SetGradual(500, 1000);
}
