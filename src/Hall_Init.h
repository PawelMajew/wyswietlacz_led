/*
//
//header file to initialize the hall library
//
//PIN 10 <----hall 1
//PIN 11 <----hall 2 
//PIN 12 <----hall 3 
//PIN 13 <----hall 4 
//
*/
/*
//@ !author: Paweł Majewski
*/

#ifndef HALL_INIT
#define HALL_INIT

#include <avr/io.h>
#include <avr/power.h>
#include <avr/interrupt.h>

#include "program_setup.h"

#define RADIUS (0.255)


#define PB_4 0x04 //set PIN 12 like hal input
#define PB_5 0x05 //set PIN 13 like hal input
#ifdef STRIP4
#define PB_2 0x02 //set PIN 10 like hal input//bad
#define PB_3 0x03 //set PIN 11 like hal input//bad
#endif

/*initialize the hall sensor*/
void Hall_Init(void);

#endif /*HALL_INIT*/