#include "Reservation.h"

Reservation::Reservation(string customerName, Date& checkInParam, int duration) {
    this->customerName = customerName;
    this->duration = duration;
    this->checkIn = &checkInParam;
}

void Reservation::setDuration(int durationParam) {
    if (durationParam > 0) {
        this->duration = duration;
    } else {
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
    } else if (testCurrentDate.lessThan(testParamDate) == true) {
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
    Date testCurrentDate(*checkIn);
    testCurrentDate.addDays(duration);
    if (testCurrentDate.equals(*res.checkIn)) {
        return true;
    }

    if (this->checkIn->lessThan(*res.checkIn)) {
        return true;

    } else {
        return false;
    }
}
bool Reservation::lessThan(Date& d) {
    if (checkIn->lessThan(d) == true) {
        return true;
    }
    Date testCurrentDate(*checkIn);
    testCurrentDate.addDays(duration);
    if (testCurrentDate.equals(d)) {
        return true;
    }
    return false;
}

void Reservation::print() {
    cout << "Reservation for " << this->customerName << " on " << checkIn->getMonthName() << checkIn->getDay() << ", " << checkIn->getYear() << " for " << duration << " days." << endl;
}
