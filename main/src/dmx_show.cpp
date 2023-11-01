#include <Arduino.h>
#include <DMXSerial.h>

#include "../include/config.h"
#include "../include/motor.h"
#include "../include/color.h"

struct LaserData{
  uint8_t motor1;
  uint8_t motor2;
  bool red;
  bool green;
  bool blue;
  uint8_t animation_i;
  uint8_t motor_calib;
  uint8_t laser_calib;
};
volatile LaserData laser;

// updates the DMX buffer
void DMX_read(){
  uint8_t* buf = DMXSerial.getBuffer();   //returns the entire DMX frame
  uint8_t* laser_buf = buf + laser_addr;  //returns the part of the dmx frame containing laser channels

  laser.motor1 = laser_buf[laser_M1Ch-1]; 
  laser.motor2 = laser_buf[laser_M2Ch-1]; 
  laser.red = (bool)laser_buf[laser_Rch-1];
  laser.green = (bool)laser_buf[laser_Gch-1];
  laser.blue = (bool)laser_buf[laser_Bch-1];
  laser.animation_i = laser_buf[laser_aniCh-1];
}

// updates DMX buffer & checs wether or not the animation indice has changed
bool animation_change(){
  uint8_t current_animation = laser.animation_i;
  DMX_read();
  return laser.animation_i != current_animation;
}

// Commands the laser output channel by channel (motors, laser diodes) (manual mode)
void DMX_Manual(){
  set_motor_speed(laser.motor1, laser.motor1);
  if(laser.motor1<40 && laser.motor2<40){
    black();
  }else{
    digitalWrite(red_pin, laser.red);
    digitalWrite(green_pin, laser.green);
    digitalWrite(blue_pin, laser.blue);
  }
}


/** PRINCIPLES for using  the built_in animation index:
 * - once the laser receives an animation indice, it runs the corresponding animation.
 * - since most laser animations require high (and irregular) frequency update, it is impossible to code them using a constant frequency, frame-by-frame approach (as with the other DMX fixtures)
 * - each function runs on an high frequency loop that exits when laser.animation changes. 
 * - every animation function must then check at a reasonbale frequency (~20Hz) wether or not it should stop running (to allow for another animation to take over)
 *    --> using bool animation_change() function and return statement
 
*/
void DMX_catalog(uint8_t animation){
  // switch(animation){

  // }
}

void DMX_loop(){
  DMX_read();

  switch(laser.animation_i){
    case 0: // manual mode
      DMX_Manual();
      break;
    default:  // preset mode
      DMX_catalog(laser.animation_i);
      break;
       
  }

  delay(20);
}



// Built-in FUNCTIONS :