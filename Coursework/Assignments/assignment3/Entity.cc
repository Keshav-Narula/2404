#include "Entity.h"

Entity::Entity(const char& charParam, const int& intParam, const string& nameParam, const Location& locationParam)
    : id(charParam + to_string(intParam)), name(nameParam), location(new Location(locationParam)), orders(new Queue) {
}
Entity::~Entity() {
    delete location;
    delete orders;
}

// Location* getLocation() const;
void Entity::setLocation(const Location* locationParam) {
    delete location;
    location = new Location(*locationParam);
}

Order* Entity::getNextOrder() {
    return (orders->popFirst());
}

int Entity::getNumOrders() const {
    return (orders->size());
}

void Entity::addOrder(Order* const order) {
    orders->addLast(order);
}

void Entity::print() const {
    cout << "ID: " << id << ", NAME: " << name << ", LOCATION: ";
    location->print();
    cout << " #Orders: " << this->getNumOrders() << endl;
}

bool Entity::equals(const string& idParam) {
    return (idParam == id);
}