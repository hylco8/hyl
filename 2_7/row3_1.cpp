#include "row3_1.h"

// 定义第一排显示0函数
void row3_1 (void)
{ 
   for ( i = 220; i < 231; i=i+10) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( 255, 255, 0) ;
    }
  }

   for ( i = 440; i < 451; i=i+10) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( 255, 255, 0) ;
    }
  }

   for ( i = 900; i < 911; i=i+10) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( 255, 255, 0) ;
    }
  }

   for ( i = 1120; i < 1131; i=i+10) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( 255, 255, 0) ;
    }
  }

   for ( i = 1580; i < 1591; i=i+10) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( 255, 255, 0) ;
    }
  }
    FastLED.show(); 
}
