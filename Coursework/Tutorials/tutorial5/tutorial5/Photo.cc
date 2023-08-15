#include "Photo.h"

Photo::Photo(const string& titleParam, const Date& dateParam, const string& contentParam)
    : title(titleParam), date(dateParam), content(contentParam) {
}

Photo::Photo()
    : title("N/A"), date(1, 1, 1), content("No Content") {
    cout << "-- Photo ctor:  " << title << endl;
}


bool Photo::equals(const string& titleParam) const {
    if (title == titleParam) {
        return true;
    } else {
        return false;
    }
}
void Photo::print() const {
    cout << endl;
    cout << "Photo MetaData: Title: " << title << " Date: ";
    date.print();
}
void Photo::display() const {
    this->print();
    cout << "Content" << content << endl;
}

string Photo::getTitle() const{
    return title;
}