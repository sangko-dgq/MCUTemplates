#include "menu_triggle.h"

void Key_test_init(void)
{
  #if USE_HAL
  __HAL_RCC_GPIOB_CLK_ENABLE();
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  
  GPIO_InitStruct.Pin = KEY_TEST_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(KEY_TEST_GPIO_Port, &GPIO_InitStruct);
  #endif
  
  #if USE_STD
  GPIO_InitTypeDef  GPIO_InitStructure;
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
  
  GPIO_InitStructure.GPIO_Pin = KEY_TEST_Pin;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		
  GPIO_Init(KEY_TEST_GPIO_Port, &GPIO_InitStructure);			
  #endif
  
  #if USE_ARDUINO
  //TODO
  #endif
  
}