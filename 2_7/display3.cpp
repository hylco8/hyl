#include "display3.h"

void display3 (void)
{ 
   for ( i = 350; i < 531; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( X, Y, 0) ;
    }
  }  
  for ( i = 480; i < 661; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( X, Y, 0) ;
    }
  }
  for ( i = 690; i < 791; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( X, Y, 0) ;
    }
  }
     for ( j = 820; j < 880; j++) 
    {
      leds[j] = CRGB ( X, Y, 0) ;
    }
   for ( i = 900; i < 1001; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( X, Y, 0) ;
    }
  }
  for ( i = 1030; i < 1211; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( X, Y, 0) ;
    }
  }
  for ( i = 1160; i < 1341; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( X, Y, 0) ;
    }
  }
 
    FastLED.show(); 
}
