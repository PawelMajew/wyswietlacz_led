/*
//@ !author: Paweł Majewski
*/
#include <Arduino.h>

#include "engine.h"
#include "sentence.h"
#include "sign.h"
#include "flags.h"


volatile void DelayMicroseconds(volatile unsigned long time){

    for( volatile unsigned long i = 0; i < time; i++){
        delayMicroseconds(1);
        
    }
}

/*************************************************************************************/
void engine(void){

    tim *Tim = tim();
    flags *Flaga = flags();
    static int counter_strip_1 = 0; //led strip 0 position
    static int counter_strip_2 = 0; //led strip 1 position
#ifdef STRIP4
    static int counter_strip_3 = 0; //led strip 2 position
    static int counter_strip_4 = 0; //led strip 3 position
#endif
    /*Shining*/
    sentence(counter_strip_1, STRIP_0_ID);
     sentence(counter_strip_2, STRIP_1_ID);
#ifdef STRIP4
    sentence(counter_strip_3, STRIP_2_ID);
    sentence(counter_strip_4, STRIP_3_ID);
#endif
    /*next position*/
    counter_strip_1++;
    counter_strip_2++;
#ifdef STRIP4
    counter_strip_3++;
    counter_strip_4++;
#endif
    SHOW(STRIP_0_ID);
    SHOW(STRIP_1_ID);
#ifdef STRIP4
    SHOW(STRIP_2_ID);
    SHOW(STRIP_3_ID);
#endif
    if(Flaga->flaga == 1){

    DelayMicroseconds((unsigned long)Tim->tim_600);//how much time should it shine

    /*LED off*/
    displayClear(STRIP_0_ID);
    displayClear(STRIP_1_ID);
    
    #ifdef STRIP4
    displayClear(STRIP_2_ID);
    displayClear(STRIP_3_ID);
    #endif

    DelayMicroseconds((int)Tim->tim_150);//how long the leds are to be turned off

    }
  
    /*the position resets when we pass the sensor*/
    if(Flaga->flag_start_1 == 1){
        counter_strip_1 = 0;
        Flaga->flag_start_1 = 0;

    }

    if(Flaga->flag_start_2 == 1){
        counter_strip_2 = 0;
        Flaga->flag_start_2 = 0;
        
    }
#ifdef STRIP4
    if(Flaga->flag_start_3 == 1){
        counter_strip_3 = 0;
        Flaga->flag_start_3 = 0;
        
    }

    if(Flaga->flag_start_4 == 1){
        counter_strip_4 = 0;
        Flaga->flag_start_4 = 0;
        
    }
#endif
}