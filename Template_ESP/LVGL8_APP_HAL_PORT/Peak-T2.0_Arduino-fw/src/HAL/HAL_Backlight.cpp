
#include "HAL.h"
#include "lvgl.h"

static uint32_t backlightValue = 0;

/**
  * @brief  闁煎啿鑻崢婊勭椤旂厧顔婃繛鎾村姇瑜板鏁嶇仦钘夌秬lv_anim闁硅矇鍐ㄧ厬
  * @param  obj:闁哄啰濮烽弫锟�
  * @param  brightness:濞存粠鍠栫€规娊宕愰敓锟�
  * @retval None
  */
static void Backlight_AnimCallback(void * obj, int32_t brightness)
{
    HAL::Backlight_SetValue(brightness);
}

/**
  * @brief  闁煎啿鑻崢婊堝礆濠靛棭娼楅柛鏍垫嫹
  * @param  闁哄喛鎷�
  * @retval 闁哄喛鎷�
  */
void HAL::Backlight_Init()
{
    // /*PWM闁跨喐鏋婚幏宄邦潗闁跨喐鏋婚幏鐑芥晸閺傘倖瀚�1000闁跨喐鏋婚幏鐑芥晸閺傘倖瀚�20KHz妫版垿鏁撻弬銈嗗*/
    // PWM_Init(CONFIG_SCREEN_BLK_PIN, 1000, 20000);
    // Backlight_SetValue(0);

    /*PWM闁告帗绻傞～鎰板礌閺嶇數绀�1024缂佺嫏宥囩5KHz濡増鍨瑰锟�*/
    ledcSetup(0, 5000, 10);
    ledcAttachPin(CONFIG_SCREEN_BLK_PIN, 0);
    ledcWrite(0, 0);
}
 
/**
  * @brief  闁煎啿鑻崢婊呮媼閸撗呮瀭闁挎稑鏈粭搴ㄥ矗濡粯娅忛柡瀣舵嫹
  * @param  target:闁烩晩鍠楅悥锝嗙椤旂厧顔�(0~1000 -> 0~100%)
  * @retval 闁哄喛鎷�
  */
void HAL::Backlight_SetGradual(uint32_t target, uint16_t time)
{
    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t)Backlight_AnimCallback);
    lv_anim_set_values(&a, Backlight_GetValue(), target);
    lv_anim_set_time(&a, time);
    lv_anim_set_path_cb(&a, lv_anim_path_ease_out);

    lv_anim_start(&a);
}

/**
  * @brief  闁兼儳鍢茶ぐ鍥嚄鐏炶棄甯ㄥù婊庡枛鐎癸拷
  * @param  闁哄喛鎷�
  * @retval 鐟滅増鎸告晶鐘崇椤旂厧顔�(0~1000 -> 0~100%)
  */
uint32_t HAL::Backlight_GetValue()
{
    // return Timer_GetCompare(
    //            PIN_MAP[CONFIG_SCREEN_BLK_PIN].TIMx,
    //            PIN_MAP[CONFIG_SCREEN_BLK_PIN].TimerChannel
    //        );

    return backlightValue;
}

/**
  * @brief  閻犱礁澧介悿鍡涙嚄鐏炶棄甯ㄥù婊庡枛鐎癸拷
  * @param  val: 濞存粠鍠栫€癸拷(0~1000 -> 0~100%)
  * @retval 闁哄喛鎷�
  */
void HAL::Backlight_SetValue(int32_t val)
{
    // CM_VALUE_LIMIT(val, 0, 1000);
    // analogWrite(CONFIG_SCREEN_BLK_PIN, val);

    val = constrain(val, 0, 1024);
    backlightValue = val;
    val =   backlightValue;
    ledcWrite(0, val);
}

/**
  * @brief  闁煎啿鑻崢婊冾嚕閸濆嫬鐓戦柣鎰扳偓娑樼槰
  * @param  en: 闁煎啿鑻崢婊勬媴閼愁垰鍘�
  * @retval 闁哄喛鎷�
  */
void HAL::Backlight_ForceLit(bool en)
{
    pinMode(CONFIG_SCREEN_BLK_PIN, OUTPUT);
    digitalWrite(CONFIG_SCREEN_BLK_PIN, en);
}
