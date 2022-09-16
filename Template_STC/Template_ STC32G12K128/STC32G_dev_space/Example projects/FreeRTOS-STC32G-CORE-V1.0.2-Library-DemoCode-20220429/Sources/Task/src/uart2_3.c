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

�����̻���STC32GΪ����оƬ��ʵ����9���б�д����.

�̽�ʵ�����ϵ�J7��J8���߽��в���.

����3��ʱ����һ�����ݸ�����2.

����2����Ӵ���3���յ�������.

������2�������ݣ�MCU�յ���Ӵ���2ԭ�����.

******************************************/

#include "FreeRTOS.h"
#include "task.h"

#include "STC32G_UART.h"
#include "uart2_3.h"

extern void TX2_write2buff(uint8_t dat);

uint16_t Sec_Cnt;    //1�����

/* RTC������ */
portTASK_FUNCTION( vUart2_3Task, pvParameters )
{
    uint8_t i;
    
    Sec_Cnt = 0;

    PrintString2("STC32G UART2-UART3 Test Programme!\r\n");  //UART2����һ���ַ���
    PrintString3("STC32G UART3-UART2 Test Programme!\r\n");  //UART3����һ���ַ���
    while(1)
    {
        Sec_Cnt++;
        if(Sec_Cnt >= (uint16_t)pvParameters)
        {
            Sec_Cnt = 0;
            PrintString3("STC32G UART3-UART2 Test Programme!\r\n");  //UART3����һ���ַ���
        }

        if(COM2.RX_TimeOut > 0)
        {
            if(--COM2.RX_TimeOut == 0)
            {
                if(COM2.RX_Cnt > 0)
                {
                    for(i=0; i<COM2.RX_Cnt; i++)    TX2_write2buff(RX2_Buffer[i]);    //���յ�������ͨ������2���
                    COM2.RX_Cnt = 0;   //����ֽ���
                }
            }
        }
        
        vTaskDelay(1);
    }
    
    vTaskDelete(NULL);
}   
