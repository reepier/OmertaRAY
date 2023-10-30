

#include "auto_show.h"
#include "config.h"

int dmx_address = 14;

enum RUN_MODE{
  DMX,
  AUTO
};
RUN_MODE mode;
void DMX_show();
bool no_DMX_connection(){return DMXSerial.noDataSince() > 100;}
//-----------------------------------------------------------------------------------
// SETUP
//-----------------------------------------------------------------------------------
void setup() {
  #ifndef DmxSerial_h
  Serial.begin(9600);
  #endif 

  
  // SET motors (pin 9 10) pwm freq to 32kHz to avoid perceptible harmonics
  // TCCR1B = TCCR1B & B11111000 | B00000001; // set timer 1 divisor to 1 for PWM frequency of 31372.55 Hz
  // Pins D9 and D10 - 15.6 kHz 10bit
  TCCR1A = 0b00000011; // 10bit
  TCCR1B = 0b00001001; // x1 fast pwm

  pinMode(red_pin, OUTPUT);
  pinMode(green_pin, OUTPUT);
  pinMode(blue_pin, OUTPUT);
  // pinMode(alim_laser, OUTPUT);
  // digitalWrite(alim_laser, HIGH);
  pinMode(motor_1, OUTPUT);
  pinMode(motor_2, OUTPUT);
  black();

  DMXSerial.init(DMXReceiver);
  delay(500);
  mode = no_DMX_connection() ? AUTO : DMX;
  
  //wake_up();
}

//---------------------------------------------------------------------------
// MAIN LOOP
//---------------------------------------------------------------------------
void loop() {
  if (mode == AUTO){
    auto_show();
  }else if (mode == DMX){
    while (true)
      DMX_show();
  }
}

 
void DMX_show(){
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






 
