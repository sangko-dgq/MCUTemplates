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

��дprintf���õ�putchar�������ض��򵽴�������������ڵ��Դ�ӡ��Ϣ.

******************************************/

#include "FreeRTOS.h"
#include "STC32G_UART.h"

extern void TX1_write2buff(uint8_t dat) reentrant;
extern void TX2_write2buff(uint8_t dat) reentrant;
extern void TX3_write2buff(uint8_t dat) reentrant;
extern void TX4_write2buff(uint8_t dat) reentrant;

/********************* Printf ���� ************************/
#if(PRINTF_SELECT == 1)

char putchar(char c)
{
	TX1_write2buff(c);
	return c;
}

#elif(PRINTF_SELECT == 2)

char putchar(char c)
{
	TX2_write2buff(c);
	return c;
}

#elif(PRINTF_SELECT == 3)

char putchar(char c)
{
	TX3_write2buff(c);
	return c;
}

#elif(PRINTF_SELECT == 4)

char putchar(char c)
{
	TX4_write2buff(c);
	return c;
}

#endif
