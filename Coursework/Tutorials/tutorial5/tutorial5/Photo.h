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
	Photo(const string& titleParam, const Date& dateParam, const string& contentParam);
	Photo();

    bool equals(const string& titleParam) const;
    void print() const;
    void display() const;

    string getTitle() const;

	//int overlapOrBeginSameDay(Date& d);
private:
	string title;
    string content;

    Date date;



};
#endif