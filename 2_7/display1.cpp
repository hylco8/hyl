#include "display1.h"

//定义显示1函数，该函数把RGB值写入数组
void display1 (void)
{ 
  /*for ( i = 350; i < 471; i=i+20) for循环，它从i = 350开始，每次循环i增加20，直到i的值达到或超过471。
  for ( j = 0; j < 5; j++) 这是嵌套在上一个for循环内的另一个for循环，它从j = 0开始，每次循环j增加1，直到j的值达到或超过5。
  leds[j+i] = CRGB ( X, Y, 0); 这是内部循环的主体部分，它设置了leds数组中索引为j+i的元素的颜色。
  这段代码的目的是在2812灯带上设置一个led灯的颜色*/
   for ( i = 350; i < 471; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( X, Y, 0) ;
    }
  }  
  for ( i = 350; i < 471; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( X, Y, 0) ;
    }
  } 
  for ( i = 485; i < 526; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( X, Y, 0) ;
    }
  } 
  for ( i = 495; i < 536; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( X, Y, 0) ;
    }
  } 
  for ( i = 540; i < 801; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( X, Y, 0) ;
    }
  } 
     for ( j = 820; j < 880; j++) 
    {
      leds[j] = CRGB ( X, Y, 0) ;
    }

    for ( i = 890; i < 1151; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( X, Y, 0) ;
    }
  } 
  for ( i = 1165; i < 1206; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( X, Y, 0) ;
    }
  } 
  for ( i = 1175; i < 1216; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( X, Y, 0) ;
    }
  } 
  for ( i = 1220; i < 1341; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( X, Y, 0) ;
    }
  } 
    FastLED.show(); 
}
