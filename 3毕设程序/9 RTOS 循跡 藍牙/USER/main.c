#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "FreeRTOS.h"
#include "task.h"
#include "freertos_demo.h"
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

void PID_Init(void);
uint16_t MS10;
int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);//����ϵͳ�ж����ȼ�����4	 
	delay_init();	    				//��ʱ������ʼ��	  
//	uart_init(115200);					//��ʼ������
	LED_Init();		  					//��ʼ��LED
	Key_Init();
	OLED_Init();
    PWM_Init();     //TIM1  A8��A9  10KHz Arr��7200-1
	Motor_Init(); 
    Timer_Init();  //TIM3  10MS���жϷ����� ��ռ���ȼ�5 �����ȼ�0
	Encoder_Init(); //TIM2  A0��A1 
	Encoder2_Init();//TIM4  B6��B7
	PID_Init();
	Serial_Init();  //USART2 A2 A3 ��ռ���ȼ�:6 �����ȼ�:0
	
	OLED_ShowString(1,1,"Sv:");
	OLED_ShowString(2,1,"Sv2:");
    PWM_SetCompare1(1000);
    PWM_SetCompare2(1000);
	
	freertos_demo();
   
}

void TIM3_IRQHandler(void) //����Ƿ�������ָ����TIM��־
{
  if(TIM_GetITStatus(TIM3,TIM_IT_Update)==SET)//���TIM�ж��Ƿ���
  {
    pid.Pv=Encoder_Get(); //բ�ŵ�ʱ�� ���ٵ��Сһ�㣬��ֹCNT���	 
    PID_Calc();  //pid����
	PWM_SetCompare1(pid.OUT);
	  
	pid.Pv2=Encoder2_Get(); //բ�ŵ�ʱ�� ���ٵ��Сһ�㣬��ֹCNT���	 
    PID2_Calc();  //pid����
	PWM_SetCompare2(pid.OUT2);
	  
	TIM_ClearITPendingBit(TIM3,TIM_IT_Update); //���TIMx���жϹ���λ
	MS10++;
  }
}

void PID_Init(void)
{
    pid.Sv=0;//�û��趨ת��
	pid.Kp=500;
	pid.T=1200;//PID��������
    pid.Ti=1000000;//����ʱ��
	
    pid.Sv2=0;//�û��趨ת��
	pid.Kp2=500;
	pid.T2=1200;//PID��������
    pid.Ti2=1000000;//����ʱ��
	
	pid.pwmcycle=7200;//pwm����1000
}
