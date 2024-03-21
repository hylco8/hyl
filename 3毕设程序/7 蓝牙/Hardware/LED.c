#include "stm32f10x.h"                  // Device header

/*LED的A1 A2两个GPIO口初始化*/
void LED_Init(void)
{
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE); 
	
 GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_1|GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
 GPIO_Init(GPIOA,&GPIO_InitStructure);
	
 GPIO_SetBits(GPIOA,GPIO_Pin_1|GPIO_Pin_2);
}


/*点亮LED1*/
void LED1_ON(void)
{
GPIO_ResetBits(GPIOA,GPIO_Pin_1);
}
/*熄灭LED1*/
void LED1_OFF(void)
{
 GPIO_SetBits(GPIOA,GPIO_Pin_1);
}
/*LED1翻转*/
void LED1_Turn(void)
{
 if(GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_1)==0)
 {
  GPIO_SetBits(GPIOA,GPIO_Pin_1);
 }
 else
 {
  GPIO_ResetBits(GPIOA,GPIO_Pin_1);
 }
}


/*点亮LED2*/
void LED2_ON(void)
{
GPIO_ResetBits(GPIOA,GPIO_Pin_2);
}
/*熄灭LED2*/
void LED2_OFF(void)
{
 GPIO_SetBits(GPIOA,GPIO_Pin_2);
}
/*LED2翻转*/
void LED2_Turn(void)
{
 if(GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_2)==0)
 {
  GPIO_SetBits(GPIOA,GPIO_Pin_2);
 }
 else
 {
  GPIO_ResetBits(GPIOA,GPIO_Pin_2);
 }
}
