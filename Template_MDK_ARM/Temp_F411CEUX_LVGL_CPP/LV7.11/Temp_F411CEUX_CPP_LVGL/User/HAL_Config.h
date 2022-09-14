
/*********************
 
 *      HAL_CONFIG

 *********************/

#ifndef _HAL_CONFIG_H
#define _HAL_CONFIG_H

/*HAL_LED_TEST*/
#define LED_TEST  PA12

/*��Ļ*/
#define TFT_CS_Pin  PA15     //Ƭѡ
#define TFT_DC_Pin  PB4     //����/����ѡ��
#define TFT_RST_Pin PB6     //��λ
#define TFT_BLK_Pin PB7    //����
//#define SPI //ʹ��Ӳ��SPI1

/*�����Ȳ���һ��FPS*/
#define USE_FPS_DEBUG  (0)

/*�Ƿ�ʹ�ô���1*/
#define USE_USART_1  (1)
#if USE_USART_1 
#define Baud_U1 (115200) 
#endif


/*Button*/
#define BTN_UP_Pin     PA0
#define BTN_DOWN_Pin   PA1
#define BTN_OK_Pin     PA2

/*��Դ����*/
#define POWER_ON_Pin PA3    //��Դ����
#define POWER_EN_Pin PA4    //��Դʹ��






#endif