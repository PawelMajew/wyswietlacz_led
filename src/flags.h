/*
//
//
//File with global variables and structs used in project
//
//
//
*/
/*
//@ !author: Paweł Majewski
*/

#ifndef FLAGS
#define FLAGS

#include "program_setup.h"

/*structure for storing flags
@param  flag_start_[number] <--set when the signal from the corresponding hall sensor is detected
@param  flaga               <--set when you want to change the program status()
@param  flaga_1             <--set when you want to change the program status()
*/
typedef struct
{
    bool flag_start_1;
    bool flag_start_2;
#ifdef STRIP4
    bool flag_start_3;
    bool flag_start_4;
#endif
    int flaga;
    int flaga_1;    
}flags;

extern flags flags_addr;

#define flags() (&flags_addr)

/*structure for storing time
@param  read_time           <--stores the time since the program is started
@param  cur_time            <--stores the current time sincethe program is started
@param  prev_time           <--stores the previous time, one reading earlier
@param  tim_600             <--stores the value of the calculated length of time when LED on
@param  tim_150             <--stores the value of the calculated length of time when LED off
@param  diff                <--stores the time difference
@param  prev_tim_150        <--stores the previous value of the calculated length of time when LED off
@param  prev_tim_600        <--stores the previous value of the calculated length of time when LED on
@param  speed               <--stores the calculated speed
@param  prev_speed          <--stores the previous calculated speed
*/
typedef struct
{
    double read_time;
    double cur_time;
    double prev_time=0;
    double tim_600;
    double tim_150;
    double diff;
    double prev_tim_150;
    double prev_tim_600;
    double speed;
    double prev_speed;
    double test_150;
    double test_600;
}tim;

extern tim tim_addr;

#define tim() (&tim_addr)

/*structure for storing data from bluetooth
@param  buffor[100]         <--stores the received data
@param  buffor_index        <--stores the current buffor index
@param  index               <--stores the number of characters
*/
typedef struct
{
    char buffor[100];
    uint16_t buffor_index;
    uint16_t index;
}buf;

extern buf buf_addr;

#define buf() (&buf_addr)

/*strip ID*/
#define STRIP_0_ID  0
#define STRIP_1_ID  1
#ifdef STRIP4
#define STRIP_2_ID  2
#define STRIP_3_ID  3
#endif


#endif /*FLAGS*/