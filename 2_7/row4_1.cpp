#include "row4_1.h"

// 定义第一排显示0函数
void row4_1 (void)
{ 
   for ( i = 300; i < 311; i=i+10) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( 255, 255, 0) ;
    }
  }   

   for ( i = 360; i < 371; i=i+10) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( 255, 255, 0) ;
    }
  } 

   for ( i = 980; i < 991; i=i+10) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( 255, 255, 0) ;
    }
  }   

   for ( i = 1040; i < 1051; i=i+10) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( 255, 255, 0) ;
    }
  }   

   for ( i = 1660; i < 1671; i=i+10) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( 255, 255, 0) ;
    }
  } 
    FastLED.show(); 
}
