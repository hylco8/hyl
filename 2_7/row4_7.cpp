#include "row4_7.h"

// 定义第一排显示0函数
void row4_7 (void)
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
      leds[j+350] = CRGB ( 255, 255, 0) ;
    }

     for ( j = 0; j < 5; j++) 
    {
      leds[j+1010] = CRGB ( 255, 255, 0) ;
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
