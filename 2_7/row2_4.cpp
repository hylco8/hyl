#include "row2_4.h"

// 定义第一排显示2函数
void row2_4 (void)
{ 

       for ( j = 0; j < 5; j++) 
    {
      leds[j+90] = CRGB ( 255, 255, 0) ;
    }
      for ( j = 0; j < 5; j++) 
    {
      leds[j+590] = CRGB ( 255, 255, 0) ;
    }   
   for ( i = 770; i < 811; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( 255, 255, 0) ;
    }
  }   

   for ( i = 780; i < 801; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( 255, 255, 0) ;
    }
  } 

     for ( j = 0; j < 5; j++) 
    {
      leds[j+1250] = CRGB ( 255, 255, 0) ;
    }
     for ( j = 0; j < 5; j++) 
    {
      leds[j+1470] = CRGB ( 255, 255, 0) ;
    }

         for ( j = 0; j < 5; j++) 
    {
      leds[j+110] = CRGB ( 255, 255, 0) ;
    }
     for ( j = 0; j < 5; j++) 
    {
      leds[j+570] = CRGB ( 255, 255, 0) ;
    }
    FastLED.show(); 
}
