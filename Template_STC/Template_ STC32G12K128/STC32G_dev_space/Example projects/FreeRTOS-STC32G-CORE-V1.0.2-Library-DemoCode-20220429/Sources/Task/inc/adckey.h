
#ifndef ADCKEY_H
#define ADCKEY_H


/* ADC����ɨ�������� */
portTASK_FUNCTION( vAdcKeyTask, pvParameters );


extern uint8_t ucKeyCode;                               //���û�ʹ�õļ���, 1~16��Ч

#endif
