
#include "Weapon.h"
#include "defs.h"

void Sword::update(int position){
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

void Claws::update(int position){
    swing.right = position +1;
    swing.left = position -1;
    swing.damage = 7;
    swing.weapon = "< >";
}

void FireBall::update(int position){
    int fireball = rand()%BOARD_SIZE;

    swing.left = fireball;
    swing.right = fireball + 5;
    swing.damage = 7;
    swing.weapon = "*****";
}