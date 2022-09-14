/*************************************
          @FILE    LvQuick.h
          @Autor   Sangko
          @Version LittleVGL7.11
*************************************/
#ifndef LVQUICK_H
#define LVQUICK_H
#define USE_LV_QUICK (1)

#include "lvgl.h"

#if USE_LV_QUICK
//lv_obj_set_size
void lsize(lv_obj_t *obj, lv_coord_t w, lv_coord_t h);
//pos
void lpos(lv_obj_t* obj, lv_coord_t x, lv_coord_t y);
//lv_obj_align
void lalign(lv_obj_t * obj, const lv_obj_t * base, lv_align_t align, lv_coord_t x_ofs, lv_coord_t y_ofs);
//lv_obj_set_style_local_bg_color +LV_OBJ_PART_MAIN + LV_STATE_DEFAULT
void lbgc_m(lv_obj_t *obj, uint32_t Hex);

//在parent创建对象
enum
{
    obj_t, label_t, img_t, btn_t, msgbox_t, page_t, list_t, tabview_t, table_t
};
lv_obj_t* lcreate(lv_obj_t *parent, uint8_t type);
//设置圆角大小
void lradius(lv_obj_t* obj, lv_style_int_t radius_val);
//设置边框粗细 MAIN + DEFAULT
void lborder_w_m(lv_obj_t* obj, lv_style_int_t width);
//给obj添加包含字体、字体颜色
void lfont(lv_obj_t* label, lv_font_t* font, uint32_t color_hex);
void ltext(lv_obj_t* label, const char* text);
void levent_set(lv_obj_t* obj, lv_event_cb_t event_cb);
//快速给对象添加出场动画
void lanim(lv_obj_t* obj, lv_anim_exec_xcb_t exec_cb, uint16_t time, lv_coord_t start, lv_coord_t end, lv_anim_path_cb_t path_cb);


void lanimed_cb(lv_obj_t* obj, lv_anim_exec_xcb_t exec_cb, uint16_t time, lv_coord_t start, lv_coord_t end, lv_anim_path_cb_t path_cb, lv_anim_ready_cb_t animed_cb);


///get size/coord
enum
{
    w_val, h_val, x_val, y_val
};
lv_coord_t lget(lv_obj_t* obj, uint8_t type);
///creat a img on parent
void limg_src(lv_obj_t* img, const void* src_img);
//加载屏幕
void lscr(lv_obj_t* scr);
//给对象添加渐变
void llinner(lv_obj_t* obj, uint32_t start_color, uint32_t end_color, lv_grad_dir_t dir);
//快速设置透明度
void lopa(lv_obj_t* obj, lv_opa_t value);
//设置状态
void lstate(lv_obj_t* obj, lv_state_t state);
///Tasks(每隔Per_ms ms去执行task_xcb一次，优先级为prio)
void ltask(lv_task_cb_t task_xcb, uint32_t Per_ms, lv_task_prio_t task_prio);
#endif
#endif // LVQUICK_H
