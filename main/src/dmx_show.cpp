#include <Arduino.h>
#include <DMXSerial.h>

#include "../include/dmx_show.h"
#include "../include/config.h"
#include "../include/motor.h"
#include "../include/color.h"

namespace DMX{

struct LaserData{
  int motor1;
  int motor2;
  bool red;
  bool green;
  bool blue;
  int animation_i;
  int motor_calib;
  int laser_calib;
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
  set_motor_speed(laser.motor1, laser.motor2);
  if(laser.motor1<40 && laser.motor2<40){
    digitalWrite(red_pin, LOW);
    digitalWrite(green_pin, LOW);
    digitalWrite(blue_pin, LOW);
  }else{
    digitalWrite(red_pin, laser.red);
    digitalWrite(green_pin, laser.green);
    digitalWrite(blue_pin, laser.blue);
  }
}

void dmx_fcn_template(){
  unsigned long start = millis();
  while(!animation_change()){
    if ((millis()-start)%5000 < 2500){
      set_red();
    }else{
      set_green();
    }
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
  simpleColor _palette[16];
  color_vec palette;
  palette.setStorage(_palette);  

  DMX_read();

  switch(laser.animation_i){
    case 0: // manual mode
      DMX_Manual();
      break;

    case 1:
      set_green();

      break;

    case 2:
      set_cyan();
      break;

    case 3 : 
      dmx_fcn_template();
      break;

    case 4:
      palette.push_back(white);
      palette.push_back(red);
      circle_dance(palette);
      break;
    
    case 5:
      palette.push_back(white);
      palette.push_back(blue);
      circle_dance(palette);
      break;
    
    case 6:
      palette.push_back(cyan);
      palette.push_back(magenta);
      circle_dance(palette);
      break;
    
    case 7:
      palette.push_back(yellow);
      palette.push_back(red);
      circle_dance(palette);
      break;

    case 8:

      break;
    case 9:
    
      break;
    case 10:
    
      break;
    case 11:
    
      break;
    case 12:
    
      break;
    case 13:
    
      break;
    case 14:
    
      break;
    case 15:
    
      break;
    case 16:
    
      break;
    case 17:
    
      break;
    case 18:
    
      break;
    case 19:
    
      break;
    case 20:
    
      break;
    case 21:
    
      break;
    case 22:
    
      break;
    case 23:
    
      break;
    case 24:
    
      break;


    default:  // preset mode
      break;
       
  }
  
palette.clear();
  delay(20);
}



// Built-in FUNCTIONS :


void circle_dance(color_vec c, unsigned long period){
  const unsigned long shake_delay = 200;
  
  const unsigned long start = millis();
  const uint8_t nc = c.size();

  uint8_t circle_cpt=0, phase = 0;
  
  while(!animation_change()){

    int t = (millis()-start)%period;
    switch (phase){
    
    case 0:
      phase = 1;
      break;
    
    case 1: // display circle
      // set motor to speed
      set_motor_speed( circle_cpt%2 ? 180:15, circle_cpt%2 ? 15:180);
      //chose color within palette
      setColor(c[ circle_cpt%nc ]);
      // check for transition
      if (t > period-200)
        phase = 2;
      break;
    
    case 2: // change circle
      // set motor to speed
      set_motor_speed( circle_cpt%2 ? 180:255, circle_cpt%2 ? 255:180);
      // increment 
      //check for next transition
      if (t < period-shake_delay){
        phase = 1;
        circle_cpt++;
      }
      break;

    default:
      break;
    }

  }
  STOP();
  
}
}



void setColor(simpleColor c){
  switch(c){
    case black :
      set_black();
      break;
    case white :
      set_white();
      break;
    case red :
      set_red();
      break;
    case green :
      set_green();
      break;
    case blue :
      set_blue();
      break;
    case cyan :
      set_cyan();
      break;
    case magenta :
      set_magenta();
      break;
    case yellow :
      set_yellow();
      break;
  }
}