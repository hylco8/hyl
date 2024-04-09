#include "display11.h"

void display11 (void)
{ 
   for ( i = 350; i < 671; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( X, Y, 0) ;
    }
  }
  for ( i = 680; i < 1001; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( X, Y, 0) ;
    }
  }
  for ( i = 1030; i < 1351; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( X, Y, 0) ;
    }
  }
    FastLED.show(); 
}
