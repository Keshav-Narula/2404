#include "Pierres.h"

Pierres::Pierres() {
}
Pierres::~Pierres() {
    for (int i = 0; i < drivers.size(); ++i) {
        delete drivers[i];
    }
    for (int i = 0; i < franchises.size(); ++i) {
        delete franchises[i];
    }
}

void Pierres::addDriver(const string& name, const Location& locationParam) {
    drivers.push_back(new Driver(name, locationParam));
}
void Pierres::addFranchise(const string& name, const Location& locationParam) {
    franchises.push_back(new Franchise(name, locationParam));
}


void Pierres::takeOrder(const string& customerName, const int& menuItem, const Location& locationParam) const {
    if (franchises.empty()) {
        cout << "ERROR - CANNOT TAKE ORDER, No franchises Exist" << endl;
    } else {
        Order* newOrder = new Order(customerName, menuItem, locationParam); //Creates new Order
        int closestDistance = franchises[0]->getLocation()->getDistance(locationParam); //Sets default starting value for closest distance to the first franchise in Vector (Already checked to make sure it exists)
        int index = 0;
        for (int i = 1; i < franchises.size(); ++i) {
            if (franchises[i]->getLocation()->getDistance(locationParam) < closestDistance) { //Loops through all other franchises instantiated in Vector to find the one with the closest distance to the locattion provided
                index = i;
            }
        }
        franchises[index]->addOrder(newOrder); //Adds new Order to closest franchise
    }
}
void Pierres::driverPickup(const string& franchiseId, const int& numOrders) const{
    Franchise* foundFranchise = nullptr;
    for (int i = 0; i < franchises.size(); ++i) { //Loops through franchises to find if there exists a Franchise in the collection with a matching ID
        if (franchises[i]->equals(franchiseId)) {
            foundFranchise = franchises[i];
            break;
        }
    }
    if (foundFranchise != nullptr) {
        Driver* foundDriver = nullptr;
        int lowestDistance = 0;
        for (int i = 0; i < drivers.size(); ++i) { //Loops through the driver collection to find the Driver (If one exists) that is availible and closest to the franchise location we found
            if (drivers[i]->isFree()) { 
                if (foundDriver == nullptr) {
                    foundDriver = drivers[i];
                    lowestDistance = foundDriver->getLocation()->getDistance(*foundFranchise->getLocation());
                } else {
                    if (drivers[i]->getLocation()->getDistance(*foundFranchise->getLocation()) < lowestDistance) {
                        foundDriver = drivers[i];
                        lowestDistance = foundDriver->getLocation()->getDistance(*foundFranchise->getLocation());
                    }
                }
            }
        }
        if (foundDriver != nullptr) {
            foundDriver->setLocation(foundFranchise->getLocation()); 
            int transferrOrders = numOrders; //Adds either all the orders or specified number of orders (Whichever is greater) in the Franchise Queue to the Driver Queue 
            if (numOrders > foundFranchise->getNumOrders()) {
                transferrOrders = foundFranchise->getNumOrders();
            }

            for (int i = 0; i < transferrOrders; i++) { //Removes from the Franchise Queue adds to the Driver Queue
                foundDriver->addOrder(foundFranchise->getNextOrder());
            }

        } else {
            cout << "ERROR - CANNOT DRIVER PICKUP, No Drivers Available" << franchiseId << endl;
        }

    } else {
        cout << "ERROR - CANNOT DRIVER PICKUP, No Franchise Exists with ID " << franchiseId << endl;
    }
}
void Pierres::driverDeliver(const string& driverId, const int& numOrders) const {
    Driver* foundDriver = nullptr;
    for (int i = 0; i < drivers.size(); ++i) { //Loops through Drivers to find if there exists a Driver in the collection with a matching ID
        if (drivers[i]->equals(driverId)) {
            foundDriver = drivers[i];
            break;
        }
    }
    if (foundDriver != nullptr) {
        int numDeliverOrders = numOrders;
        if (numOrders > foundDriver->getNumOrders()) { //Delivers either all the orders or specified number of orders (Whichever is greater) in the Driver Queue 
            numDeliverOrders = foundDriver->getNumOrders();
        }

        for (int i = 0; i < numDeliverOrders; i++) { //Pops the next Order in the Driver's queue, Delivers and deletes that Order, Looped specified number of times
            Order* currentDelivery;
            currentDelivery = foundDriver->getNextOrder();
            foundDriver->setLocation(currentDelivery->getLocation());
            cout << endl
                 << "Driver " << foundDriver->getId() << " - Deliverying, ";
            currentDelivery->print();
            delete currentDelivery;
        }

    } else {
        cout << "ERROR - CANNOT DRIVER DELIVER, No Driver Exists with ID " << driverId << endl;
    }
}

void Pierres::printFranchises() const {
    cout << endl
         << "Printing All Franchises: " << endl;
    for (int i = 0; i < franchises.size(); ++i) {
        franchises[i]->print();
    }
}
void Pierres::printDrivers() const {
    cout << endl
         << "Printing All Drivers: " << endl;
    for (int i = 0; i < drivers.size(); ++i) {
        drivers[i]->print();
    }
}
