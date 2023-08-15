#include "Driver.h"

int Driver::nextId = 1;
const char Driver:: code = 'D';

Driver::Driver(const string& nameParam, const Location& locationParam)
    : Entity(code, nextId++, nameParam, locationParam) {
}

Driver::~Driver() {
}

bool Driver::isFree() const {
    return(Entity::orders->empty());
}
void Driver::print() const {
    cout<<endl<<"DRIVER: ";
    Entity::print();
}
