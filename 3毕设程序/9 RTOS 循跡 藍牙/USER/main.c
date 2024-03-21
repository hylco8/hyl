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
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);//设置系统中断优先级分组4	 
	delay_init();	    				//延时函数初始化	  
//	uart_init(115200);					//初始化串口
	LED_Init();		  					//初始化LED
	Key_Init();
	OLED_Init();
    PWM_Init();     //TIM1  A8、A9  10KHz Arr：7200-1
	Motor_Init(); 
    Timer_Init();  //TIM3  10MS进中断服务函数 抢占优先级5 子优先级0
	Encoder_Init(); //TIM2  A0、A1 
	Encoder2_Init();//TIM4  B6、B7
	PID_Init();
	Serial_Init();  //USART2 A2 A3 抢占优先级:6 子优先级:0
	
	OLED_ShowString(1,1,"Sv:");
	OLED_ShowString(2,1,"Sv2:");
    PWM_SetCompare1(1000);
    PWM_SetCompare2(1000);
	
	freertos_demo();
   
}

void TIM3_IRQHandler(void) //检查是否设置了指定的TIM标志
{
  if(TIM_GetITStatus(TIM3,TIM_IT_Update)==SET)//检查TIM中断是否发生
  {
    pid.Pv=Encoder_Get(); //闸门的时间 测速电机小一点，防止CNT溢出	 
    PID_Calc();  //pid计算
	PWM_SetCompare1(pid.OUT);
	  
	pid.Pv2=Encoder2_Get(); //闸门的时间 测速电机小一点，防止CNT溢出	 
    PID2_Calc();  //pid计算
	PWM_SetCompare2(pid.OUT2);
	  
	TIM_ClearITPendingBit(TIM3,TIM_IT_Update); //清除TIMx的中断挂起位
	MS10++;
  }
}

void PID_Init(void)
{
    pid.Sv=0;//用户设定转速
	pid.Kp=500;
	pid.T=1200;//PID计算周期
    pid.Ti=1000000;//积分时间
	
    pid.Sv2=0;//用户设定转速
	pid.Kp2=500;
	pid.T2=1200;//PID计算周期
    pid.Ti2=1000000;//积分时间
	
	pid.pwmcycle=7200;//pwm周期1000
}
