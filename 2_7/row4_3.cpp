#include "row4_3.h"

// 定义第一排显示0函数
void row4_3 (void)
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
      leds[j+1030] = CRGB ( 255, 255, 0) ;
    }

   for ( i = 1650; i < 1691; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( 255, 255, 0) ;
    }
  }

   for ( i = 1660; i < 1681; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( 255, 255, 0) ;
    }
  }
    FastLED.show(); 
}
