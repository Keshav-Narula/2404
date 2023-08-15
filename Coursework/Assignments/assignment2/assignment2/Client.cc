#include "Client.h"

Client::Client()
    : albums(new AlbumArray) {
}
Client::~Client() {
    for (int i = 0; i < albums->size(); ++i) {
        delete albums->get(i);
    }
    delete albums;
}

bool Client::downloadAlbum(const PhotoGram* pg, const string& albumTitle) {
    if (albums->isFull() == true) {
        return false;
        cout << "downloadAlbum() FAILED - AlbumArray is full" << endl;
    }
    Album* dlAlbum = pg->downloadAlbum(albumTitle);
    if (dlAlbum == nullptr) {
        return false;
    } else {
        Album* newAlbum = new Album(*dlAlbum);
        albums->add(newAlbum);
        return true;
    }
}
bool Client::displayOnlinePhoto(const PhotoGram* pg, const string& albumTitle, const string& photoTitle) const {
    Photo* photoFound = pg->downloadPhoto(albumTitle, photoTitle);
    if (photoFound == nullptr) {
        return false;
    } else {
        photoFound->display();
        return true;
    }
}
bool Client::displayLocalPhoto(const string& albumTitle, const string& photoTitle) const {
    if (albums->get(albumTitle) == nullptr) {
        cout << "displayLocalPhoto() FAILED - Album not found " << endl;
        return false;
    } else {
        Photo* photoFound = albums->get(albumTitle)->getPhoto(photoTitle);
        if (photoFound == nullptr) {
            cout << "displayLocalPhoto() FAILED - Photo not found " << endl;
            return false;
        } else {
            photoFound->display();
            return true;
        }
    }
}

void Client::printLocalAlbums() const {
    albums->print();
}
void Client::displayLocalAlbums() const {
    albums->display();
}