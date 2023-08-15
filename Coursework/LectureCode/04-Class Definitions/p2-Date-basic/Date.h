
#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

using namespace std;

class Date {
		
	public:
		//constructor
		Date(int year = 1901, int month = 1, int day = 1);
		Date(Date&);
		
		//setters, due to the principal of least privilege, dont always awnt headers, here it is useful since we might want to change the date, or we can make valid checks in order to make sure the values are in the correct range
		void setDay( int);
		void setMonth(int);
		void setYear(int);
		void setDate(int, int, int);
		void setDate(Date&);
		
		
	
		string getMonthName();
		
		//other
		void print();
	
	private:
		//functions
		int getMaxDay();	
	
		//variables
		int day;
		int month;
		int year;

};
#endif
