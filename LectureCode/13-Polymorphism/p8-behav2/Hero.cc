
#include "Hero.h"
#include <time.h>
#include <cstdlib>


Hero::Hero(): Character(0, 20, "H"){
    weapon = new Sword;
}

void Hero::updatePosition(){
        position = rand()%BOARD_SIZE;
}




void Hero::print() const{
     cout<<" Hero: "<<health;
}
		


void Hero::collide(){
    health -= 10;
}
