#ifndef CRITERIA_H
#define CRITERIA_H

#include <iomanip>
#include <iostream>
#include <string>

#include "Photo.h"

using namespace std;

class Criteria {
    friend ostream& operator<<(ostream& ost, const Criteria& c);

   public:
    virtual void print(ostream& ost) const = 0;
    virtual bool matches(const Photo&) const = 0;

   protected:
};

class Cat_Criteria : virtual public Criteria {
   public:
    // constructor
    Cat_Criteria(const string& categoryParam);


    void print(ostream& ost) const;
    bool matches(const Photo& p) const;

   private:
    string category;
};


class Date_Criteria : virtual public Criteria {
   public:
    // constructor
    Date_Criteria(const Date& startDateParam, const Date& endDateParam);


    void print(ostream& ost) const;
    bool matches(const Photo& p) const;

   private:
    Date start;
    Date end;
};


class CandD_Criteria : public Date_Criteria , public Cat_Criteria {
   public:
    // constructor
    CandD_Criteria(const Date& startDateParam, const Date& endDateParam, const string& categoryParam);


    void print(ostream& ost) const;
    bool matches(const Photo& p) const;
};
#endif