#include "display9.h"

void display9 (void)
{ 
   for ( i = 350; i < 431; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( X, Y, 0) ;
    }
  }
  for ( i = 440; i < 541; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( X, Y, 0) ;
    }
  }
  for ( i = 470; i < 571; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( X, Y, 0) ;
    }
  }
  for ( i = 580; i < 761; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( X, Y, 0) ;
    }
  }
   for ( i = 790; i < 891; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( X, Y, 0) ;
    }
  }
  for ( i = 800; i < 901; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( X, Y, 0) ;
    }
  }
  for ( i = 930; i < 1111; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( X, Y, 0) ;
    }
  }
  for ( i = 1120; i < 1221; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( X, Y, 0) ;
    }
  }
  for ( i = 1150; i < 1251; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( X, Y, 0) ;
    }
  }
  for ( i = 1260; i < 1341; i=i+20) 
  {
     for ( j = 0; j < 5; j++) 
    {
      leds[j+i] = CRGB ( X, Y, 0) ;
    }
  }
    FastLED.show(); 
}
