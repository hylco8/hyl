#include "middle.h"

// 定义第一排显示0函数
void middle (void)
{ 
     for ( j = 0; j < 20; j++) 
    {
      leds[j+500] = CRGB ( 255, 255, 0) ;
    } 

     for ( j = 0; j < 20; j++) 
    {
      leds[j+1180] = CRGB ( 255, 255, 0) ;
    } 
    FastLED.show(); 
}
