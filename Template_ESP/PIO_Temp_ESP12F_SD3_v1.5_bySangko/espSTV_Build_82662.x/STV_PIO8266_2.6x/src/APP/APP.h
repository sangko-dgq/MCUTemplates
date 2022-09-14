


#ifndef _APP_H
#define _APP_H
#include "../Common/g_config.h"
#include "../HAL/HAL.h"

/*Display*/
bool tft_output(int16_t x, int16_t y, uint16_t w, uint16_t h, uint16_t *bitmap);
extern byte loadingBarValue;
void LcdBuild_LoadingBar(byte delayTime);   
void LcdBuild_HumidityBox();
void LcdBuild_TempertureBox();
void LCD_reflash(int en);


void LcdShow_WeaterData(String *cityDZ, String *dataSK, String *dataFC);
void scrollBanner();
#if imgAst_EN
void imgAnim();
#endif
void digitalClockDisplay(int reflash_en);
String week();
String monthDay();






#endif