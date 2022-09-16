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

#include "STC32G_CAN.h"

//========================================================================
// ����: uint8_t ReadReg(uint8_t addr)
// ����: CAN���ܼĴ�����ȡ������
// ����: CAN���ܼĴ�����ַ.
// ����: CAN���ܼĴ�������.
// �汾: VER1.0
// ����: 2020-11-16
// ��ע: 
//========================================================================
uint8_t CanReadReg(uint8_t addr)
{
	uint8_t dat;
	CANAR = addr;
	dat = CANDR;
	return dat;
}

//========================================================================
// ����: void WriteReg(uint8_t addr, uint8_t dat)
// ����: CAN���ܼĴ������ú�����
// ����: CAN���ܼĴ�����ַ, CAN���ܼĴ�������.
// ����: none.
// �汾: VER1.0
// ����: 2020-11-16
// ��ע: 
//========================================================================
void CanWriteReg(uint8_t addr, uint8_t dat)
{
	CANAR = addr;
	CANDR = dat;
}

//========================================================================
// ����: void CAN_Inilize(uint8_t CANx, CAN_InitTypeDef *CAN)
// ����: CAN ��ʼ������.
// ����: CAN: �ṹ����,��ο�CAN.h��Ķ���.
// ����: none.
// �汾: V1.0, 2021-06-02
//========================================================================
void CAN_Inilize(uint8_t CANx, CAN_InitTypeDef *CAN)
{
	if(CANx == CAN1)
	{
		CANSEL = CAN1;		//ѡ��CAN1ģ��
		CanWriteReg(MR  ,0x04);		//ʹ�� Reset Mode

		if(CAN->CAN_Enable == ENABLE)	CANEN = 1;		//ʹ��CAN1ģ��
		else								CANEN = 0;		//�ر�CAN1ģ��
		
		CanWriteReg(BTR0,(uint8_t)((CAN->CAN_SJW << 6) + CAN->CAN_BRP));
		CanWriteReg(BTR1,(uint8_t)((CAN->CAN_SAM << 7) + (CAN->CAN_TSG2 << 4) + CAN->CAN_TSG1));

		CanWriteReg(ACR0,CAN->CAN_ACR0);		//�������մ���Ĵ���
		CanWriteReg(ACR1,CAN->CAN_ACR1);
		CanWriteReg(ACR2,CAN->CAN_ACR2);
		CanWriteReg(ACR3,CAN->CAN_ACR3);
		CanWriteReg(AMR0,CAN->CAN_AMR0);		//�����������μĴ���
		CanWriteReg(AMR1,CAN->CAN_AMR1);
		CanWriteReg(AMR2,CAN->CAN_AMR2);
		CanWriteReg(AMR3,CAN->CAN_AMR3);

		CanWriteReg(ISR ,0xff);		//���жϱ�־
		CanWriteReg(IMR ,CAN->CAN_IMR);			//�жϼĴ�������
		CanWriteReg(MR  ,0x00);		//�˳� Reset Mode
	}
	else if(CANx == CAN2)
	{
		CANSEL = CAN2;		//ѡ��CAN2ģ��
		
		CanWriteReg(MR  ,0x04);		//ʹ�� Reset Mode

		if(CAN->CAN_Enable == ENABLE)	CAN2EN = 1;		//ʹ��CAN2ģ��
		else								CAN2EN = 0;		//�ر�CAN2ģ��
		
		CanWriteReg(BTR0,(uint8_t)((CAN->CAN_SJW << 6) + CAN->CAN_BRP));
		CanWriteReg(BTR1,(uint8_t)((CAN->CAN_SAM << 7) + (CAN->CAN_TSG2 << 4) + CAN->CAN_TSG1));

		CanWriteReg(ACR0,CAN->CAN_ACR0);		//�������մ���Ĵ���
		CanWriteReg(ACR1,CAN->CAN_ACR1);
		CanWriteReg(ACR2,CAN->CAN_ACR2);
		CanWriteReg(ACR3,CAN->CAN_ACR3);
		CanWriteReg(AMR0,CAN->CAN_AMR0);		//�����������μĴ���
		CanWriteReg(AMR1,CAN->CAN_AMR1);
		CanWriteReg(AMR2,CAN->CAN_AMR2);
		CanWriteReg(AMR3,CAN->CAN_AMR3);

		CanWriteReg(ISR ,0xff);		//���жϱ�־
		CanWriteReg(IMR ,CAN->CAN_IMR);			//�жϼĴ�������
		CanWriteReg(MR  ,0x00);		//�˳� Reset Mode
	}
}

//========================================================================
// ����: void CanReadFifo(uint8_t *pdat)
// ����: ��ȡCAN���������ݺ�����
// ����: *pdat: ���CAN����������.
// ����: none.
// �汾: VER1.0
// ����: 2020-11-16
// ��ע: 
//========================================================================
void CanReadFifo(uint8_t *pdat)
{
	pdat[0]  = CanReadReg(RX_BUF0);
	pdat[1]  = CanReadReg(RX_BUF1);
	pdat[2]  = CanReadReg(RX_BUF2);
	pdat[3]  = CanReadReg(RX_BUF3);

	pdat[4]  = CanReadReg(RX_BUF0);
	pdat[5]  = CanReadReg(RX_BUF1);
	pdat[6]  = CanReadReg(RX_BUF2);
	pdat[7]  = CanReadReg(RX_BUF3);

	pdat[8]  = CanReadReg(RX_BUF0);
	pdat[9]  = CanReadReg(RX_BUF1);
	pdat[10] = CanReadReg(RX_BUF2);
	pdat[11] = CanReadReg(RX_BUF3);

	pdat[12]  = CanReadReg(RX_BUF0);
	pdat[13]  = CanReadReg(RX_BUF1);
	pdat[14]  = CanReadReg(RX_BUF2);
	pdat[15]  = CanReadReg(RX_BUF3);
}

//========================================================================
// ����: uint16_t CanReadStandardFrame(uint8_t *pdat)
// ����: CAN��ȡ��׼֡������
// ����: *pdat: �������ݻ�����.
// ����: CAN ID.
// �汾: VER1.0
// ����: 2020-11-19
// ��ע: 
//========================================================================
uint16_t CanReadStandardFrame(uint8_t *pdat)
{
	uint8_t i;
	uint16_t CanID;
	uint8_t buffer[16];

	CanReadFifo(buffer);
	CanID = ((buffer[1] << 8) + buffer[2]) >> 5;
	for(i=0;i<8;i++)
	{
		pdat[i] = buffer[i+3];
	}
	return CanID;
}

//========================================================================
// ����: uint32_t CanReadExtendedFrame(uint8_t *pdat)
// ����: CAN��ȡ��չ֡������
// ����: *pdat: �������ݻ�����.
// ����: CAN ID.
// �汾: VER1.0
// ����: 2020-11-19
// ��ע: 
//========================================================================
uint32_t CanReadExtendedFrame(uint8_t *pdat)
{
	uint8_t i;
	uint32_t CanID;
	uint8_t buffer[16];

	CanReadFifo(buffer);
	CanID = (((uint32_t)buffer[1] << 24) + ((uint32_t)buffer[2] << 16) + ((uint32_t)buffer[3] << 8) + buffer[4]) >> 3;
	for(i=0;i<8;i++)
	{
		pdat[i] = buffer[i+5];
	}
	return CanID;
}

//========================================================================
// ����: void CanSendStandardFrame(uint16_t canid, uint8_t *pdat)
// ����: CAN���ͱ�׼֡������
// ����: canid: CAN ID; *pdat: �������ݻ�����.
// ����: none.
// �汾: VER1.0
// ����: 2020-11-19
// ��ע: 
//========================================================================
void CanSendStandardFrame(uint16_t canid, uint8_t *pdat)
{
	uint16_t CanID;

	CanID = canid << 5;
	CanWriteReg(TX_BUF0,0x08);	//bit7: ��׼֡(0)/��չ֡(1), bit6: ����֡(0)/Զ��֡(1), bit3~bit0: ���ݳ���(DLC)
	CanWriteReg(TX_BUF1,(uint8_t)(CanID>>8));
	CanWriteReg(TX_BUF2,(uint8_t)CanID);
	CanWriteReg(TX_BUF3,pdat[0]);

	CanWriteReg(TX_BUF0,pdat[1]);
	CanWriteReg(TX_BUF1,pdat[2]);
	CanWriteReg(TX_BUF2,pdat[3]);
	CanWriteReg(TX_BUF3,pdat[4]);

	CanWriteReg(TX_BUF0,pdat[5]);
	CanWriteReg(TX_BUF1,pdat[6]);
	CanWriteReg(TX_BUF2,pdat[7]);
	
	CanWriteReg(TX_BUF3,0x00);
	CanWriteReg(CMR ,0x04);		//����һ��֡����
}

//========================================================================
// ����: void CanSendExtendedFrame(uint32_t canid, uint8_t *pdat)
// ����: CAN������չ֡������
// ����: canid: CAN ID; *pdat: �������ݻ�����.
// ����: none.
// �汾: VER1.0
// ����: 2020-11-19
// ��ע: 
//========================================================================
void CanSendExtendedFrame(uint32_t canid, uint8_t *pdat)
{
	uint32_t CanID;

	CanID = canid << 3;
	CanWriteReg(TX_BUF0,0x88);	//bit7: ��׼֡(0)/��չ֡(1), bit6: ����֡(0)/Զ��֡(1), bit3~bit0: ���ݳ���(DLC)
	CanWriteReg(TX_BUF1,(uint8_t)(CanID>>24));
	CanWriteReg(TX_BUF2,(uint8_t)(CanID>>16));
	CanWriteReg(TX_BUF3,(uint8_t)(CanID>>8));

	CanWriteReg(TX_BUF0,(uint8_t)CanID);
	CanWriteReg(TX_BUF1,pdat[0]);
	CanWriteReg(TX_BUF2,pdat[1]);
	CanWriteReg(TX_BUF3,pdat[2]);

	CanWriteReg(TX_BUF0,pdat[3]);
	CanWriteReg(TX_BUF1,pdat[4]);
	CanWriteReg(TX_BUF2,pdat[5]);
	CanWriteReg(TX_BUF3,pdat[6]);

	CanWriteReg(TX_BUF0,pdat[7]);
	CanWriteReg(TX_BUF1,0x00);
	CanWriteReg(TX_BUF2,0x00);
	CanWriteReg(TX_BUF3,0x00);

	CanWriteReg(CMR ,0x04);		//����һ��֡����
}

