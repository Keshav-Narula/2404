#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <string>

class View;
class University;

using namespace std;

class Controller {
		
	public:
		//launch function
		void launch();
	
	private:

		void addStudent();

		//Has a view and a univeristy manages the interactions between between 
		View* view;
		University* uni;
	
};
#endif