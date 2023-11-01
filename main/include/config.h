#pragma once
#include <DMXSerial.h>


// Arduino output pin config
#define red_pin 3
#define green_pin 5
#define blue_pin 6
#define alim_laser 4
#define motor_1 10
#define motor_2 9

// DMX config
#define laser_addr      14
#define laser_M1Ch      1
#define laser_M2Ch      2
#define laser_Rch       3
#define laser_Gch       4
#define laser_Bch       5
#define laser_aniCh     6
#define laser_motCalCh  7
#define laser_lasCalCh  8

#define d_anim (unsigned long)20000        //ms

#define d_pause (unsigned long)20000       //ms
#define d_pause_mini (unsigned long)2000   //ms 

#define dmx_address 14  
