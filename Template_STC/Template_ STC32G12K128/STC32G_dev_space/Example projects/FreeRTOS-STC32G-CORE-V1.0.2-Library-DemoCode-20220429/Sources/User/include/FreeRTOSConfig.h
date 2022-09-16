/*
 * FreeRTOS V202112.00
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://www.FreeRTOS.org
 * http://aws.amazon.com/freertos
 *
 * 1 tab == 4 spaces!
 */

#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#include "stc32g.h"
#include "intrins.h"

/*-----------------------------------------------------------
 * Application specific definitions.
 *
 * These definitions should be adjusted for your particular hardware and
 * application requirements.
 *
 * THESE PARAMETERS ARE DESCRIBED WITHIN THE 'CONFIGURATION' SECTION OF THE
 * FreeRTOS API DOCUMENTATION AVAILABLE ON THE FreeRTOS.org WEB SITE.
 *
 * See http://www.freertos.org/a00110.html
 *----------------------------------------------------------*/

/*-----------------------------------------------------------
 * �汾������ʷ
 *
 * V1.0.2 (2022-4-27)
 *     �����������pvParameters��ʼѹջ���������
 *     (ע��pvParameters��������ַ����������ʱֻ�е�24λ����Чλ�����8λ����ʱ���Զ���0)
 *
 * V1.0.1 (2022-4-26)
 *     �����޷�����ʹ��xdata������
 *
 * V1.0.0 (2022-4-24)
 *     ��ֲ�ɹ�����������
 *----------------------------------------------------------*/


/***************************************************************************************************************/
/*                                        STC32-251������������ѡ��                                            */
/***************************************************************************************************************/
#define configPORT_VERSION_NUMBER               "V1.0.2"                //STC��ֲ����汾

#define configUSE_ROMHUGE                       0                       //1 ROMʹ��HUGEģʽ��0ʹ��LARGEģʽ
#define MAIN_Fosc                               ( 24000000UL )          //ϵͳ����Ƶ��

#if ( configUSE_ROMHUGE == 0 )
    #pragma ROM ( LARGE )
#else
    #pragma ROM ( HUGE )
#endif

#pragma WARNING DISABLE = 47                                            //�ر�47�ž���: unreferenced local variable
#pragma WARNING DISABLE = 138                                           //�ر�138�ž���: expression with possibly no effect
#pragma WARNING DISABLE = 183                                           //�ر�183�ž���: dead assignment eliminated

#ifndef configUSE_ROMHUGE
    #error Missing definition:  configUSE_ROMHUGE must be defined in FreeRTOSConfig.h as either 1 or 0.
#endif

//#define UNUSED(expr)      (void)(expr)
#define UNUSED(expr)        if ((expr) == 0)


/***************************************************************************************************************/
/*                                        FreeRTOS������������ѡ��                                             */
/***************************************************************************************************************/

#define configUSE_PREEMPTION                    1                       //1ʹ����ռʽ�ںˣ�0ʹ��Э��
#define configUSE_TIME_SLICING                  1                       //1ʹ��ʱ��Ƭ����(Ĭ��ʽʹ�ܵ�)
#define configUSE_PORT_OPTIMISED_TASK_SELECTION	0                       //1�������ⷽ����ѡ����һ��Ҫ���е�����
                                                                        //һ����Ӳ������ǰ����ָ������ʹ�õ�
                                                                        //MCUû����ЩӲ��ָ��Ļ��˺�Ӧ������Ϊ0��
#define configUSE_TICKLESS_IDLE                 0                       //1���õ͹���ticklessģʽ
#define configUSE_QUEUE_SETS                    0                       //Ϊ1ʱ���ö���
#define configCPU_CLOCK_HZ                      (MAIN_Fosc)             //CPUƵ��
#define configTICK_RATE_HZ                      ((TickType_t)1000)      //ʱ�ӽ���Ƶ�ʣ���������Ϊ1000,���ھ���1ms
#define configMAX_PRIORITIES                    (32)                    //��ʹ�õ�������ȼ�
#define configDEFAULT_PRIORITIES                (tskIDLE_PRIORITY + 1)  //����Ĭ�����ȼ�
#define configMINIMAL_STACK_SIZE                ((unsigned short)256)   //��������ʹ�õĶ�ջ��С
#define configDEFAULT_STACK_SIZE                ((unsigned short)128)   //����Ĭ�϶�ջ��С
#define configMAX_TASK_NAME_LEN                 (8)                     //���������ַ�������
#define configUSE_IDLE_HOOK						0                       //1ʹ�ÿ��й���,0��ʹ�� /*void vApplicationIdleHook( void );*/
#define configUSE_TICK_HOOK						0                       //1ʹ��ʱ��Ƭ����,0��ʹ�� /*void vApplicationTickHook( void );*/
#define configSUPPORT_DYNAMIC_ALLOCATION        1                       //֧�ֶ�̬�ڴ�����
#define configTOTAL_HEAP_SIZE					((size_t)(2*1024))     // ϵͳ�����ܵĶѴ�С

#define configUSE_16_BIT_TICKS                  0                       //ϵͳ���ļ����������������ͣ�
                                                                        //1��ʾΪ16λ�޷������Σ�0��ʾΪ32λ�޷�������
#define configIDLE_SHOULD_YIELD                 1                       //Ϊ1ʱ�����������CPUʹ��Ȩ������ͬ���ȼ����û�����
#define configUSE_TASK_NOTIFICATIONS            1                       //Ϊ1ʱ��������֪ͨ���ܣ�Ĭ�Ͽ���
#define configUSE_MUTEXES                       1                       //Ϊ1ʱʹ�û����ź���
#define configQUEUE_REGISTRY_SIZE               0                       //��Ϊ0ʱ��ʾ���ö��м�¼�������ֵ�ǿ���
                                                                        //��¼�Ķ��к��ź��������Ŀ��
#define configCHECK_FOR_STACK_OVERFLOW          0                       //����0ʱ���ö�ջ�����⹦�ܣ����ʹ�ô˹���
                                                                        //�û������ṩһ��ջ������Ӻ��������ʹ�õĻ�
                                                                        //��ֵ����Ϊ1����2����Ϊ������ջ�����ⷽ����
#define configUSE_RECURSIVE_MUTEXES             0                       //Ϊ1ʱʹ�õݹ黥���ź���
#define configUSE_MALLOC_FAILED_HOOK            0                       //1ʹ���ڴ�����ʧ�ܹ��Ӻ���
#define configUSE_APPLICATION_TASK_TAG          0
#define configUSE_COUNTING_SEMAPHORES           0                       //Ϊ1ʱʹ�ü����ź���

#define configGENERATE_RUN_TIME_STATS	        0                       //Ϊ1ʱ��������ʱ��ͳ�ƹ���
#define configUSE_TRACE_FACILITY				0                       //Ϊ1���ÿ��ӻ����ٵ���
#define configUSE_STATS_FORMATTING_FUNCTIONS	0                       //���configUSE_TRACE_FACILITYͬʱΪ1ʱ���������3������
                                                                        //prvWriteNameToBuffer(),vTaskList(),
                                                                        //vTaskGetRunTimeStats()
/* Co-routine definitions. */
#define configUSE_CO_ROUTINES 			        0                       //Ϊ1ʱ����Э�̣�����Э���Ժ��������ļ�croutine.c
#define configMAX_CO_ROUTINE_PRIORITIES         (2)                     //Э�̵���Ч���ȼ���Ŀ

/* Set the following definitions to 1 to include the API function, or zero
to exclude the API function. */

#define INCLUDE_xTaskGetSchedulerState          0
#define INCLUDE_vTaskPrioritySet                1
#define INCLUDE_uxTaskPriorityGet               1
#define INCLUDE_vTaskDelete                     1
#define INCLUDE_vTaskCleanUpResources           0
#define INCLUDE_vTaskSuspend                    1
#define INCLUDE_vTaskDelayUntil                 1
#define INCLUDE_vTaskDelay                      1
#define INCLUDE_eTaskGetState                   0
#define INCLUDE_xTimerPendFunctionCall          0



#endif /* FREERTOS_CONFIG_H */
