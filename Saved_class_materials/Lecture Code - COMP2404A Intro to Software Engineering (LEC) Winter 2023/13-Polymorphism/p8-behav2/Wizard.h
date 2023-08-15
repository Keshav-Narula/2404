
#ifndef WIZARD_H
#define WIZARD_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Character.h"

using namespace std;

class Wizard: public Character {
		
	public:
		//constructor
		Wizard();
		
		void updatePosition();
		
		void print() const;
	
	private:
	
};
#endif