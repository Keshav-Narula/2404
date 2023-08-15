#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <string>
#include "Location.h"

using namespace std;

class Order {
    public:
        Order(const string& nameParam, const int& menuItemParam, const Location& locationParam);
        ~Order();

        Location* getLocation() const;
        void print() const;


    private:
        string customerName;
        int menuItem;
        Location* deliveryLocation;

};

#endif