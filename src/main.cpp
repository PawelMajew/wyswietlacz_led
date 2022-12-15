/*
//main
//
//connection description:
// 24    <----number of leds in one strip
//PIN 6  <----one led strip
//PIN 7  <----second led strip
//PIN 8  <----third led strip
//PIN 9  <----fourth led strip
//PIN 10 <----hall 1
//PIN 11 <----hall 2 
//PIN 12 <----hall 3 
//PIN 13 <----hall 4 
//PIN 0  <----bluetooth module
//PIN 1  <----bluetooth module
//
*/
/*
//@ !author: Paweł Majewski
*/

#include <Arduino.h>
/*own library*////////////
#include "Adafruit_Init.h"
#include "Adafruit_NeoPixel.h"
#include "Hall_Init.h"
#include "main_loop.h"
#include "flags.h"

/*************************************************************************************/
void setup() {
  Adafruit_Init();      //init leds
  Hall_Init();          //init hall
  Serial.begin(9600);   // set serial for bluetooth
}

/*************************************************************************************/
void loop() {
  
  main_loop();          //main loop

}