
/*********************
 
 *      HAL_H

 *********************/
#ifndef _HAL_H
#define _HAL_H

#include "Arduino.h"
#include "User/HAL_Config.h"

namespace HAL
{
   void Init(void);
   void Update(void); 
	
/*HAL_LED_TEST*/
  void LED_TEST_Init(void);

	

}
#endif