#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
#include <iomanip>


using namespace std;

class Date {

public:
	//constructors
	Date();
	Date(int year, int month, int day);
	Date(const Date&);
	~Date();


	//setters
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	void setDate(int, int, int);
	void setDate(Date&);

	//getters
	int getDay();
	int getMonth();
	int getYear();
	string getMonthName();

	//other
	// advance this Date by 1 day
	void incDate();
	void print();

	//This should return true if the Date in question and d are equal and false otherwise.
	bool equals(Date& d);
	//This should return true if the Date in question comes before d and false otherwise.
	bool lessThan(Date& d);
	//) function that advances this Date by the number of days in the days parameter.You may call on the incDate() function if you wish.
	void addDays(int days);

	bool overlaps(int duration, Date& passedDate);


	//int overlapOrBeginSameDay(Date& d);
private:
	//functions
	// get the number of days in this month
	int getMaxDay();

	//variables
	int day;
	int month;
	int year;

};
#endif
