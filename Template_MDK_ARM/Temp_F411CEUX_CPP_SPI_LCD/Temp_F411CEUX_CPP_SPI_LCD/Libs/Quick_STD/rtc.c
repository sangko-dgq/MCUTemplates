#include "rtc.h"
#include "delay.h"

/**
  * @brief  RTCʱ������
  * @param  hour:Сʱ
  * @param  min:����
  * @param  sec:����
  * @param  ampm:@RTC_AM_PM_Definitions  :RTC_H12_AM/RTC_H12_PM
  * @retval SUCCESS(1),�ɹ� ERROR(0),�����ʼ��ģʽʧ��
  */
ErrorStatus RTCx_SetTime(uint8_t hour, uint8_t min, uint8_t sec, uint8_t ampm)
{
    RTC_TimeTypeDef RTC_TimeTypeInitStructure;

    RTC_TimeTypeInitStructure.RTC_Hours = hour;
    RTC_TimeTypeInitStructure.RTC_Minutes = min;
    RTC_TimeTypeInitStructure.RTC_Seconds = sec;
    RTC_TimeTypeInitStructure.RTC_H12 = ampm;

    return RTC_SetTime(RTC_Format_BIN, &RTC_TimeTypeInitStructure);
}

/**
  * @brief  RTC��������
  * @param  year:��(0~99)
  * @param  month:��(1~12)
  * @param  date:��(0~31)
  * @param  week:����(1~7,0:�Ƿ�!)
  * @retval SUCCESS(1),�ɹ� ERROR(0),�����ʼ��ģʽʧ��
  */
ErrorStatus RTCx_SetDate(uint8_t year, uint8_t month, uint8_t date, uint8_t week)
{
    RTC_DateTypeDef RTC_DateTypeInitStructure;
    RTC_DateTypeInitStructure.RTC_Date = date;
    RTC_DateTypeInitStructure.RTC_Month = month;
    RTC_DateTypeInitStructure.RTC_WeekDay = week;
    RTC_DateTypeInitStructure.RTC_Year = year;
    return RTC_SetDate(RTC_Format_BIN, &RTC_DateTypeInitStructure);
}

/**
  * @brief  ���ڻ�������(1~7)
  * @param  RTC_DateStruct:���ڽṹ���ַ
  * @retval ��
  */
void RTCx_GetWeekDay(RTC_DateTypeDef *RTC_DateStruct)
{
    int year = RTC_DateStruct->RTC_Year + 2000;
    int month = RTC_DateStruct->RTC_Month;
    int date = RTC_DateStruct->RTC_Date;
    if(month == 1) month = 13, year--;
    if(month == 2) month = 14, year--;
    int weekdey = (date + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400) % 7;
    RTC_DateStruct->RTC_WeekDay = weekdey + 1;
}

/**
  * @brief  RTC��������
  * @param  ��
  * @retval 0:��ʼ���ɹ�; 1:LSE����ʧ��; 2:�����ʼ��ģʽʧ��;
  */
void RTCx_Init(void)
{
    RTC_InitTypeDef RTC_InitStructure;
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE);//ʹ��PWRʱ��
    PWR_BackupAccessCmd(ENABLE);    //ʹ�ܺ󱸼Ĵ�������

    if(RTC_ReadBackupRegister(RTC_BKP_DR0) != 0x5050)   //�Ƿ��һ������?
    {
        RCC_LSEConfig(RCC_LSE_ON);//LSE ����
        while (RCC_GetFlagStatus(RCC_FLAG_LSERDY) == RESET); //���ָ����RCC��־λ�������,�ȴ����پ������

        RCC_RTCCLKConfig(RCC_RTCCLKSource_LSE);     //����RTCʱ��(RTCCLK),ѡ��LSE��ΪRTCʱ��
        RCC_RTCCLKCmd(ENABLE);  //ʹ��RTCʱ��

        RTC_InitStructure.RTC_AsynchPrediv = 0x7F;//RTC�첽��Ƶϵ��(1~0X7F)
        RTC_InitStructure.RTC_SynchPrediv  = 0xFF;//RTCͬ����Ƶϵ��(0~7FFF)
        RTC_InitStructure.RTC_HourFormat   = RTC_HourFormat_24;//RTC����Ϊ,24Сʱ��ʽ
        RTC_Init(&RTC_InitStructure);

        RTCx_SetTime(00, 00, 00, RTC_H12_AM); //����ʱ��
        RTCx_SetDate(00, 1, 1, 1);  //��������

        RTC_WriteBackupRegister(RTC_BKP_DR0, 0x5050);   //����Ѿ���ʼ������
    }
}

/**
  * @brief  ��������ʱ��(����������,24Сʱ��)
  * @param  week:���ڼ�(1~7) @ref  RTC_Alarm_Definitions
  * @param  hour:Сʱ
  * @param  min:����
  * @param  sec:����
  * @retval 0:��ʼ���ɹ�; 1:LSE����ʧ��; 2:�����ʼ��ģʽʧ��;
  */
void RTCx_SetAlarmA(uint8_t week, uint8_t hour, uint8_t min, uint8_t sec)
{
    RTC_AlarmTypeDef RTC_AlarmTypeInitStructure;
    RTC_TimeTypeDef RTC_TimeTypeInitStructure;
    NVIC_InitTypeDef  NVIC_InitStructure;

    RTC_AlarmCmd(RTC_Alarm_A, DISABLE); //�ر�����A

    RTC_TimeTypeInitStructure.RTC_Hours = hour; //Сʱ
    RTC_TimeTypeInitStructure.RTC_Minutes = min; //����
    RTC_TimeTypeInitStructure.RTC_Seconds = sec; //��
    RTC_TimeTypeInitStructure.RTC_H12 = RTC_H12_AM;

    RTC_AlarmTypeInitStructure.RTC_AlarmDateWeekDay = week; //����
    RTC_AlarmTypeInitStructure.RTC_AlarmDateWeekDaySel = RTC_AlarmDateWeekDaySel_WeekDay; //��������
    RTC_AlarmTypeInitStructure.RTC_AlarmMask = RTC_AlarmMask_None; //��ȷƥ�����ڣ�ʱ����
    RTC_AlarmTypeInitStructure.RTC_AlarmTime = RTC_TimeTypeInitStructure;
    RTC_SetAlarm(RTC_Format_BIN, RTC_Alarm_A, &RTC_AlarmTypeInitStructure);

    RTC_ClearITPendingBit(RTC_IT_ALRA);//���RTC����A�ı�־
    RTC_ITConfig(RTC_IT_ALRA, ENABLE); //��������A�ж�
    RTC_AlarmCmd(RTC_Alarm_A, ENABLE); //��������A

    NVIC_InitStructure.NVIC_IRQChannel = RTC_Alarm_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;//��ռ���ȼ�1
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;//�����ȼ�2
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;//ʹ���ⲿ�ж�ͨ��
    NVIC_Init(&NVIC_InitStructure);//����
}

/**
  * @brief  �����Ի��Ѷ�ʱ������
  * @param  wksel:  @ref RTC_Wakeup_Timer_Definitions
  * @param  cnt:�Զ���װ��ֵ.����0,�����ж�.
  * @retval ��
  */
void RTCx_SetWakeUp(uint32_t wksel, uint16_t cnt)
{
    NVIC_InitTypeDef  NVIC_InitStructure;

    RTC_WakeUpCmd(DISABLE);//�ر�WAKE UP
    RTC_WakeUpClockConfig(wksel);//����ʱ��ѡ��
    RTC_SetWakeUpCounter(cnt);//����WAKE UP�Զ���װ�ؼĴ���
    RTC_ClearITPendingBit(RTC_IT_WUT); //���RTC WAKE UP�ı�־

    RTC_ITConfig(RTC_IT_WUT, ENABLE); //����WAKE UP ��ʱ���ж�
    RTC_WakeUpCmd( ENABLE);//����WAKE UP ��ʱ����

    NVIC_InitStructure.NVIC_IRQChannel = RTC_WKUP_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;//��ռ���ȼ�1
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;//�����ȼ�2
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;//ʹ���ⲿ�ж�ͨ��
    NVIC_Init(&NVIC_InitStructure);//����
}

/**
  * @brief  RTC�����жϷ�����
  * @param  ��
  * @retval ��
  */
void RTC_Alarm_IRQHandler(void)
{
    if(RTC_GetFlagStatus(RTC_FLAG_ALRAF) == SET) //ALARM A�ж�
    {
        RTC_ClearFlag(RTC_FLAG_ALRAF);//����жϱ�־
    }
}

/**
  * @brief  RTC WAKE UP�жϷ�����
  * @param  ��
  * @retval ��
  */
void RTC_WKUP_IRQHandler(void)
{
    if(RTC_GetFlagStatus(RTC_FLAG_WUTF) == SET) //WK_UP�ж�
    {
        RTC_ClearFlag(RTC_FLAG_WUTF);   //����жϱ�־
    }
}
