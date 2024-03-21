#include "stm32f10x.h"                  // Device header
#include "PID.h"
#include "Motor.h"

PID pid; //���PID�㷨����Ҫ������


void PID_Calc(void)  //pid����
{
  float out;

 pid.Ek=pid.Sv-pid.Pv;   //�õ���ǰ��ƫ��ֵ
 pid.Pout=pid.Kp*pid.Ek;      //�������
 
 pid.SEk+=pid.Ek;        //��ʷƫ���ܺ�
 
  pid.Iout=(pid.T/pid.Ti) * pid.Kp * pid.SEk;  //�������


  out= pid.Pout+ pid.Iout+1000;
//out= pid.Pout+ pid.Iout+ pid.Dout;
 
 if(out>(pid.pwmcycle-100))  //===PWM������7200 ������7100
 {
  out=(pid.pwmcycle-100);
 }
 if(out<-(pid.pwmcycle-100))
 {
  out=-(pid.pwmcycle-100);
 }
 
 if(out>0)
 {
	 GPIO_ResetBits(GPIOA,GPIO_Pin_5);
     GPIO_SetBits(GPIOA,GPIO_Pin_4);
 }
 else
 {	
	 GPIO_ResetBits(GPIOA,GPIO_Pin_4);
     GPIO_SetBits(GPIOA,GPIO_Pin_5);
 }
 
 if(out>=0)
 {
  pid.OUT=out;
 }
 else
	 pid.OUT=-out;
}

void PID2_Calc(void)  //pid����
{
	float out;

 pid.Ek2=pid.Sv2-pid.Pv2;   //�õ���ǰ��ƫ��ֵ
 pid.Pout2=pid.Kp2*pid.Ek2;      //�������
 
 pid.SEk2+=pid.Ek2;        //��ʷƫ���ܺ�
 
  pid.Iout2=(pid.T2/pid.Ti2) * pid.Kp2 * pid.SEk2;  //�������


  out= pid.Pout2+ pid.Iout2+1000;
//out= pid.Pout+ pid.Iout+ pid.Dout;
 
 if(out>(pid.pwmcycle-100))  //===PWM������7200 ������7100
 {
  out=(pid.pwmcycle-100);
 }
 if(out<-(pid.pwmcycle-100))
 {
  out=-(pid.pwmcycle-100);
 }
 
 if(out>0)
 {
	 GPIO_ResetBits(GPIOA,GPIO_Pin_7);
     GPIO_SetBits(GPIOA,GPIO_Pin_6);	 

 }
 else
 {
	 GPIO_ResetBits(GPIOA,GPIO_Pin_6);
     GPIO_SetBits(GPIOA,GPIO_Pin_7);
 }
 
 if(out>=0)
 {
  pid.OUT2=out;
 }
 else
	 pid.OUT2=-out;
}


/**************************************************************************
�������ܣ�����PI������
��ڲ���������������ֵ��Ŀ���ٶ�
����  ֵ�����PWM
��������ʽ��ɢPID��ʽ 
pwm+=Kp[e��k��-e(k-1)]+Ki*e(k)+Kd[e(k)-2e(k-1)+e(k-2)]
e(k)������ƫ�� 
e(k-1)������һ�ε�ƫ��  �Դ����� 
pwm�����������
�����ǵ��ٶȿ��Ʊջ�ϵͳ���棬ֻʹ��PI����
pwm+=Kp[e��k��-e(k-1)]+Ki*e(k)
**************************************************************************/
//int Incremental_PI (int Encoder,int Target)
//{ 	
//   float Kp=80,Ki=30;	
//	 static int Bias,Pwm,Last_bias;
//	 Bias=Encoder-Target;                //����ƫ��
//	 Pwm+=Kp*(Bias-Last_bias)+Ki*Bias;   //����ʽPI������
//	 Last_bias=Bias;	                   //������һ��ƫ�� 
//	 return Pwm;                         //�������
//}
