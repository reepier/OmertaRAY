#pragma once

#include "config.h"
namespace AUTO{

extern uint8_t color[9]; // array used to pass color palettes to animation functions
void auto_loop();
//---------------------------------------------------------------------------
// Animations low level
//---------------------------------------------------------------------------
void glitter(unsigned long duration, int period, float alpha);
void zbeul(unsigned long duration);
void whip(unsigned long duration, int period);
void whip_ellipse(unsigned long duration, int period);
void smooth_broken(unsigned long duration);
void broken(unsigned long duration);
void glitch(unsigned long duration);
void ballet_triangle(unsigned long duration);
void ballet_ellipse(unsigned long duration);
void portal_dance(unsigned long duration, unsigned long period);
void palm_dance(unsigned long duration);
void circle_dance(unsigned long duration, unsigned long period);
void circle_dance_2(unsigned long duration, unsigned long period);
void simple_circle(unsigned long duration, uint8_t *c);
void ribbon(unsigned long duration, unsigned long p);
void ribbon_dyn(unsigned long duration, unsigned long period, uint8_t duty_cycle);
void ribbon_analog(unsigned long duration, float dcr, float dcg, float dcb, int period);
//---------------------------------------------------------------------------
// Special functions
//---------------------------------------------------------------------------
float random_walk(float x, float weight, float amp);
float random_walk_capped(float x, float weight, float capmin, float capmax);

//---------------------------------------------------------------------------
// COLORS DEFINITION
//---------------------------------------------------------------------------
// Build color vector
void set_color(uint8_t c_number, uint8_t c0=0,uint8_t c1=0,uint8_t c2=0,uint8_t c3=0,uint8_t c4=0,uint8_t c5=0,uint8_t c6=0,uint8_t c7=0,uint8_t c8=0);
// call color function usng a integer (from 0 to 7)  
void digital_color(uint8_t color);}

//---------------------------------------------------------------------------
// Timer correction Functions
//---------------------------------------------------------------------------
float get_correction_sync();
float get_correction_mot();
void adjust_motor_speed();
