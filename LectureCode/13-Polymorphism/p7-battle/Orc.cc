
#include "Orc.h"

Orc::Orc():Character(14, 20, "O"){}



void Orc::update(){
    //moves slowly
    int direction = rand()%2;
    if (direction == 0){
        position -= 1;
        if (position < 0) position = 0;
        
    }else{
        position += 1;
        if (position >= BOARD_SIZE) position = BOARD_SIZE - 1;
    }   
    //cout<<"Orc position "<<position<<endl;

    swing.right = position +1;
    swing.left = position -1;
    swing.damage = 7;
    swing.weapon = "< >";
}


void Orc::print() const{
    cout<<" Orc: "<<health;
}