#ifndef HOTEL_H
#define HOTEL_H


#include <iostream>
#include <string>
#include <iomanip>

#include "Date.h"
#include "Reservation.h"
#include "Room.h"

using namespace std;

class Hotel{
    public:
    Hotel();
    ~Hotel();

    bool addRoom(int roomNumber, string bedType, int capacity, bool fr);
    bool deleteRoom(int roomNumber);
    bool getRoom(int roomNumber, Room** room);
    bool addReservation(string customer, string bedType, int capacity, bool fr, Date& date, int duration);
    void updateReservations(Date& currentDate);
    void print();
    void printReservations();
    private:
    Room* roomArray[MAX_ROOMS];
    int numRooms;

};

#endif
