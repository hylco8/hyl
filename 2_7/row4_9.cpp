#include "row4_9.h"

// 定义第一排显示0函数
void row4_9 (void)
{ 
 for ( i = 290; i < 331; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( 255, 255, 0) ;
    }
  }  

   for ( i = 300; i < 321; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( 255, 255, 0) ;
    }
  }
 
      for ( j = 0; j < 5; j++) 
    {
      leds[j+390] = CRGB ( 255, 255, 0) ;
    }

     for ( j = 0; j < 5; j++) 
    {
      leds[j+350] = CRGB ( 255, 255, 0) ;
    }

   for ( i = 970; i < 1011; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( 255, 255, 0) ;
    }
  }

     for ( j = 0; j < 5; j++) 
    {
      leds[j+1030] = CRGB ( 255, 255, 0) ;
    }

     for ( j = 0; j < 5; j++) 
    {
      leds[j+1690] = CRGB ( 255, 255, 0) ;
    } 

    FastLED.show(); 
}