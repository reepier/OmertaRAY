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

simpleColor _palette[16];
color_vec palette(_palette);

void DMX_loop(){
  
  DMX_read();

  switch(laser.animation_i){
    case 0: // manual mode
      DMX_Manual();
      break;

    case 1:
      palette.push_back(red);
      circle_dance();
      break;
    case 2:
      palette.push_back(green);
      circle_dance();
      break;
    case 3 : 
      palette.push_back(blue);
      circle_dance();
      break;
    case 4:
      palette.push_back(yellow);
      circle_dance();
      break;
    case 5:
      palette.push_back(cyan);
      circle_dance();
      break;
    case 6:
      palette.push_back(magenta);
      circle_dance();
      break;
    case 7:
      palette.push_back(white);
      circle_dance();
      break;
    case 8:
      palette.push_back(white);
      palette.push_back(red);
      circle_dance();
      break;
    case 9:
      palette.push_back(white);
      palette.push_back(green);
      circle_dance();
      break;
    case 10:
      palette.push_back(white);
      palette.push_back(blue);
      circle_dance();
      break;
    case 11:
      palette.push_back(white);
      palette.push_back(yellow);
      circle_dance();
      break;
    case 12:
      palette.push_back(white);
      palette.push_back(cyan);
      circle_dance();
      break;
    case 13:
      palette.push_back(white);
      palette.push_back(magenta);
      circle_dance();
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
      palette.push_back(white);
      palette.push_back(red);
      glitch();
      break;
    case 21:
      palette.push_back(white);
      palette.push_back(green);
      glitch();
      break;
    case 22:
      palette.push_back(white);
      palette.push_back(blue);
      glitch();    
      break;
    case 23:
      palette.push_back(white);
      palette.push_back(yellow);
      glitch();
      break;
    case 24:
      palette.push_back(white);
      palette.push_back(cyan);
      glitch();
      break;
    case 25	:
      palette.push_back(white);
      palette.push_back(magenta);
      glitch();
      break;
    case 26	:
      palette.push_back(red);
      glitch();
      break;
    case 27	:
      palette.push_back(green);
      glitch();
      break;
    case 28	:
      palette.push_back(blue);
      glitch();
      break;
    case 29	:
      palette.push_back(yellow);
      glitch();
      break;
    case 30	:
      palette.push_back(cyan);
      glitch();
      break;
    case 31	:
      palette.push_back(magenta);
      glitch();
      break;
    case 32	:
      palette.push_back(white);
      glitch();
      break;
    case 33	:
      
      break;
    case 34	:
      
      break;
    case 35	:
      
      break;
    case 36	:
      
      break;
    case 37	:
      
      break;
    case 38	:
      
      break;
    case 39	:
      
      break;
    case 40	:
      
      break;
    case 41	:
      
      break;
    case 42	:
      
      break;
    case 43	:
      
      break;
    case 44	:
      
      break;
    case 45	:
      
      break;
    case 46	:
      
      break;
    case 47	:
      
      break;
    case 48	:
      
      break;
    case 49	:
      
      break;
    case 50	:
      palette.push_back(white);
      palette.push_back(red);
      palm_dance();
      break;
    case 51	:
      palette.push_back(white);
      palette.push_back(green);
      palm_dance();
      break;
    case 52	:
      palette.push_back(white);
      palette.push_back(blue);
      palm_dance();
      break;
    case 53	:
      palette.push_back(white);
      palette.push_back(yellow);
      palm_dance();
      break;
    case 54	:
      palette.push_back(white);
      palette.push_back(cyan);
      palm_dance();
      break;
    case 55	:
      palette.push_back(red);
      palette.push_back(magenta);
      palm_dance();
      break;
    case 56	:
      palette.push_back(red);
      palette.push_back(black);
      palm_dance();
      break;
    case 57	:
      palette.push_back(green);
      palette.push_back(black);
      palm_dance();
      break;
    case 58	:
      palette.push_back(blue);
      palette.push_back(black);
      palm_dance();
      break;
    case 59	:
      palette.push_back(yellow);
      palette.push_back(black);
      palm_dance();
      break;
    case 60	:
      palette.push_back(cyan);
      palette.push_back(black);
      palm_dance();
      break;
    case 61	:
      palette.push_back(magenta);
      palette.push_back(black);
      palm_dance();
      break;
    case 62	:
      palette.push_back(white);
      palette.push_back(black);
      palm_dance();
      break;
    case 63	:
      
      break;
    case 64	:
      
      break;
    case 65	:
      
      break;
    case 66	:
      
      break;
    case 67	:
      
      break;
    case 68	:
      
      break;
    case 69	:
      
      break;
    case 70	:
      
      break;
    case 71	:
      
      break;
    case 72	:
      
      break;
    case 73	:
      
      break;
    case 74	:
      
      break;
    case 75	:
      
      break;
    case 76	:
      
      break;
    case 77	:
      
      break;
    case 78	:
      
      break;
    case 79	:
      
      break;
    case 80	:
      palette.push_back(black);
      palette.push_back(white);
      whip();
      break;
    case 81	:
      palette.push_back(black);
      palette.push_back(red);
      whip();
      break;
    case 82	:
      palette.push_back(black);
      palette.push_back(green);
      whip();
      break;
    case 83	:
      palette.push_back(black);
      palette.push_back(blue);
      whip();
      break;
    case 84	:
      palette.push_back(black);
      palette.push_back(cyan);
      whip();
      break;
    case 85	:
      palette.push_back(black);
      palette.push_back(magenta);
      whip();
      break;
    case 86	:
      palette.push_back(black);
      palette.push_back(yellow);
      whip();
      break;
    case 87	:
      palette.push_back(white);
      palette.push_back(red);
      whip();
      break;
    case 88	:
      palette.push_back(white);
      palette.push_back(green);
      whip();
      break;
    case 89	:
      palette.push_back(white);
      palette.push_back(blue);
      whip();
      break;
    case 90	:
      palette.push_back(white);
      palette.push_back(cyan);
      whip();
      break;
    case 91	:
      palette.push_back(white);
      palette.push_back(magenta);
      whip();
      break;
    case 92	:
      palette.push_back(white);
      palette.push_back(yellow);
      whip();
      break;
    case 93	:
      
      break;
    case 94	:
      
      break;
    case 95	:
      
      break;
    case 96	:
      
      break;
    case 97	:
      
      break;
    case 98	:
      
      break;
    case 99	:
      
      break;
    case 100	:

      break;
    
    default:  // preset mode
      break;
       
  }

STOP();
palette.clear();
  delay(20);
}



// Built-in FUNCTIONS :


void circle_dance(unsigned long period){
  const unsigned long shake_duration = 200;
  const unsigned long start = millis();
  const uint8_t nc = palette.size();
  uint8_t circle_cpt=0, phase = 0;
  
  while(!animation_change()){
    int t = (millis()-start)%period;
    switch (phase){
    
    case 0:
      phase = 1;
      break;
    
    case 1: // display circle
      // set motor to speed & chose color within palette
      set_motor_speed( circle_cpt%2 ? 180:15, circle_cpt%2 ? 15:180);
      setColor(palette[ circle_cpt%nc ]);
      // check for transition
      if (t > period-200)
        phase = 2;
      break;
    
    case 2: // change circle
      // set motor to speed
      set_motor_speed( circle_cpt%2 ? 180:255, circle_cpt%2 ? 255:180);
      //check for next transition
      if (t < period-shake_duration){
        phase = 1;
        circle_cpt++;
      }
      break;

    default:
      break;
    }

    delay(20);
  }
  STOP();
  
}


void glitch(unsigned long bmin, unsigned long bmax, unsigned long fmin, unsigned long fmax){
  randomSeed(analogRead(A0));
  const uint8_t nc = palette.size();
  set_motor_speed(50,40);

  
  while(!animation_change()){
    // wait for a random duration
    set_black();
    delay(random(bmin, bmax));
    // switch on the laser for a random (short) duration
    setColor(palette[random(0, palette.size())]);
    delay(random(fmin, fmax));
  }
}


void palm_dance(){
  set_motor_speed(50, 68);
  while(!animation_change()){
    ribbon(100, 1000);
    set_black();
    delay(500);
  }
}

void whip(){
  set_motor_speed(50,45);
  while(!animation_change())
    ribbon(500, 5000);
}

// !! insert new animation above this line !! 

/** - duration in milliseconds
 *  - p in microseconds*/
void ribbon(unsigned long duration_ms, unsigned long p_us){
  uint8_t i = 0;
  unsigned long start = millis();
  uint8_t n_color = palette.size();
  unsigned long period = p_us/n_color;
  
  while(millis()-start <= duration_ms){
    setColor(palette[i]);
    delayMicroseconds(period);
    i = (i+1)%n_color;
  }
}
}// end of namespace DMX::



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