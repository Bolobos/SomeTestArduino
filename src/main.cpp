#include <Arduino.h>
int var = 2; //variable leds
bool sens = 1; //mise à 1 = allumage leds, mise à 0 = extinction leds

void setup() {
  DDRD = 0x3C;
  Serial.begin(9600);
  PORTD = 0x00;
}

void loop() {
  if(sens){
    PORTD = PORTD | (1 << var);
    delay(70);
  }
  else{
    PORTD = PORTD & ~(1 << var);
    delay(70);
  }


  //choix du sens (allumage ou extinction)
  if(var == 5){
    var = 1;
    if (sens){
      sens = 0;
    }
    else{
      sens = 1;
    }
  }

  //compteur leds
  var++;
}