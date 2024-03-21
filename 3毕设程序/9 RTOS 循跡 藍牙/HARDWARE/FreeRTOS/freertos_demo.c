#include "freertos_demo.h"
#include "FreeRTOS.h"
#include "task.h"
#include "led.h"
#include "Key.h"
#include "OLED.h"
#include "Timer.h"
#include "Encoder.h"
#include "Encoder2.h"
#include "PWM.h"
#include "Motor.h"
#include "PID.h"
#include "Serial.h"
#include "Track.h"

extern uint16_t MS10;

#define START_TASK_PRIO        1
#define START_TASK_STACK_SIZE  128
TaskHandle_t start_task_handler;
void start_task( void * pvParameters );

#define TASK1_PRIO             3
#define TASK1_STACK_SIZE       128
TaskHandle_t  task1_handler;
void task1( void * pvParameters );

#define TASK2_PRIO             3
#define TASK2_STACK_SIZE       128
TaskHandle_t  task2_handler;
void task2( void * pvParameters );

#define TASK3_PRIO             4
#define TASK3_STACK_SIZE       128
TaskHandle_t  task3_handler;
void task3( void * pvParameters );

void freertos_demo(void)
{
   	 xTaskCreate((TaskFunction_t) start_task,
				(char *         ) "start_task",
				(uint16_t       ) START_TASK_STACK_SIZE,
				 (void *        ) NULL,
				 (UBaseType_t   ) START_TASK_PRIO,
				 (TaskHandle_t *) &start_task_handler );
	 vTaskStartScheduler(  );
}

void start_task( void * pvParameters )
{
	 taskENTER_CRITICAL();               /* 进入临界区 ~portDISABLE_INTERRUPTS();*/
   	 xTaskCreate((TaskFunction_t) task1,
				(char *         ) "task1",
				(uint16_t       ) TASK1_STACK_SIZE,
				 (void *        ) NULL,
				 (UBaseType_t   ) TASK1_PRIO,
				 (TaskHandle_t *) &task1_handler );
				
   	 xTaskCreate((TaskFunction_t) task2,
				(char *         ) "task2",
				(uint16_t       ) TASK2_STACK_SIZE,
				 (void *        ) NULL,
				 (UBaseType_t   ) TASK2_PRIO,
				 (TaskHandle_t *) &task2_handler );	
				 
   	 xTaskCreate((TaskFunction_t) task3,
				(char *         ) "task3",
				(uint16_t       ) TASK3_STACK_SIZE,
				 (void *        ) NULL,
				 (UBaseType_t   ) TASK3_PRIO,
				 (TaskHandle_t *) &task3_handler );
	vTaskSuspend(task1_handler); /*挂起task1*/
    vTaskDelete(NULL);
    taskEXIT_CRITICAL();                /* 退出临界区 portENABLE_INTERRUPTS();*/				 
}

void  task1( void * pvParameters )
{
  while(1)
  {
    Patrol_Control(); //循迹
  }
}

void  task2( void * pvParameters )
{
  while(1)
  {
	 if(Serial_RxFlag==1)
	 {
		switch ( Serial_RxPacket[0] )
			 {
				 case 'U':  
				 Turnfront();
				 break;
					
				 case 'D':
                 Turnback();
				 break;
					
				 case 'L':
	             Turnleft();
                 MS10=0;				 
		         break;
				 
				 case 'R':
                 Turnright();		 			 
				 MS10=0;
		         break;
				 
				 case 'O':
				 Stop();
		         break;				 		
			 }		 
		Serial_RxFlag=0;  
		Serial_SendString("R_OK\r\n");
      }
	 if(MS10==200)
	 {
	  if(pid.Sv>pid.Sv2)
		  pid.Sv2 = pid.Sv;
	  else
		  pid.Sv = pid.Sv2;
	   MS10=0;
	 }
  }
}

void  task3( void * pvParameters )
{ uint8_t Key_Num;
  static uint8_t Key_Count=0;
  while(1)
  {
	 Key_Num=Key_GetNum();  
	 if(Key_Num==1)
	 {
		  if(Key_Count==0) 	 
		  {
			pid.Sv=0;//用户设定转速
			pid.Sv2=0;//用户设定转速
			vTaskSuspend(task2_handler); /*挂起task2*/
			vTaskResume(task1_handler);  
			Key_Count=1;
		  }
		   else 
		   {
			   pid.Sv=0;//用户设定转速
			   pid.Sv2=0;//用户设定转速
			   vTaskSuspend(task1_handler);
			   vTaskResume(task2_handler);
			   Key_Count=0;   
		   }  
	  }
	   OLED_ShowSignedNum(1,5,pid.Sv,2);
       OLED_ShowSignedNum(2,5,pid.Sv2,2);
		 
       vTaskDelay(100);
  }
}

