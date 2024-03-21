#include "stm32f10x.h"                  // Device header
#include "delay.h"
#include "Key.h"

void Key_Init(void)
{
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitTypeDef GPIO_Initstruction;
	GPIO_Initstruction.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Initstruction.GPIO_Pin=GPIO_Pin_15;
	GPIO_Initstruction.GPIO_Speed=GPIO_Speed_50MHz;    //输入模式，这个速度没有用，多少都ok
 GPIO_Init(GPIOB,&GPIO_Initstruction);
}

uint8_t Key_GetNum(void)
{
 uint8_t Key_Num=0;
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_15)==0)
	{
	 delay_ms(20);
	 while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_15)==0);
	 delay_ms(20);
	 Key_Num=1;
	}
	return Key_Num;
}
