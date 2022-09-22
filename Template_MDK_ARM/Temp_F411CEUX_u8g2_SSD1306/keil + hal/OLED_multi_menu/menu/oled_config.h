#ifndef OLED_CONFIG_H
#define OLED_CONFIG_H

#define USE_HAL     1
#define USE_STD     0
#define USE_ARDUINO 0

/************************************ USE_HAL *****************************************/

#if USE_HAL
/*
  GPIO for u8g2 to ii2-sw
  oled_use
*/
// PB6-PB7
#define IIC_GPIO_Port   GPIOB
#define SCL_Pin         GPIO_PIN_6
#define SDA_Pin         GPIO_PIN_7


/* 
  GPIO for menu for KEY
  menu_triggle 
*/
// PB5
#define KEY_TEST_Pin         GPIO_PIN_5
#define KEY_TEST_GPIO_Port   GPIOB
#define KEY_TEST_RCC_EN      __HAL_RCC_GPIOB_CLK_ENABLE()
#define KET_TEST_Sta         HAL_GPIO_ReadPin(KEY_TEST_GPIO_Port, KEY_TEST_Pin)

/* 
  interface for u8g2 (must!!!) 
*/

#define U8X8_DELAY_1MS       HAL_Delay(1)
#define U8X8_I2C_SCL_SET     HAL_GPIO_WritePin(IIC_GPIO_Port, SCL_Pin, GPIO_PIN_SET)
#define U8X8_I2C_SCL_RESET   HAL_GPIO_WritePin(IIC_GPIO_Port, SCL_Pin, GPIO_PIN_RESET)
#define U8X8_I2C_SDA_SET     HAL_GPIO_WritePin(IIC_GPIO_Port, SDA_Pin, GPIO_PIN_SET)
#define U8X8_I2C_SDA_RESET   HAL_GPIO_WritePin(IIC_GPIO_Port, SDA_Pin, GPIO_PIN_RESET)

#endif //!USE_HAL



/************************************ USE_STD *****************************************/

#if USE_STD
/*
  GPIO for u8g2 to ii2-sw
  oled_use
*/
#define IIC_GPIO_Port   GPIOB
#define SCL_Pin         GPIO_Pin_6
#define SDA_Pin         GPIO_Pin_7

/* 
  GPIO for menu for key
  menu_triggle 
*/
// PB5
#define KEY_TEST_Pin         GPIO_Pin_5
#define KEY_TEST_GPIO_Port   GPIOB
#define KEY_TEST_RCC_EN      RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE)
#define KET_TEST_Sta         GPIO_ReadPin(KEY_TEST_GPIO_Port, KEY_TEST_Pin)

/* 
  interface for u8g2 (must!!!) 
*/

#define U8X8_DELAY_1MS       //HAL_Delay(1) //TODO
#define U8X8_I2C_SCL_SET     GPIO_SetBits(IIC_GPIO_Port, SCL_Pin);
#define U8X8_I2C_SCL_RESET   GPIO_ResetBits(IIC_GPIO_Port, SCL_Pin);
#define U8X8_I2C_SDA_SET     GPIO_SetBits(IIC_GPIO_Port, SDA_Pin);
#define U8X8_I2C_SDA_RESET   GPIO_ResetBits(IIC_GPIO_Port, SDA_Pin);

#endif //!USE_STD


/************************************ USE_ARDUINO *****************************************/
//TODO


/************************************ COMMON DEFINE *****************************************/
/* gobal font style */
#define U8G2_GOBAL_FONT      u8g2_font_unifont_t_symbols


#endif