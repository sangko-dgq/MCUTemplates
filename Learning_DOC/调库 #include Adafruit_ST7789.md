1. 调库 #include "Adafruit_ST7789.h"

2. 类 **typedef Adafruit_ST7789** SCREEN_CLASS;    

3. 类的实例**SCREEN_CLASS** screen(TFT_CS_Pin, TFT_DC_Pin, TFT_RST_Pin);

4. 定义使用哪个硬件SPI    #define SPI1

5. 初始化

    ```c++
        /*背光关闭*/
        Backlight_SetValue(1000);
        
        /*屏幕初始化*/
        screen.begin();
        screen.setRotation(0);
        screen.fillScreen(screen.Black);
    ```








 error:  #317: return type is not identical to nor covariant with return type "std::size_t" of overridden virtual function "Print::write" 

Keil宏定义补充添加ARDUINO=111





