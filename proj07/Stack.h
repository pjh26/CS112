/* Stack.h provides a (dynamic-array-based) Stack class.
 * Joel Adams, for CS 112 at Calvin College.
 * Student Name: Peter Haagsma
 * Date:		 March 27, 2018
 * 
 * Invariant: mySize == 0 && isEmpty() && !isFull()
 *         || mySize == myCapacity && !isEmpty() && isFull()
 *         || mySize > 0 && mySize < myCapacity && !isEmpty() && !isFull().
 * Notes: 
 * 1. Member mySize always contains the index of the next empty space in myArray
 *        (the index of the array element into which the next pushed item will be placed).
 * 2. Sending push() to a full Stack throws the exception Stack::Overflow.
 * 3. Sending pop() or peekTop() to an empty Stack throws the exception Stack::Underflow.
 */

#ifndef STACK_H_
#define STACK_H_

#include <string>
#include <iostream>
#include "StackException.h"

using namespace std;

//typedef int  Item;
template <class Item>
class Stack {
public:
	Stack(unsigned capacity);
	Stack(const Stack<Item>& original);
	~Stack();
	Stack<Item>& operator=(const Stack<Item>& original);
	bool isEmpty() const;
	bool isFull() const;
	unsigned getSize() const { return mySize; }
	unsigned getCapacity() const { return myCapacity; }
	void setCapacity(unsigned newCap);
	void push(const Item& it);
	const Item& peekTop() const;
	Item pop();
	
protected:
	void makeCopyOf(const Stack<Item>& original);
	
private:
	unsigned myCapacity;
	unsigned mySize;
	Item*    myArray;
	friend class StackTester;
};

template <class Item>
Stack<Item>::Stack(unsigned capacity) {
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
template <class Item>
Stack<Item>::Stack(const Stack<Item>& original) { // @suppress("Class members should be properly initialized")
	makeCopyOf(original);
}

/* utility method containing code refactored from
 *  the copy constructor and operator=.
 * Parameter: original, a Stack (const reference).
 * Precondition: original.myCapacity > 0.
 * Postcondition: I am a copy of original.
 */
template <class Item>
void Stack<Item>::makeCopyOf(const Stack<Item>& original) {
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
template <class Item>
Stack<Item>::~Stack() {
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
template <class Item>
Stack<Item>& Stack<Item>::operator=(const Stack<Item>& original) {
	if (this != &original) {
		delete [] myArray;
		makeCopyOf(original);
	}
	return *this;
}

/* Checks if the stack is empty
 * returns: true if the size is 0, otherwise false
 */
template <class Item>
bool Stack<Item>::isEmpty() const {
	return mySize == 0;
}

/* Checks if the stack is full
 * returns: true if the size is equal to capacity, otherwise false
 */
template <class Item>
bool Stack<Item>::isFull() const {
	return mySize == myCapacity;
}

/* Adds item to the top of the stack
 * @params: Some Item it
 * Precondition:  Stack object
 * Postcontition: Same stack object with new item it added to the end if there is room for it
 */
template <class Item>
void Stack<Item>::push(const Item& it) {
	if ( isFull() ) {
		throw StackException("push()", "stack is full!");
	}
	myArray[mySize++] = it;
}

/* Getter for the top item of our stack
 * returns: a read-only reference of the top Item
 */
template <class Item>
const Item& Stack<Item>::peekTop() const {
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
template <class Item>
Item Stack<Item>::pop() {
	if ( isEmpty() ) {
		throw StackException("pop()", "stack is empty");
	}
	return myArray[--mySize];
}

/* Changes capacity of stack
 * @params: unsigned new capacity
 * Precondition:  Stack of a certain capacity
 * Postcondition: New stack with same items and the new capacity
 * 				  If the new capacity is smaller than the original size
 * 				  then a stack exception is thrown
 */
template <class Item>
void Stack<Item>::setCapacity(unsigned newCap) {
	if (newCap < mySize) {
		throw StackException("setCapacity()", "New capacity must be equal to or larger than size!");
	}

	Item* tempArray = new Item[newCap];
	for ( unsigned i = 0; i < myCapacity; i++ ) {
		tempArray[i] = myArray[i];
	}
	delete [] myArray;
	myArray = tempArray;
	myCapacity = newCap;
}

#endif
