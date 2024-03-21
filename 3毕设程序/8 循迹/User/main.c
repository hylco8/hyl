#include "stm32f10x.h"                  // Device header
#include "Delay.h."
#include "OLED.h"
#include "Timer.h"
#include "Encoder.h"
#include "Encoder2.h"
#include "PWM.h"
#include "Motor.h"
#include "PID.h"
#include "sys.h"
#include "Track.h"

void PID_Init(void);

int main(void)
{
	OLED_Init();
    Timer_Init();   //TIM3         10MS进一次中断服务函数
	Encoder_Init(); //TIM2  A0、A1 
	Encoder2_Init();//TIM4  B6、B7
    PWM_Init();     //TIM1  A8、A9  10KHz Arr：7200-1
	Motor_Init(); 
	PID_Init();
	Track_Init();
	
	OLED_ShowString(1,1,"Sv:");
	OLED_ShowString(2,1,"Sv2:");	
	OLED_ShowSignedNum(1,5,pid.Sv,2);
    OLED_ShowSignedNum(2,5,pid.Sv2,2);
	
    PWM_SetCompare1(3600);
    PWM_SetCompare2(3600);
	
   while(1)
   {
        Patrol_Control();
		OLED_ShowSignedNum(1,5,pid.Sv,2);
        OLED_ShowSignedNum(2,5,pid.Sv2,2);
   }
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
  }
}

void PID_Init(void)
{
    pid.Sv=0;//用户设定10MS转速
	pid.Kp=500;
	pid.T=1200;//PID计算周期
    pid.Ti=1000000;//积分时间
	
    pid.Sv2=0;//用户设定10MS转速
	pid.Kp2=500;
	pid.T2=1200;//PID计算周期
    pid.Ti2=1000000;//积分时间
	
	pid.pwmcycle=7200;//pwm周期1000
}
/*
定时器：TIM4 定时10ms进入中断一次--采样pid.Pv、计算pid.OUT、并把pid.OUT放进去PWM_SetCompare3(pid.OUT);
PWM: TIM2  ARR:7200-1 PCB:1-1  10KHz
Encoder：Tim3 CH1 CH2
*/
