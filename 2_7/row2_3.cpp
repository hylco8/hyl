#include "row2_3.h"

// 定义第一排显示2函数
void row2_3 (void)
{ 
   for ( i = 90; i < 131; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( 255, 255, 0) ;
    }
  }  

     for ( i = 100; i < 121; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( 255, 255, 0) ;
    }
  } 
     for ( j = 0; j < 5; j++) 
    {
      leds[j+550] = CRGB ( 255, 255, 0) ;
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
      leds[j+1230] = CRGB ( 255, 255, 0) ;
    }

     for ( i = 1450; i < 1491; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( 255, 255, 0) ;
    }
  } 

       for ( i = 1460; i < 1481; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( 255, 255, 0) ;
    }
  } 
    FastLED.show(); 
}
