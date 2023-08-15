#include "Franchise.h"

int Franchise::nextId = 1;
const char Franchise::code = 'F';

const string Franchise::menu[MENU_ITEMS] = {"1. Large Poutine ", "2. Medium Poutine ", "3. Small Poutine "};

Franchise::Franchise(const string& nameParam, const Location& locationParam)
    : Entity(code, nextId++, nameParam, locationParam) {
}

Franchise::~Franchise() {
}

void Franchise::print() const {
    cout << endl
         << "FRANCHISE: ";
    Entity::print();
}

void Franchise::printMenu() {
    cout << "Menu: ";
    for (int i = 0; i < MENU_ITEMS; i++) {
        cout << menu[i];
    }
    cout << endl;
}
string Franchise::getMenu(const int& index) {
    if (index - 1 >= 0 && index - 1 <= 2) {
        return (menu[index - 1]);

    } else {
        return ("unknown menu item");
    }
}
