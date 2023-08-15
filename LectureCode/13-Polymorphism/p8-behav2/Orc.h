
#ifndef ORC_H
#define ORC_H

#include <iostream>
#include <string>
#include "defs.h"
#include "Swing.h"
#include "Character.h"


using namespace std;

class Orc: public Character{
		
	public:
		//constructor
		Orc();
		
		void updatePosition();
		void print() const;
	

};
#endif