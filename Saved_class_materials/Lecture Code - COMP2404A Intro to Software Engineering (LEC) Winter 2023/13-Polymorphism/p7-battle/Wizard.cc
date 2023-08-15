
#include "Wizard.h"
#include "defs.h"

Wizard::Wizard():Character(0, 10, "W"){

}

// this code is different between Orc and Wizard, but both are called 'update'
void Wizard::update(){
    //dances
    int fireball = rand()%BOARD_SIZE;

    swing.left = fireball;
    swing.right = fireball + 5;
    swing.damage = 7;
    swing.weapon = "*****";
    //cout<<"Wizard position "<<position<<endl;
    int direction = rand()%2;
    if (direction == 0){
        position -= 1;
        if (position < 0) position = 0;
        
    }else{
        position += 1;
        if (position >= BOARD_SIZE) position = BOARD_SIZE - 1;
    }   
}



void Wizard::print() const{
     cout<<" Wizard: "<<health;
}
