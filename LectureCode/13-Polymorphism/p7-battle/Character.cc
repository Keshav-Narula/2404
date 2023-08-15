
#include "Character.h"

Character::Character(int position, int health, const string& avatar):
position(position), health(health), avatar(avatar){
}


int Character::getPosition()const {return position;}

const Swing& Character::getSwing()const {return swing;}

bool Character::getHit(const Swing& swing){
    if (position >= swing.left && position <= swing.right){
        //we've been hit
        health -= swing.damage;
        return true;
    }
    return false;
}

const string& Character::getAvatar()const{return avatar;}

bool Character::isDead()const{return health <= 0;}

