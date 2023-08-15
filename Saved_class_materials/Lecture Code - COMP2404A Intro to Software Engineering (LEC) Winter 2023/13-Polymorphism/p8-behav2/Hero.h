
#ifndef HERO_H
#define HERO_H

#include <iostream>
#include <string>
#include "Swing.h"
#include "defs.h"
#include "Character.h"

using namespace std;

class Hero: public Character {
		
	public:
		//constructor
		Hero();

		

		void updatePosition();
		void print() const;
		void collide();
			
	
	
};
#endif