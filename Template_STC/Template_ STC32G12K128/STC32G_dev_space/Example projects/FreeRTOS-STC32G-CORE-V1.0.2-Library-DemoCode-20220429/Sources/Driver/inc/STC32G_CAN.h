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

#ifndef	__STC32G_CAN_H
#define	__STC32G_CAN_H

#include	"FreeRTOS.h"

//========================================================================
//                              ��������
//========================================================================

#define	CAN1	0
#define	CAN2	1

//========================================================================
//                              ��������
//========================================================================

#define CAN_DOIM     0x01  //��������ж�
#define CAN_BEIM     0x02  //���ߴ�λ�ж�
#define CAN_TIM      0x04  //�����ж�
#define CAN_RIM      0x08  //�����ж�
#define CAN_EPIM     0x10  //������λ�ж�
#define CAN_EWIM     0x20  //��λ�����ж�
#define CAN_ALIM     0x40  //�ٲö�ʧ�ж�
#define CAN_ALLIM    0x7F  //�����ж�

//========================================================================
//                              ��������
//========================================================================

typedef struct
{
	uint8_t	CAN_Enable;					//CAN����ʹ��  	ENABLE,DISABLE
	uint8_t	CAN_IMR;						//CAN�жϼĴ��� 	CAN_DOIM,CAN_BEIM,CAN_TIM,CAN_RIM,CAN_EPIM,CAN_EWIM,CAN_ALIM,CAN_ALLIM,DISABLE
	uint8_t	CAN_SJW;						//����ͬ����Ծ���  0~3
	uint8_t	CAN_BRP;						//�����ʷ�Ƶϵ��    0~63
	uint8_t	CAN_SAM;						//���ߵ�ƽ��������  0:����1��; 1:����3��
	uint8_t	CAN_TSG1;						//ͬ��������1       0~15
	uint8_t	CAN_TSG2;						//ͬ��������2       1~7 (TSG2 ��������Ϊ0)

	uint8_t	CAN_ACR0;						//�������մ���Ĵ��� 0~0xFF
	uint8_t	CAN_ACR1;						//�������մ���Ĵ��� 0~0xFF
	uint8_t	CAN_ACR2;						//�������մ���Ĵ��� 0~0xFF
	uint8_t	CAN_ACR3;						//�������մ���Ĵ��� 0~0xFF
	uint8_t	CAN_AMR0;						//�����������μĴ��� 0~0xFF
	uint8_t	CAN_AMR1;						//�����������μĴ��� 0~0xFF
	uint8_t	CAN_AMR2;						//�����������μĴ��� 0~0xFF
	uint8_t	CAN_AMR3;						//�����������μĴ��� 0~0xFF
} CAN_InitTypeDef;


//========================================================================
//                              �ⲿ����
//========================================================================

uint8_t CanReadReg(uint8_t addr);
void CanReadFifo(uint8_t *pdat);
void CAN_Inilize(uint8_t CANx, CAN_InitTypeDef *CAN);
uint16_t CanReadStandardFrame(uint8_t *pdat);
uint32_t CanReadExtendedFrame(uint8_t *pdat);
void CanSendStandardFrame(uint16_t canid, uint8_t *pdat);
void CanSendExtendedFrame(uint32_t canid, uint8_t *pdat);

#endif
