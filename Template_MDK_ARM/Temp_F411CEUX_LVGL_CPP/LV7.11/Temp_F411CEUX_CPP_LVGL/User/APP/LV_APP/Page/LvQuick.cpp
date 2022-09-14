/*************************************
          @FILE    LvQuick.c
          @Autor   Sangko
          @Version LittleVGL7.11
*************************************/
#define USE_LV_QUICK (1)
#include "lvgl.h"
#include "LvQuick.h"

#if USE_LV_QUICK

/*Create obj、label、img、btn...*/
lv_obj_t* lcreate(lv_obj_t *parent, uint8_t type)
{
    switch (type)
    {
    case  0 :
        return lv_obj_create(parent, NULL);
        break;
    case 1 :
        return lv_label_create(parent, NULL);
        break;
    case 2:
        return lv_img_create(parent, NULL);
        break;
    case 3:
        return lv_btn_create(parent, NULL);
    case 4:
        return lv_msgbox_create(parent, NULL);
    case 5:
        return lv_page_create(parent, NULL);
    case 6:
        return lv_list_create(parent, NULL);
    case 7:
        return lv_tabview_create(parent, NULL);
    case 8:
        return lv_table_create(parent, NULL);
    default:
        return NULL;
        break;
    }
    return NULL;

}
///SIZE
void lsize(lv_obj_t* obj, lv_coord_t w, lv_coord_t h)
{
    lv_obj_set_size(obj, w, h);
}
///Position
void lpos(lv_obj_t* obj, lv_coord_t x, lv_coord_t y)
{
    lv_obj_set_pos(obj, x, y);
}

///Border Width
void lborder_w_m(lv_obj_t* obj, lv_style_int_t width)
{
    lv_obj_set_style_local_border_width(obj, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, width);
}
///Align
void lalign(lv_obj_t * obj, const lv_obj_t * base, lv_align_t align, lv_coord_t x_ofs, lv_coord_t y_ofs)
{
    lv_obj_align(obj, base, align, x_ofs, y_ofs);
}
///BackgroundColor
void lbgc_m(lv_obj_t *obj, uint32_t Hex)
{
    lv_obj_set_style_local_bg_color(obj, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, lv_color_hex(Hex));
}

///Radius
//lv_style_t style_boderRadius;//必须放在函数外面!!
void lradius(lv_obj_t* obj, lv_style_int_t radius_val)
{
//    lv_style_init(&style_boderRadius);
//    lv_style_set_radius(&style_boderRadius, LV_STATE_DEFAULT, radius_val);
//    lv_obj_add_style(obj, LV_OBJ_PART_MAIN, &style_boderRadius);
    lv_obj_set_style_local_radius(obj, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, radius_val);
}
/////快速添加自定义字体样式
//void lfontstyle(lv_obj_t* label, lv_font_t* font, lv_style_t* fontstyle, uint32_t color_hex)
//{
//    //init style
//    lv_style_init(fontstyle);
//    //map font -> style
//    lv_style_set_text_font(fontstyle, LV_STATE_DEFAULT, font);
//    lv_style_set_text_color(fontstyle, LV_STATE_DEFAULT,lv_color_hex(color_hex));
//    //add style to obj
//    lv_obj_add_style(label, LV_OBJ_PART_MAIN, fontstyle);
//}
///快速给label设置字体
void lfont(lv_obj_t* label, lv_font_t* font, uint32_t color_hex)
{
    lv_obj_set_style_local_text_font(label, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, font);
    lv_obj_set_style_local_text_color(label, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, lv_color_hex(color_hex));
}
///Text
void ltext(lv_obj_t* label, const char* text)
{
    lv_label_set_text(label, text);
}
///Event Set
void levent_set(lv_obj_t* obj, lv_event_cb_t event_cb)
{
    lv_obj_set_event_cb(obj, event_cb);
}

///Get obj's info
lv_coord_t lget(lv_obj_t* obj, uint8_t type)
{
    switch (type)
    {
    case 0:
        return lv_obj_get_width(obj);
        break;
    case 1:
        return lv_obj_get_height(obj);
        break;
    case 2:
        return lv_obj_get_x(obj);
        break;
    case 3:
        return lv_obj_get_y(obj);
        break;
    default:
        break;
    }
    return NULL;

}

///create a img on parent
void limg_src(lv_obj_t* img, const void* src_img)
{
    lv_img_set_src(img, src_img);
}


/*
 * 快速给对象添加出场动画
 *obj: 控件对象
 *exec_cb：动画设置函数，例如：操作控件的哪个位置等 lv_obj_set_x
 *time：动画时长
 *start：动画开始值
 *end:动画结束值
 *path_cb：动画效果
 */
void lanim(lv_obj_t* obj, lv_anim_exec_xcb_t exec_cb, uint16_t time, lv_coord_t start, lv_coord_t end, lv_anim_path_cb_t path_cb)
{
    lv_anim_t a;

    lv_anim_init(&a);
    lv_anim_set_var(&a, obj); //动画对象

    lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t)exec_cb); //动画函数
    lv_anim_set_time(&a, time);

    a.start = start;		  //起始值
    a.end = end; //结束值
    a.path.cb = path_cb;	  //动画计算方法
    a.playback_time = 0;				  //回放时间设为0不执行动画回放

    lv_anim_start(&a); //开启动画
}

/*赋予对象带回调的动画*/
void lanimed_cb(lv_obj_t* obj, lv_anim_exec_xcb_t exec_cb, uint16_t time, lv_coord_t start, lv_coord_t end, lv_anim_path_cb_t path_cb, lv_anim_ready_cb_t animed_cb)
{
    lv_anim_t a;

    lv_anim_init(&a);
    lv_anim_set_var(&a, obj); //动画对象

	/*Set the "animator" function*/
    lv_anim_set_exec_cb(&a, exec_cb);//Yes
	
    lv_anim_set_time(&a, time);

    a.start = start;		  //起始值
    a.end = end; //结束值
    a.path.cb = path_cb;	  //动画计算方法
    a.playback_time = 0;				  //回放时间设为0不执行动画回放

     /*Set a callback to call when animation is ready.*/
    lv_anim_set_ready_cb(&a, animed_cb);
	
    /*Set a callback to call when animation is started (after delay).*/
    lv_anim_set_start_cb(&a, animed_cb);


    lv_anim_start(&a); //开启动画
}

/*Load Screen*/
void lscr(lv_obj_t* scr)
{
    lv_scr_load(scr);
}

/*快速创建渐变样式*/
void llinner(lv_obj_t* obj, uint32_t start_color, uint32_t end_color, lv_grad_dir_t dir)
{
    static lv_style_t linner_color_style;
    lv_style_init(&linner_color_style);
    lv_style_set_radius(&linner_color_style, LV_STATE_DEFAULT, 5);

    /*Make a gradient*/
    lv_style_set_bg_opa(&linner_color_style, LV_STATE_DEFAULT, LV_OPA_COVER); //255不透明度
    lv_style_set_bg_color(&linner_color_style, LV_STATE_DEFAULT, lv_color_hex(start_color));//背景色
    lv_style_set_bg_grad_color(&linner_color_style, LV_STATE_DEFAULT, lv_color_hex(end_color)); //渐变色
    lv_style_set_bg_grad_dir(&linner_color_style, LV_STATE_DEFAULT, dir); //水平渐变

    /*Shift the gradient to the bottom*/
    lv_style_set_bg_main_stop(&linner_color_style, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_grad_stop(&linner_color_style, LV_STATE_DEFAULT, 255);

    lv_obj_add_style(obj, LV_OBJ_PART_MAIN, &linner_color_style);
}

/*快速设置透明度*/
void lopa(lv_obj_t* obj, lv_opa_t value)
{
//  lv_obj_set_style_local_value_opa(obj, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, value); //ERROR
    lv_obj_set_style_local_bg_opa(obj, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, value);
}

///设置对象状态
void lstate(lv_obj_t* obj, lv_state_t state)
{
    lv_obj_set_state(obj, state);
}

///Tasks(每隔Per_ms ms去执行task_xcb一次，优先级为prio)
void ltask(lv_task_cb_t task_xcb, uint32_t Per_ms, lv_task_prio_t task_prio)
{
    lv_task_create(task_xcb, Per_ms, task_prio, NULL);
}

#endif // USE_LV_QUICK



