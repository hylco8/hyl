#include "stm32f10x.h"                  // Device header

void PWM_Init(void)
{
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1,ENABLE); //启用或禁用APB1 (Low Speed APB)外设时钟
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE); 

		GPIO_InitTypeDef GPIO_InitStructure;
		GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP; //按照流程原本是后面的步骤
		GPIO_InitStructure.GPIO_Pin=GPIO_Pin_8|GPIO_Pin_9;
		GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
		GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	TIM_InternalClockConfig(TIM1);//配置TIM1内部时钟
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;//指定时钟分频
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; //指定计数器模式
	TIM_TimeBaseInitStructure.TIM_Period=7200-1;//指定要加载到活动的周期值 在下一次更新事件时自动重新加载寄存器 ARR
	TIM_TimeBaseInitStructure.TIM_Prescaler=1-1;//指定用于分频TIM时钟的预分频器值 PSC
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter=0;//指定重复计数器的值，该参数仅对TIM1和TIM8有效	
	TIM_TimeBaseInit(TIM1,&TIM_TimeBaseInitStructure); //初始化TIMx时间基准单元外设
	
	TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_OCStructInit(&TIM_OCInitStructure);
	TIM_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM1;//指定TIM模式
	TIM_OCInitStructure.TIM_OCPolarity=TIM_OCPolarity_High; //指定输出极性
	TIM_OCInitStructure.TIM_OutputState=TIM_OutputState_Enable;//指定TIM输出比较状态
	TIM_OCInitStructure.TIM_Pulse=0;//指定要加载到捕获比较寄存器(CCR)中的脉冲值 CCR
	TIM_OC1Init(TIM1,&TIM_OCInitStructure);

	TIM_OC2Init(TIM1,&TIM_OCInitStructure);
	//初始化TIMx通道1，根据指定参数在TIM_OCInitStruct

    TIM_CtrlPWMOutputs(TIM1,ENABLE);
    TIM_Cmd(TIM1,ENABLE);//启用或禁用指定的TIM外设(CK_CNT才有效~TIM计数器) 
}

void PWM_SetCompare1(uint16_t Compare1)
{
 TIM_SetCompare1(TIM1,Compare1);
}
void PWM_SetCompare2(uint16_t Compare2)
{
 TIM_SetCompare2(TIM1,Compare2);
}


