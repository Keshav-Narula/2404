
#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Date {
		
	public:
		//constructor
		Date();
		Date(const int& year,const int& month,const int& day);
		Date(const Date&);
		
		//setters
		void setDay(int&);
		void setMonth(int&);
		void setYear(int&);
		void setDate(int, int, int);
		void setDate(const Date&);
		
		//getters
		int getDay() const;
		int getMonth() const;
		int getYear() const;
		string getMonthName() const;
		
		//other
		void incDate();
		void addDays(const int&);
		bool lessThan(const Date& d) const;
		bool equals(const Date& d) const;
		void print() const;
	
	private:
		//functions
		int getMaxDay() const;	
	
		//variables
		int day;
		int month;
		int year;
	
};
#endif