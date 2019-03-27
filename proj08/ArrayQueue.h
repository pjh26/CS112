/* ArrayQueue.h declares a Queue class using a dynamic array.
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 * Student name: Peter Haagsma
 * 		   Date: April 10, 2018
 * 
 * Class Invariant: 
 *    mySize == 0 ||
 *    mySize > 0 && myArray[myFirst] == getFirst()
 *               && myArray[myLast] == getLast().
 * 
 *  (When I am not empty:
 *     myFirstIndex is the index of my oldest value;
 *     myLastIndex is the index of my newest value.)
 */

#ifndef ARRAY_QUEUE_H_
#define ARRAY_QUEUE_H_

#include "QueueException.h"
#include <cstring>      // memcpy()
using namespace std;
//typedef int Item;
template<class Item>
class ArrayQueue {
public:
	ArrayQueue(const ArrayQueue<Item>& original);
	virtual ~ArrayQueue();
	ArrayQueue<Item>& operator=(const ArrayQueue<Item>& original);
	unsigned getSize() const;
	unsigned getCapacity() const;
	bool isEmpty() const;
	bool isFull() const;

	ArrayQueue(int capacity);
	void append(const Item& it);
	Item getFirst() const;
	Item getLast() const;
	Item remove();

	void setCapacity(unsigned newCapacity);


protected:
	virtual void makeCopyOf(const ArrayQueue<Item>& original);
private:
	unsigned mySize;       // number of items I contain
	unsigned myCapacity;   // how many items I can store
	unsigned myFirstIndex; // index of oldest item (if any)
	unsigned myLastIndex;  // index of newest item (if any)
	Item*    myArrayPtr;   // dynamic array of items

	friend class ArrayQueueTester;
};

/* Constructor for ArrayQueue
 * @param: int capacity, the size of the internal array for the queue
 * Postcondition: New queue with capacity given and size 0
 */
template<class Item>
ArrayQueue<Item>::ArrayQueue(int capacity) {
	if (capacity == 0) {
		throw EmptyQueueException("ArrayQueue<Item>::ArrayQueue(int)");
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
template<class Item>
ArrayQueue<Item>::ArrayQueue(const ArrayQueue<Item>& original) {
	makeCopyOf(original);
}

/* utility method to build copies
 * @param: original, the ArrayQueue to be copied.
 * Postcondition: I am a deep copy of original.
 */
template<class Item>
void ArrayQueue<Item>::makeCopyOf(const ArrayQueue<Item>& original) {
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
template<class Item>
ArrayQueue<Item>::~ArrayQueue() {
	delete [] myArrayPtr;
	myArrayPtr = NULL;
	mySize = myFirstIndex = myLastIndex = 0;
}

/* assignment operator
 * @param: aQueue, an ArrayQueue/
 * @return: myself.
 * Postcondition: I am a deep copy of aQueue.
 */
template<class Item>
ArrayQueue<Item>& ArrayQueue<Item>::operator=(const ArrayQueue<Item>& aQueue) {
	if (this != &aQueue) {
		delete [] myArrayPtr;
		makeCopyOf(aQueue);
	}
	return *this;
}

/* Am I empty?
 * @return: true if I am empty, false othewise.
 */
template<class Item>
bool ArrayQueue<Item>::isEmpty() const {
	return mySize == 0;
}

/* Am I full?
 * @return: true if I am full, false othewise.
 */
template<class Item>
bool ArrayQueue<Item>::isFull() const {
	return getSize() == myCapacity;
}

/* accessor for myCapacity
 * @return myCapacity.
 */
template<class Item>
unsigned ArrayQueue<Item>::getCapacity() const {
	return myCapacity;
}

/* accessor for mySize
 * @return mySize.
 */
template<class Item>
unsigned ArrayQueue<Item>::getSize() const {
	return mySize;
}

/* Adds an item to the end of the queue
 * @params: an item 'it'
 * Postcondition: If queue was full:
 * 				  	  FullQueueException is thrown
 * 				  else:
 * 				  	  item is added to end of queue
 */
template<class Item>
void ArrayQueue<Item>::append(const Item& it) {
	if ( isFull() ) {
		throw FullQueueException("ArrayQueue<Item>::append(const Item&)");
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
template<class Item>
Item ArrayQueue<Item>::getFirst() const {
	if (mySize == 0) {
		throw EmptyQueueException("ArrayQueue<Item>::getFirst()");
	}
	return myArrayPtr[myFirstIndex];
}

/* Getter for the last item in the queue
 * returns: if the queue is empty:
 * 				throws an EmptyQueueException
 * 			else:
 * 				the last item in the queue
 */
template<class Item>
Item ArrayQueue<Item>::getLast() const {
	if (mySize == 0) {
		throw EmptyQueueException("ArrayQueue<Item>::getLast()");
	}
	return myArrayPtr[myLastIndex];
}

/* Removes the first item from the queue and returns it
 * returns: the first item in the queue
 * Postcondition: The queue has one less item, myFirstPtr points to the next item and the size is decremented
 * 				  If the original size of the queue is 0 then an EmptyQueueException is thrown
 */
template<class Item>
Item ArrayQueue<Item>::remove() {
	if (mySize == 0) {
		throw EmptyQueueException("ArrayQueue<Item>::remove()");
	}
	mySize--;
	Item temp = myArrayPtr[myFirstIndex];
	myFirstIndex = (myFirstIndex + 1) % myCapacity;
	return temp;
}

/*
 *
 *
 *
 *
 *
 *
 */
template<class Item>
void ArrayQueue<Item>::setCapacity(unsigned newCapacity) {
	if (!newCapacity) {
		throw EmptyQueueException("ArrayQueue<Item>::setCapacity(unsigned)");
	} else if (newCapacity < mySize) {
		throw FullQueueException("ArrayQueue<Item>::setCapacity(unsigned)");
	}
	Item* tempArrayPtr = myArrayPtr;
	myArrayPtr = new Item[newCapacity];
	for (unsigned i = 0; i < mySize; i++) {
		myArrayPtr[i] = tempArrayPtr[(i + myFirstIndex) % myCapacity];
	}
	delete [] tempArrayPtr;
	myFirstIndex = 0;
	myLastIndex  = mySize - 1;
	myCapacity   = newCapacity;
}

#endif /*ARRAY_QUEUE_H_*/
