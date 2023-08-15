#ifndef RESERVATION_H
#define RESERVATION_H


#include <iostream>
#include <string>
#include <iomanip>

//#include "Room.h"

#include "Date.h"
#include "defs.h"

#include <iostream>
#include <string>

using namespace std;

class Reservation{
    public:
    Reservation(string customerName, Date& checkIn, int duration);
    ~Reservation();


    void setDuration(int duration);
    bool overlaps(Reservation& r);
    bool lessThan(Reservation& res);
    bool lessThan(Date& d);
    void print();

    string getCustomerName();


    private:
    string customerName;
    Date* checkIn;
    int duration;


};



#endif
