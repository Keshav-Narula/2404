
#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>
#include "defs.h"

using namespace std;

class Board {
		
	public:
		//constructor
		Board();
		void reset();
		void setCharacter(string av, int pos);
		void setRed(int pos);
		void print() const;
	
	private:
		char positions[BOARD_SIZE];
		bool red[BOARD_SIZE];
	
};
#endif