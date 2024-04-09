#include "row4_4.h"

// 定义第一排显示0函数
void row4_4 (void)
{ 
   for ( i = 290; i < 311; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( 255, 255, 0) ;
    }
  }  

   for ( i = 370; i < 391; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( 255, 255, 0) ;
    }
  }  

   for ( i = 370; i < 391; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( 255, 255, 0) ;
    }
  }

   for ( i = 970; i < 1011; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( 255, 255, 0) ;
    }
  }

   for ( i = 980; i < 1001; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( 255, 255, 0) ;
    }
  }

     for ( j = 0; j < 5; j++) 
    {
      leds[j+1050] = CRGB ( 255, 255, 0) ;
    }
     for ( j = 0; j < 5; j++) 
    {
      leds[j+1670] = CRGB ( 255, 255, 0) ;
    }
    FastLED.show(); 
}
