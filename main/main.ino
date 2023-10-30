#include "include/auto_show.h"
#include "include/dmx_show.h"
#include "include/config.h"
#include "include/motor.h"
#include "include/color.h"

enum RUN_MODE{
  DMX,
  AUTO
};
RUN_MODE mode;
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
    while(true){
      auto_loop();  //runs the automated sequence indefinitely
    }
  }

  
  DMX_loop(); // runs the DMX function
  
  
}

 







 
