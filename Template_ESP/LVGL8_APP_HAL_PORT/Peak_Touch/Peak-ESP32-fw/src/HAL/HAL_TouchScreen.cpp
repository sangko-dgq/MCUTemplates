#include "HAL.h"

M5Touch Touch;

void HAL::Touch_Init()
{
    /* Touch init */
    Touch.begin();
}

// /* Don't work well */
bool HAL::Touch_Ispressed()
{
    return Touch.ispressed();
}

void HAL::Touch_GetPressPoint(TouchPoint_t* coordinate)
{
    *coordinate = Touch.getPressPoint();
}