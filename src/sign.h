/*
//
//library with characters and numbers and special picture
//return index + 1 to seperate characters
// and function with clear leds
//
*/
/*
//@ !author: Paweł Majewski
*/

#ifndef SIGN
#define SIGN

#include "Adafruit_Init.h"
#include "Adafruit_NeoPixel.h"
#include "program_setup.h"

extern Adafruit_NeoPixel pixels_one;
extern Adafruit_NeoPixel pixels_two;
#ifdef STRIP4
extern Adafruit_NeoPixel pixels_three;
extern Adafruit_NeoPixel pixels_four;
#endif
//clear leds strip
void displayClear(uint8_t strip_id);

void SHOW(uint8_t strip_id);
//alphabet
//return index plus 1 to seperate characters
int  A(int poz, int index, uint8_t strip_id);
int  B(int poz, int index, uint8_t strip_id);
int  C(int poz, int index, uint8_t strip_id);
int  D(int poz, int index, uint8_t strip_id);
int  E(int poz, int index, uint8_t strip_id);
int FF(int poz, int index, uint8_t strip_id);
int  G(int poz, int index, uint8_t strip_id);
int  H(int poz, int index, uint8_t strip_id);
int  I(int poz, int index, uint8_t strip_id);
int  J(int poz, int index, uint8_t strip_id);
int  K(int poz, int index, uint8_t strip_id);
int  L(int poz, int index, uint8_t strip_id);
int  M(int poz, int index, uint8_t strip_id);
int  N(int poz, int index, uint8_t strip_id);
int  O(int poz, int index, uint8_t strip_id);
int  P(int poz, int index, uint8_t strip_id);
int  Q(int poz, int index, uint8_t strip_id);
int  R(int poz, int index, uint8_t strip_id);
int  S(int poz, int index, uint8_t strip_id);
int  T(int poz, int index, uint8_t strip_id);
int  U(int poz, int index, uint8_t strip_id);
int  W(int poz, int index, uint8_t strip_id);
int  X(int poz, int index, uint8_t strip_id);
int  Y(int poz, int index, uint8_t strip_id);
int  Z(int poz, int index, uint8_t strip_id);

//numbers 
//return index plus 1 to seperate characters
int  zero (int poz, int index, uint8_t strip_id);
int  one  (int poz, int index, uint8_t strip_id);
int  two  (int poz, int index, uint8_t strip_id);
int  three(int poz, int index, uint8_t strip_id);
int  four (int poz, int index, uint8_t strip_id);
int  five (int poz, int index, uint8_t strip_id);
int  six  (int poz, int index, uint8_t strip_id);
int  seven(int poz, int index, uint8_t strip_id);
int  eight(int poz, int index, uint8_t strip_id);
int  nine (int poz, int index, uint8_t strip_id);

//separate characters more
int  space(int poz, int index, uint8_t strip_id);
int  slash(int poz, int index, uint8_t strip_id);

//special picture
//return index +1
int  smile(int poz, int index, uint8_t strip_id);
int  heart(int poz, int index, uint8_t strip_id);
int  welcome_sentence(int poz, int index, uint8_t strip_id);

#endif /*SIGN*/

