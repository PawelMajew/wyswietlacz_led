/*
//@ !author: Paweł Majewski
*/
#include <Arduino.h>
#include "flags.h"

/*set flags to change programm status*/
void execmd(){
    flags *Flaga = flags();
    buf *Buffor = buf();

    if(strcmp(Buffor->buffor,"start") == 0){
        if(Flaga->flaga == 1){
            Flaga->flaga = 0;
        }else if(Flaga->flaga == 0){
            Flaga->flaga = 1;
        }
    }

    if(strcmp(Buffor->buffor,"ready") == 0){
        if(Flaga->flaga_1 == 1){
            Flaga->flaga_1 = 0;
        }else if(Flaga->flaga_1 == 0){
            Flaga->flaga_1 = 1;
        }
    }

}

/*bluetooth support*/
void serialEvent(){
    buf *Buffor = buf();

    if(Serial.available() > 0)  
    {   
        char character = (char)Serial.read();

        if(character == '\n')
        {
            Buffor->buffor[Buffor->buffor_index] = 0;
            execmd();

            Buffor->index = Buffor->buffor_index;
            Buffor->buffor_index = 0;

        }else{
            Buffor->buffor[Buffor->buffor_index] = character;
            if(Buffor->buffor_index < 99)Buffor->buffor_index++;
        }
    } 

}