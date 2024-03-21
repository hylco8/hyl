#include "stm32f10x.h"                  // Device header
#include "PID.h"

void Motor_Init(void)
{

	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE); 
		
	 GPIO_InitTypeDef GPIO_InitStructure;
		GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
		GPIO_InitStructure.GPIO_Pin=GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;
		GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	 GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	  GPIO_ResetBits(GPIOA,GPIO_Pin_4);
      GPIO_SetBits(GPIOA,GPIO_Pin_5);
	
	  GPIO_ResetBits(GPIOA,GPIO_Pin_6);
      GPIO_SetBits(GPIOA,GPIO_Pin_7);
}

void Turnfront(void)
{
	 pid.Sv += 10;
	 pid.Sv2 +=10;	
}

void Turnback(void)
{
	pid.Sv -= 10;
	pid.Sv2 -=10;	
	
	if((pid.Sv<10)||(pid.Sv2<10)) //Sv_Control
	{
	 pid.Sv =10;
	 pid.Sv2=10;
	}
}

void Turnleft(void)
{
	 pid.Sv -= 5;
	 pid.Sv2 =pid.Sv2;
}

void Turnright(void)
{
	 pid.Sv  = pid.Sv;
	 pid.Sv2 -=5;		
}
void Stop(void)
{
  	 pid.Sv  = 0;
	 pid.Sv2 = 0;
}

void Leftaround(void);
void Rightaround(void);

