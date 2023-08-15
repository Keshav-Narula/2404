
#include "Orc.h"

Orc::Orc():Character(14, 20, "O"){
    weapon = new Claws;
}

void Orc::updatePosition(){
    int direction = rand()%2;
    if (direction == 0){
        position -= 1;
        if (position < 0) position = 0;
        
    }else{
        position += 1;
        if (position >= BOARD_SIZE) position = BOARD_SIZE - 1;
    }   
}



void Orc::print() const{
    cout<<" Orc: "<<health;
}