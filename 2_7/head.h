#ifndef __HEAD_H
#define __HEAD_H

#include <FastLED.h>          //调用驱动2812灯带的库
#define LED_PIN     7         //对应引脚
#define NUM_LEDS    1700      //对应灯的个数
extern CRGB leds[NUM_LEDS];   //声明保存RGB各颜色比例的数值
extern unsigned int i,j,X,Y;  //声明一些无符号整型变量
extern char K;                 //声明一些字符型变量

#endif
