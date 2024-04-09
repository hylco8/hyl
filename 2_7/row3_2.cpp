#include "row3_2.h"

// 定义第一排显示0函数
void row3_2 (void)
{ 
   for ( i = 210; i < 251; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( 255, 255, 0) ;
    }
  }

   for ( i = 220; i < 241; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( 255, 255, 0) ;
    }
  }

     for ( j = 0; j < 5; j++) 
    {
      leds[j+430] = CRGB ( 255, 255, 0) ;
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
      leds[j+1150] = CRGB ( 255, 255, 0) ;
    }

   for ( i = 1570; i < 1611; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( 255, 255, 0) ;
    }
  }

   for ( i = 1580; i < 1601; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( 255, 255, 0) ;
    }
  }

    FastLED.show(); 
}
