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

/*************  ����˵��    **************

�����̻���STC32GΪ����оƬ��ʵ������б�д���ԡ�

��STC��MCU��IO��ʽ����8λ����ܡ�

��ʾЧ��Ϊ: ģ������ʱ��.

���4λLED��ʾʱ��(Сʱ,����).

******************************************/

#include "FreeRTOS.h"
#include "task.h"

#include "rtc.h"
#include "display.h"

static void prvRtcInit( void );
static void prvRtcCounter( void );

void vRtcUpdateDisplay( void );

static uint8_t ucDotState;                              //������ʾ״̬

uint8_t ucHour;                                         //ʱ�ӱ���(ʱ)
uint8_t ucMinute;                                       //ʱ�ӱ���(��)
uint8_t ucSecond;                                       //ʱ�ӱ���(��)

/* RTC������ */
portTASK_FUNCTION( vRtcTask, pvParameters )
{
    
    UNUSED( pvParameters );
    
    prvRtcInit();
    while(1)
    {
        prvRtcCounter();
        vRtcUpdateDisplay();
        vTaskDelay(500);
    }
    
    vTaskDelete(NULL);
}   

static void prvRtcInit( void )
{
    ucHour   = 12;                                      //��ʼ��ʱ��ֵ
    ucMinute = 0;
    ucSecond = 0;
    ucDotState = 0;
}


/********************** ��ʾʱ�Ӻ��� ************************/
void vRtcUpdateDisplay( void )
{
    pucLEDBuffer[0] = ucHour >= 10 ? ucHour / 10 : DIS_BLACK;
    pucLEDBuffer[1] = ucHour % 10;
    pucLEDBuffer[2] = ucMinute / 10;
    pucLEDBuffer[3] = ucMinute % 10;
    
    if (ucDotState)
        pucLEDBuffer[1] |= DIS_DOT;                     //Сʱ���С����������
}

/********************** ʱ����ʾ���� ************************/
static void prvRtcCounter( void )
{
    ucDotState = !ucDotState;
    
    if (!ucDotState) return;

    if(++ucSecond >= 60)
    {
        ucSecond = 0;
        if(++ucMinute >= 60)
        {
            ucMinute = 0;
            if(++ucHour >= 24)
                ucHour = 0;
        }
    }
}
