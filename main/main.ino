#include "include/auto_show.h"
#include "include/dmx_show.h"
#include "include/config.h"
#include "include/motor.h"
#include "include/color.h"

enum RUN_MODE{
  dmx,
  automat
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

  
  // Timer1 (Pins D9 and D10) - 15.6 kHz 10bit
  TCCR1A = 0b00000011; // 10bit
  TCCR1B = 0b00001001; // 15.6 kHz

  pinMode(red_pin, OUTPUT);
  pinMode(green_pin, OUTPUT);
  pinMode(blue_pin, OUTPUT);
  // pinMode(alim_laser, OUTPUT);
  // digitalWrite(alim_laser, HIGH);
  pinMode(motor_1, OUTPUT);
  pinMode(motor_2, OUTPUT);
  set_black();

  DMXSerial.init(DMXReceiver);
  delay(500);
  mode = no_DMX_connection() ? automat : dmx;
  
  //wake_up();
}

//---------------------------------------------------------------------------
// MAIN LOOP
//---------------------------------------------------------------------------
void loop() {
  if (mode == automat){
    while(true){
      AUTO::auto_loop();  //runs the automated sequence indefinitely
    }
  }

  
  DMX::DMX_loop(); // runs the DMX function
}

 







 
