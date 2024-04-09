/*
①这段代码是 C 语言中的头文件包含指令，用于在当前源文件中引入其他头文件。头文件通常包含函数声明、宏定义、类型定义和其他预处理指令，它们是 C 语言中组织和管理代码的重要部分。
第一个头文件head.h中包含了调用驱动2812灯带的库、利用宏定义设置Arduino Mega 2560单片机引脚控制2812灯带、利用宏定义设置灯带个数、声明数组和一些变量。
后面的头文件中都建立了对应.cpp与.h文件，每一个文件都对应一种显示画面，11个播放图案定义为 display1、display2、display3、display5.display7、display9、display11,由于display2 与display4、display6、display8、display10 显示的效果相同，因此只定义一个即可。
*/
#include "head.h"      //引用自己建立的头文件
#include "display1.h"  //引用自己建立的显示1头文件
#include "display2.h"  //引用自己建立的显示2头文件
#include "display3.h"  //引用自己建立的显示3头文件  
#include "display5.h"  //引用自己建立的显示5头文件
#include "display7.h"  //引用自己建立的显示7头文件
#include "display9.h"  //引用自己建立的显示9头文件
#include "display11.h" //引用自己建立的显示11头文件

#include "row1_0.h"
#include "row1_1.h"
#include "row1_2.h"
#include "row2_0.h"
#include "row2_1.h"
#include "row2_2.h"
#include "row2_3.h"
#include "row2_4.h"
#include "row3_0.h"
#include "row3_1.h"
#include "row3_2.h"
#include "row3_3.h"
#include "row3_4.h"
#include "row3_5.h"
#include "row3_6.h"
#include "row4_0.h"
#include "row4_1.h"
#include "row4_2.h"
#include "row4_3.h"
#include "row4_4.h"
#include "row4_5.h"
#include "row4_6.h"
#include "row4_7.h"
#include "row4_8.h"
#include "row4_9.h"
#include "middle.h"
/*
②创建数组和变量。数组leds[NUM_LEDS]用于存储每一个灯珠的RGB值，实现精准控制每一个灯珠的颜色。
无符号整型变量X,Y用于放在数组CRGB ( x, y, 0)中，用于每一种灯的颜色、无符号整型变量i,j用于for循环。
字符型变量K用于for循环、字符型变量display_num用来控制轮流播放11个图案
*/
CRGB leds[NUM_LEDS];   //定义保存RGB各颜色比例的数值
unsigned int i,j,X,Y;  //定义一些无符号整型变量
char K,display_num;    //定义一些字符型变量

/*
③这个函数只运行一次，主要的作用是初始化。
清零变量display_num，使播放图案从第一个显示图案开始
 FastLED.addLeds主要是初始化Arduino Mega 2560控制2812灯带的引脚、2812灯带个数
for语句和FastLED.show函数是熄灭所有2812灯带，为轮流播放11个图案做准备
*/
void setup() {
  display_num = 0;                                       //清零变量
  FastLED.addLeds<WS2812, LED_PIN,
   GRB>(leds, NUM_LEDS); //初始化2812的引脚、灯个数

    for ( i = 0; i < NUM_LEDS; i++)                      //往数组里面，全部写入（0，0，0）
    leds[i] = CRGB ( 0, 0, 0);                    
    FastLED.show();                                      //把数组里面的数据，写入到灯带  熄灭所有的2812灯带
                          
    delay(2000);                                         //延时2000ms （2s）
}

//将主代码放在这个函数里面，以便重复运行
void loop() {
  while(1)
  { 
     row1_0 (); //第一排显示0函数
     row1_1 (); //第一排显示1函数
     row1_2 (); //第一排显示2函数
     row2_0 (); //第二排显示0函数
     row2_1 (); //第二排显示1函数
     row2_2 (); //第二排显示2函数
     row2_3 (); //第二排显示3函数
     row2_4 (); //第二排显示3函数
     row3_0 (); //第三排显示0函数
     row3_1 (); //第三排显示1函数
     row3_2 (); //第三排显示2函数
     row3_3 (); //第三排显示3函数
     row3_4 (); //第三排显示4函数
     row3_5 (); //第三排显示5函数
     row3_6 (); //第三排显示6函数
     row4_0 (); //第四排显示0函数
     row4_1 (); //第四排显示1函数
     row4_2 (); //第四排显示2函数
     row4_3 (); //第四排显示2函数
     row4_4 (); //第四排显示2函数
     row4_5 (); //第四排显示2函数
     row4_6 (); //第四排显示2函数
     row4_7 (); //第四排显示2函数
     row4_8 (); //第四排显示2函数
     row4_9 (); //第四排显示2函数
     middle (); //声明第一排显示0函数
     /*
    display_num ++ ;                     //显示的变量display_num加1
    if( display_num>11 )                 //当display_num大于11时，重新赋值为1
    display_num = 1;
    
    for ( K =0; K < 100; K++)            //for语句，循环显示各个显示方案
    {
      X=2.55*K,Y=K;                      //调整RGB的数值大小，实现灯带慢慢变亮的效果
      if( display_num == 1 )             //当display_num为1，显示1方案运行
      display1 ();
      else if ( display_num == 2 )       //当display_num为2，显示2方案运行       
      display2 ();
      else if ( display_num == 3 )       //当display_num为3，显示3方案运行
      display3 ();
      else if ( display_num == 4 )       //当display_num为4，显示2方案运行
      display2 ();
      else if ( display_num == 5 )       //当display_num为5，显示5方案运行
      display5 ();
      else if ( display_num == 6 )       //当display_num为6，显示2方案运行
      display2 ();      
      else if ( display_num == 7 )       //当display_num为7，显示7方案运行
      display7 (); 
      else if ( display_num == 8 )       //当display_num为8，显示2方案运行
      display2 (); 
      else if ( display_num == 9 )       //当display_num为9，显示9方案运行
      display9 (); 
      else if ( display_num == 10 )       //当display_num为10，显示2方案运行
      display2 (); 
      else if ( display_num == 11 )       //当display_num为11，显示11方案运行
      display11 ();  
      delay(25);                          //亮度变亮的时间 间隔为25ms
    }
    for ( ; K >=0; K--)                   //for语句，循环显示各个显示方案
    {
      X=2.55*K,Y=K;                      //调整RGB的数值大小，实现灯带慢慢变暗的效果
      if( display_num == 1 )             //当display_num为1，显示1方案运行
      display1 ();
      else if ( display_num == 2 )       //当display_num为2，显示2方案运行 
      display2 ();
      else if ( display_num == 3 )       //当display_num为3，显示3方案运行
      display3 ();
      else if ( display_num == 4 )       //当display_num为4，显示2方案运行
      display2 ();
      else if ( display_num == 5 )       //当display_num为5，显示5方案运行
      display5 ();
      else if ( display_num == 6 )       //当display_num为6，显示2方案运行
      display2 ();      
      else if ( display_num == 7 )       //当display_num为7，显示7方案运行
      display7 ();  
      else if ( display_num == 8 )       //当display_num为8，显示2方案运行
      display2 ();  
      else if ( display_num == 9 )       //当display_num为9，显示9方案运行
      display9 ();
      else if ( display_num == 10 )      //当display_num为10，显示2方案运行
      display2 ();      
      else if ( display_num == 11 )      //当display_num为11，显示11方案运行
      display11 ();  
      delay(25);                         //亮度变暗的时间 间隔为25ms
    }     
    delay(2000);
    */
  }
}
