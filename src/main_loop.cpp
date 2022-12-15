/*
//
//main loop
//
//
//
*/
/*
//@ !author: Paweł Majewski
*/

#include <Arduino.h>
#include "main_loop.h"
#include "engine.h"
#include "Hall_Init.h"
#include "flags.h"

flags flags_addr;
tim tim_addr;
buf buf_addr;

/*************************************************************************************/
void main_loop(void){

    engine();

}