#ifndef PIERRES_H
#define PIERRES_H

#include <iostream>
#include <string>
#include <vector>

#include "Driver.h"
#include "Franchise.h"


using namespace std;

class Pierres {
   public:
    Pierres();
    ~Pierres();

    void addDriver(const string& name, const Location& locationParam);
    void addFranchise(const string& name, const Location& locationParam);

    // Make const?
    void takeOrder(const string& customerName, const int& menuItem, const Location& locationParam) const;
    void driverPickup(const string& franchiseId, const int& numOrders)const;
    void driverDeliver(const string& driverId, const int& numOrders) const;

    void printFranchises() const;
    void printDrivers() const;

   private:
    vector<Driver*> drivers;
    vector<Franchise*> franchises;
};

#endif