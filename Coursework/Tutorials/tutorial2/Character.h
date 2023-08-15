#ifndef CHARCTER_H

#define CHARCTER_H
#include <iostream>
#include <string>
using namespace std;

class Character {
   public:
    // constructor
    Character(const string &name, int maxHealth, int damage);

    // getter for the name member variable
    string getName();

    // Subtract the parameter value from the currentHealth. If currentHealth drops below 0, reset it to 0
    void takeDamage(int damage);

    // getter for the damage parameter. Return the damage member variable
    int strike();

    // Print the name and current health of the character to the console in whatever format you like.
    void print();

   private:
    // variables
    string name;
    int maxHealth;
    int currentHealth;
    int damage;
	
};

#endif