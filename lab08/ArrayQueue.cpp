/* ArrayQueue.cpp defines the methods for class ArrayQueue.
 * Joel Adams, for CS 112 at Calvin College.
 * Student name: Peter Haagsma
 * 		   Date: April 10, 2018
 */

#include "ArrayQueue.h"
#include "QueueException.h"
#include <cstring>      // memcpy()
using namespace std;

/* Constructor for ArrayQueue
 * @param: int capacity, the size of the internal array for the queue
 * Postcondition: New queue with capacity given and size 0
 */
ArrayQueue::ArrayQueue(int capacity) {
	if (capacity == 0) {
		throw EmptyQueueException("ArrayQueue::ArrayQueue(int)");
	}
	myArrayPtr = new Item[capacity];
	myCapacity = capacity;
	mySize = 0;
	myFirstIndex = 0;
	myLastIndex = capacity - 1;
}

/* copy constructor
 * @param: original, the ArrayQueue to be copied.
 * Postcondition: I am a deep copy of original.
 */
ArrayQueue::ArrayQueue(const ArrayQueue& original) {
	makeCopyOf(original);
}

/* utility method to build copies
 * @param: original, the ArrayQueue to be copied.
 * Postcondition: I am a deep copy of original.
 */
void ArrayQueue::makeCopyOf(const ArrayQueue& original) {
	mySize = original.mySize;
	myCapacity = original.myCapacity;
	myFirstIndex = original.myFirstIndex;
	myLastIndex = original.myLastIndex;
	myArrayPtr = new Item[myCapacity];
	memcpy(myArrayPtr, original.myArrayPtr, myCapacity*sizeof(Item) );
}

/* destructor
 * Postcondition: my dynamic array has been deallocated.
 */
ArrayQueue::~ArrayQueue() {
	delete [] myArrayPtr;
	myArrayPtr = NULL;
	mySize = myFirstIndex = myLastIndex = 0;
}

/* assignment operator
 * @param: aQueue, an ArrayQueue/
 * @return: myself.
 * Postcondition: I am a deep copy of aQueue.
 */
ArrayQueue& ArrayQueue::operator=(const ArrayQueue& aQueue) {
	if (this != &aQueue) {
		delete [] myArrayPtr;
		makeCopyOf(aQueue);
	}
	return *this;
}

/* Am I empty?
 * @return: true if I am empty, false othewise.
 */
bool ArrayQueue::isEmpty() const {
	return mySize == 0;
}

/* Am I full?
 * @return: true if I am full, false othewise.
 */
bool ArrayQueue::isFull() const {
	return getSize() == myCapacity;
}

/* accessor for myCapacity
 * @return myCapacity.
 */
unsigned ArrayQueue::getCapacity() const {
	return myCapacity;
}

/* accessor for mySize
 * @return mySize.
 */
unsigned ArrayQueue::getSize() const {
	return mySize;
}

/* Adds an item to the end of the queue
 * @params: an item 'it'
 * Postcondition: If queue was full:
 * 				  	  FullQueueException is thrown
 * 				  else:
 * 				  	  item is added to end of queue
 */
void ArrayQueue::append(const Item& it) {
	if ( isFull() ) {
		throw FullQueueException("ArrayQueue::append(const Item&)");
	}
	myLastIndex = (myLastIndex + 1) % myCapacity;
	myArrayPtr[myLastIndex] = it;
	mySize++;
}

/* Getter for the first item in the queue
 * returns: if the queue is empty:
 * 				throws an EmptyQueueException
 * 			else:
 * 				the first item in the queue
 */
Item ArrayQueue::getFirst() const {
	if (mySize == 0) {
		throw EmptyQueueException("ArrayQueue::getFirst()");
	}
	return myArrayPtr[myFirstIndex];
}

/* Getter for the last item in the queue
 * returns: if the queue is empty:
 * 				throws an EmptyQueueException
 * 			else:
 * 				the last item in the queue
 */
Item ArrayQueue::getLast() const {
	if (mySize == 0) {
		throw EmptyQueueException("ArrayQueue::getLast()");
	}
	return myArrayPtr[myLastIndex];
}

/* Removes the first item from the queue and returns it
 * returns: the first item in the queue
 * Postcondition: The queue has one less item, myFirstPtr points to the next item and the size is decremented
 * 				  If the original size of the queue is 0 then an EmptyQueueException is thrown
 */
Item ArrayQueue::remove() {
	if (mySize == 0) {
		throw EmptyQueueException("ArrayQueue::remove()");
	}
	mySize--;
	Item temp = myArrayPtr[myFirstIndex];
	myFirstIndex = (myFirstIndex + 1) % myCapacity;
	return temp;
}

