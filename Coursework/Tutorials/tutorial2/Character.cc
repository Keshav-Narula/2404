#include "Character.h"

Character::Character(const string &name, int maxHealth, int damage) {
    this->name = name;
    this->maxHealth = maxHealth;
    this->currentHealth = maxHealth;
    this->damage = damage;
}

//Getter
string Character::getName(){
    return this->name;
}

// Subtract the parameter value from the currentHealth. If currentHealth drops below 0, reset it to 0
void Character::takeDamage(int damage){
    this->currentHealth -= damage;
    if(this->currentHealth < 0){
        this->currentHealth = 0;
    }
}

// getter for the damage parameter. Return the damage member variable
int Character::strike(){
    return this->damage;
}

// Print the name and current health of the character to the console in whatever format you like.
void Character::print(){
    cout <<"NAME: " <<this->name << " , CURRENT_HEALTH: " <<this->currentHealth<<endl;
}
