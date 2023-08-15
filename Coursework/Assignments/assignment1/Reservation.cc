//Emulates a Reservation for a room, has the Name of the customer for the reservatoin, the start date and the duration of the stay
#include "Reservation.h"

Reservation::Reservation(string paramCustomerName, Date& paramCheckIn, int paramDuration) {
    customerName = paramCustomerName;
    duration = paramDuration;
    //Date checkIn = (paramCheckIn);
    checkIn = new Date(paramCheckIn);
}

Reservation::~Reservation() {
}

void Reservation::setDuration(int durationParam) {
    if (durationParam > 0) {
        this->duration = duration;
    }
    else {
        this->duration = 1;
    }
}

bool Reservation::overlaps(Reservation& r) {
    Date testParamDate(*r.checkIn);
    Date testCurrentDate(*checkIn);

    if (testCurrentDate.equals(testParamDate)) {
        return true;
    }

    if (testParamDate.lessThan(testCurrentDate) == true) {
        testParamDate.addDays(r.duration);
        if (testParamDate.lessThan(testCurrentDate) == false && testParamDate.equals(testCurrentDate) == false) {
            return true;
        }
    }
    else if (testCurrentDate.lessThan(testParamDate) == true) {
        testCurrentDate.addDays(duration);
        if (testCurrentDate.lessThan(testParamDate) == false && testParamDate.equals(testCurrentDate) == false) {
            return true;
        }
    }
    return false;
}
bool Reservation::lessThan(Reservation& res) {
    if (this->overlaps(res)) {
        return false;
    }
    //Checking edge case they end on the same day, which should return true;
    Date testCurrentDate(*checkIn);
    testCurrentDate.addDays(duration);
    if (testCurrentDate.equals(*res.checkIn)) {
        return true;
    }

    if (this->checkIn->lessThan(*res.checkIn)) {
        return true;

    }
    else {
        return false;
    }
}
bool Reservation::lessThan(Date& d) {
    if (checkIn->lessThan(d) == true) {
        return true;
    }
    //Checking edge case they end on the same day, which should return true;
    Date testCurrentDate(*checkIn);
    testCurrentDate.addDays(duration);
    if (testCurrentDate.equals(d)) {
        return true;
    }
    return false;
}

void Reservation::print() {
    Date testCurrentDate(*checkIn);
    cout << "Reservation for " << this->customerName << " on " << testCurrentDate.getMonthName() << " " << testCurrentDate.getDay() << ", " << testCurrentDate.getYear() << " for " << duration << " days." << endl;
}

string Reservation::getCustomerName() {
    return customerName;

}

