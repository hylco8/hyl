#include "stm32f10x.h"                  // Device header

void Encoder_Init(void)
{
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE); //启用或禁用APB1 (Low Speed APB)外设时钟
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE); 

		GPIO_InitTypeDef GPIO_InitStructure;
		GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU; //按照流程原本是后面的步骤
		GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0|GPIO_Pin_1;
		GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
		GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;//指定时钟分频 分频后频率为滤波器的采样频率
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; //指定计数器模式
	TIM_TimeBaseInitStructure.TIM_Period=65536-1;//指定要加载到活动的周期值 在下一次更新事件时自动重新加载寄存器 ARR
	TIM_TimeBaseInitStructure.TIM_Prescaler=1-1;//指定用于分频TIM时钟的预分频器值 PSC
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter=0;//指定重复计数器的值，该参数仅对TIM1和TIM8有效	
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStructure); //初始化TIMx时间基准单元外设
	
	TIM_ICInitTypeDef  TIM_ICInitStructrue;
	TIM_ICStructInit(&TIM_ICInitStructrue);//用默认值填充每个TIM_ICInitStruct成员
	TIM_ICInitStructrue.TIM_Channel=TIM_Channel_1;//指定TIM通道
	TIM_ICInitStructrue.TIM_ICFilter=0xF; //指定输入捕获过滤器
	TIM_ICInit(TIM2,&TIM_ICInitStructrue);//初始化TIM外设
		TIM_ICInitStructrue.TIM_Channel=TIM_Channel_2;//指定TIM通道
		TIM_ICInitStructrue.TIM_ICFilter=0xF; //指定输入捕获过滤器
		TIM_ICInit(TIM2,&TIM_ICInitStructrue);//初始化TIM外设
		
	TIM_EncoderInterfaceConfig(TIM2,TIM_EncoderMode_TI12,TIM_ICPolarity_Rising,TIM_ICPolarity_Rising);//配置TIMx编码器接口
		                                                                                              //Rising~就是通道不反向
	TIM_Cmd(TIM2,ENABLE);//启用或禁用指定的TIM外设																								  
}

int16_t Encoder_Get(void)//reference参考
{
    int16_t Temp;
	Temp=TIM_GetCounter(TIM2);
	TIM_SetCounter(TIM2,0);
	return Temp;
}

