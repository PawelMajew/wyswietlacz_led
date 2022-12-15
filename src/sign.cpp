/*
//
//
//characters and numbers and special picture
//
//
*/
/*
//@ !author: Paweł Majewski
*/

#include <Arduino.h>
#include "sign.h"
#include "flags.h"


void SETPIXELCOLOR(uint16_t number, uint8_t r, uint8_t g, uint8_t b, uint8_t strip_id){
  switch (strip_id)
  {
  case STRIP_0_ID:
    pixels_one.setPixelColor(number, r, g, b);
    break;
  case STRIP_1_ID:
    pixels_two.setPixelColor(number, r, g, b);
    break;
#ifdef STRIP4
  case STRIP_2_ID:
    pixels_three.setPixelColor(number, r, g, b);
    break;
  case STRIP_3_ID:
    pixels_four.setPixelColor(number, r, g, b);
    break;
#endif
  default:
    break;
  }
}

/*************************************************************************************/
void SHOW(uint8_t strip_id){
  switch (strip_id)
  {
  case STRIP_0_ID:
    pixels_one.show();
    break;
  case STRIP_1_ID:
    pixels_two.show();
    break;
#ifdef STRIP4
  case STRIP_2_ID:
    pixels_three.show();
    break;
  case STRIP_3_ID:
    pixels_four.show();
    break;
#endif
  default:
    break;
  }
}

/*************************************************************************************/
void displayClear(uint8_t strip_id){
  for (int i = 0; i < 24; i++) {
    SETPIXELCOLOR(i, 0, 0, 0, strip_id);
  }
  SHOW(strip_id);
}

/*************************************************************************************/
int  A(int poz, int index, uint8_t strip_id) {
  if (poz ==  index + 1 || poz == index + 4) {
    for (int i = 16; i <= 21; i++) {
      SETPIXELCOLOR(i, 0, 0, 255, strip_id);
    }
    SHOW(strip_id);
  }
  if (poz == index + 2 || poz == index + 3) {
    SETPIXELCOLOR(19, 0, 0, 255, strip_id);
    SETPIXELCOLOR(22, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  return index + 5;
}

/*************************************************************************************/
int B(int poz, int index, uint8_t strip_id) {
  if (poz == index + 1 ) {
    SETPIXELCOLOR(17, 0, 0, 255, strip_id);
    SETPIXELCOLOR(18, 0, 0, 255, strip_id);
    SETPIXELCOLOR(20, 0, 0, 255, strip_id);
    SETPIXELCOLOR(21, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 2 || poz == index + 3 ) {
    SETPIXELCOLOR(16, 0, 0, 255, strip_id);
    SETPIXELCOLOR(19, 0, 0, 255, strip_id);
    SETPIXELCOLOR(22, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 4) {
    for (int i = 16; i <= 22; i++) {
      SETPIXELCOLOR(i, 0, 0, 255, strip_id);
    }
    SHOW(strip_id);
  }
  return index + 5;
}

/*************************************************************************************/
int C(int poz, int index, uint8_t strip_id) {
  if (poz ==  index + 1 ) {
    SETPIXELCOLOR(17, 0, 0, 255, strip_id);
    SETPIXELCOLOR(21, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index +  2 || poz == index + 3) {
    SETPIXELCOLOR(16, 0, 0, 255, strip_id);
    SETPIXELCOLOR(22, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 4 ) {
    for (int i = 17; i <= 21; i++) {
      SETPIXELCOLOR(i, 0, 0, 255, strip_id);
    }
    SHOW(strip_id);
  }
  return index + 5;
}

/*************************************************************************************/
int D(int poz, int index, uint8_t strip_id) {
  if (poz == index + 1) {
    for (int i = 17; i <= 21; i++) {
      SETPIXELCOLOR(i, 0, 0, 255, strip_id);
    }
    SHOW(strip_id);
  }
  if (poz ==  index + 2 || poz == index + 3 ) {
    SETPIXELCOLOR(16, 0, 0, 255, strip_id);
    SETPIXELCOLOR(22, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 4) {
    for (int i = 16; i <= 22; i++) {
      SETPIXELCOLOR(i, 0, 0, 255, strip_id);
    }
    SHOW(strip_id);
  }
  return index + 5;
}

/*************************************************************************************/
int E(int poz, int index, uint8_t strip_id) {
  if (poz ==  index + 1 ) {
    SETPIXELCOLOR(16, 0, 0, 255, strip_id);
    SETPIXELCOLOR(22, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz ==  index + 2 || poz == index + 3 ) {
    SETPIXELCOLOR(16, 0, 0, 255, strip_id);
    SETPIXELCOLOR(19, 0, 0, 255, strip_id);
    SETPIXELCOLOR(22, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 4) {
    for (int i = 16; i <= 22; i++) {
      SETPIXELCOLOR(i, 0, 0, 255, strip_id);
    }
    SHOW(strip_id);
  }
  return index + 5;
}

/*************************************************************************************/
int FF(int poz, int index, uint8_t strip_id) {
  if (poz ==  index + 1) {
    SETPIXELCOLOR(22, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz ==  index + 2 || poz == index + 3) {
    SETPIXELCOLOR(19, 0, 0, 255, strip_id);
    SETPIXELCOLOR(22, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 4) {
    for (int i = 16; i <= 22; i++) {
      SETPIXELCOLOR(i, 0, 0, 255, strip_id);
    }
    SHOW(strip_id);
  }
  return index + 5;
}

/*************************************************************************************/
int G(int poz, int index, uint8_t strip_id) {
  if (poz == index + 1 ) {
    SETPIXELCOLOR(16, 0, 0, 255, strip_id);
    SETPIXELCOLOR(17, 0, 0, 255, strip_id);
    SETPIXELCOLOR(18, 0, 0, 255, strip_id);
    SETPIXELCOLOR(21, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 2 ) {
    SETPIXELCOLOR(16, 0, 0, 255, strip_id);
    SETPIXELCOLOR(18, 0, 0, 255, strip_id);
    SETPIXELCOLOR(22, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 3 ) {
    SETPIXELCOLOR(16, 0, 0, 255, strip_id);
    SETPIXELCOLOR(22, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 4 ) {
    for (int i = 17; i <= 21; i++) {
      SETPIXELCOLOR(i, 0, 0, 255, strip_id);
    }
    SHOW(strip_id);
  }
  return index + 5;
}

/*************************************************************************************/
int H(int poz, int index, uint8_t strip_id) {
  if (poz ==  index + 1 || poz ==  index + 4) {
    for (int i = 16; i <= 22; i++) {
      SETPIXELCOLOR(i, 0, 0, 255, strip_id);
    }
    SHOW(strip_id);
  }
  if (poz == index + 2 || poz == index + 3) {
    SETPIXELCOLOR(19, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  return index + 5;//szerokość litery plus spacja
}

/*************************************************************************************/
int I(int poz, int index, uint8_t strip_id) {
  if (poz == index + 1 || poz == index + 3 ) {
    SETPIXELCOLOR(16, 0, 0, 255, strip_id);
    SETPIXELCOLOR(22, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 2 ) { //8
    for (int i = 16; i <= 22; i++) {
      SETPIXELCOLOR(i, 0, 0, 255, strip_id);
    }
    SHOW(strip_id);
  }
  return index + 4;
}

/*************************************************************************************/
int J(int poz, int index, uint8_t strip_id) {
  if (poz == index + 1) {
    for (int i = 17; i <= 22; i++) {
      SETPIXELCOLOR(i, 255, 255, 0, strip_id);
    }
    SHOW(strip_id);
  }
  if (poz == index + 2 || poz == index + 3 ) {
    SETPIXELCOLOR(16, 255, 255, 0, strip_id);
    SHOW(strip_id);
  }
  if (poz ==  index + 4 ) {
    SETPIXELCOLOR(17, 255, 255, 0, strip_id);
    SETPIXELCOLOR(18, 255, 255, 0, strip_id);
    SHOW(strip_id);
  }
  return index + 5;
}

/*************************************************************************************/
int K(int poz, int index, uint8_t strip_id) {
  if (poz == index + 1) {
    SETPIXELCOLOR(16, 0, 0, 255, strip_id);
    SETPIXELCOLOR(17, 0, 0, 255, strip_id);
    SETPIXELCOLOR(21, 0, 0, 255, strip_id);
    SETPIXELCOLOR(22, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 2) {
    SETPIXELCOLOR(18, 0, 0, 255, strip_id);
    SETPIXELCOLOR(20, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 3) {
    SETPIXELCOLOR(19, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 4) {
    for (int i = 16; i <= 22; i++) {
      SETPIXELCOLOR(i, 0, 0, 255, strip_id);
    }
    SHOW(strip_id);
  }
  return index + 5;
}

/*************************************************************************************/
int L(int poz, int index, uint8_t strip_id) {
  if (poz == index + 1 || poz == index + 2 || poz == index + 3) {
    SETPIXELCOLOR(16, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 4) {
    for (int i = 16; i <= 22; i++) {
      SETPIXELCOLOR(i, 0, 0, 255, strip_id);
    }
    SHOW(strip_id);
  }
  return index + 5;
}

/*************************************************************************************/
int M(int poz, int index, uint8_t strip_id) {
  if (poz == index + 2 || poz == index + 4) {
    SETPIXELCOLOR(21, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 3) {
    SETPIXELCOLOR(20, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 1 || poz == index + 5) {
    for (int i = 16; i <= 22; i++) {
      SETPIXELCOLOR(i, 0, 0, 255, strip_id);
    }
    SHOW(strip_id);
  }
  return index + 6;
}

/*************************************************************************************/
int N(int poz, int index, uint8_t strip_id) {
  if (poz == index + 2) {
    SETPIXELCOLOR(19, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 3) {
    SETPIXELCOLOR(20, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }

  if (poz == index + 1 || poz == index + 4) {
    for (int i = 16; i <= 22; i++) {
      SETPIXELCOLOR(i, 0, 0, 255, strip_id);
    }
    SHOW(strip_id);
  }
  return index + 5;
}

/*************************************************************************************/
int O(int poz, int index, uint8_t strip_id) {
  if (poz == index + 2 || poz == index + 3) {
    SETPIXELCOLOR(16, 0, 0, 255, strip_id);
    SETPIXELCOLOR(22, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 1 || poz == index + 4) {
    for (int i = 17; i <= 21; i++) {
      SETPIXELCOLOR(i, 0, 0, 255, strip_id);
    }
    SHOW(strip_id);
  }
  return index + 5;
}

/*************************************************************************************/
int P(int poz, int index, uint8_t strip_id) {
  if (poz == index + 1) {
    SETPIXELCOLOR(20, 255, 255, 0, strip_id);
    SETPIXELCOLOR(21, 255, 255, 0, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 2 || poz == index + 3) {
    SETPIXELCOLOR(19, 255, 255, 0, strip_id);
    SETPIXELCOLOR(22, 255, 255, 0, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 4) {
    for (int i = 16; i <= 22; i++) {
      SETPIXELCOLOR(i, 255, 255, 0, strip_id);
    }
    SHOW(strip_id);
  }
  return index + 5;
}

/*************************************************************************************/
int Q(int poz, int index, uint8_t strip_id) {
  if (poz == index + 1) {
    SETPIXELCOLOR(16, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 2) {
    for (int i = 16; i <= 21; i++) {
      SETPIXELCOLOR(i, 0, 0, 255, strip_id);
    }
    SHOW(strip_id);
  }
  if (poz == index + 3 || poz == index + 4) {
    SETPIXELCOLOR(16, 0, 0, 255, strip_id);
    SETPIXELCOLOR(22, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 5) {
    for (int i = 17; i <= 21; i++) {
      SETPIXELCOLOR(i, 0, 0, 255, strip_id);
    }
    SHOW(strip_id);
  }
  return index + 6;
}

/*************************************************************************************/
int R(int poz, int index, uint8_t strip_id) {
  if (poz == index + 1) {
    SETPIXELCOLOR(16, 0, 0, 255, strip_id);
    SETPIXELCOLOR(17, 0, 0, 255, strip_id);
    SETPIXELCOLOR(18, 0, 0, 255, strip_id);
    SETPIXELCOLOR(20, 0, 0, 255, strip_id);
    SETPIXELCOLOR(21, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 2 || poz == index + 3) {
    SETPIXELCOLOR(19, 0, 0, 255, strip_id);
    SETPIXELCOLOR(22, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 4) {
    for (int i = 16; i <= 22; i++) {
      SETPIXELCOLOR(i, 0, 0, 255, strip_id);
    }
    SHOW(strip_id);
  }
  return index + 5;
}

/*************************************************************************************/
int S(int poz, int index, uint8_t strip_id) {
  if (poz == index + 1) {
    SETPIXELCOLOR(17, 0, 0, 255, strip_id);
    SETPIXELCOLOR(18, 0, 0, 255, strip_id);
    SETPIXELCOLOR(21, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 2 || poz == index + 3) {
    SETPIXELCOLOR(16, 0, 0, 255, strip_id);
    SETPIXELCOLOR(19, 0, 0, 255, strip_id);
    SETPIXELCOLOR(22, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 4) {
    SETPIXELCOLOR(17, 0, 0, 255, strip_id);
    SETPIXELCOLOR(20, 0, 0, 255, strip_id);
    SETPIXELCOLOR(21, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  return index + 5;
}

/*************************************************************************************/
int T(int poz, int index, uint8_t strip_id) {
  if (poz == index + 1 || poz == index + 2 || poz == index + 4 || poz == index + 5) {
    SETPIXELCOLOR(22, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 3) {
    for (int i = 16; i <= 22; i++) {
      SETPIXELCOLOR(i, 0, 0, 255, strip_id);
    }
    SHOW(strip_id);
  }
  return index + 6;
}

/*************************************************************************************/
int U(int poz, int index, uint8_t strip_id) {
  if (poz == index + 1 || poz == index + 4) {
    for (int i = 16; i <= 22; i++) {
      SETPIXELCOLOR(i, 0, 0, 255, strip_id);
    }
    SHOW(strip_id);
  }
  if (poz == index + 2 || poz == index + 3) {
    SETPIXELCOLOR(16, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  return index + 5;
}

/*************************************************************************************/
int V(int poz, int index, uint8_t strip_id) {
  if (poz == index + 1 || poz == index + 4) {
    for (int i = 17; i <= 22; i++) {
      SETPIXELCOLOR(i, 0, 0, 255, strip_id);
    }
    SHOW(strip_id);
  }
  if (poz == index + 2 || poz == index + 3) {
    SETPIXELCOLOR(16, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  return index + 5;
}

/*************************************************************************************/
int W(int poz, int index, uint8_t strip_id) {
  if (poz == index + 1 || poz == index + 3 || poz == index + 5) {
    for (int i = 17; i <= 22; i++) {
      SETPIXELCOLOR(i, 0, 0, 255, strip_id);
    }
    SHOW(strip_id);
  }
  if (poz == index + 2 || poz == index + 4) {
    SETPIXELCOLOR(16, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  return index + 6;
}

/*************************************************************************************/
int X(int poz, int index, uint8_t strip_id) {
  if (poz == index + 1 || poz == index + 4) {
    SETPIXELCOLOR(16, 0, 0, 255, strip_id);
    SETPIXELCOLOR(17, 0, 0, 255, strip_id);
    SETPIXELCOLOR(18, 0, 0, 255, strip_id);
    SETPIXELCOLOR(20, 0, 0, 255, strip_id);
    SETPIXELCOLOR(21, 0, 0, 255, strip_id);
    SETPIXELCOLOR(22, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 2 || poz == index + 3) {
    SETPIXELCOLOR(19, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  return index + 5;
}

/*************************************************************************************/
int Y(int poz, int index, uint8_t strip_id) {
  if (poz == index + 1 || poz == index + 5) {
    SETPIXELCOLOR(20, 0, 0, 255, strip_id);
    SETPIXELCOLOR(21, 0, 0, 255, strip_id);
    SETPIXELCOLOR(22, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 2 || poz == index + 4) {
    SETPIXELCOLOR(19, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 3) {
    SETPIXELCOLOR(16, 0, 0, 255, strip_id);
    SETPIXELCOLOR(17, 0, 0, 255, strip_id);
    SETPIXELCOLOR(18, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  return index + 6;
}

/*************************************************************************************/
int Z(int poz, int index, uint8_t strip_id) {
  if (poz == index + 1) {
    SETPIXELCOLOR(16, 0, 0, 255, strip_id);
    SETPIXELCOLOR(21, 0, 0, 255, strip_id);
    SETPIXELCOLOR(22, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 2) {
    SETPIXELCOLOR(16, 0, 0, 255, strip_id);
    SETPIXELCOLOR(19, 0, 0, 255, strip_id);
    SETPIXELCOLOR(20, 0, 0, 255, strip_id);
    SETPIXELCOLOR(22, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 3) {
    SETPIXELCOLOR(16, 0, 0, 255, strip_id);
    SETPIXELCOLOR(18, 0, 0, 255, strip_id);
    SETPIXELCOLOR(22, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 4) {
    SETPIXELCOLOR(16, 0, 0, 255, strip_id);
    SETPIXELCOLOR(17, 0, 0, 255, strip_id);
    SETPIXELCOLOR(22, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  return index + 5;
}

/*************************************************************************************/
int one(int poz, int index, uint8_t strip_id) {
  if (poz == index + 1) {
    for (int i = 16; i <= 22; i++) {
      SETPIXELCOLOR(i, 0, 0, 255, strip_id);
    }
    SHOW(strip_id);
  }
  if (poz == index + 2) {
    SETPIXELCOLOR(21, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 3) {
    SETPIXELCOLOR(20, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  return index + 4;
}

/*************************************************************************************/
int two(int poz, int index, uint8_t strip_id) {
  if (poz == index + 1) {
    SETPIXELCOLOR(16, 255, 255, 0, strip_id);
    SETPIXELCOLOR(20, 255, 255, 0, strip_id);
    SETPIXELCOLOR(21, 255, 225, 0, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 2) {
    SETPIXELCOLOR(16, 255, 255, 0, strip_id);
    SETPIXELCOLOR(19, 255, 255, 0, strip_id);
    SETPIXELCOLOR(22, 255, 255, 0, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 3) {
    SETPIXELCOLOR(16, 255, 255, 0, strip_id);
    SETPIXELCOLOR(18, 255, 255, 0, strip_id);
    SETPIXELCOLOR(22, 255, 255, 0, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 4) {
    SETPIXELCOLOR(16, 255, 255, 0, strip_id);
    SETPIXELCOLOR(17, 255, 255, 0, strip_id);
    SETPIXELCOLOR(21, 255, 255, 0, strip_id);
    SHOW(strip_id);
  }
  return index + 5;
}

/*************************************************************************************/
int three(int poz, int index, uint8_t strip_id) {
  if (poz == index + 1) {
    SETPIXELCOLOR(17, 0, 0, 255, strip_id);
    SETPIXELCOLOR(18, 0, 0, 255, strip_id);
    SETPIXELCOLOR(20, 0, 0, 255, strip_id);
    SETPIXELCOLOR(21, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 2) {
    SETPIXELCOLOR(16, 0, 0, 255, strip_id);
    SETPIXELCOLOR(19, 0, 0, 255, strip_id);
    SETPIXELCOLOR(22, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 3) {
    SETPIXELCOLOR(16, 0, 0, 255, strip_id);
    SETPIXELCOLOR(22, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 4) {
    SETPIXELCOLOR(17, 0, 0, 255, strip_id);
    SETPIXELCOLOR(22, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }

  return index + 5;
}

/*************************************************************************************/
int four(int poz, int index, uint8_t strip_id) {
  if (poz == index + 1) {
    for (int i = 16; i <= 22; i++) {
      SETPIXELCOLOR(i, 0, 0, 255, strip_id);
    }
    SHOW(strip_id);
  }
  if (poz == index + 2) {
    SETPIXELCOLOR(18, 0, 0, 255, strip_id);
    SETPIXELCOLOR(21, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 3) {
    SETPIXELCOLOR(18, 0, 0, 255, strip_id);
    SETPIXELCOLOR(20, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 4) {
    SETPIXELCOLOR(18, 0, 0, 255, strip_id);
    SETPIXELCOLOR(19, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  return index + 5;
}

/*************************************************************************************/
int five(int poz, int index, uint8_t strip_id) {
  if (poz == index + 1) {
    SETPIXELCOLOR(17, 0, 0, 255, strip_id);
    SETPIXELCOLOR(18, 0, 0, 255, strip_id);
    SETPIXELCOLOR(21, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 2 || poz == index + 3) {
    SETPIXELCOLOR(16, 0, 0, 255, strip_id);
    SETPIXELCOLOR(19, 0, 0, 255, strip_id);
    SETPIXELCOLOR(22, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 4) {
    SETPIXELCOLOR(17, 0, 0, 255, strip_id);
    SETPIXELCOLOR(20, 0, 0, 255, strip_id);
    SETPIXELCOLOR(21, 0, 0, 255, strip_id);
    SETPIXELCOLOR(22, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  return index + 5;
}

/*************************************************************************************/
int six(int poz, int index, uint8_t strip_id) {
  if (poz == index + 1) {
    SETPIXELCOLOR(17, 0, 0, 255, strip_id);
    SETPIXELCOLOR(18, 0, 0, 255, strip_id);
    SETPIXELCOLOR(21, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 2 || poz == index + 3) {
    SETPIXELCOLOR(16, 0, 0, 255, strip_id);
    SETPIXELCOLOR(19, 0, 0, 255, strip_id);
    SETPIXELCOLOR(22, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 4) {
    for (int i = 17; i <= 21; i++) {
      SETPIXELCOLOR(i, 0, 0, 255, strip_id);
    }
    SHOW(strip_id);
  }
  return index + 5;
}

/*************************************************************************************/
int seven(int poz, int index, uint8_t strip_id) {
  if (poz == index + 1) {
    SETPIXELCOLOR(20, 0, 0, 255, strip_id);
    SETPIXELCOLOR(21, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 2) {
    SETPIXELCOLOR(19, 0, 0, 255, strip_id);
    SETPIXELCOLOR(22, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 3) {
    SETPIXELCOLOR(18, 0, 0, 255, strip_id);
    SETPIXELCOLOR(22, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 4) {
    SETPIXELCOLOR(16, 0, 0, 255, strip_id);
    SETPIXELCOLOR(17, 0, 0, 255, strip_id);
    SETPIXELCOLOR(22, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  return index + 5;
}

/*************************************************************************************/
int eight(int poz, int index, uint8_t strip_id) {
  if (poz == index + 1 || poz == index + 4) {
    SETPIXELCOLOR(17, 0, 0, 255, strip_id);
    SETPIXELCOLOR(18, 0, 0, 255, strip_id);
    SETPIXELCOLOR(20, 0, 0, 255, strip_id);
    SETPIXELCOLOR(21, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 2 || poz == index + 3) {
    SETPIXELCOLOR(16, 0, 0, 255, strip_id);
    SETPIXELCOLOR(19, 0, 0, 255, strip_id);
    SETPIXELCOLOR(22, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }

  return index + 5;
}

/*************************************************************************************/
int nine(int poz, int index, uint8_t strip_id) {
  if (poz == index + 1) {
    for (int i = 17; i <= 21; i++) {
      SETPIXELCOLOR(i, 0, 0, 255, strip_id);
    }
    SHOW(strip_id);
  }
  if (poz == index + 2 || poz == index + 3) {
    SETPIXELCOLOR(16, 0, 0, 255, strip_id);
    SETPIXELCOLOR(19, 0, 0, 255, strip_id);
    SETPIXELCOLOR(22, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 2) {
    SETPIXELCOLOR(17, 0, 0, 255, strip_id);
    SETPIXELCOLOR(20, 0, 0, 255, strip_id);
    SETPIXELCOLOR(21, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  return index + 5;
}

/*************************************************************************************/
int zero(int poz, int index, uint8_t strip_id) {
  if (poz == index + 1 || poz == index + 4) {
    for (int i = 17; i <= 21; i++) {
      SETPIXELCOLOR(i, 0, 0, 255, strip_id);
    }
    SHOW(strip_id);
  }
  if (poz == index + 2) {
    SETPIXELCOLOR(16, 0, 0, 255, strip_id);
    SETPIXELCOLOR(19, 0, 0, 255, strip_id);
    SETPIXELCOLOR(22, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 3) {
    SETPIXELCOLOR(16, 0, 0, 255, strip_id);
    SETPIXELCOLOR(18, 0, 0, 255, strip_id);
    SETPIXELCOLOR(22, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  return index + 5;
}

/*************************************************************************************/
int space(int poz, int index, uint8_t strip_id) {
  if (poz == index + 1) {
    for (int i = 16; i <= 22; i++) {
      SETPIXELCOLOR(i, 0, 0, 0, strip_id);
    }
    SHOW(strip_id);
  }
  return index + 2;
}

/*************************************************************************************/
int slash(int poz, int index, uint8_t strip_id){
  if (poz == index + 1) {
    SETPIXELCOLOR(21, 0, 0, 255, strip_id);
    SETPIXELCOLOR(22, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 2) {
    SETPIXELCOLOR(19, 0, 0, 255, strip_id);
    SETPIXELCOLOR(20, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 3) {
    SETPIXELCOLOR(18, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 4) {
    SETPIXELCOLOR(16, 0, 0, 255, strip_id);
    SETPIXELCOLOR(17, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  return index + 5;
}

/*************************************************************************************/
int smile(int poz, int index, uint8_t strip_id) {
  if (poz == index + 1 || poz == index + 16) {
    SETPIXELCOLOR(11, 0, 0, 255, strip_id);
    SETPIXELCOLOR(12, 0, 0, 255, strip_id);
    SETPIXELCOLOR(13, 0, 0, 255, strip_id);
    SETPIXELCOLOR(14, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 2 || poz == index + 15) {
    SETPIXELCOLOR(9, 0, 0, 255, strip_id);
    SETPIXELCOLOR(10, 0, 0, 255, strip_id);
    SETPIXELCOLOR(15, 0, 0, 255, strip_id);
    SETPIXELCOLOR(16, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 3 || poz == index + 14) {
    SETPIXELCOLOR(8, 0, 0, 255, strip_id);
    SETPIXELCOLOR(17, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 4 || poz == index + 13) {
    SETPIXELCOLOR(7, 0, 0, 255, strip_id);
    SETPIXELCOLOR(18, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 5 || poz == index + 12) {
    SETPIXELCOLOR(6, 0, 0, 255, strip_id);
    SETPIXELCOLOR(11, 0, 0, 255, strip_id);
    SETPIXELCOLOR(14, 0, 0, 255, strip_id);
    SETPIXELCOLOR(15, 0, 0, 255, strip_id);
    SETPIXELCOLOR(19, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 6 || poz == index + 11) {
    SETPIXELCOLOR(6, 0, 0, 255, strip_id);
    SETPIXELCOLOR(10, 0, 0, 255, strip_id);
    SETPIXELCOLOR(14, 0, 0, 255, strip_id);
    SETPIXELCOLOR(15, 0, 0, 255, strip_id);
    SETPIXELCOLOR(19, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  if (poz == index + 7 || poz == index + 8 || poz == index + 9 || poz == index + 10) {
    SETPIXELCOLOR(5, 0, 0, 255, strip_id);
    SETPIXELCOLOR(9, 0, 0, 255, strip_id);
    SETPIXELCOLOR(20, 0, 0, 255, strip_id);
    SHOW(strip_id);
  }
  return index + 17;
}

/*************************************************************************************/
int heart(int poz, int index, uint8_t strip_id){
    if (poz == index + 1 || poz == index + 7 ) {
    SETPIXELCOLOR(16, 255, 0, 255, strip_id);
    SETPIXELCOLOR(17, 255, 0, 255, strip_id);
    SETPIXELCOLOR(18, 255, 0, 255, strip_id);
    SHOW(strip_id);
    }
    if (poz == index + 2 || poz == index + 6) {
     for (int i = 14; i <= 20; i++) {
        SETPIXELCOLOR(i, 255, 0, 255, strip_id);
      }
      SHOW(strip_id);
    }
    if (poz == index + 3 || poz == index + 5) {
     for (int i = 11; i <= 22; i++) {
        SETPIXELCOLOR(i, 255, 0, 255, strip_id);
      }
      SHOW(strip_id);
    }
    if (poz == index + 4) {
     for (int i = 9; i <= 19; i++) {
        SETPIXELCOLOR(i, 255, 0, 255, strip_id);
      }
      SHOW(strip_id);
    }
  
    return index + 8;
}

/*************************************************************************************/
int welcome_sentence(int poz, int index, uint8_t strip_id){
  
  static int next_led = 0;
  static int next_color = 0;
  static int counter = 0;
  counter+=1;

  if(poz==0){
      next_led+=1;
      displayClear(STRIP_0_ID);
      displayClear(STRIP_1_ID);
      #ifdef STRIP4
      displayClear(STRIP_2_ID);
      displayClear(STRIP_3_ID);
      #endif
  }

    switch (next_color) {
      case 0: {
          SETPIXELCOLOR(next_led, 255, 0, 0, strip_id);
          SHOW(strip_id);
          break;
        }
      case 1: {
          SETPIXELCOLOR(next_led, 0, 255, 0, strip_id);
          SHOW(strip_id);
          break;
        }
      case 2: {
          SETPIXELCOLOR(next_led, 0, 0, 255, strip_id);
          SHOW(strip_id);
          break;
        }
      case 3: {
          SETPIXELCOLOR(next_led, 255, 0, 255, strip_id);
          SHOW(strip_id);
          break;
        }
      default: {
          displayClear(STRIP_0_ID);
          displayClear(STRIP_1_ID);
          #ifdef STRIP4
          displayClear(STRIP_2_ID);
          displayClear(STRIP_3_ID);
          #endif          
          next_color = 0;
          break;
        }
    }

    if (next_led >= 23) {
      displayClear(STRIP_0_ID);
      displayClear(STRIP_1_ID);
      #ifdef STRIP4
      displayClear(STRIP_2_ID);
      displayClear(STRIP_3_ID);
      #endif
      next_led = 0;
      next_color+=1;

    }
return 1;
}