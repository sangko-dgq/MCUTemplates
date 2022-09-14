
/*********************
 
 *      HAL_CONFIG

 *********************/

#ifndef _HAL_CONFIG_H
#define _HAL_CONFIG_H

/*HAL_LED_TEST*/
#define LED_TEST  PA12

/*屏幕*/
#define TFT_CS_Pin  PA15     //片选
#define TFT_DC_Pin  PB4     //数据/命令选择
#define TFT_RST_Pin PB6     //复位
#define TFT_BLK_Pin PB7    //背光
//#define SPI //使用硬件SPI1

/*开机先测试一遍FPS*/
#define USE_FPS_DEBUG  (0)

/*是否使用串口1*/
#define USE_USART_1  (1)
#if USE_USART_1 
#define Baud_U1 (115200) 
#endif


/*Button*/
#define BTN_UP_Pin     PA0
#define BTN_DOWN_Pin   PA1
#define BTN_OK_Pin     PA2

/*电源控制*/
#define POWER_ON_Pin PA3    //电源保持
#define POWER_EN_Pin PA4    //电源使能






#endif