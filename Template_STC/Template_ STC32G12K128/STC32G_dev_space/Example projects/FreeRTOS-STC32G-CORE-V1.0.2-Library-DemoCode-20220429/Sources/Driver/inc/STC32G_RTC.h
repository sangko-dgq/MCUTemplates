/*---------------------------------------------------------------------*/
/* --- STC MCU Limited ------------------------------------------------*/
/* --- STC 1T Series MCU Demo Programme -------------------------------*/
/* --- Mobile: (86)13922805190 ----------------------------------------*/
/* --- Fax: 86-0513-55012956,55012947,55012969 ------------------------*/
/* --- Tel: 86-0513-55012928,55012929,55012966 ------------------------*/
/* --- Web: www.STCMCU.com --------------------------------------------*/
/* --- Web: www.STCMCUDATA.com  ---------------------------------------*/
/* --- QQ:  800003751 -------------------------------------------------*/
/* ���Ҫ�ڳ�����ʹ�ô˴���,���ڳ�����ע��ʹ����STC�����ϼ�����            */
/*---------------------------------------------------------------------*/

#ifndef	__STC32G_RTC_H
#define	__STC32G_RTC_H

#include	"FreeRTOS.h"

//========================================================================
//                              ��������
//========================================================================

#define RTC_IRC32KCR		0		//RTCʱ��Դʹ���ڲ�32Kʱ��
#define RTC_X32KCR			1		//RTCʱ��Դʹ���ⲿ32K����

//�ж�ʹ��, 0x80:�����ж�, 0x40:���ж�, 0x20:Сʱ�ж�, 0x10:�����ж�, 0x08:���ж�, 0x04:1/2���ж�, 0x02:1/8���ж�, 0x01:1/32���ж�
#define RTC_ALARM_INT		0x80		//RTC �����ж�
#define RTC_DAY_INT			0x40		//RTC ���ж�
#define RTC_HOUR_INT		0x20		//RTC Сʱ�ж�
#define RTC_MIN_INT			0x10		//RTC �����ж�
#define RTC_SEC_INT			0x08		//RTC ���ж�
#define RTC_SEC2_INT		0x04		//RTC 1/2���ж�
#define RTC_SEC8_INT		0x02		//RTC 1/8���ж�
#define RTC_SEC32_INT		0x01		//RTC 1/32���ж�

typedef struct
{
	uint8_t	RTC_Enable;		//RTC ʹ��, ENABLE, DISABLE
	uint8_t	RTC_Clock;		//RTC ʱ��, RTC_IRC32KCR, RTC_X32KCR
	uint8_t	RTC_Year;			//RTC ��, 00~99, ��Ӧ2000~2099��
	uint8_t	RTC_Month;		//RTC ��, 01~12
	uint8_t	RTC_Day;			//RTC ��, 01~31
	uint8_t	RTC_Hour;			//RTC ʱ, 00~23
	uint8_t	RTC_Min;			//RTC ��, 00~59
	uint8_t	RTC_Sec;			//RTC ��, 00~59
	uint8_t	RTC_Ssec;			//RTC 1/128��, 00~127

	uint8_t	RTC_ALAHour;	//RTC ����ʱ, 00~23
	uint8_t	RTC_ALAMin;		//RTC ���ӷ�, 00~59
	uint8_t	RTC_ALASec;		//RTC ������, 00~59
	uint8_t	RTC_ALASsec;	//RTC ����1/128��, 00~127
} RTC_InitTypeDef;

uint8_t	RTC_Inilize(RTC_InitTypeDef *RTCx);

#endif
