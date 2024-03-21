#include "stm32f10x.h"                  // Device header
#include "PID.h"
#include "Motor.h"

PID pid; //存放PID算法所需要的数据


void PID_Calc(void)  //pid计算
{
  float out;

 pid.Ek=pid.Sv-pid.Pv;   //得到当前的偏差值
 pid.Pout=pid.Kp*pid.Ek;      //比例输出
 
 pid.SEk+=pid.Ek;        //历史偏差总和
 
  pid.Iout=(pid.T/pid.Ti) * pid.Kp * pid.SEk;  //积分输出


  out= pid.Pout+ pid.Iout+1000;
//out= pid.Pout+ pid.Iout+ pid.Dout;
 
 if(out>(pid.pwmcycle-100))  //===PWM满幅是7200 限制在7100
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

void PID2_Calc(void)  //pid计算
{
	float out;

 pid.Ek2=pid.Sv2-pid.Pv2;   //得到当前的偏差值
 pid.Pout2=pid.Kp2*pid.Ek2;      //比例输出
 
 pid.SEk2+=pid.Ek2;        //历史偏差总和
 
  pid.Iout2=(pid.T2/pid.Ti2) * pid.Kp2 * pid.SEk2;  //积分输出


  out= pid.Pout2+ pid.Iout2+1000;
//out= pid.Pout+ pid.Iout+ pid.Dout;
 
 if(out>(pid.pwmcycle-100))  //===PWM满幅是7200 限制在7100
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
函数功能：增量PI控制器
入口参数：编码器测量值，目标速度
返回  值：电机PWM
根据增量式离散PID公式 
pwm+=Kp[e（k）-e(k-1)]+Ki*e(k)+Kd[e(k)-2e(k-1)+e(k-2)]
e(k)代表本次偏差 
e(k-1)代表上一次的偏差  以此类推 
pwm代表增量输出
在我们的速度控制闭环系统里面，只使用PI控制
pwm+=Kp[e（k）-e(k-1)]+Ki*e(k)
**************************************************************************/
//int Incremental_PI (int Encoder,int Target)
//{ 	
//   float Kp=80,Ki=30;	
//	 static int Bias,Pwm,Last_bias;
//	 Bias=Encoder-Target;                //计算偏差
//	 Pwm+=Kp*(Bias-Last_bias)+Ki*Bias;   //增量式PI控制器
//	 Last_bias=Bias;	                   //保存上一次偏差 
//	 return Pwm;                         //增量输出
//}
