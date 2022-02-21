#include <Fonctions.h>

void setup() {
  DDRD = 0x3C;//B00111100
  Serial.begin(9600);
  //7 segments
  DDRB = 0X1E;
  DDRC = 0x3C;
  PORTB = 0x1E;
  PORTC = 0x3C;
  //
}

void loop() {
  //a rentrer l'un des modes
}