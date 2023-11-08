#pragma once
#include <DMXSerial.h>
#include "color.h"

namespace DMX{

void DMX_loop();

void ribbon(unsigned long, unsigned long);

void circle_dance(unsigned long period = 5000);
void glitch(unsigned long bmin = 0, unsigned long bmax = 800, unsigned long fmin = 0, unsigned long fmax = 90);
void palm_dance();
void whip();
}