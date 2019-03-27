/* List.h declares the methods for the List class
 *
 *  Created on: Mar 6, 2018
 *      Author: Peter Haagsma
 *       Class: CS 112L C
 */

#ifndef LIST_H_
#define LIST_H_
#include <iostream>
#include <stdexcept>
#include <cassert>
using namespace std;
typedef double Item;

class List {
public:

	List();
	List(const List& original);
	unsigned getSize() const;
	Item getFirst() const;
	Item getLast() const;
	void append(Item it);
	List& operator=(const List& l2);
	~List();
private:

	unsigned mySize;

	struct Node {
		Node();
		Node(Item it, Node* next);
		Item myItem;
		Node* myNext;

		~Node();
	};
	Node* myFirst;
	Node* myLast;
	friend class ListTester;
};

#endif /* LIST_H_ */
