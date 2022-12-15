/*
//
//header file to initialize the led library
// 24   <----number of leds in one strip
//PIN 6 <----one led strip
//PIN 7 <----second led strip
//PIN 8 <----third led strip
//PIN 9 <----fourth led strip
//
*/
/*
//@ !author: Paweł Majewski
*/
#ifndef ADAFRUIT_INIT
#define ADAFRUIT_INIT

#include "program_setup.h"

#define PIN_ONE        6  //PIN for one strip
#define NUMPIXELS_ONE  24 // number of leds
#define PIN_TWO        7  //PIN for one strip
#define NUMPIXELS_TWO  24 // number of leds
#ifdef STRIP4
#define PIN_THREE       8  //PIN for one strip
#define NUMPIXELS_THREE 24 // number of leds
#define PIN_FOUR        9  //PIN for one strip
#define NUMPIXELS_FOUR  24 // number of leds
#endif

/*initialize the led strips*/
void Adafruit_Init(void);

#endif /*ADAFRUIT_INIT*/