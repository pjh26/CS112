/* Stack.cpp defines the dynamically allocated (array-based ) Stack operations.
 * Joel Adams, for CS 112 at Calvin College.
 * Student Name: Peter Haagsma
 * Date:		 March 27, 2018
 */

#include "Stack.h"
#include "StackException.h"

/* explicit-value constructor
 * Parameter: capacity, an unsigned value.
 * Precondition: capacity > 0.
 * Postcondition: mySize == 0 && myCapacity == capacity
 *              && myArray contains the address of a dynamic array of 'capacity' entries.
 */
Stack::Stack(unsigned capacity) {
	if (capacity < 1) {
		throw StackException("Stack(size)", "size must be positive!");
	}
	mySize = 0;
	myCapacity = capacity;
	myArray = new Item[capacity];
}

/* copy constructor
 * Parameter: original, a Stack (const reference).
 * Postcondition: I am a copy of original.
 */
Stack::Stack(const Stack& original) {
	makeCopyOf(original);
}


/* utility method containing code refactored from
 *  the copy constructor and operator=.
 * Parameter: original, a Stack (const reference).
 * Precondition: original.myCapacity > 0.
 * Postcondition: I am a copy of original.
 */
void Stack::makeCopyOf(const Stack& original) {
	myCapacity = original.myCapacity;
	myArray = new Item[myCapacity];

	for (unsigned i = 0; i < myCapacity; i++) {
		myArray[i] = original.myArray[i];
	}
	mySize = original.mySize;
}


/* destructor
 * Postcondition: myCapacity == 0 && mySize == 0
 *             && myArray has been deallocated.
 */
Stack::~Stack() {
	delete [] myArray;
	myArray = NULL;
	myCapacity = 0;
	mySize = 0;
}


/* assignment operator
 * Parameter: original, a Stack (const reference).
 * Postcondition: I am a copy of original
 *              && I have been returned.
 */
Stack& Stack::operator=(const Stack& original) {
	if (this != &original) {
		delete [] myArray;
		makeCopyOf(original);
	}
	return *this;
}


/* Checks if the stack is empty
 * returns: true if the size is 0, otherwise false
 */
bool Stack::isEmpty() const {
	return mySize == 0;
}


/* Checks if the stack is full
 * returns: true if the size is equal to capacity, otherwise false
 */
bool Stack::isFull() const {
	return mySize == myCapacity;
}


/* Adds item to the top of the stack
 * @params: Some Item it
 * Precondition:  Stack object
 * Postcontition: Same stack object with new item it added to the end if there is room for it
 */
void Stack::push(const Item& it) {
	if ( isFull() ) {
		throw StackException("push()", "stack is full!");
	}
	myArray[mySize++] = it;
}


/* Getter for the top item of our stack
 * returns: a read-only reference of the top Item
 */
const Item& Stack::peekTop() const {
	if ( isEmpty() ) {
		throw StackException("peekTop()", "stack is empty!");
	}
	return myArray[mySize - 1];
}


/* "Removes" top item from stack and returns it
 * returns: copy of top item of stack
 * Precondition:  Stack object with some amount of items in it
 * Postcondition: Same stack object with the size reduced by 1.
 * 				  NOTE: Item is not immediately deleted/set to 0, the memory is allocated at runtime
 * 				  and it is therefore okay to leave that memory location with a value in it
 */
Item Stack::pop() {
	if ( isEmpty() ) {
		throw StackException("pop()", "stack is empty");
	}
	return myArray[--mySize];
}








