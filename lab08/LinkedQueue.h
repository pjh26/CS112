/* LinkedQueue.h declares a Queue class using linked nodes.
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 * Student name: Peter Haagsma
 * 		   Date: April 10, 2018
 * 
 * Class Invariant: 
 *    mySize == 0 && myFirstPtr == NULL && myLastPtr == NULL ||
 *    mySize > 0 && myFirstPtr == the address of a node containing the oldest item
 *               && myLastPtr == the address of a node containing the newest item.
 */

#ifndef LINKED_QUEUE_H_
#define LINKED_QUEUE_H_

#include "QueueException.h"

typedef int Item;

class LinkedQueue {
public:
	LinkedQueue(const LinkedQueue& original);
	virtual ~LinkedQueue();
	LinkedQueue& operator=(const LinkedQueue& original);
	unsigned getSize() const { return mySize; }
	bool isEmpty() const { return mySize == 0; }
	bool isFull() const { return false; }

	LinkedQueue();
	void append(const Item& it);
	Item getFirst() const;
	Item getLast() const;
	Item remove();
protected:
	void makeCopyOf(const LinkedQueue& original);
private:
	unsigned mySize;
	struct Node {
		Item myItem;
		Node * myNextPtr;
		
		Node(const Item& it, Node* nextPtr) { myItem = it; myNextPtr = nextPtr; }
		~Node() { delete myNextPtr; }
	};
	Node * myFirstPtr;
	Node * myLastPtr;

	friend class LinkedQueueTester;
};

#endif /*LINKED_QUEUE_H_*/

