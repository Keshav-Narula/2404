#ifndef PHOTO_H
#define PHOTO_H

#include <iostream>
#include <string>
#include <iomanip>

#include "Date.h"



using namespace std;

class Photo {

public:
	//constructors
	Photo(const string& title, const Date& date, const string& content);
	Photo();
	Photo(const Photo&);


    bool equals(string title);
    void print();
    void display();

	//int overlapOrBeginSameDay(Date& d);
private:
	string title;
    string content;

    Date date;



};
#endif