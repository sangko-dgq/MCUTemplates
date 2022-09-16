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

#ifndef __STC32G_UART_H
#define __STC32G_UART_H	 

#include	"FreeRTOS.h"

//========================================================================
//                              ��������
//========================================================================

#define	UART1	1
#define	UART2	2
#define	UART3	3
#define	UART4	4

#define	UART_BUF_type	edata

#define	PRINTF_SELECT  UART2		//ѡ�� printf ������ʹ�õĴ��ڣ����� UART1~UART4

#ifdef UART1
#define	COM_TX1_Lenth	64
#define	COM_RX1_Lenth	64
#endif
#ifdef UART2
#define	COM_TX2_Lenth	64
#define	COM_RX2_Lenth	64
#endif
#ifdef UART3
#define	COM_TX3_Lenth	64
#define	COM_RX3_Lenth	64
#endif
#ifdef UART4
#define	COM_TX4_Lenth	64
#define	COM_RX4_Lenth	64
#endif

#define	UART_ShiftRight	0		//ͬ����λ���
#define	UART_8bit_BRTx	(1<<6)	//8λ����,�ɱ䲨����
#define	UART_9bit				(2<<6)	//9λ����,�̶�������
#define	UART_9bit_BRTx	(3<<6)	//9λ����,�ɱ䲨����


#define	TimeOutSet1		5
#define	TimeOutSet2		5
#define	TimeOutSet3		5
#define	TimeOutSet4		5

#define	BRT_Timer1	1
#define	BRT_Timer2	2
#define	BRT_Timer3	3
#define	BRT_Timer4	4

//========================================================================
//                              UART����
//========================================================================

#define		UART1_RxEnable(n)		(n==0?(REN = 0):(REN = 1))				/* UART1����ʹ�� */
#define		UART2_RxEnable(n)		(n==0?(S2REN = 0):(S2REN = 1))		/* UART2����ʹ�� */
#define		UART3_RxEnable(n)		(n==0?(S3REN = 0):(S3REN = 1))		/* UART3����ʹ�� */
#define		UART4_RxEnable(n)		(n==0?(S4REN = 0):(S4REN = 1))		/* UART4����ʹ�� */


#define		CLR_TI2()			S2TI = 0			/* ���TI2											 */
#define		CLR_RI2()			S2RI = 0			/* ���RI2											 */
#define		CLR_TI3()			S3TI = 0			/* ���TI3											 */
#define		CLR_RI3()			S3RI = 0			/* ���RI3											 */
#define		CLR_TI4()			S4TI = 0			/* ���TI3									     */
#define		CLR_RI4()			S4RI = 0			/* ���RI3									     */

#define		S3_8bit()			S3SM0 = 0	/* ����3ģʽ0��8λUART�������� = ��ʱ��������� / 4  */
#define		S3_9bit()			S3SM0 = 1	/* ����3ģʽ1��9λUART�������� = ��ʱ��������� / 4  */
#define 	S3_BRT_UseTimer3()	S3ST3 = 1	/* BRT select Timer3								 */
#define 	S3_BRT_UseTimer2()	S3ST3 = 0	/* BRT select Timer2								 */

#define		S4_8bit()			S4SM0 = 0	/* ����4ģʽ0��8λUART�������� = ��ʱ��������� / 4  */
#define		S4_9bit()			S4SM0 = 1	/* ����4ģʽ1��9λUART�������� = ��ʱ��������� / 4  */
#define 	S4_BRT_UseTimer4()	S4ST4 = 1	/* BRT select Timer4								 */
#define 	S4_BRT_UseTimer2()	S4ST4 = 0	/* BRT select Timer2								 */

//========================================================================
//                              ��������
//========================================================================

typedef struct
{ 
	uint8_t	id;				//���ں�

	uint8_t	TX_send;		//�ѷ���ָ��
	uint8_t	TX_write;		//����дָ��
	uint8_t	B_TX_busy;		//æ��־

	uint8_t RX_Cnt;			//�����ֽڼ���
	uint8_t	RX_TimeOut;		//���ճ�ʱ
	uint8_t	B_RX_OK;		//���տ����
} COMx_Define; 

typedef struct
{ 
	uint8_t	UART_Mode;			//ģʽ,         UART_ShiftRight,UART_8bit_BRTx,UART_9bit,UART_9bit_BRTx
	uint8_t	UART_BRT_Use;		//ʹ�ò�����,   BRT_Timer1,BRT_Timer2,BRT_Timer3,BRT_Timer4
	uint32_t UART_BaudRate;		//������, 	   һ�� 110 ~ 115200
	uint8_t	Morecommunicate;	//���ͨѶ����, ENABLE,DISABLE
	uint8_t	UART_RxEnable;		//�������,   ENABLE,DISABLE
	uint8_t	BaudRateDouble;		//�����ʼӱ�, ENABLE,DISABLE
} COMx_InitDefine; 

#ifdef UART1
extern	COMx_Define	COM1;
extern	uint8_t	UART_BUF_type TX1_Buffer[COM_TX1_Lenth];	//���ͻ���
extern	uint8_t 	UART_BUF_type RX1_Buffer[COM_RX1_Lenth];	//���ջ���
#endif
#ifdef UART2
extern	COMx_Define	COM2;
extern	uint8_t	UART_BUF_type TX2_Buffer[COM_TX2_Lenth];	//���ͻ���
extern	uint8_t 	UART_BUF_type RX2_Buffer[COM_RX2_Lenth];	//���ջ���
#endif
#ifdef UART3
extern	COMx_Define	COM3;
extern	uint8_t	UART_BUF_type TX3_Buffer[COM_TX3_Lenth];	//���ͻ���
extern	uint8_t 	UART_BUF_type RX3_Buffer[COM_RX3_Lenth];	//���ջ���
#endif
#ifdef UART4
extern	COMx_Define	COM4;
extern	uint8_t	UART_BUF_type TX4_Buffer[COM_TX4_Lenth];	//���ͻ���
extern	uint8_t 	UART_BUF_type RX4_Buffer[COM_RX4_Lenth];	//���ջ���
#endif

uint8_t	UART_Configuration(uint8_t UARTx, COMx_InitDefine *COMx);
#ifdef UART1
//void TX1_write2buff(uint8_t dat);
void PrintString1(uint8_t *puts);
#endif
#ifdef UART2
//void TX2_write2buff(uint8_t dat);
void PrintString2(uint8_t *puts);
#endif
#ifdef UART3
//void TX3_write2buff(uint8_t dat);
void PrintString3(uint8_t *puts);
#endif
#ifdef UART4
//void TX4_write2buff(uint8_t dat);
void PrintString4(uint8_t *puts);
#endif

//void COMx_write2buff(COMx_Define *COMx, uint8_t dat);
//void PrintString(COMx_Define *COMx, uint8_t *puts);

#endif

