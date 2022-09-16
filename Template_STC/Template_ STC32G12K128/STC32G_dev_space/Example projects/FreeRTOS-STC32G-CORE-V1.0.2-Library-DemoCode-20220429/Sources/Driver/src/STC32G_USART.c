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

#include "STC32G_UART.h"
#include "STC32G_USART.h"

//========================================================================
//                               ���ر�������
//========================================================================

//========================================================================
// ����: void UsartLinSendByte(uint8_t USARTx, uint8_t dat)
// ����: ����һ���ֽں�����
// ����: none.
// ����: none.
// �汾: VER1.0
// ����: 2021-10-28
// ��ע: 
//========================================================================
void UsartLinSendByte(uint8_t USARTx, uint8_t dat)
{
	if(USARTx == USART1)
	{
		COM1.B_TX_busy = 1;
		SBUF = dat;
		while(COM1.B_TX_busy);
	}
	else if(USARTx == USART2)
	{
		COM2.B_TX_busy = 1;
		S2BUF = dat;
		while(COM2.B_TX_busy);
	}
}

//========================================================================
// ����: void UsartLinSendData(uint8_t USARTx, uint8_t *pdat)
// ����: Lin�������ݺ�����
// ����: *pdat: �������ݻ�����.
// ����: Lin ID.
// �汾: VER1.0
// ����: 2021-10-28
// ��ע: 
//========================================================================
void UsartLinSendData(uint8_t USARTx, uint8_t *pdat)
{
	uint8_t i;

	for(i=0;i<FRAME_LEN;i++)
	{
		UsartLinSendByte(USARTx,pdat[i]);
	}
}

//========================================================================
// ����: void UsartLinSendChecksum(uint8_t USARTx, uint8_t *dat)
// ����: ����У���벢���͡�
// ����: ���ݳ����������.
// ����: none.
// �汾: VER1.0
// ����: 2020-12-2
// ��ע: 
//========================================================================
void UsartLinSendChecksum(uint8_t USARTx, uint8_t *dat)
{
  uint16_t sum = 0;
  uint8_t i;

  for(i = 0; i < FRAME_LEN; i++)
  {
    sum += dat[i];
    if(sum & 0xFF00)
    {
      sum = (sum & 0x00FF) + 1;
    }
  }
  sum ^= 0x00FF;
	UsartLinSendByte(USARTx,(uint8_t)sum);
}

//========================================================================
// ����: void UsartSendBreak(void)
// ����: ��ģʽ����Lin����Break������
// ����: none.
// ����: none.
// �汾: VER1.0
// ����: 2021-10-28
// ��ע: 
//========================================================================
void UsartSendBreak(uint8_t USARTx)
{
	if(USARTx == USART1)
	{
		USARTCR5 |= 0x04;		//��ģʽ Send Break
	}
	else if(USARTx == USART2)
	{
		USART2CR5 |= 0x04;		//��ģʽ Send Break
	}
	UsartLinSendByte(USARTx,0x00);
}

//========================================================================
// ����: void UsartLinSendPID(uint8_t id)
// ����: ID�����У�����ת��PID�벢���͡�
// ����: ID��.
// ����: none.
// �汾: VER1.0
// ����: 2020-12-2
// ��ע: 
//========================================================================
void UsartLinSendPID(uint8_t USARTx, uint8_t id)
{
	uint8_t P0 ;
	uint8_t P1 ;
	
	P0 = (((id)^(id>>1)^(id>>2)^(id>>4))&0x01)<<6 ;
	P1 = ((~((id>>1)^(id>>3)^(id>>4)^(id>>5)))&0x01)<<7 ;
	
	UsartLinSendByte(USARTx,id|P0|P1);
}

//========================================================================
// ����: void UsartLinSendHeader(uint8_t lid)
// ����: Lin��������֡ͷ������
// ����: ID��.
// ����: none.
// �汾: VER1.0
// ����: 2021-10-28
// ��ע: 
//========================================================================
void UsartLinSendHeader(uint8_t USARTx, uint8_t lid)
{
	UsartSendBreak(USARTx);						//Send Break
	UsartLinSendByte(USARTx,0x55);		//Send Sync Field
	UsartLinSendPID(USARTx,lid);			//��������ID
}

//========================================================================
// ����: void UsartLinSendFrame(uint8_t USARTx, uint8_t lid, uint8_t *pdat)
// ����: Lin������������֡������
// ����: lid: Lin ID; *pdat: �������ݻ�����.
// ����: none.
// �汾: VER1.0
// ����: 2021-10-28
// ��ע: 
//========================================================================
void UsartLinSendFrame(uint8_t USARTx, uint8_t lid, uint8_t *pdat)
{
	UsartSendBreak(USARTx);						//Send Break
	UsartLinSendByte(USARTx,0x55);		//Send Sync Field

	UsartLinSendPID(USARTx,lid);			//��������ID
	UsartLinSendData(USARTx,pdat);
	UsartLinSendChecksum(USARTx,pdat);
}

//========================================================================
// ����: void UsartLinBaudrate(uint8_t USARTx, uint16_t brt)
// ����: Lin���߲��������ú�����
// ����: brt: ������.
// ����: none.
// �汾: VER1.0
// ����: 2021-10-28
// ��ע: 
//========================================================================
void UsartLinBaudrate(uint8_t USARTx, uint16_t brt)
{
	uint16_t tmp;
	
	tmp = (MAIN_Fosc >> 4) / brt;
	if(USARTx == USART1)
	{
		USARTBRH = (uint8_t)(tmp>>8);
		USARTBRL = (uint8_t)tmp;
	}
	else if(USARTx == USART2)
	{
		USART2BRH = (uint8_t)(tmp>>8);
		USART2BRL = (uint8_t)tmp;
	}
}

//========================================================================
// ����: UASRT_LIN_Configuration
// ����: USART��ʼ������.
// ����: USARTx: UART���, USART�ṹ����,��ο�USART.h��Ķ���.
// ����: none.
// �汾: V1.0, 2022-03-30
//========================================================================
uint8_t UASRT_LIN_Configuration(uint8_t USARTx, USARTx_LIN_InitDefine *USART)
{
	if(USARTx == USART1)
	{
		SCON = (SCON & 0x3f) | 0x40;    //USART1ģʽ, 0x00: ͬ����λ���, 0x40: 8λ����,�ɱ䲨����, 0x80: 9λ����,�̶�������, 0xc0: 9λ����,�ɱ䲨����
		SMOD = 1;
		TI = 0;
		REN = 1;    //�������
		ES  = 1;    //�����ж�

		if(USART->LIN_Enable == ENABLE)	USARTCR1 |= 0x80;		//ʹ��LINģ��
		else								USARTCR1 &= ~0x80;		//�ر�LINģ��
		if(USART->LIN_Mode == LinSlaveMode)	USARTCR5 |= 0x20;		//LINģ��ӻ�ģʽ
		else								USARTCR5 &= ~0x20;		//LINģ������ģʽ
		if(USART->LIN_AutoSync == ENABLE)	USARTCR5 |= 0x10;		//ʹ���Զ�ͬ��
		else								USARTCR5 &= ~0x10;		//�ر��Զ�ͬ��

		UsartLinBaudrate(USART1,USART->LIN_Baudrate);			//���ò�����

		return SUCCESS;
	}

	if(USARTx == USART2)
	{
		S2CON = (S2CON & 0x3f) | 0x50;
		T2x12 = 1;   //��ʱ��2ʱ��1Tģʽ
		T2R = 1;     //��ʼ��ʱ
		ES2 = 1;     //�����ж�
		S2CFG |= 0x80;				//S2MOD = 1

		if(USART->LIN_Enable == ENABLE)	USART2CR1 |= 0x80;		//ʹ��LINģ��
		else								USART2CR1 &= ~0x80;		//�ر�LINģ��
		if(USART->LIN_Mode == LinSlaveMode)	USART2CR5 |= 0x20;		//LINģ��ӻ�ģʽ
		else								USART2CR5 &= ~0x20;		//LINģ������ģʽ
		if(USART->LIN_AutoSync == ENABLE)	USART2CR5 |= 0x10;		//ʹ���Զ�ͬ��
		else								USART2CR5 &= ~0x10;		//�ر��Զ�ͬ��

		UsartLinBaudrate(USART2,USART->LIN_Baudrate);			//���ò�����

		return SUCCESS;
	}
	return FAIL;	//����
}

/*********************************************************/
