#ifndef _APP_H
#define _APP_H

/*APP*/
#include "lvgl.h"
#include "Adafruit_ST7789.h"

#include "User/HAL/HAL.h"
#include "User/MID/MID.h"


/*LVGL*/
void lv_port_disp_init(void);



/*APP*/
namespace APP
{
	void Init(void);
	void LV_Update(void);
	
	/*APP_TEST*/
	void lv_ex_spinbox_1(void);
	
	

}













#endif