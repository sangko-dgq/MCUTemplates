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

ͨ��ADC�ɼ�������ADCֵ������ADCֵ���ü���Ϊ1~16.

����ֻ֧�ֵ�������, ��֧�ֶ��ͬʱ����, ���������в���Ԥ֪�Ľ��.

�����³���1���,����10��/����ٶ��ṩ�ؼ����. �û�ֻ��Ҫ���KeyCode�Ƿ��0���жϼ��Ƿ���.

����ʱ���:
����1: Сʱ+.
����2: Сʱ-.
����3: ����+.
����4: ����-.

******************************************/

#include "FreeRTOS.h"
#include "task.h"

#include "STC32G_ADC.h"

#include "adckey.h"
#include "rtc.h"
//#include "display.h"

#define ADCKEY_CHANNEL          0                       //ADC����������ͨ����P1.0��
#define ADC_OFFSET              64                      //ADC����ɨ��ʱ��ƫ�Χ


static void prvAdcKeyInit( void );
static void prvAdcCalculateKey( void );
static void prvAdcKeyEvent( void );


static uint8_t ucKeyState;                              //ADC����״̬
static uint8_t ucKeyState1;
static uint8_t ucKeyState2;
static uint8_t ucKeyState3;
static uint8_t ucKeyHoldCnt;                            //�����¼�ʱ

uint8_t ucKeyCode;                                      //���û�ʹ�õļ���, 1~16��Ч

/* ADC����ɨ�������� */
portTASK_FUNCTION( vAdcKeyTask, pvParameters )
{
    
	UNUSED( pvParameters );

    prvAdcKeyInit();
    while(1)
    {
        prvAdcCalculateKey();
        prvAdcKeyEvent();

        vTaskDelay(10);
    }
    
    vTaskDelete(NULL);
}   

static void prvAdcKeyInit( void )
{
//    P1M1 |= 0x01;                                       //���� P1.0 Ϊ ADC �����
//    P1M0 &= ~0x01;

    ucKeyState  = 0;
    ucKeyState1 = 0;
    ucKeyState2 = 0;
    ucKeyState3 = 0;                                    //��״̬
    ucKeyHoldCnt = 0;                                   //�����¼�ʱ
    ucKeyCode = 0;                                      //���û�ʹ�õļ���, 1~16��Ч
}

/***************** ADC���̼������ *****************************
��·������㷨���: Coody
��ADC���̷����ںܶ�ʵ�ʲ�Ʒ�����, ��֤�����ȶ��ɿ�, ��ʹ����ʹ�õ���Ĥ,���ܿɿ�.
16����,�����ϸ�������Ӧ��ADCֵΪ (4096 / 16) * k = 256 * k, k = 1 ~ 16, �ر��, k=16ʱ,��Ӧ��ADCֵ��4095.
����ʵ�ʻ���ƫ��,���ж�ʱ�������ƫ��, ADC_OFFSETΪ+-ƫ��, ��ADCֵ�� (256*k-ADC_OFFSET) �� (256*k+ADC_OFFSET)֮��Ϊ����Ч.
���һ����ʱ��,�Ͳ���һ��ADC,����10ms.
Ϊ�˱���żȻ��ADCֵ����, ���߱���ADC���������½�ʱ����, ʹ������3��ADCֵ����ƫ�Χ��ʱ, ADCֵ����Ϊ��Ч.
�����㷨, �ܱ�֤�����ǳ��ɿ�.
**********************************************/
static void prvAdcCalculateKey( void )
{
    uint16_t usResult;
    uint8_t i;
    uint16_t j;
    
    usResult = Get_ADCResult(ADCKEY_CHANNEL);
    
    if(usResult < (256 - ADC_OFFSET))
    {
        ucKeyState = 0;                                 //��״̬��0
        ucKeyHoldCnt = 0;
    }
    
    j = 256;
    for (i = 1; i <= 16; i++)
    {
        if ((usResult >= (j - ADC_OFFSET)) &&
            (usResult <= (j + ADC_OFFSET)))
           break;                                       //�ж��Ƿ���ƫ�Χ��
        j += 256;
    }
    
    ucKeyState3 = ucKeyState2;
    ucKeyState2 = ucKeyState1;
    
    if (i > 16)
        ucKeyState1 = 0;                                //����Ч
    else                                                //����Ч
    {
        ucKeyState1 = i;
        if ((ucKeyState3 == ucKeyState2) &&
            (ucKeyState2 == ucKeyState1) &&
            (ucKeyState3 > 0) &&
            (ucKeyState2 > 0) &&
            (ucKeyState1 > 0))
        {
            if (ucKeyState == 0)                        //��һ�μ�⵽
            {
                ucKeyCode = i;                          //�������
                ucKeyState = i;                         //�����״̬
                ucKeyHoldCnt = 0;
            }
            
            if (ucKeyState == i)                        //������⵽ͬһ������
            {
                if (++ucKeyHoldCnt >= 100)              //����1���,��10��ÿ����ٶ�Repeat Key
                {
                    ucKeyHoldCnt = 90;
                    ucKeyCode  = i;                     //�������
                }
            }
            else
                ucKeyHoldCnt = 0;                       //����ʱ�������0
        }
    }
}

static void prvAdcKeyEvent( void )
{
    uint8_t ucCode;
    
    ucCode = ucKeyCode;
    ucKeyCode = 0;
    
    if (ucCode > 0)                                     //�м�����
    {
//        pucLEDBuffer[6] = ucCode / 10;                  //��ʾ����
//        pucLEDBuffer[7] = ucCode % 10;                  //��ʾ����

        switch (ucCode)
        {
        case 1:                                         //hour +1
            if (++ucHour >= 24)
                ucHour = 0;
            break;
        case 2:                                         //hour -1
            if (--ucHour >= 24)
                ucHour = 23;
            break;
        case 3:                                         //minute +1
            ucSecond = 0;
            if (++ucMinute >= 60)
                ucMinute = 0;
            break;
        case 4:                                         //minute -1
            ucSecond = 0;
            if (--ucMinute >= 60)
                ucMinute = 59;
            break;
        default:
            return;
        }
        
        vRtcUpdateDisplay();
    }
}


