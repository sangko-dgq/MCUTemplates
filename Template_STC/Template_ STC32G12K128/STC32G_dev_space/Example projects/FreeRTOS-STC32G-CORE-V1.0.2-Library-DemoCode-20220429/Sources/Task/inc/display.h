
#ifndef DISPLAY_H
#define DISPLAY_H

#define DIS_DOT     0x20
#define DIS_BLACK   0x10
#define DIS_        0x11


/* ��ʾ������ */
portTASK_FUNCTION( vDisplayTask, pvParameters );

extern uint8_t pucLEDBuffer[8];                         //��ʾ����


#endif
