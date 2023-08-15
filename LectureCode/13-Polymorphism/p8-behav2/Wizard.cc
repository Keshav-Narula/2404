
#include "Wizard.h"
#include "defs.h"

Wizard::Wizard():Character(0, 10, "W"){
    weapon = new FireBall;
}

void Wizard::updatePosition(){
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
