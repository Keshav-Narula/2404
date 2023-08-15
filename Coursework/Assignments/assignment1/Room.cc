//Room class emulates a Room inside the Hotel, it stoes info about its room, along with an array of chronological reservations for that room
#include "Room.h"

#include <iostream>
#include <string>

Room::Room(int paramRoomNumber, string paramBedType, int paramCapacity, bool paramHasFridge) {
    roomNumber = paramRoomNumber;
    bedType = paramBedType;
    capacity = paramCapacity;
    hasFridge = paramHasFridge;
    numReservations = 0;
    //reservations = new Reservation*[MAX_RES];


}
Room::~Room() {
    
}

int Room::getRoomNumber() { return roomNumber; }

bool Room::isMatch(string bt, int cap, bool f) {

    if(bedType == bt){
        if(capacity >= cap){
            if(f == true){
                if(hasFridge == true){
                    return true;
                }else{
                    return false;
                }
            }else{
                return true;
            }
        }

    }
    return false;
}

bool Room::lessThan(Room& r) {
    if (roomNumber < r.roomNumber) {
        return true;
    }
    else {
        return false;
    }
}

bool Room::addReservation(string customerName, Date& d, int duration) {
    if (numReservations >= MAX_RES) return false;

    Reservation* newRes = new Reservation(customerName, d, duration);

    for (int i = numReservations; i > 0; --i) {
        if (newRes->overlaps(*reservations[i-1])) {
            delete newRes;
            return false;
        }
        if (newRes->lessThan(*reservations[i - 1])) {
            reservations[i] = reservations[i - 1];
        }
        else {
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
    //cout<<"HERE"<<reservations[0]->getCustomerName()<<endl;

}

void Room::printReservations() {
    print();
    for (int i = 0; i < numReservations; ++i) {
        reservations[i]->print();
    }
}
