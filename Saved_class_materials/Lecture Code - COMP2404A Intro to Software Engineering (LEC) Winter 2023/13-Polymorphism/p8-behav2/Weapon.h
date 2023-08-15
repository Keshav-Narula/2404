
#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Swing.h"

using namespace std;

class Weapon {
		
	public:
		
		const Swing& getSwing(){return swing;}
		virtual void update(int position) = 0;
	
	protected:
		Swing swing;
	
};

class Sword: public Weapon{
	virtual void update(int position);
};

class Claws: public Weapon{
	virtual void update(int position);
};

class FireBall: public Weapon{
	virtual void update(int position);
};
#endif