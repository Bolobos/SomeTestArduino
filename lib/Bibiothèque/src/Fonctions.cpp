#include <Fonctions.h>

//pas vraiment des fonctions mais plus des modes, genre ptit stockage
//à placer dans la loop



//Défilement leds simple
int var = 2; //variable leds
bool sens = 1; //mise à 1 = allumage leds, mise à 0 = extinction leds
bool alum = 1;
void defilementLEDS(){

    if(sens){
        PORTD = PORTD | (1 << var);
        delay(DELAY);
    }
    else{
        PORTD = PORTD & ~(1 << var);
        delay(DELAY);
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













//fonctionnement appui = allumage leds, relachement = leds éteintes
void BPPLEDS(){

    if (0x40 == (PIND & 0x40)) { //bouton appuyé
        Serial.println("bouton appuyé----------------------------------------------------");

        if(sens){
            PORTD = PORTD | (1 << var);
            delay(DELAY);
        }
        else{
            PORTD = PORTD & ~(1 << var);
            delay(DELAY);
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

    else{
        Serial.println("bouton relaché");
        PORTD = 0x00;
    }
}







void ONOFFLEDS(){

    if((0x40 == (PIND & 0x40)) && (alum == 1)){
        delay(10);
        while(0x40 == (PIND & 0x40)){
            PORTD = 0x00;
        }
    alum = 0;
    }

    if((0x40 == (PIND & 0x40)) && (alum == 0)){
        delay(10);
        while(0x40 == (PIND & 0x40)){}
        alum = 1;
    }
    //enregistrement de l'appui sur le bouton
    if (alum){ //bouton appuyé

        if(sens){
            PORTD = PORTD | (1 << var);
            delay(DELAY);
        }
        else{
            PORTD = PORTD & ~(1 << var);
            delay(DELAY);
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
    else{
        PORTD = 0x00;
    }  
}