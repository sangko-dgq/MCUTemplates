
#ifndef RTC_H
#define RTC_H


/* RTC������ */
portTASK_FUNCTION( vRtcTask, pvParameters );

void vRtcUpdateDisplay( void );

extern uint8_t ucHour;                                  //RTC����(ʱ)
extern uint8_t ucMinute;                                //RTC����(��)
extern uint8_t ucSecond;                                //RTC����(��)


#endif
