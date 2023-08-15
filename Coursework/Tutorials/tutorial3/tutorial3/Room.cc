#include "Room.h"

#include <iostream>
#include <string>

Room::Room(int roomNumber, string bedType, int capacity, bool hasFridge) {
    this->roomNumber = roomNumber;
    this->bedType = bedType;
    this->capacity = capacity;
    this->hasFridge = hasFridge;
    this->numReservations = 0;

}
Room::~Room() {
}

int Room::getRoomNumber() { return roomNumber; }

bool Room::isMatch(string bt, int cap, bool f) {
    if(this->hasFridge == f){
      if(this->capacity >= cap){
        if(bt.compare(bedType) == 0){
          return true;
        }
      }
    }
    return false;
}

bool Room::lessThan(Room& r) {
    if (roomNumber < r.roomNumber) {
        return true;
    } else {
        return false;
    }
}

bool Room::addReservation(string customerName, Date& d, int duration) {
    if (numReservations >= MAX_RES) return false;

    Reservation* newRes = new Reservation(customerName, d, duration);

    for (int i = numReservations; i > 0; --i) {
        if (newRes->overlaps(*reservations[i]) == true) {
            delete newRes;
            return false;
        }
        if (newRes->lessThan(*reservations[i - 1])) {
            reservations[i] = reservations[i - 1];
        } else {
            reservations[i] = newRes;
            ++numReservations;
            return true;
        }
    }
    reservations[0] = newRes;
    ++numReservations;
    return true;
}

void Room::print() {
    cout << "Room Number: " << roomNumber << ", BedType: " << bedType << ", Capacity: " << capacity << ", HasFridge: " << hasFridge << ", numReservations: " << numReservations << endl;
}

void Room::printReservations() {
    print();
    for (int i = 0; i < numReservations; ++i) {
        reservations[i]->print();
    }
}
