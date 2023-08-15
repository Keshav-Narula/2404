
#include "Hero.h"
#include <time.h>
#include <cstdlib>


Hero::Hero(): Character(0, 20, "H"){
}



// this code is different between Orc and Hero, but both are called 'update'
void Hero::update(){
    //dances
    position = rand()%BOARD_SIZE;
    //cout<<"Hero position "<<position<<endl;
    int direction = rand()%2;
    if (direction == 0){
        swing.right = position - 1;
        swing.left = position - 4;
        swing.damage = 5;
        swing.weapon="<---";
    }else{
        swing.left = position + 1;
        swing.right = position + 4;
        swing.damage = 5;
        swing.weapon = "--->";
    }
}



void Hero::print() const{
     cout<<" Hero: "<<health;
}
		


void Hero::collide(){
    health -= 10;
}
