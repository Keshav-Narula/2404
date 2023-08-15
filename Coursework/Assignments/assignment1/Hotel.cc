//Purpose of this class to to emulate a Hotel, with multiple unique rooms inside, each room holds a list of the reservations it has in chronological order

#include "Hotel.h"

Hotel::Hotel() {
    numRooms = 0;
}
Hotel::~Hotel() {

}

bool Hotel::addRoom(int roomNumber, string bedType, int capacity, bool fr) {
    if (numRooms >= MAX_ROOMS) {
        return false;
    }
    Room* newRoom = new Room(roomNumber, bedType, capacity, fr);
    for (int i = numRooms; i > 0; --i) {
        if (newRoom->getRoomNumber() == roomArray[i - 1]->getRoomNumber()) {
            delete newRoom;
            return false;
        }
        if (newRoom->lessThan(*roomArray[i - 1])) {
            roomArray[i] = roomArray[i - 1];
        }
        else {
            roomArray[i] = newRoom;
            ++numRooms;
            return true;
        }
    }
    roomArray[0] = newRoom;
    ++numRooms;
    return true;
}

bool Hotel::deleteRoom(int roomNumber) {
    int index = 0;
    while (roomNumber != roomArray[index]->getRoomNumber() && index < numRooms) {
        ++index;
    }

    if (index == numRooms) return false;

    delete roomArray[index];

    while (index < numRooms - 1) {
        roomArray[index] = roomArray[index + 1];
        ++index;
    }
    --numRooms;
    return true;
}
bool Hotel::getRoom(int roomNumber, Room** room) {

    for (int i = 0; i < numRooms; ++i) {
        if (roomNumber == roomArray[i]->getRoomNumber()) {
            *room = roomArray[i];
            return true;
        }
    }
    return false;
}
bool Hotel::addReservation(string customer, string bedType, int capacity, bool fr, Date& date, int duration) {
    for (int i = 0; i < numRooms; ++i) {
        if (roomArray[i]->isMatch(bedType, capacity, fr) == true) {
            if (roomArray[i]->addReservation(customer, date, duration) == true) {
                return true;
            }
        }
    }
    return false;
}

void Hotel::print() {
    cout << endl << "PRINTING ALL ROOMS DATA:" << endl;
    for (int i = 0; i < numRooms; ++i) {
        roomArray[i]->print();
    }
    cout << endl;
}
void Hotel::printReservations() {
    cout << endl << "PRINTING ALL ROOMS & RESERVATIONS DATA:" << endl;
    for (int i = 0; i < numRooms; ++i) {
        roomArray[i]->printReservations();
    }
    cout << endl;

}

void Hotel::updateReservations(Date& currentDate) {

}