#include "Photo.h"

Photo::Photo(const string& titleParam, const string& categoryParam, const Date& dateParam, const string& contentParam)
    : title(titleParam), category(categoryParam), date(dateParam), content(contentParam) {
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
void Photo::print(ostream& ost) const {
    ost << endl;
    ost << "Photo MetaData: Title: " << title << " Date: ";
    ost<<this->date;
}

void Photo::display(ostream& ost) const {
    this->print(ost);
    ost << " Content: " << content << endl;
}

const string& Photo::getTitle() const{
    return title;
}

const string& Photo::getCategory() const{
    return category;
}

const Date& Photo::getDate() const {
    return date;
}

ostream& operator<<(ostream& ost, const Photo& p) {
    p.print(ost);
    return ost;
}
