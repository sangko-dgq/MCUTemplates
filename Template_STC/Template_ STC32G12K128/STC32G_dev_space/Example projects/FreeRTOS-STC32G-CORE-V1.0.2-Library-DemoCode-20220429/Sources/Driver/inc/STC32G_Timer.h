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

#ifndef	__STC32G_TIMER_H
#define	__STC32G_TIMER_H

#include	"FreeRTOS.h"

//========================================================================
//                             ��ʱ��0����
//========================================================================

/* 0,1: ��ʱ��0������ʱ��, 12T/1T; 2: ��ʱ��0����������	*/
#define 	Timer0_CLK_Select(n)	do{if(n == 0) T0x12 = 0, T0_CT = 0; \
																if(n == 1) T0x12 = 1, T0_CT = 0; \
																if(n == 2) T0_CT = 1; \
																}while(0)

#define		Timer0_CLK_Output(n)	T0CLKO = n	/* T0 ���������T0�����ʹ�� */
#define 	Timer0_Run(n)					(n==0?(TR0 = 0):(TR0 = 1))				/* ��ʱ��0����ʹ�� */
#define 	Timer0_Stop()	 				TR0 = 0				/* ��ֹ��ʱ��0���� */
#define		T0_Load(n)						TH0 = (n) / 256,	TL0 = (n) % 256

//========================================================================
//                             ��ʱ��1����
//========================================================================

/* 0,1: ��ʱ��1������ʱ��, 12T/1T; 2: ��ʱ��1����������	*/
#define 	Timer1_CLK_Select(n)	do{if(n == 0) T1x12 = 0, T1_CT = 0; \
																if(n == 1) T1x12 = 1, T1_CT = 0; \
																if(n == 2) T1_CT = 1; \
																}while(0)

#define		Timer1_CLK_Output(n)	T1CLKO = n	/* T1 ���������T1�����ʹ�� */
#define 	Timer1_Run(n)					(n==0?(TR1 = 0):(TR1 = 1))				/* ��ʱ��1����ʹ�� */
#define 	Timer1_Stop()	 				TR1 = 0				/* ��ֹ��ʱ��1���� */
#define		T1_Load(n)						TH1 = (n) / 256,	TL1 = (n) % 256

//========================================================================
//                             ��ʱ��2����
//========================================================================

/* 0,1: ��ʱ��2������ʱ��, 12T/1T; 2: ��ʱ��2����������	*/
#define 	Timer2_CLK_Select(n)	do{if(n == 0) T2x12 = 0, T2_CT = 0; \
																if(n == 1) T2x12 = 1, T2_CT = 0; \
																if(n == 2) T2_CT = 1; \
																}while(0)

#define		Timer2_CLK_Output(n)	T2CLKO = n	/* T2 ���������T2�����ʹ�� */
#define 	Timer2_Run(n)					(n==0?(T2R = 0):(T2R = 1))		/* ��ʱ��2����ʹ�� */
#define 	Timer2_Stop()	 				T2R = 0		/* ��ֹ��ʱ��2����	*/
#define		T2_Load(n)						T2H = (n) / 256,	T2L = (n) % 256

//========================================================================
//                             ��ʱ��3����
//========================================================================

/* 0,1: ��ʱ��3������ʱ��, 12T/1T; 2: ��ʱ��3����������	*/
#define 	Timer3_CLK_Select(n)	do{if(n == 0) T3x12 = 0, T3_CT = 0; \
																if(n == 1) T3x12 = 1, T3_CT = 0; \
																if(n == 2) T3_CT = 1; \
																}while(0)

#define		Timer3_CLK_Output(n)	T3CLKO = n				/* T3 ���������T3�����ʹ�� */
#define 	Timer3_Run(n)					(n==0?(T3R = 0):(T3R = 1))	/* ��ʱ��3����ʹ�� */
#define 	Timer3_Stop()	 				T3R = 0	/* ��ֹ��ʱ��3����	*/
#define		T3_Load(n)						T3H = (n) / 256,	T3L = (n) % 256

//========================================================================
//                             ��ʱ��4����
//========================================================================

/* 0,1: ��ʱ��4������ʱ��, 12T/1T; 2: ��ʱ��4����������	*/
#define 	Timer4_CLK_Select(n)	do{if(n == 0) T4x12 = 0, T4_CT = 0; \
																if(n == 1) T4x12 = 1, T4_CT = 0; \
																if(n == 2) T4_CT = 1; \
																}while(0)

#define		Timer4_CLK_Output(n)	T4CLKO = n	/* T4 ���������T4�����ʹ�� */
#define 	Timer4_Run(n)					(n==0?(T4R = 0):(T4R = 1))	/* ��ʱ��4����ʹ�� */
#define 	Timer4_Stop()	 				T4R = 0	/* ��ֹ��ʱ��4����	*/
#define		T4_Load(n)						T4H = (n) / 256,	T4L = (n) % 256

//========================================================================
//                              ��������
//========================================================================

#define	Timer0						0
#define	Timer1						1
#define	Timer2						2
#define	Timer3						3
#define	Timer4						4

#define	TIM_16BitAutoReload				0
#define	TIM_16Bit									1
#define	TIM_8BitAutoReload				2
#define	TIM_16BitAutoReloadNoMask	3
#define	TIM_T1Stop								3

#define	TIM_CLOCK_12T				0
#define	TIM_CLOCK_1T				1
#define	TIM_CLOCK_Ext				2

typedef struct
{
	uint8_t	TIM_Mode;		//����ģʽ,  	TIM_16BitAutoReload,TIM_16Bit,TIM_8BitAutoReload,TIM_16BitAutoReloadNoMask
	uint8_t	TIM_ClkSource;	//ʱ��Դ		TIM_CLOCK_1T,TIM_CLOCK_12T,TIM_CLOCK_Ext
	uint8_t	TIM_ClkOut;		//�ɱ��ʱ�����,	ENABLE,DISABLE
	uint16_t	TIM_Value;	//װ�س�ֵ
	uint8_t	TIM_Run;		//�Ƿ�����		ENABLE,DISABLE
} TIM_InitTypeDef;

uint8_t	Timer_Inilize(uint8_t TIM, TIM_InitTypeDef *TIMx);

#endif
