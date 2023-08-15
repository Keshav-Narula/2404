#include <iostream>
#include <string>
using namespace std;

#include "List.h"

List::List(): head(NULL){}


List::~List(){
    Node* currNode = head;
    Node* nextNode = NULL;

    while(currNode!=NULL){
        nextNode = currNode->next;
        delete currNode->data;
        delete currNode;
        currNode = nextNode;
    }

}

//add in sorted order by name
void List::add(Student* stu){
    Node* newNode = new Node();
    newNode->data = stu;
    newNode->next = NULL;

    Node* currNode = head;
    Node* prevNode = NULL;

    while(currNode!=NULL){
        if (newNode->data->lessThan(*currNode->data)){ //Check studnet if its data is less than the the current data, if so you found the correct location to insert 
            break; 
        }
        prevNode = currNode;
        currNode = currNode->next;
    }

    //insert currNode
    if (prevNode == NULL){ // Empty list
        head = newNode;
    }else{
        prevNode->next = newNode;
    }
    newNode->next = currNode;

}

void List::remove(const string& name, Student** goner){
    Node * currNode;
    Node * prevNode;

    currNode = head;
    prevNode = NULL;

    while (currNode!=NULL){
        if (currNode->data->matches(name)){
           break; 
        }
        prevNode = currNode;
        currNode = currNode->next;
    }

    if (currNode == NULL){
        *goner = NULL;
        return;
    }
    //currNode is not NULL
    if (prevNode == NULL){
        head = currNode->next;
    }else{
        prevNode->next = currNode->next;
    }
    *goner = currNode->data;
    delete currNode;
}

void List::get(const string& name, Student** stu){
    Node * currNode;

    currNode = head;

    while (currNode!=NULL){
        if (currNode->data->matches(name)){
           break; 
        }
        currNode = currNode->next;
    }

    if (currNode == NULL){
        *stu = NULL;
        return;
    }
    //currNode is not NULL
    *stu = currNode->data;
}

void List::removeUpTo(const string& name){
    Node * currNode;
    Node * prevNode;

    currNode = head;
    prevNode = NULL;

    while (currNode!=NULL){
        if (currNode->data->matches(name)){
           break; 
        }
        prevNode = currNode;
        currNode = currNode->next;
        delete prevNode->data;
        delete prevNode;
    }

    head = currNode;
}

void List::print() const{
    Node* currNode = head;
    cout<<"Print list..."<<endl;

    if (currNode == NULL){
        cout <<"List empty"<<endl;
    }

    while(currNode != NULL){
        currNode->data->print();
        currNode = currNode->next;
    }
}



