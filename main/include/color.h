#pragma once
#include <Vector.h>

// ELementary color functions
void set_black();
void set_white();
void set_red();
void set_green();
void set_blue();
void set_cyan();
void set_magenta();
void set_yellow();

enum simpleColor{
    black = 0,
    red,
    green,
    blue,
    yellow,
    cyan,
    magenta,
    white
};
void setColor(simpleColor);

typedef Vector<simpleColor> color_vec; 
