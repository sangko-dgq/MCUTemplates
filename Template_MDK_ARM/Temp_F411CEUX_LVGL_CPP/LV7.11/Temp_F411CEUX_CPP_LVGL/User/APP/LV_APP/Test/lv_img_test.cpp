#include "lv_img_test.h"
#include "lvgl.h"


lv_style_t img_style;

//图片申明
LV_IMG_DECLARE(img_2233);
LV_IMG_DECLARE(true_color_chroma_keyed);


//例程入口
void lv_img_test_start()
{
  lv_obj_t *scr = lv_scr_act();//获取当前活跃的屏幕对象

  //3.创建显示True color格式的图片对象
  lv_obj_t * img2 = lv_img_create(scr,NULL);
  lv_img_set_src(img2,&true_color_chroma_keyed);
//  lv_img_set_style(img2,LV_IMG_STYLE_MAIN,&img_style);//设置样式
  lv_obj_align(img2,NULL,LV_ALIGN_CENTER,0,0);
	

}


////按键处理
//void key_handler()
//{
//	u8 key = KEY_Scan(0);
//	
//	if(key==KEY0_PRES)
//	{
//		//修改样式中的重绘色强度
//		img_style.image.intense += 10;
//		if(img_style.image.intense>=250)
//			img_style.image.intense = 0;
//		lv_obj_report_style_mod(&img_style);//刷新使用了此样式的对象
//	}else if(key==KEY1_PRES)
//	{
//		//修改样式中的透明度
//		img_style.image.opa -= 10;
//		if(img_style.image.opa<=10)
//			img_style.image.opa = LV_OPA_COVER;
//		lv_obj_report_style_mod(&img_style);//刷新使用了此样式的对象
//	}
//}



