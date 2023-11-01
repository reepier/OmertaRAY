#pragma once
#include <DMXSerial.h>
#include "color.h"

namespace DMX{

void DMX_loop();

void circle_dance(color_vec c, unsigned long period = 5000);

}