#include "Order.h"

Order::Order(const string& nameParam, const int& menuItemParam, const Location& locationParam)
    : customerName(nameParam), menuItem(menuItemParam), deliveryLocation( new Location(locationParam)) {
}

Order::~Order(){ 
    delete deliveryLocation;

}


Location* Order::getLocation() const{
    return deliveryLocation;
}

//FIx for assignement
void Order::print() const {
    cout<<"Menu Item: "<< menuItem<<endl;
}
