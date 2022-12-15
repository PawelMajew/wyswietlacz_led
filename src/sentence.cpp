/*
//
//
//add function responsible for displaying
//
//
*/
/*
//@ !author: Paweł Majewski
*/

#include <Arduino.h>
#include <string.h>

#include "sentence.h"
#include "engine.h"
#include "sign.h"
#include "flags.h"


void startSentence(int zegar_pozycja, int strip_id);                                    //next level with write strion or display picture
void readySign(int zegar_pozycja, int strip_id);                                        //picture selection
void readySentence(int zegar_pozycja, int strip_id, int speed_sentence);                //displaying characters from buffor
int readSign(int index, int index_tablicy, int zegar_pozycja, int strip_id, char *cmd); //decryption of characters
void welcomeSentence(int zegar_pozycja, int strip_id);                                  //simple sentence for start

/*************************************************************************************/
void sentence(int zegar_pozycja, int strip_id){
    flags *Flaga = flags();

    if(Flaga->flaga == 1){
        startSentence(zegar_pozycja, strip_id);
    }else{
        welcomeSentence(zegar_pozycja,strip_id);
    }
 
}

void startSentence(int zegar_pozycja, int strip_id){
    flags *Flaga = flags();

    if(Flaga->flaga_1 == 1){
        readySign(zegar_pozycja, strip_id);
    } else{
        readySentence(zegar_pozycja, strip_id, 0);
    }

}

void readySign(int zegar_pozycja, int strip_id){
    buf *Buffor = buf();
    int index = 0;

    if(strcmp(Buffor->buffor,"heart")==0){
        index = heart(zegar_pozycja, index, strip_id);
    }else if(strcmp(Buffor->buffor,"speed") == 0){
        readySentence(zegar_pozycja, strip_id, 1);
    }else{
        index = smile(zegar_pozycja, index, strip_id);
    }

}

void welcomeSentence(int zegar_pozycja, int strip_id){
    int index = 0;

    index = welcome_sentence(zegar_pozycja, index, strip_id);
}

void readySentence(int zegar_pozycja, int strip_id, int speed_sentence){
    buf *Buffor = buf();
    int index = 0;
    const char* km = "  km/h";
    tim *Tim = tim();
    int speed = (int)Tim->speed;
    char char_speed[3+5];//3-number :: 3-km/h

    sprintf(char_speed,"%d",speed);
    strcat(char_speed, km);

    if(speed_sentence != 1){
        for(int i = Buffor->index;i>=0; i--){
            index = readSign(index, i, zegar_pozycja, strip_id, Buffor->buffor);
        }
    }else{
        for(int i = sizeof(char_speed);i>=0; i--){
            index = readSign(index, i, zegar_pozycja, strip_id, char_speed);
        }    
    }
}

int readSign(int index, int index_tablicy, int zegar_pozycja, int strip_id, char *cmd){
    
    switch(cmd[index_tablicy]){
        case 'a':
            return A(zegar_pozycja,index,strip_id);
            break;
        case 'b':
            return B(zegar_pozycja, index, strip_id);
            break;
        case 'c':
            return C(zegar_pozycja, index, strip_id);
            break;
        case 'd':
            return D(zegar_pozycja,index,strip_id);
            break;
        case 'e':
            return E(zegar_pozycja, index, strip_id);
            break;
        case 'f':
            return FF(zegar_pozycja, index, strip_id);
            break;
        case 'g':
            return G(zegar_pozycja, index, strip_id);
            break;
        case 'h':
            return H(zegar_pozycja,index,strip_id);
            break;
        case 'i':
            return I(zegar_pozycja, index, strip_id);
            break;
        case 'j':
            return J(zegar_pozycja, index, strip_id);
            break;
        case 'k':
            return K(zegar_pozycja, index, strip_id);
            break;
        case 'l':
            return L(zegar_pozycja,index,strip_id);
            break;
        case 'm':
            return M(zegar_pozycja, index, strip_id);
            break;
        case 'n':
            return N(zegar_pozycja, index, strip_id);
            break;
        case 'o':
            return O(zegar_pozycja, index, strip_id);
            break;
        case 'p':
            return P(zegar_pozycja, index, strip_id);
            break;
        case 'q':
            return Q(zegar_pozycja, index, strip_id);
            break;
        case 'r':
            return R(zegar_pozycja, index, strip_id);
            break;
        case 's':
            return S(zegar_pozycja,index,strip_id);
            break;
        case 't':
            return T(zegar_pozycja, index, strip_id);
            break;
        case 'u':
            return U(zegar_pozycja, index, strip_id);
            break;
        case 'w':
            return W(zegar_pozycja, index, strip_id);
            break;
        case 'x':
            return X(zegar_pozycja,index,strip_id);
            break;
        case 'y':
            return Y(zegar_pozycja, index, strip_id);
            break;
        case 'z':
            return Z(zegar_pozycja, index, strip_id);
            break;
        case '0':
            return zero(zegar_pozycja, index, strip_id);
            break;
        case '1':
            return one(zegar_pozycja,index,strip_id);
            break;
        case '2':
            return two(zegar_pozycja, index, strip_id);
            break;
        case '3':
            return three(zegar_pozycja, index, strip_id);
            break;
        case '4':
            return four(zegar_pozycja, index, strip_id);
            break;
        case '5':
            return five(zegar_pozycja,index,strip_id);
            break;
        case '6':
            return six(zegar_pozycja, index, strip_id);
            break;
        case '7':
            return seven(zegar_pozycja, index, strip_id);
            break;
        case '8':
            return eight(zegar_pozycja, index, strip_id);
            break;
        case '9':
            return nine(zegar_pozycja,index,strip_id);
            break;
        case ' ':
            return space(zegar_pozycja,index,strip_id);
            break;
        case '/':
            return slash(zegar_pozycja,index,strip_id);
            break;
        default:
            return space(zegar_pozycja, index, strip_id);
            break;
    }
    return 0;
}