/*
//
//the hall library
//
//
*/
/*
//@ !author: Paweł Majewski
*/

#include "Arduino.h"
#include "Hall_Init.h"
#include "flags.h"

/*************************************************************************************/
void Hall_Init(void){
noInterrupts();
    DDRB &= ~(1 << PB_4);       //input PIN 12
    PORTB |= (1 << PB_4);       //pull-up PIN 12
    //interrupt
    PCMSK0 |= (1 << PCINT4);    //Pin Change Mask// B - PCINT[7:0].
    PCICR |= (1 << PCIE0);      //Pin Change Interrupt Control

    DDRB &= ~(1 << PB_5);       //input PIN 13
    PORTB |= (1 << PB_5);       //pull-up PIN 13
    //interrupt
    PCMSK0 |= (1 << PCINT5);    //Pin Change Mask// B - PCINT[7:0].
    PCICR |= (1 << PCIE0);      //Pin Change Interrupt Control

#ifdef STRIP4
    DDRB &= ~(1 << PB_2);       //input PIN 10
    PORTB |= (1 << PB_2);       //pull-up PIN 10
    //interrupt
    PCMSK0 |= (1 << PCINT2);    //Pin Change Mask// B - PCINT[7:0].
    PCICR |= (1 << PCIE0);      //Pin Change Interrupt Control

    DDRB &= ~(1 << PB_3);       //input PIN 11
    PORTB |= (1 << PB_3);       //pull-up PIN 11
    //interrupt
    PCMSK0 |= (1 << PCINT3);    //Pin Change Mask// B - PCINT[7:0].
    PCICR |= (1 << PCIE0);      //Pin Change Interrupt Control
#endif
interrupts();
}

void Time(){
    tim *Tim = tim();
    double rpm = 0;

    Tim->read_time = micros();//resets after 70 min
    Tim->cur_time = Tim->read_time;
    Tim->diff = Tim->cur_time - Tim->prev_time;//difference
    rpm = 1/((Tim->diff / 1000000) / 60);//rpm

    Tim->speed = 2 * 3.6 * PI * RADIUS * (rpm / 60);//km/h
    /*synchronization*/
    Tim->tim_150 = (((((Tim->diff / 100)*2)/5))-1033);
    Tim->tim_600 = (((((Tim->diff / 100)*3)/5))-1033);

    if(Tim->tim_150 > Tim->prev_tim_150 + 5000 || Tim->tim_150 < Tim->prev_tim_150-5000){//eliminating possible bad readings
        Tim->tim_150 = Tim->prev_tim_150;
        Tim->tim_600 = Tim->prev_tim_600;    
    }

    Tim->prev_tim_150 = Tim->tim_150;
    Tim->prev_tim_600 = Tim->tim_600;

    Tim->prev_time = Tim->cur_time;
}

/*interrupt*/
ISR (PCINT0_vect)
{
    if (!(PINB & (1 << 4))) {
        flags *Flag = flags();
        Flag->flag_start_1 = 1;
        Time();
    }
    if (!(PINB & (1 << 5))) {
        flags *Flag = flags();
        Flag->flag_start_2 = 1;
    }
#ifdef STRIP4
    if (!(PINB & (1 << 3))) {
        flags *Flag = flags();
        Flag->flag_start_3 = 1;
    }
    if (!(PINB & (1 << 2))) {
        flags *Flag = flags();
        Flag->flag_start_4 = 1;
    }
#endif
}

