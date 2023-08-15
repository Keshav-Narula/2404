#include "MovieList.h"

MovieList::MovieList() {
	head = NULL;
	tail = NULL;

}

MovieList::~MovieList() {

	Node* currNode;
	Node* nextNode;
	
	currNode = head;
	
	while (currNode != NULL) {
		
		nextNode = currNode->next;
		delete currNode;
		currNode = nextNode;	
		
	}
}

// add to the front of the MovieList
void MovieList::addFront(Movie* movie) {

	Node* node = new Node();
	node->data = movie;
	node->next = NULL;
	
	if (head == NULL) {
	
		head = node;
		tail = node;

	} else {
	
		node->next = head;
		head = node;
	}

}
// add to the back of the MovieList
void MovieList::addBack(Movie* movie) {

	Node* node = new Node();
	node->data = movie;
	node->next = NULL;
	
	if (tail == NULL) {
	
		head = node;
		tail = node;

	} else {
	
		tail->next = node
		tail = node;	
	}

}

// remove and return the Movie at the front
Movie* MovieList::removeFront() {
	
	Movie* movie = NULL;
	
	if (head != NULL) {
		
		movie = head->data;
		Node* node = head;
		head = head->next;
		delete node;
	}		
	
	return movie;
}

// remove and return the Movie at the back
Movie * MovieList::removeBack () {

	Movie* movie = NULL;
	
	if (tail != NULL) {
		//One element
		if (head->next == NULL) {
			
			Node* node = head;
			head = NULL;
			tail = NULL;
			delete node;
			
		} else {
		
			Node* node = head;
			//Need to stop at the secound last Node, since that will be the new tail to the Linked List,
			//So we would update the node as we were traversing
			while (node->next->next != NULL) {
				node = node->next;
			}
			
			movie = node->next->data;
			tail = node;
			
			node = node->next;
			delete node;
		}
	
	
	}

	
	return movie;	
}
