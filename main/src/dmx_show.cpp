#include <Arduino.h>
#include <DMXSerial.h>

#include "../include/config.h"
#include "../include/motor.h"
#include "../include/color.h"

void DMX_loop(){
  uint8_t dmx[5];
  for (int i=0; i<5; i++){
    dmx[i] = DMXSerial.read(dmx_address + i);
  }
  set_motor_speed(dmx[0], dmx[1]);
  
  if(dmx[0]<40 && dmx[1]<40){
    black();
  }else{
    analogWrite(red_pin, dmx[2]);
    analogWrite(green_pin, dmx[3]);
    analogWrite(blue_pin, dmx[4]);
  }
  delay(20);
}