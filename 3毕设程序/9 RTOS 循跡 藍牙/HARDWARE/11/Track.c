#include "stm32f10x.h"                  // Device header
#include "PID.h"

void Track_Init(void)
{

 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitTypeDef GPIO_Initstruction;
	GPIO_Initstruction.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Initstruction.GPIO_Pin=GPIO_Pin_11|GPIO_Pin_12;
	GPIO_Initstruction.GPIO_Speed=GPIO_Speed_50MHz;    //����ģʽ������ٶ�û���ã����ٶ�ok
 GPIO_Init(GPIOA,&GPIO_Initstruction);
	
	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_Initstruction.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Initstruction.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_12 |  GPIO_Pin_14 | GPIO_Pin_0 | GPIO_Pin_15 | GPIO_Pin_13;
	GPIO_Initstruction.GPIO_Speed=GPIO_Speed_50MHz;    //����ģʽ������ٶ�û���ã����ٶ�ok
 GPIO_Init(GPIOB,&GPIO_Initstruction);
}

uint8_t L2 (void)
{
 return  GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_11);
}

uint8_t L1 (void)
{
 return  GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_12);
}

uint8_t M0 (void)
{
 return  GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1);
}

uint8_t R1 (void)
{
 return  GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12);
}

uint8_t R2 (void)
{
 return  GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_14);
}

void Patrol_Control(void)
{
  		if(     (L2 ()==0) && (L1 ()==1) && (M0()==1) && (R1()==1) && (R2()==0) )//�м�	
		{
		 pid.Sv=25;
		 pid.Sv2=25;
		}
		else if( (L2 ()==0) && (L1 ()==0) && (M0()==1) && (R1()==1) && (R2()==0) )//ƫ��
		{
		 pid.Sv=25;
		 pid.Sv2=5;
		}
		else if( (L2 ()==0) && (L1 ()==1) && (M0()==1) && (R1()==0) && (R2()==0) )//ƫ��
		{
		 pid.Sv=5;
		 pid.Sv2=25;
		}
		 else if( (L2 ()==1) && (L1 ()==1) && (M0()==0) && (R1()==0) && (R2()==0) )//ƫƫ��
		{
		 pid.Sv=5;
		 pid.Sv2=35;
		}
		else if( (L2 ()==0) && (L1 ()==0) && (M0()==0) && (R1()==1) && (R2()==1) )//ƫƫ��
		{
		 pid.Sv=35;
		 pid.Sv2=5;
		}
}

