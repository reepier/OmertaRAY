#define red_pin 3
#define green_pin 5
#define blue_pin 6
#define alim_laser 4
#define motor_1 10
#define motor_2 9

int fader_sync = A0;
int fader_mot = A1;
uint8_t color[9]; // array used to pass color palettes to animation functions
uint8_t c_temp[8]; // array used to pass secondary colors
int motor1_speed = 0;
int motor2_speed = 0;
void set_color(uint8_t c_number, uint8_t c0=0,uint8_t c1=0,uint8_t c2=0,uint8_t c3=0,uint8_t c4=0,uint8_t c5=0,uint8_t c6=0,uint8_t c7=0,uint8_t c8=0);
void palette();

unsigned long d_anim = 20000; //ms

unsigned long d_pause = 20000; //ms
unsigned long d_pause_mini = 2000; //ms 

//-----------------------------------------------------------------------------------
// SETUP
//-----------------------------------------------------------------------------------
void setup() {
  Serial.begin(9600);
  
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

  
  //wake_up();
}

//---------------------------------------------------------------------------
// MAIN LOOP
//---------------------------------------------------------------------------
void loop() {
  /*
  white();
  set_motor_speed(0,0);
  while (true){}*/
  /*
  analogWrite(green_pin, 30);
  set_motor_speed(70, 90);
  while (true){}
  */

  

  set_color(2,  2,7); // Green + White
  circle_dance(d_anim*25/20, 5000);
  set_color(2,  2,1); // Green Red
  circle_dance(d_anim*25/20, 3000);
  pause(d_pause_mini);
  
  set_color(8, 7,0,7,0,7,0,7,0);
  whip(d_anim, 20000);
  set_color(8, 7,0,7,1,7,0,7,1);
  whip(d_anim, 20000);
  set_color(8, 7,1,7,1,7,1,7,1);
  whip(d_anim, 20000);
  pause(d_pause_mini);
  
  set_color(8, 1,7);
  smooth_broken(d_anim);
  set_color(8, 3,1);
  smooth_broken(d_anim);
  pause(d_pause_mini);
    
  set_color(8,  0,0,1,1,0,0,0,3);
  ballet_triangle(d_anim*30/20);
  
  set_color(8, 0,0,0,6,6,6,0,5);
  ballet_ellipse(d_anim*30/20);
  set_color(8, 0,0,0,6,6,0,0,5);
  ballet_ellipse(d_anim*30/20);

  set_color(3, 1,3,0);
  whip_ellipse(d_anim, 5000);
  
  pause(2*d_pause);

  
  set_color(2, 7, 5);
  glitter(d_anim, 2500, 0.8);
  
  set_color(2,  1,4);       // Red yellow
  circle_dance(d_anim, 2000);
  set_color(4,  5,7,6,7);   // Cyan Blanc Magenta
  circle_dance(d_anim, 2000);
  
  set_color(8, 0,0,0,1,1,0,3,3);
  ballet_ellipse(d_anim*30/20);
  pause(d_pause_mini);
  
  set_color(4,  1,3,6,3);   // Red Blue Magenta
  circle_dance(d_anim, 2000);
  
  STOP();
  pause(d_pause_mini);
  
  set_color(8,  0,0,5,5,0,0,0,2);
  ballet_triangle(d_anim);
  pause(d_pause_mini);
  
  set_color(2, 1,7);
  palm_dance(d_anim*15/20);
  set_color(2, 2,7);
  palm_dance(d_anim*15/20);
  set_color(2, 3,7);
  palm_dance(d_anim*15/20);
  pause(d_pause_mini);
  
  set_color(8, 7,7,7,7,2,2,7,3);
  glitch(d_anim*30/20);
  pause(d_pause_mini);
  
  set_color(8, 7,6);
  smooth_broken(d_anim*25/20);
  pause(3*d_pause);
  
  set_color(8, 7,7,7,5,7,5,7,7);
  whip(d_anim, 20000);
  set_color(8, 7,7,7,1,7,1,7,7);
  whip(d_anim, 20000);
  set_color(8, 7,7,7,3,7,3,7,7);
  whip(d_anim, 20000);
  STOP();
  pause(d_pause_mini);
  
  set_color(8, 6,6,6,6,0,0,0,0);
  ballet_ellipse(d_anim*30/20);
  
  set_color(3, 7,6,5);
  portal_dance(d_anim*60/20, 20000);
  STOP();
  pause(d_pause_mini);
  
  set_color(8,  0,0,5,5,0,0,0,6);
  ballet_triangle(d_anim*30/20);
  
  set_color(8, 0,0,0,2,2,0,7,7);
  ballet_ellipse(d_anim*30/20);
  STOP();
  pause(d_pause_mini);
  
  set_color(8, 5,0,5,0,5,0,5,0);
  whip_ellipse(d_anim, 10000);
  set_color(8, 5,0,5,6,5,0,5,6);
  whip_ellipse(d_anim, 10000);
  set_color(8, 5,6,5,6,5,6,5,6);
  whip_ellipse(d_anim, 10000);
  
  set_color(2, 1,4);
  palm_dance(d_anim*5/20);
  set_color(2, 2,6);
  palm_dance(d_anim*5/20);
  set_color(2, 0,5);
  palm_dance(d_anim*5/20);
  STOP();
  
  set_color(2, 7, 2);
  glitter(d_anim, 5000, 0.9);
  
  set_color(8, 7,7,7,7,1,1,3,6);
  glitch(d_anim*30/20);
  STOP();
  pause(d_pause_mini);
  
  set_color(8,  0,0,1,1,0,6,0,0);
  ballet_triangle(d_anim*60/20);
  set_color(8,  0,1,1,0,0,7,0,0);
  ballet_ellipse(d_anim*30/20);
  set_color(8,  0,1,0,3,0,1,0,3);
  ballet_triangle(d_anim*30/20);  
  pause(3*d_pause);
  
  set_color(2, 1, 3);
  glitter(d_anim, 800, 1);
  
  set_color(8,  5,7,6,7,2,7,1,7);
  circle_dance_2(d_anim, 2000);
  set_color(8,  1,3,3,5,5,6,6,3);
  circle_dance_2(d_anim, 2000);
  STOP();
  pause(d_pause_mini);
  
  set_color(8, 3,5);
  smooth_broken(d_anim);
  STOP();
  pause(d_pause_mini);
  
  set_color(8,  1,0,6,0,3,0,5,0);
  circle_dance_2(d_anim, 2000);
  
  set_color(8,  1,0,2,0,3,0,7,0);
  circle_dance_2(d_anim, 2000);
  STOP();
  pause(d_pause_mini);
  
  set_color(8, 1,2);
  smooth_broken(d_anim);
  STOP();
  pause(d_pause_mini);
  
  set_color(8,  0,0,6,6,0,5,0,0);
  ballet_triangle(d_anim*40/20);
  
  set_color(8, 7,7,7,7,2,2,7,3);
  glitch(d_anim*30/20);
  
  set_color(3, 7,6,5);
  portal_dance(d_anim*60/20, 20000);
  
  set_color(8, 7,0,7,0,7,0,7,0);
  whip_ellipse(d_anim, 10000);
  set_color(8, 7,0,7,1,7,0,7,1);
  whip_ellipse(d_anim, 10000);
  set_color(8, 7,1,7,1,7,1,7,1);
  whip_ellipse(d_anim, 10000);
  
  set_color(1, 7);
  glitter(d_anim, 1000, 0.7);
  pause(5*d_pause);

  }


//---------------------------------------------------------------------------
// Animations low level
//---------------------------------------------------------------------------
void glitter(unsigned long duration, int period, float alpha){
  unsigned long start = millis();
  const uint8_t ncolor = color[0];
  
  for(uint8_t j=1 ; j <= ncolor ; j++){
    c_temp[j-1] = color[j];
  }
  
  uint8_t i=0;
  
  while (millis() - start < duration){
     
     set_color(3, 0,0,c_temp[i]);
     set_motor_speed(180,230);
     ribbon(period*alpha, 4000);
     
     black();
     set_motor_speed(50,50);
     delay((int)(period*(1-alpha)));
     
     if (i<(ncolor-1)){
      i++;
     }
     else{
      i=0;
     }
  }
}

void zbeul(unsigned long duration){
  unsigned long start = millis();
  
  while(millis()-start < duration){
    set_motor_speed(random(35,150), random(35,150));
    digital_color( color[ random(1, color[0]) ] );
    delay(100);
  }
}

void whip(unsigned long duration, int period){
  set_motor_speed(50,43);
  ribbon(duration, period);
}
void whip_ellipse(unsigned long duration, int period){
  set_motor_speed(50,50);
  ribbon(duration, period);
}

void smooth_broken(unsigned long duration){
  set_shape_square();
  randomSeed(analogRead(A0));
  unsigned long start = millis();
  uint8_t i = 1;
  
  while (millis() - start <= duration){

    digital_color(color[1]);
    delay(random(0, 2000));
    digital_color(color[2]);
    delay(random(0, 100));
    adjust_motor_speed();
  }
}

void broken(unsigned long duration){
  randomSeed(analogRead(A0));
  unsigned long start = millis();
  uint8_t i = 1;
  
  while (millis() - start <= duration){
    set_motor_speed(255,25);
    digital_color(color[1]);
    delay(random(0, 1000));
    digital_color(color[2]);
    set_motor_speed(255,255);
    delay(random(0, 150));
  }
}

void glitch(unsigned long duration){
  randomSeed(analogRead(A0));
  unsigned long start = millis();
  set_motor_speed(50,40);
  uint8_t i = 1;
  
  while (millis() - start <= duration){
    black();
    delay(random(0, 800));
    digital_color(color[random(1, color[0])]);
    delay(random(0, 90));
  }
}

void ballet_triangle(unsigned long duration){
  set_shape_triangle();
  ribbon(duration, 11200);
}

void ballet_ellipse(unsigned long duration){
  set_shape_ellipse();
  ribbon(duration, 23200);
}

void portal_dance(unsigned long duration, unsigned long period){
    unsigned long start = millis();
    for(uint8_t j=1;j<=color[0];++j){
      c_temp[j-1] = color[j];
    }
    
    uint8_t i=0;
    const uint8_t ncolor = color[0];
      
    while(millis()<= start+duration){
        set_color(7, c_temp[i] ,c_temp[i] ,c_temp[i] ,0 ,0 ,0 ,0);
        set_shape_circle();
        ribbon(period, 8150);
        black();
        set_motor_speed(150,255);
        delay(200);
        if (i<ncolor-1){
          i++;
        }
        else{
          i=0;
          adjust_motor_speed();
        }
    }
  STOP();
}


void palm_dance(unsigned long duration){
  unsigned long start = millis();
  
  set_motor_speed(50, 68);
  while(millis()-start<=duration){
    ribbon(100, 3000);
    black();
    delay(500);
  }
}

void circle_dance(unsigned long duration, unsigned long period){
  unsigned long start = millis();
  uint8_t i = 1, cpt=1;
  
  while(millis()<= start+duration){
  
    if (cpt%2==0){
      set_motor_speed(200, 15);
    }
    else{
      set_motor_speed(15, 150);
    }
    
    digital_color(color[i]);
    delay(period);
    
    if (cpt%2==0){
      set_motor_speed(200, 255);
    }
    else{
      set_motor_speed(255, 150);
    }
    delay(200);
    
    if (i<color[0]){
      i++;
    }
    else{
      i=1;
    }
    cpt++;
  }
STOP();
}


void circle_dance_2(unsigned long duration, unsigned long period){
  unsigned long start = millis();
  uint8_t i = 0;
  uint8_t n_color = 8;
  uint8_t temp_color[color[0]];
  for(uint8_t i=1;i<=color[0];++i){
    temp_color[i-1]=color[i];
  }
  
  while(millis()<= start+duration){
    
    set_color(2, temp_color[i], temp_color[i+1], temp_color[i], temp_color[i+1]);
    set_motor_speed(15, 200);
    ribbon(period, 1750);
    set_motor_speed(255,200);
    delay(200);
    if (i < n_color-2){
      i+=2;
    }
    else{
      i=0;
    }
  }
STOP();
}

void simple_circle(unsigned long duration, uint8_t *c){
  set_shape_circle();
  digital_color(c[0]);
  delay(duration);
  STOP();
}

void ribbon(unsigned long duration, unsigned long p){
  uint8_t i = 1;
  unsigned long start = millis();
  uint8_t n_color = color[0];
  unsigned long period = p/n_color;
  unsigned long adj_period = period * get_correction_sync();
  
  while(millis()-start <= duration){
    digital_color(color[i]);
    delayMicroseconds(adj_period);
    if (i<n_color){
      ++i;
    }
    else{
      i=1;
      adj_period = period * get_correction_sync();
      adjust_motor_speed();
    }
  }
}

void ribbon_dyn(unsigned long duration, unsigned long period, uint8_t duty_cycle){
  unsigned long period_1 = 2 * period * (unsigned long)duty_cycle / 100;
  unsigned long period_2 = 2 * period - period_1;
  unsigned long start = millis();
  
  while (millis()-start < duration){
    digital_color(color[1]);
    delayMicroseconds(period_1);
    digital_color(color[2]);
    delayMicroseconds(period_2);
  }
}

void ribbon_analog(unsigned long duration, float dcr, float dcg, float dcb, int period){
  unsigned long start = millis();
  float tot = dcr + dcg + dcb;
  float pr = period * dcr/tot;
  float pg = period * dcg/tot;
  float pb = period * dcb/tot;
  
  while (millis()-start < duration){
    if(pr != 0){
      digital_color(1);
      delayMicroseconds((int)pr);
    }
    if(pg != 0){
    digital_color(2);
    delayMicroseconds((int)pg);
    }
    if(pb != 0){
    digital_color(3);
    delayMicroseconds((int)pb);
    }
  }

  float m = 10;
  if(pr>m*pg && pr>m*pb){red();}
  else if(pg>m*pr && pg>m*pb){green();}
  else if(pb>m*pr && pb>m*pg){blue();}
  else{black();}
}

//---------------------------------------------------------------------------
// Special functions
//---------------------------------------------------------------------------
float random_walk(float x, float weight, float amp){
 float tirage = random(-100, 100)/100.0*amp;
 float y = weight*x + (1-weight)*(x+tirage);
 return(y);
}

float random_walk_capped(float x, float weight, float capmin, float capmax){
 float tirage = x + random(-100, 100)/100.0*(capmax-capmin);
 
 float y = weight*x + (1-weight)*(tirage);

 if (y > capmax) {y=capmax;}
 if (y < capmin) {y=capmin;}

 return(y);
}

//---------------------------------------------------------------------------
// COLORS DEFINITION
//---------------------------------------------------------------------------

// Build color vector
void set_color(uint8_t c_number, uint8_t c0=0,uint8_t c1=0,uint8_t c2=0,uint8_t c3=0,uint8_t c4=0,uint8_t c5=0,uint8_t c6=0,uint8_t c7=0,uint8_t c8=0){
    color[0]=c_number; // stores the number of colors that will follow
    color[1]=c0;
    color[2]=c1;
    color[3]=c2;
    color[4]=c3;
    color[5]=c4;
    color[6]=c5;
    color[7]=c6;
    color[8]=c7;
    color[9]=c8;
}

// call color function usng a integer (from 0 to 7)  
void digital_color(uint8_t color){
  switch (color){
    case 0: black();
    break;
    case 1: red();
    break;
    case 2: green();
    break;
    case 3: blue();
    break;
    case 4: yellow();
    break;
    case 5: cyan();
    break;
    case 6: magenta();
    break;
    case 7: white();
    break;
  }
}

// ELementary color functions
void black(){
  digitalWrite(red_pin, LOW);
  digitalWrite(green_pin, LOW);
  digitalWrite(blue_pin, LOW);
}
void white(){
  digitalWrite(red_pin, HIGH);
  digitalWrite(green_pin, HIGH);
  digitalWrite(blue_pin, HIGH);
}
void red(){
  digitalWrite(red_pin, HIGH);
  digitalWrite(green_pin, LOW);
  digitalWrite(blue_pin, LOW);
}
void green(){
  digitalWrite(red_pin, LOW);
  digitalWrite(green_pin, HIGH);
  digitalWrite(blue_pin, LOW);
}
void blue(){
  digitalWrite(red_pin, LOW);
  digitalWrite(green_pin, LOW);
  digitalWrite(blue_pin, HIGH);
}
void cyan(){
  digitalWrite(red_pin, LOW);
  digitalWrite(green_pin, HIGH);
  digitalWrite(blue_pin, HIGH);
}
void magenta(){
  digitalWrite(red_pin, HIGH);
  digitalWrite(green_pin, LOW);
  digitalWrite(blue_pin, HIGH);
}
void yellow(){
  digitalWrite(red_pin, HIGH);
  digitalWrite(green_pin, HIGH);
  digitalWrite(blue_pin, LOW);
}

//---------------------------------------------------------------------------
// MOTOR SPEED Functions
//---------------------------------------------------------------------------
void set_motor_speed(uint8_t speed_1, uint8_t speed_2) {
  motor1_speed = speed_1*4;
  motor2_speed = speed_2*4;

  analogWrite(motor_1, motor1_speed*get_correction_mot());
  analogWrite(motor_2, motor2_speed);
}

void set_shape_ellipse() {
  set_motor_speed(156,154);
}
void set_shape_circle(){
  set_motor_speed(200,0);
}
void set_shape_atom_7() {
  set_motor_speed(255,200);
}
void set_shape_triangle(){
  set_motor_speed(198,112);
}
void set_shape_square(){
  set_motor_speed(189,80);
}

void STOP(){
  black();
  set_motor_speed(0,0);
}

void wake_up(){
  set_color(8, 1,2,3,4,5,6,7,7);
  zbeul(20000);
  STOP();
  set_motor_speed(200,200);
  white();
  delay(20000);
  STOP();
  delay(5000);
}

void pause(unsigned long duration){
  set_motor_speed(80,80);
  black();
  delay(duration);
}

//---------------------------------------------------------------------------
// DEBUG & TEST Functions
//---------------------------------------------------------------------------
void disp_color(){
  for (int i=1; i<=color[0]; i++){
    Serial.println(color[i]);
  }
}

// show color vector (test purpose)
void palette(uint8_t c_number){
  for (int i=0; i<c_number; ++i){
    digital_color(color[i]);
    delay(1000);
  }
}void palette(){
  for (int i=1; i<=color[0]; ++i){
    digital_color(color[i]);
    delay(1000);
  }
}

//---------------------------------------------------------------------------
// Timer correction Functions
//---------------------------------------------------------------------------
float get_correction_sync(){
  float corr = 0.95 + analogRead(fader_sync)/1023.0*(0.1);
  return corr;
}
float get_correction_mot(){
  float corr = 0.95 + analogRead(fader_mot)/1023.0*(0.1);
  return 1/corr;
}

void adjust_motor_speed(){
  analogWrite(motor_1, motor1_speed*get_correction_mot());
}

/*A faire :
 * trouver un moyen de créer plusieurs vecteur couleur pour pouvoir les passer en cascade dans les fonctions
 * ex: envoyer une animation avec 8 couleurs en paramètres, cette animation lance à son tour des animations élémentaires
 * avec les couleurs par groupe de 2.
 * color=[1 2 3 4 5 6] stock la chaine de couleurs principales
 * c_temp1=[1 2] / [3 4] /[5 6] stock les paires de couleurs ç passer à la deuxième fonction
 
 
 */

 
