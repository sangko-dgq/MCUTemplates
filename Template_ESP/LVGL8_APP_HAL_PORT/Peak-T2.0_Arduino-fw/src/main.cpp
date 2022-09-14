
#include <Arduino.h>
#include "HAL/HAL.h"
#include "HAL/HAL_Def.h"
#include "Port/Display.h"

#include "APP/PeakTrack/PeakTrack.h"
#include "APP/MUXPad/ui.h"

#include "lv_demo.h"
void lvgl_test(char i)
{
    switch (i)
    {
    case 0:
        lv_demo_benchmark();
        break;
    case 1:
        lv_demo_widgets();
        break;
    case 2:
        lv_demo_stress();
        break;
    case 3:
        lv_demo_keypad_encoder();
        break;
    case 4:
        lv_demo_music();
        break;
    default:
        break;
    }
}

void setup()
{
    /*Init HAL:*/
    HAL::HAL_Init();

    /*Init Port*/
    Port_Init();

    /*Init APP*/
    // bkeyInit();

    /* lvgl test */
    // lvgl_test(0);
    // Peak_Track_init();

    ui_init_muxpad(); 

    /* Enable lvgl task */
    INIT_DONE();
}

void loop()
{
    HAL::HAL_Update();

    // HAL::Buzz_Tone(3500, 400);
    // delay(500);
    // HAL::Buzz_Tone(3500, 400);
    // delay(500);
}
