#include "row3_4.h"

// 定义第一排显示0函数
void row3_4 (void)
{ 
   for ( i = 210; i < 231; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( 255, 255, 0) ;
    }
  }    

   for ( i = 450; i < 471; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( 255, 255, 0) ;
    }
  } 

   for ( i = 890; i < 931; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( 255, 255, 0) ;
    }
  } 

   for ( i = 900; i < 921; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( 255, 255, 0) ;
    }
  }

     for ( j = 0; j < 5; j++) 
    {
      leds[j+1130] = CRGB ( 255, 255, 0) ;
    }

     for ( j = 0; j < 5; j++) 
    {
      leds[j+1590] = CRGB ( 255, 255, 0) ;
    }
    FastLED.show(); 
}
