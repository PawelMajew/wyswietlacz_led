/*
//@ !author: Paweł Majewski
*/

#include "Arduino.h"
#include "Adafruit_Init.h"
#include "Adafruit_NeoPixel.h"

Adafruit_NeoPixel pixels_one(NUMPIXELS_ONE, PIN_ONE, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels_two(NUMPIXELS_TWO, PIN_TWO, NEO_GRB + NEO_KHZ800);
#ifdef STRIP4
Adafruit_NeoPixel pixels_three(NUMPIXELS_THREE, PIN_THREE, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels_four(NUMPIXELS_FOUR, PIN_FOUR, NEO_GRB + NEO_KHZ800);
#endif

/*************************************************************************************/
void Adafruit_Init(void){

    pixels_one.begin();           // INITIALIZE NeoPixel strip 0 object
    pixels_one.show();            
    pixels_two.begin();           // INITIALIZE NeoPixel strip 1 object
    pixels_two.show();            
#ifdef STRIP4
    pixels_three.begin();         // INITIALIZE NeoPixel strip 3 object
    pixels_three.show();            
    pixels_four.begin();          // INITIALIZE NeoPixel strip 4 object
    pixels_four.show();            
#endif

}