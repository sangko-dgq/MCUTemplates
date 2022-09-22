#ifndef __OLED_H
#define __OLED_H


//-----------------OLED端口定义----------------  
/*
    PA5     ------> SPI1_SCK
    PA6     ------> SPI1_MISO
    PA7     ------> SPI1_MOSI
*/
#define OLED_SCLK_GPIO_Port GPIOA
#define OLED_SCLK_Pin       GPIO_PIN_5
#define OLED_SDIN_GPIO_Port GPIOA
#define OLED_SDIN_Pin       GPIO_PIN_6

#define OLED_RST_GPIO_Port  GPIOA
#define OLED_RST_Pin        GPIO_PIN_11
#define OLED_DC_GPIO_Port   GPIOA
#define OLED_DC_Pin         GPIO_PIN_12
#define OLED_CS_GPIO_Port   GPIOA
#define OLED_CS_Pin         GPIO_PIN_15

void oled_gpio_init();

#define OLED_SCLK_Clr() HAL_GPIO_WritePin(OLED_SCLK_GPIO_Port, OLED_SCLK_Pin, GPIO_PIN_RESET);
#define OLED_SCLK_Set() HAL_GPIO_WritePin(OLED_SCLK_GPIO_Port, OLED_SCLK_Pin, GPIO_PIN_SET);

#define OLED_SDIN_Clr() HAL_GPIO_WritePin(OLED_SDIN_GPIO_Port, OLED_SDIN_Pin, GPIO_PIN_RESET);
#define OLED_SDIN_Set() HAL_GPIO_WritePin(OLED_SDIN_GPIO_Port, OLED_SDIN_Pin, GPIO_PIN_SET);

#define OLED_RST_Clr()  HAL_GPIO_WritePin(OLED_RST_GPIO_Port, OLED_RST_Pin, GPIO_PIN_RESET);
#define OLED_RST_Set()  HAL_GPIO_WritePin(OLED_RST_GPIO_Port, OLED_RST_Pin, GPIO_PIN_SET);

#define OLED_DC_Set()   HAL_GPIO_WritePin(OLED_DC_GPIO_Port, OLED_DC_Pin, GPIO_PIN_SET);
#define OLED_DC_Clr()   HAL_GPIO_WritePin(OLED_DC_GPIO_Port, OLED_DC_Pin, GPIO_PIN_RESET);
 		     
#define OLED_CS_Set()   HAL_GPIO_WritePin(OLED_CS_GPIO_Port, OLED_CS_Pin, GPIO_PIN_SET);
#define OLED_CS_Clr()   HAL_GPIO_WritePin(OLED_CS_GPIO_Port, OLED_CS_Pin, GPIO_PIN_RESET);

//--------------------------------------------  						  		   

//OLED控制用函数
void OLED_Display_On(void);
void OLED_Display_Off(void);	
void OLED_Set_Brightness(unsigned char brightness);
void OLED_setBreathing(unsigned char k, unsigned char interval);
//void OLED_Horizental_Reverse(unsigned char reverse);
//void OLED_Vertical_Reverse(unsigned char reverse);
void OLED_Inverse(unsigned char k);
void OLED_Clear(void);
//void OLED_Set_Pos(unsigned char x, unsigned char y);
void OLED_Refresh(unsigned char *buf);
void OLED_Init(void);

#endif  
	 



