#include "User/HAL/HAL.h"

/**
  * @brief  �������Ƚ��䣬��lv_anim����
  * @param  obj:����
  * @param  brightness:����ֵ
  * @retval None
  */
static void Backlight_AnimCallback(void * obj, int16_t brightness)
{
    Backlight_SetValue(brightness);
}

/**
  * @brief  �����ʼ��
  * @param  ��
  * @retval ��
  */
void Backlight_Init()
{
    /*PWM��ʼ����1000����20KƵ��*/
    PWM_Init(TFT_BLK_Pin, 1000, 20000);
}

/**
  * @brief  �������ã�����Ч��
  * @param  target:Ŀ������(0~1000 -> 0~100%)
  * @retval ��
  */
void Backlight_SetGradual(uint16_t target, uint16_t time)
{
    lv_obj_add_anim(
        NULL, NULL,
        (lv_anim_exec_xcb_t)Backlight_AnimCallback,
        Backlight_GetValue(), target,
        time
    );
}

/**
  * @brief  ��ȡ��������
  * @param  ��
  * @retval ��ǰ����(0~1000 -> 0~100%)
  */
uint16_t Backlight_GetValue()
{
    return timer_get_compare(PIN_MAP[TFT_BLK_Pin].TIMx, PIN_MAP[TFT_BLK_Pin].TimerChannel);
}

/**
  * @brief  ���ñ�������
  * @param  val: ����(0~1000 -> 0~100%)
  * @retval ��
  */
void Backlight_SetValue(int16_t val)
{
    __LimitValue(val, 0, 1000);
    analogWrite(TFT_BLK_Pin, val);
}

/**
  * @brief  �Ӻ󱸼Ĵ�����ȡ���籣��ı�������
  * @param  ��
  * @retval ����(0~1000 -> 0~100%)
  */
uint16_t Backlight_GetBKP()
{
    uint16_t value = 0;
    
    /*����ֵ�Ƿ�Ƿ�*/
    if(value == 0 || value > 1000)
    {
        /*����Ĭ������*/
        value = 1000;
    }
    
    return value;
}

/**
  * @brief  ����ǰ���ȸ������󱸼Ĵ���
  * @param  ��
  * @retval ��
  */
void Backlight_UpdateBKP()
{
}

