/**
 * @file lv_port_indev_templ.c
 *
 */

/*Copy this file as "lv_port_indev.c" and set this value to "1" to enable content*/
#if 1

/*********************
 *      INCLUDES
 *********************/
#include "lvgl.h"
#include "HAL/HAL.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
/*encoder*/
static void encoder_init(void);
static void encoder_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data);

/*touchpad*/
static void touchpad_init(void);
static void touchpad_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data);

/**********************
 *  STATIC VARIABLES
 **********************/
/*encoder*/
static lv_indev_t *indev_Encoder;
static lv_indev_drv_t indev_drv_Encoder;

/*touchpad*/
static lv_indev_t *indev_touchpad;
static lv_indev_drv_t indev_drv_Touchpad;
static TouchPoint_t coordinate;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lv_port_indev_init(void)
{

    /*------------------
     * Encoder
     * -----------------*/

    /*Initialize your encoder if you have*/
    encoder_init();

    /*Register a encoder input device*/
    lv_indev_drv_init(&indev_drv_Encoder);
    indev_drv_Encoder.type = LV_INDEV_TYPE_ENCODER;
    indev_drv_Encoder.read_cb = encoder_read;
    indev_Encoder = lv_indev_drv_register(&indev_drv_Encoder);

    /* Later you should create group(s) with `lv_group_t * group = lv_group_create()`,
     * add objects to the group with `lv_group_add_obj(group, obj)`
     * and assign this input device to group to navigate in it:
     * `lv_indev_set_group(indev_encoder, group);` */

    /*------------------
     * Touchpad
     * -----------------*/
    touchpad_init();
     /*Register a touchpad input device*/
    lv_indev_drv_init(&indev_drv_Touchpad);
    indev_drv_Touchpad.type = LV_INDEV_TYPE_POINTER;
    indev_drv_Touchpad.read_cb = touchpad_read;
    indev_touchpad = lv_indev_drv_register(&indev_drv_Touchpad);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/*------------------
 * Encoder
 * -----------------*/

/* Initialize your keypad */
static void encoder_init(void)
{
    /*Do it in Init*/
}

/* Will be called by the library to read the encoder */
static void encoder_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data)
{
    data->enc_diff = HAL::Encoder_GetDiff();
    data->state = HAL::Encoder_GetIsPush() ? LV_INDEV_STATE_PR : LV_INDEV_STATE_REL;
}


/*------------------
 * Touchpad
 * -----------------*/
/* Initialize your touchpad */
static void touchpad_init(void)
{
    /*Do it in Init*/
}
/*Will be called by the library to read the touchpad*/
static void touchpad_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data)
{
    /* Read touch point */
    HAL::Touch_GetPressPoint(&coordinate);
    // Serial.printf("x:%d, y:%d \r\n", coordinate.x, coordinate.y);
    if (coordinate.x == -1)
    {
        data->state = LV_INDEV_STATE_REL;
    }
    else
    {
        data->point.x = coordinate.x;
        data->point.y = coordinate.y;
        data->state = LV_INDEV_STATE_PR;
    }
}




#else /* Enable this file at the top */

/* This dummy typedef exists purely to silence -Wpedantic. */
typedef int keep_pedantic_happy;
#endif
