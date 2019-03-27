/* LinkedQueue.cpp defines the methods for class LinkedQueue.
 * Joel Adams, for CS 112 at Calvin College.
 * Student name: Peter Haagsma
 * 		   Date: April 10, 2018
 */

#include "LinkedQueue.h"
#include "QueueException.h"

/* Constructor for a linked node queue
 * Postcondition: Empty queue with size == 0
 * 								   myFirstPtr == NULL
 * 								   myLastPtr  == NULL
 */
LinkedQueue::LinkedQueue() {
	mySize = 0;
	myFirstPtr = NULL;
	myLastPtr = NULL;
}

/* Copy constructor for linked queue
 * @params: an original LinkedQueue object
 * Postcondition: A deep copy of the original linkedqueue object is created
 */
LinkedQueue::LinkedQueue(const LinkedQueue& original) {
	makeCopyOf(original);
}

/* Creates a copy of a linked queue, this function is used in the =operater and copy constructor
 * @params: an original LinkedQueue object
 * Postcondition: A deep copy of the original linkedqueue object is created
 */
void LinkedQueue::makeCopyOf(const LinkedQueue& original) {
	mySize = original.mySize;
	if ( mySize == 0 ) {
		myFirstPtr = myLastPtr = NULL;
	} else {
		myFirstPtr = new Node(original.getFirst(), NULL);
		Node * temp0 = original.myFirstPtr->myNextPtr;
		Node * temp1 = myFirstPtr;
		while (temp0 != NULL) {
			temp1->myNextPtr = new Node(temp0->myItem, NULL);
			temp1 = temp1->myNextPtr;
			temp0 = temp0->myNextPtr;
		}
		myLastPtr = temp1;
	}
}

/* Destructor for linkedqueue object
 * Postcondition: all nodes deallocated
 * 				  size set to 0
 * 				  pointers set to NULL
 */
LinkedQueue::~LinkedQueue() {
	delete myFirstPtr;
	myFirstPtr = myLastPtr = NULL;
	mySize = 0;
}

/* Assignment operator: creates a deep copy of LinkedQueue and sets another linkedqueue object equal to it
 * @params: an original LinkedQueue object
 * returns: the deep copy of the linkequeue object
 * Postcondition: A linked queue is set equal to deep copy of original
 */
LinkedQueue& LinkedQueue::operator=(const LinkedQueue& aQueue) {
	if (this != &aQueue) {
		delete myFirstPtr;    // invokes recursive ~Node()
		makeCopyOf(aQueue);
	}
	return *this;
}

/* Adds a new node to the end of the LinkedQueue
 * @params: an item 'it'
 * Postcondition: LinkedQueue with a new node
 * 								   myLastPtr pointing to new node
 * 								   mySize ++
 */
void LinkedQueue::append(const Item& it) {
	Node* newNode = new Node(it, NULL);
	if (myFirstPtr) {
		myLastPtr->myNextPtr = newNode;
		myLastPtr = newNode;
	} else {
		myFirstPtr = myLastPtr = newNode;
	}
	mySize++;
}

/* Getter for the item of the first node in the queue
 * returns: the item of the first node in the queue
 */
Item LinkedQueue::getFirst() const {
	if (myFirstPtr) {
		return myFirstPtr->myItem;
	}
	throw EmptyQueueException("LinkedQueue::getFirst()");
}

/* Getter for the item of the last node in the queue
 * returns: the item of the last node in the queue
 */
Item LinkedQueue::getLast() const {
	if (myLastPtr) {
		return myLastPtr->myItem;
	}
	throw EmptyQueueException("LinkedQueue::getLast()");
}

/* Removes the first node in the queue and returns its item
 * returns: the first node's item
 * Postcondition: Queue with first item removed
 * 							 myFirstPtr pointing to the second (now First) item
 */
Item LinkedQueue::remove() {
	// Check for empty queue
	if (!myFirstPtr) {
		throw EmptyQueueException("LinkedQueue::remove()");
	}
	// Store node info
	Item tempItem = myFirstPtr->myItem;
	Node* tempPtr = myFirstPtr->myNextPtr;
	// Check for size == 1
	if (mySize == 1) {
		myLastPtr = NULL;
	} else {
		myFirstPtr->myNextPtr = NULL;
	}
	// delete the node
	delete myFirstPtr;
	// update the list info
	myFirstPtr = tempPtr;
	mySize--;
	return tempItem;
}






