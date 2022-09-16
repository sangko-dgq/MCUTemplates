
/*
 * FreeRTOS STC port V1.0.2
 * 
 * STC32G12K128���ܼ�飺
 *    2�� CAN, 3��Lin, USB, 32λ 8051, RMB5,
 *    �߾�׼12λADC, DMA ֧��(TFT����, ADC, 4�鴮��, SPI, I2C )
 *  
 *  ��λ�û��ں�����ʹ�ù����У���������в���ȷ�ĵط�����
 *  �пɸ��Ƶĵط������STC��ϵ����STC�ٷ�����ͳһ�޸Ĳ����°汾
 *
 *  �����Ĵ������������Ҫ���ñ�������еĲ�����ֲ���룬��������
 *  �����������ע���ο���ʹ����STC��FreeRTOS����ֲ����
*/

#include "FreeRTOS.h"
#include "task.h"
#include "System_init.h"

#include "display.h"
#include "rtc.h"
#include "ntc.h"
#include "adckey.h"
#include "uart2_3.h"
#include "MatrixKey.h"
#include "i2c_ps.h"
#include "pwmb.h"

void vSystemInit( void );

void main( void )
{
    /* ϵͳ��ʼ�� */
    vSystemInit();

	/* �������� */
    xTaskCreate((TaskFunction_t )vDisplayTask,
                (const char*    )"DISPLAY",
                (uint16_t       )configDEFAULT_STACK_SIZE,
                (void*          )NULL,
                (UBaseType_t    )(configDEFAULT_PRIORITIES + 1),
                (TaskHandle_t*  )NULL);
    xTaskCreate((TaskFunction_t )vRtcTask,
                (const char*    )"RTC",
                (uint16_t       )configDEFAULT_STACK_SIZE,
                (void*          )NULL,
                (UBaseType_t    )(configDEFAULT_PRIORITIES + 1),
                (TaskHandle_t*  )NULL);
    xTaskCreate((TaskFunction_t )vAdcKeyTask,
                (const char*    )"ADCKEY",
                (uint16_t       )configDEFAULT_STACK_SIZE,
                (void*          )NULL,
                (UBaseType_t    )(configDEFAULT_PRIORITIES),
                (TaskHandle_t*  )NULL);
    xTaskCreate((TaskFunction_t )vNtcTask,
                (const char*    )"NTC",
                (uint16_t       )configDEFAULT_STACK_SIZE,
                (void*          )NULL,
                (UBaseType_t    )(configDEFAULT_PRIORITIES),
                (TaskHandle_t*  )NULL);
    xTaskCreate((TaskFunction_t )vUart2_3Task,
                (const char*    )"UART2_3",
                (uint16_t       )configDEFAULT_STACK_SIZE,
                (void*          )1000,  //ע��pvParameters��������ַ����������ʱֻ�е�24λ����Чλ�����8λ����ʱ���Զ���0. ��ͨ���������߳�������32�ֽ�����.
                (UBaseType_t    )(configDEFAULT_PRIORITIES),
                (TaskHandle_t*  )NULL);
    xTaskCreate((TaskFunction_t )vMatrixKeyTask,
                (const char*    )"MatrixKey",
                (uint16_t       )configDEFAULT_STACK_SIZE,
                (void*          )NULL,
                (UBaseType_t    )(configDEFAULT_PRIORITIES),
                (TaskHandle_t*  )NULL);
    xTaskCreate((TaskFunction_t )vI2C_PsTask,
                (const char*    )"I2C_PS",
                (uint16_t       )configDEFAULT_STACK_SIZE,
                (void*          )NULL,
                (UBaseType_t    )(configDEFAULT_PRIORITIES),
                (TaskHandle_t*  )NULL);
    xTaskCreate((TaskFunction_t )vPWMB_LedTask,
                (const char*    )"PWMB_LED",
                (uint16_t       )configDEFAULT_STACK_SIZE,
                (void*          )NULL,
                (UBaseType_t    )(configDEFAULT_PRIORITIES),
                (TaskHandle_t*  )NULL);

    /* ���������������ʼ������� */
    vTaskStartScheduler();

    /* ��������²������е��˴� */
    while (1);
}
