/* List.cpp defines the methods for the List Class
 *
 *  Created on: Mar 6, 2018
 *      Author: Peter Haagsma
 *       Class: CS 112L C
 */

#include "List.h"

/* Default constructor for List object
 * Precondition: Nothing
 * Postcondition:List object with no size or nodes
 */
List::List() {
	mySize = 0;
	myFirst = NULL;
	myLast = NULL;
}


/* Copy constructor for List object
 * @params: List original
 * Precondition: Nothing
 * Postcondition:New list object that is a deep copy of List original
 */
List::List(const List& original) {
	myFirst = myLast = NULL;
	mySize = 0;
	if (original.mySize > 0) {
		Node* oPtr = original.myFirst;
		while (oPtr != NULL) {
			append(oPtr->myItem);
			oPtr = oPtr->myNext;
		}
	}
}


/* Default constructor for Node object
 * Precondition: Nothing
 * Postcondition:Node object with no value, pointing at nothing
 */
List::Node::Node() {
	myItem = 0;
	myNext = NULL;
}


/* Explicit constructor for Node object
 * @params: Item it and a pointer to the next Node
 * Precondition:  Nothing
 * Postcondition: Node object with value it, pointing at another node
 */
List::Node::Node(Item it, Node* next) {
	myItem = it;
	myNext = next;
}


/* Getter for size of List object
 * returns: Size of List object
 */
unsigned List::getSize() const {
	return mySize;
}


/* Getter for List object
 * Returns: pointer for first Node
 */
Item List::getFirst() const {
	if (mySize != 0) {
		return myFirst->myItem;
	} else {
		throw underflow_error("List is empty cannot access values: getFirst()");
	}
}


/* Getter for List object
 * Returns: pointer for last Node
 */
Item List::getLast() const {
	if (mySize != 0) {
		return myLast->myItem;
	} else {
		throw underflow_error("List is empty cannot access values: getFirst()");
	}
}


/* Appends a new node with value it to the end of a list
 * @params: Item it
 * Precondition:  List object
 * Postcondition: List object with new node holding value 'it' attached to the end
 */
void List::append(Item it) {
	List::Node* newNodePtr = new List::Node(it, NULL);
	if (mySize == 0) {
		myFirst = newNodePtr;
	} else {
		myLast->myNext = newNodePtr;
	}
	myLast = newNodePtr;
	mySize++;
}


/* Assignment operator for List objects
 * @params: List original
 * returns: this
 * Precondition:  List objects on either side of '=' operator
 * Postcondition: List object on left side of '=' operator is a deep copy of the right side and
 * 				  the left side is returned.
 */
List& List::operator=(const List& original) {
	if (this != &original) {
		delete myFirst;
		mySize = 0;
		myFirst = myLast = NULL;
		if (original.mySize != 0) {
			Node* oPtr = original.myFirst;
			while (oPtr != NULL) {
				append(oPtr->myItem);
				oPtr = oPtr->myNext;
			}
		}
	}
	return *this;
}


/* Destructor for Node Objects
 * Precondition:  Node object
 * Postcondition: Node object deleted; recursively calling delete on the next node object
 */
List::Node::~Node() {
	delete myNext;
}


/* Destructor for List objects
 * Precondition:  List object
 * Postcondition: Nodes deleted recursively and pointers set to null, size set to 0
 */
List::~List() {
	delete myFirst;
	myFirst = myLast = NULL;
	mySize = 0;
}
