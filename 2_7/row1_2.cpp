#include "row1_2.h"

// 定义第一排显示2函数
void row1_2 (void)
{ 
   for ( i = 10; i < 51; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( 255, 255, 0) ;
    }
  }   
     for ( i = 20; i < 41; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( 255, 255, 0) ;
    }
  } 
     for ( j = 0; j < 5; j++) 
    {
      leds[j+630] = CRGB ( 255, 255, 0) ;
    }
    
       for ( i = 690; i < 731; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( 255, 255, 0) ;
    }
  }

       for ( i = 700; i < 721; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( 255, 255, 0) ;
    }
  }

       for ( j = 0; j < 5; j++) 
    {
      leds[j+1350] = CRGB ( 255, 255, 0) ;
    }

    for ( i = 1370; i < 1411; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( 255, 255, 0) ;
    }
  }
  
         for ( i = 1380; i < 1401; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( 255, 255, 0) ;
    }
  }
    FastLED.show(); 
}
