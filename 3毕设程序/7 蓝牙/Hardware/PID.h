#ifndef __PID_
#define __PID_
#include "stm32f10x.h"                  // Device header

typedef struct
{
 float Sv;//用户设定值
 float Pv;
	
 float Kp;
 float T;  //PID计算周期--采样周期
 float Ti;
	
 float Ek;  //本次偏差
 float SEk; //历史偏差之和
	
	float Iout;
	float Pout;

 uint16_t OUT;


/********/
 float Sv2;//用户设定值
 float Pv2;
	
 float Kp2;
 float T2;  //PID计算周期--采样周期
 float Ti2;
	
 float Ek2;  //本次偏差
 float SEk2; //历史偏差之和
	
	float Iout2;
	float Pout2;

 uint16_t OUT2;
 
 u16 pwmcycle;//pwm周期
}PID;

extern PID pid; //存放PID算法所需要的数据
void PID_Calc(void);  //pid计算
void PID2_Calc(void);  //pid计算



#endif
