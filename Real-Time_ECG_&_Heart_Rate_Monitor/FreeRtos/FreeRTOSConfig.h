/*
 * FreeRTOS V202212.01
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
 * https://www.FreeRTOS.org
 * https://github.com/FreeRTOS
 *
 */


/* The following #error directive is to remind users that a batch file must be
 * executed prior to this project being built.  The batch file *cannot* be
 * executed from within CCS4!  Once it has been executed, re-open or refresh
 * the CCS4 project and remove the #error line below.
 */
//#error Ensure CreateProjectDirectoryStructure.bat has been executed before building.  See comment immediately above.

#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

/*-----------------------------------------------------------
 * Application-specific definitions.
 *----------------------------------------------------------*/

/* CPU Clock */
#define configCPU_CLOCK_HZ              ( 84000000UL )  /* 84 MHz */
#define configTICK_RATE_HZ              ( ( TickType_t ) 1000 )  /* 1 ms tick */

/* Task Management */
#define configUSE_PREEMPTION            1
#define configUSE_TIME_SLICING          1
#define configMAX_PRIORITIES            ( 5 )
#define configMINIMAL_STACK_SIZE        ( ( unsigned short ) 128 )
#define configTOTAL_HEAP_SIZE           ( ( size_t ) ( 10 * 1024 ) ) /* 10 KB Heap */
#define configMAX_TASK_NAME_LEN         ( 10 )

/* Hook Functions */
#define configUSE_IDLE_HOOK             0
#define configUSE_TICK_HOOK             0
#define configUSE_MALLOC_FAILED_HOOK    1
#define configCHECK_FOR_STACK_OVERFLOW  2  /* Enable Stack Overflow Checking */

/* Software Timer Definitions */
#define configUSE_TIMERS                1
#define configTIMER_TASK_PRIORITY       ( 3 )
#define configTIMER_QUEUE_LENGTH        5
#define configTIMER_TASK_STACK_DEPTH    ( configMINIMAL_STACK_SIZE * 2 ) /* Increased Stack Depth */
#define configUSE_16_BIT_TICKS  0  // Set to 1 if using a 16-bit timer, otherwise 0

/* Synchronization */
#define configUSE_MUTEXES               1
#define configUSE_RECURSIVE_MUTEXES     1
#define configQUEUE_REGISTRY_SIZE       5

/* Run-time Statistics */
#define configUSE_TRACE_FACILITY        1
#define configGENERATE_RUN_TIME_STATS   0

/* API Inclusions */
#define INCLUDE_vTaskPrioritySet        1
#define INCLUDE_uxTaskPriorityGet       1
#define INCLUDE_vTaskDelete             1
#define INCLUDE_vTaskCleanUpResources   0
#define INCLUDE_vTaskSuspend            1
#define INCLUDE_vTaskDelayUntil         1
#define INCLUDE_vTaskDelay              1

/* Cortex-M4 Interrupt Configuration */
#ifdef __NVIC_PRIO_BITS
    #define configPRIO_BITS             __NVIC_PRIO_BITS
#else
    #define configPRIO_BITS             4  /* 15 priority levels */
#endif

#define configLIBRARY_LOWEST_INTERRUPT_PRIORITY         15
#define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY    5

#define configKERNEL_INTERRUPT_PRIORITY    ( configLIBRARY_LOWEST_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )
#define configMAX_SYSCALL_INTERRUPT_PRIORITY  ( configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )

/* Assertion */
#define configASSERT( x ) if( ( x ) == 0 ) { taskDISABLE_INTERRUPTS(); for( ;; ); }

/* FreeRTOS Handlers */
#define vPortSVCHandler    SVC_Handler
#define xPortPendSVHandler PendSV_Handler
#define xPortSysTickHandler SysTick_Handler

#endif /* FREERTOS_CONFIG_H */
