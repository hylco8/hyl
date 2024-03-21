#include "stm32f10x.h"                  // Device header


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

//void Set_MotorSpeed(int8_t Speed)
//{
// if(Speed>=0)
// {
//  GPIO_ResetBits(GPIOA,GPIO_Pin_4);
//  GPIO_SetBits(GPIOA,GPIO_Pin_5);
// }
// else
// {
//  GPIO_SetBits(GPIOA,GPIO_Pin_4);
//  GPIO_ResetBits(GPIOA,GPIO_Pin_5);
//	Speed=-Speed; 
// }
// PWM_SetCompare3(Speed);
//}
