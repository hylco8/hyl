#include "row1_1.h"

// 定义第一排显示1函数
void row1_1 (void)
{ 
   for ( i = 20; i < 31; i=i+10) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( 255, 255, 0) ;
    }
  }  
     for ( i = 640; i < 651; i=i+10) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( 255, 255, 0) ;
    }
  } 
     for ( i = 700; i < 711; i=i+10) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( 255, 255, 0) ;
    }
  }
     for ( i = 1320; i < 1331; i=i+10) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( 255, 255, 0) ;
    }
  }  
     for ( i = 1380; i < 1391; i=i+10) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( 255, 255, 0) ;
    }
  } 
    FastLED.show(); 
}
