#include "Queue.h"

Queue::Queue() : head(nullptr), tail(nullptr), numOrders(0) {}

Queue::~Queue() {
    Node* currNode = head;
    Node* nextNode = nullptr;

    while (currNode != nullptr) {
        nextNode = currNode->next;
        //delete currNode->data;
        delete currNode;
        currNode = nextNode;
    }
}

bool Queue::empty() const {
    if (numOrders <= 0) {
        return true;
    } else {
        return false;
    }
}

int Queue::size() const {
    return numOrders;
}

Order* Queue::peekFirst() const {
    if (head != nullptr) {
        return head->data;
    } else {
        return nullptr;
    }
}

Order* Queue::popFirst() {
    if(empty() == true){
        return nullptr;
    }

    Order* returnOrder = head->data;
    Node* currNode;

    currNode = head;

    head = currNode->next;
    delete currNode;
    numOrders--;
    if(numOrders == 0){
        head = nullptr;
    }

    if(numOrders == 1){
        tail = nullptr;
    }
    return returnOrder;


}

void Queue::addLast(Order* order) {
    Node* newNode = new Node();
    newNode->data = order;
    newNode->next = nullptr;

    if (head == nullptr && numOrders <= 0) {
        head = newNode;
        numOrders++;
        return;
    }

    if (tail == nullptr && numOrders == 1) {
        tail = newNode;
        head->next = newNode;
        numOrders++;

        return;
    }
    numOrders++;
    Node* currTail = tail;
    currTail->next = newNode;
    tail = newNode;
}
