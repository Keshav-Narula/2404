#include "PhotoGram.h"

PhotoGram::PhotoGram()
    : albums(new AlbumArray) {
}
PhotoGram::~PhotoGram() {
    for (int i = 0; i < albums->size(); ++i) {
        delete albums->get(i);
    }
    delete albums;
}

bool PhotoGram::addAlbum(const string& albumTitle, const string& descriptionParam) {
    if (albums->isFull() == true) {
        cout << "addAlbum() FAILED - AlbumArray is full" << endl;
        return false;
    }
    // Album* newAlbum = new Album(albumTitle, descriptionParam);
    albums->add((new Album(albumTitle, descriptionParam)));
    return true;
}
bool PhotoGram::addPhoto(const string& albumTitle, const Photo& photoParam) {
    if (albums->get(albumTitle) == nullptr) {
        cout << "addPhoto() FAILED - Album not found " << endl;
        return false;
    } else {
        Photo* newPhoto = new Photo(photoParam);
        if (albums->get(albumTitle)->addPhoto(newPhoto) == true) {
            return true;
        } else {
            delete newPhoto;
            cout << "addPhoto() FAILED - PhotoArray is full" << endl;
            return false;
        }
    }
}
bool PhotoGram::removePhoto(const string& albumTitle, const string& photoTitle) {
    if (albums->get(albumTitle) == nullptr) {
        cout << "removePhoto() FAILED - Album not found " << endl;
        return false;
    } else {
        Photo* rmPhoto = albums->get(albumTitle)->removePhoto(photoTitle);
        if (rmPhoto == nullptr) {
            cout << "removePhoto() FAILED - Photo not found " << endl;
            return false;

        } else {
            delete rmPhoto;
            return true;
        }
    }
}
bool PhotoGram::removeAlbum(const string& albumTitle) {
    Album* returnAlbum = albums->remove(albumTitle);
    if (returnAlbum == nullptr) {
        cout << "removeAlbum() FAILED - Album not found " << endl;
        return false;
    } else {
        delete returnAlbum;
        return true;
    }
}

// Client Services

Album* PhotoGram::downloadAlbum(const string& albumTitle) const {
    Album* returnAlbum = albums->get(albumTitle);
    if (returnAlbum == nullptr) {
        cout << "downloadAlbum() FAILED - Album not found " << endl;
        return nullptr;
    } else {
        return returnAlbum;
    }
}
Photo* PhotoGram::downloadPhoto(const string& albumTitle, const string& photoTitle) const {
    if (albums->get(albumTitle) == nullptr) {
        cout << "downloadPhoto() FAILED - Album not found " << endl;
        return nullptr;
    } else {
        Photo* returnPhoto = albums->get(albumTitle)->getPhoto(photoTitle);
        if (returnPhoto == nullptr) {
            cout << "downloadPhoto() FAILED - Photo not found " << endl;
            return nullptr;
        } else {
            return returnPhoto;
        }
    }
}

// print
void PhotoGram::printAlbums() const {
    albums->print();
}
void PhotoGram::displayAlbums() const {
    albums->display();
}
