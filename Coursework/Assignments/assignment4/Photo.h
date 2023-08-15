#ifndef PHOTO_H
#define PHOTO_H

#include <iomanip>
#include <iostream>
#include <string>

#include "Date.h"

using namespace std;

class Photo {
    friend ostream& operator<<(ostream&, const Photo&);

   public:
    // constructors
    Photo(const string& titleParam, const string& categoryParam, const Date& dateParam, const string& contentParam);
    Photo();

    bool equals(const string& titleParam) const;
    // void print() const;
    // void display() const;

    // string getTitle() const;
    //  string getCategory() const;

    //    Date& getDate();

    const Date& getDate() const;
    const string& getCategory() const;
    const string& getTitle() const;

    void print(ostream&) const;
    void display(ostream&) const;

   private:
    string title;
    string content;
    string category;

    Date date;
};
#endif