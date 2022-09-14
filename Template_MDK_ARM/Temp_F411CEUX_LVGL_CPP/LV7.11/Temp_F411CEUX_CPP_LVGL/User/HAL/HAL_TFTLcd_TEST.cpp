/*********************
 
 *      TFTLcd Drive By "Adafruit_ST7789.h"

 *********************/

#include "User\HAL\HAL.h"
#include "Adafruit_ST7789.h"

SCREEN_CLASS screen(TFT_CS_Pin, TFT_DC_Pin, TFT_RST_Pin);

/*FPS����*/
#if USE_FPS_DEBUG
void HAL::Display_FPSTest()
{
    float Ftime, Ltime;
    float FPS;
    Ftime = millis();
    int i;
    for(i = 100; i > 0; i--)
    {
        screen.fillScreen(screen.Black);
        screen.fillScreen(screen.White);
    }
    Ltime = millis() - Ftime;
    FPS = 100.0f / (Ltime / 1000.0f) * 2.0f;
    screen.fillScreen(screen.Blue);
    screen.setTextSize(1);
    screen.setTextColor(screen.White);
    screen.setCursor(0, 0);
    screen.print(Ltime);
    screen.setCursor(45, 0);
    screen.print("ms");
    screen.setCursor(0, 9);
    screen.print("FPS:");
    screen.setCursor(25, 9);
    screen.print(FPS);
    while(1);
}
#endif

void HAL::LCD_Init()
{
    /*�����ʼ��*/
    Backlight_Init();

	 /*����ر�*/
    Backlight_SetValue(0);
    
    /*��Ļ��ʼ��*/
    screen.begin();
    screen.setRotation(0);
    screen.fillScreen(screen.Black);
	
	/*���⽥��������800(80%),��ʱ1000ms*/
	//Backlight_SetGradual(Backlight_GetBKP(), 1000);
	for(int v = Backlight_GetValue(); v <= 1000; v+=5)
	{
		Backlight_SetValue(v);
		delay_ms(5); //����
	}

	
	/*FPS��ʼ����*/
	#if USE_FPS_DEBUG
	HAL::Display_FPSTest();
	#endif
	
}
void HAL::LCD_Shine()
{
	screen.fillScreen(screen.Blue);
	delay_ms(1000);
	screen.fillScreen(screen.Yellow);
	delay_ms(1000);
}

