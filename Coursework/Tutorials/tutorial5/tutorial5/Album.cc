#include "Album.h"

Album::Album(const string& titleParam, const string& descriptionParam)
    : title(titleParam), description(descriptionParam), photos(new PhotoArray) {
}
Album::Album(const Album& album) : title(album.title), description(album.description), photos(new PhotoArray(*album.photos)) {
}

Album::~Album() {
    delete photos;
}

string Album::getTitle() const {
    return title;
}
bool Album::equals(const string& s) const {
    if (title == s) {
        return true;
    } else {
        return false;
    }
}
bool Album::lessThan(const Album& alb) const {
    return (title < alb.getTitle());
}
bool Album::addPhoto(Photo* const photo) {
    return (photos->add(photo));
}
bool Album::addPhoto(const int& index, Photo* const photo) {
    return (photos->add(photo, index));
}
Photo* Album::getPhoto(const string& titleParam) const {
    return (photos->get(titleParam));
}
Photo* Album::getPhoto(const int& index) const {
    return (photos->get(index));
}
Photo* Album::removePhoto(const string& titleParam) {
    return (photos->remove(titleParam));
}
Photo* Album::removePhoto(const int& index) {
    return (photos->remove(index));
}

void Album::print() const {
    cout << endl;
    cout << "ALBUM MetaData: Title: " << title << " Description: " << description;
}
void Album::display() const {
    this->print();
    cout << endl<<"Photos: " << endl;
    photos->print();
    
}

int Album::size() const{
    return(photos->size());
}

