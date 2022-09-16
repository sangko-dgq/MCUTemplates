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

ͨ��P5.4������͵�ƽ������Դ������.

����ɨ�谴��ÿ���������º��������һ��.

******************************************/

#include "FreeRTOS.h"
#include "task.h"

#include "MatrixKey.h"

/****************************** �û������ ***********************************/

sbit BEEP = P5^4;

uint8_t cntms;
uint8_t KeyCode;    //���û�ʹ�õļ���, 1~16��Ч
uint8_t IO_KeyState, IO_KeyState1, IO_KeyHoldCnt;    //���м��̱���

void MatrixKeyScan(void);

/* RTC������ */
portTASK_FUNCTION( vMatrixKeyTask, pvParameters )
{
    UNUSED( pvParameters );
    
    P5M1 &= ~0x10;   P5M0 |= 0x10;   //����P5.4Ϊ�������
    BEEP = 1;  //�������ر�
    while(1)
    {
        if(cntms > 0)
        {
            cntms--;
        }
        else
        {
            BEEP = 1;    //�������ر�
        }

        MatrixKeyScan();
        if(KeyCode > 0)  //�м�����
        {
            KeyCode = 0;
            BEEP = 0;    //����������
            cntms = 5;   //����ʱ�� 5*50ms
        }
        
        vTaskDelay(50);
    }
    
    vTaskDelete(NULL);
}   

/*****************************************************
    ���м�ɨ�����
    ʹ��XY����4x4���ķ�����ֻ�ܵ������ٶȿ�

   Y     P04      P05      P06      P07
          |        |        |        |
X         |        |        |        |
P00 ---- K00 ---- K01 ---- K02 ---- K03 ----
          |        |        |        |
P01 ---- K04 ---- K05 ---- K06 ---- K07 ----
          |        |        |        |
P02 ---- K08 ---- K09 ---- K10 ---- K11 ----
          |        |        |        |
P03 ---- K12 ---- K13 ---- K14 ---- K15 ----
          |        |        |        |
******************************************************/

uint8_t code T_KeyTable[16] = {0,1,2,0,3,0,0,0,4,0,0,0,0,0,0,0};

void IO_KeyDelay(void)
{
    uint8_t i;
    i = 60;
    while(--i)  ;
}

void MatrixKeyScan(void)    //50ms call
{
    uint8_t  j;

    j = IO_KeyState1;   //������һ��״̬

    P0 = 0xf0;  //X�ͣ���Y
    IO_KeyDelay();
    IO_KeyState1 = P0 & 0xf0;

    P0 = 0x0f;  //Y�ͣ���X
    IO_KeyDelay();
    IO_KeyState1 |= (P0 & 0x0f);
    IO_KeyState1 ^= 0xff;   //ȡ��
    
    if(j == IO_KeyState1)   //�������ζ����
    {
        j = IO_KeyState;
        IO_KeyState = IO_KeyState1;
        if(IO_KeyState != 0)    //�м�����
        {
            F0 = 0;
            if(j == 0)  F0 = 1; //��һ�ΰ���
            else if(j == IO_KeyState)
            {
                if(++IO_KeyHoldCnt >= 20)   //1����ؼ�
                {
                    IO_KeyHoldCnt = 18;
                    F0 = 1;
                }
            }
            if(F0)
            {
                j = T_KeyTable[IO_KeyState >> 4];
                if((j != 0) && (T_KeyTable[IO_KeyState& 0x0f] != 0)) 
                    KeyCode = (j - 1) * 4 + T_KeyTable[IO_KeyState & 0x0f] + 16;    //������룬17~32
            }
        }
        else    IO_KeyHoldCnt = 0;
    }
    P0 = 0xff;
}
