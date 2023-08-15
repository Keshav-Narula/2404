#include "Album.h"

Album::Album(const string& titleParam, const string& descriptionParam)
    : title(titleParam), description(descriptionParam) {
}


bool Album::equals(const string& s) const {
    if (title == s) {
        return true;
    } else {
        return false;
    }
}

void Album::addPhoto(Photo* const photo) {
    //return (photos->add(photo));
    photos += photo;
}

Photo* Album::getPhoto(const int index) const {
    Photo* returnPhoto = photos[index];
    if(returnPhoto == NULL){
        return nullptr;
    }
    return returnPhoto;
}

void Album::print(ostream &ost) const {
    ost << endl;
    ost << "ALBUM MetaData: Title: " << title << " Description: " << description;
}
void Album::display(ostream &ost) const {
    print(ost);
    ost << endl<<"Photos: " << endl;
    for(int i=0; i < photos.size(); i++){
        photos[i]->display(ost);
    }    
}

int Album::size() const{
    return(photos.size());
}


ostream& operator<<(ostream& ost, const Album& d) {
    d.print(ost);	
    return ost;
}

