
#ifndef BATTLE_H
#define BATTLE_H

#include <iostream>
#include <string>
#include <vector>
#include "defs.h"
#include "Hero.h"
#include "Orc.h"
#include "Wizard.h"
#include "Board.h"

using namespace std;

class Battle {
		
	public:
		Battle();
		bool isOver() const;
		void update();	
		void printResult() const;
	private:
		Board board;
		vector<Character*> ch;
		Hero hero;
		Orc orc;
		Wizard wiz;
};
#endif