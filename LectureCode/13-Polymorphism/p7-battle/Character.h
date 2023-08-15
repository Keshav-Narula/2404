
#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Swing.h"

using namespace std;

class Character {
		
	public:
		//constructor
		Character(int position, int health, const string& avatar);
		
		int getPosition() const;
		const Swing& getSwing() const;
		const string& getAvatar() const;

		bool getHit(const Swing&);
		bool isDead() const;

		virtual void update() = 0;
		virtual void print() const = 0;

	protected:
		int position;
		int health;
		string avatar;
		Swing swing;	
		
};
#endif