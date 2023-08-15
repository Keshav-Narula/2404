#include "Photo.h"

Photo::Photo(const string& titleParam, const Date& dateParam, const string& contentParam)
    : title(titleParam), date(dateParam), content(contentParam) {
    cout << "-- Photo ctor:  " << title << endl;
}

Photo::Photo()
    : title("N/A"), date(1, 1, 1), content("No Content") {
    cout << "-- Photo ctor:  " << title << endl;
}

Photo::Photo(const Photo& p)
    : title(p.title), date(p.date), content("RCMP") {
}

bool Photo::equals(string titleParam) {
    if (title == titleParam) {
        return true;
    } else {
        return false;
    }
}
void Photo::print() {
    cout << endl;
    cout << "Photo MetaData: Title: " << title << " Date: ";
    date.print();
}
void Photo::display() {
    this->print();
    cout << "Content" << content << endl;
}