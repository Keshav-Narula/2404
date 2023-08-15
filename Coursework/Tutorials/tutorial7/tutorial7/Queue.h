#ifndef QUEUE_H
#define QUEUE_H
#include <string>

#include "Order.h"

class Queue{

    //friend class Student;

    //private by default
    class Node {

        public:
            Order* data;
            Node* next;
    };

    public:
        Queue();
        
        // Any data left in the List gets destroyed
        ~Queue();

        bool empty() const;
        int size() const;

        Order* peekFirst() const;

        //Removing from the head and adding to the tail
        Order* popFirst(); 
        //we have unlimited size, so add always succeeds
        void addLast(Order* order);
        //we have unlimited size, so add always succeeds

    private:
        Node* head;
        Node* tail;
        int numOrders;

};


#endif