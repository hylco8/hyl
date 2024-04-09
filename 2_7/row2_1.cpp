#include "row2_1.h"

// 定义第一排显示2函数
void row2_1 (void)
{ 
   for ( i = 100; i < 111; i=i+10) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( 255, 255, 0) ;
    }
  }   
     for ( i = 560; i < 571; i=i+10) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( 255, 255, 0) ;
    }
  }  
     for ( i = 780; i < 791; i=i+10) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( 255, 255, 0) ;
    }
  }  
     for ( i = 1240; i < 1251; i=i+10) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( 255, 255, 0) ;
    }
  }  
     for ( i = 1460; i < 1471; i=i+10) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( 255, 255, 0) ;
    }
  }  
    FastLED.show(); 
}
