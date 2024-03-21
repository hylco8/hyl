#include "stm32f10x.h"                  // Device header

void Timer_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE); //启用或禁用APB1 (Low Speed APB)外设时钟
	
	TIM_InternalClockConfig(TIM3);//配置TIM2内部时钟
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;//指定时钟分频
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; //指定计数器模式
	TIM_TimeBaseInitStructure.TIM_Period=100-1;//指定要加载到活动的周期值 在下一次更新事件时自动重新加载寄存器
	TIM_TimeBaseInitStructure.TIM_Prescaler=7200-1;//指定用于分频TIM时钟的预分频器值
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter=0;//指定重复计数器的值，该参数仅对TIM1和TIM8有效	
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStructure); //初始化TIMx时间基准单元外设
	
	TIM_ClearFlag(TIM3,TIM_FLAG_Update);/*清除TIMx的挂起标志，如不操作这个步骤，执行完上面程序就已经进入中断服务函数一次
	                                    (为解决预分频寄存器手动更新，导致中断标志位置set问题)*/
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);//启用或禁用指定的TIM中断
	
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//配置优先级分组:抢占优先级和子优先级
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel=TIM3_IRQn; //指定要启用或禁用的IRQ通道
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE; //是否为NVIC_IRQ通道中定义的IRQ通道是启用还是禁用
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=5; //指定IRQ通道的抢占优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0; //指定IRQ通道的子优先级
	NVIC_Init(&NVIC_InitStructure);	//初始化NVIC外设

    TIM_Cmd(TIM3,ENABLE);//启用或禁用指定的TIM外设(CK_CNT才有效~TIM计数器) 
}


//void TIM3_IRQHandler(void) //检查是否设置了指定的TIM标志
//{
//  if(TIM_GetITStatus(TIM3,TIM_IT_Update)==SET)//检查TIM中断是否发生
//  {

//   TIM_ClearITPendingBit(TIM3,TIM_IT_Update); //清除TIMx的中断挂起位
//  }
//}

