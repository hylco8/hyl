#ifndef __PID_
#define __PID_
#include "stm32f10x.h"                  // Device header

typedef struct
{
 float Sv;//�û��趨ֵ
 float Pv;
	
 float Kp;
 float T;  //PID��������--��������
 float Ti;
	
 float Ek;  //����ƫ��
 float SEk; //��ʷƫ��֮��
	
	float Iout;
	float Pout;

 uint16_t OUT;


/********/
 float Sv2;//�û��趨ֵ
 float Pv2;
	
 float Kp2;
 float T2;  //PID��������--��������
 float Ti2;
	
 float Ek2;  //����ƫ��
 float SEk2; //��ʷƫ��֮��
	
	float Iout2;
	float Pout2;

 uint16_t OUT2;
 
 u16 pwmcycle;//pwm����
}PID;

extern PID pid; //���PID�㷨����Ҫ������
void PID_Calc(void);  //pid����
void PID2_Calc(void);  //pid����



#endif
