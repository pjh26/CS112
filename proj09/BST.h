/* BST.h declares a "classic" binary search tree of linked nodes.
 * Joel Adams, for CS 112 at Calvin College.
 * Student Name:
 * Date:
 * 
 * Class Invariant:
 *   myNumItems == 0 && myRoot == NULL ||
 *   myNumItems > 0 && 
 *     myRoot stores the address of a Node containing an item &&
 *       all items in myRoot->myLeft are less than myRoot->myItem &&
 *       all items in myRoot->myRight are greater than myRoot->myItem.
 */

#ifndef BST_H_
#define BST_H_

#include "Exception.h"
#include <iostream>
#include <fstream>
using namespace std;

//typedef double Item;
template <class Item>
class BST {
public:

	BST();

	virtual ~BST();
	bool isEmpty() const;
	unsigned getNumItems() const;

	void insert( const Item& it );
	bool contains( const Item& it );
	void traverseInorder();
	void traversePreorder();
	void traversePostorder();

	unsigned getHeight() const;

private:
	struct Node {
	    Node(const Item& it);
            virtual ~Node();
            void insert(const Item& it);
            bool contains(const Item& it);
            void traverseInorder();
            void traversePreorder();
            void traversePostorder();
            virtual void processItem();
            unsigned getHeight();

            Item myItem;
            Node* myLeft;
            Node* myRight;
	};
	Node* myRoot;
	unsigned myNumItems;
	friend class BST_Tester;
};

/* BST.cpp defines binary search tree methods.
 * Joel Adams, for CS 112 at Calvin College.
 * Student Name:
 * Date:
 */

#include "BST.h"

/* Default constructor for the BST class
 * Postcondition: BST object created with size of zero and root set to NULL
 */
template <class Item>
BST<Item>::BST() {
	myRoot = NULL;
	myNumItems = 0;
}

/* Destructor for the BST class
 * Postcondition: All nodes deleted and root set to NULL and size set to 0
 */
template <class Item>
BST<Item>::~BST() {
	delete myRoot;
	myRoot = NULL;
	myNumItems = 0;
}

/* Constructor for BST::Node class
 * @params: const Item it
 * Postcondition: Object with item set to 'it' and two NULL pointers myRight and myLeft created
 */
template <class Item>
BST<Item>::Node::Node(const Item& it) {
   myItem = it;
   myLeft = NULL;
   myRight = NULL;
}

/* Destructor for BST::Node class
 * Postcondition: recursively called on all nodes causing all nodes to be deleted
 */
template <class Item>
BST<Item>::Node::~Node() {
	delete myLeft;
	delete myRight;
}

/* Checks if the BST is empty
 * returns: False if the number of items is 0, otherwise it returns true
 */
template <class Item>
bool BST<Item>::isEmpty() const {
	return myNumItems == 0;
}

/* Getter for the number of items in the BST
 * returns: number of items (myNumItems)
 */
template <class Item>
unsigned BST<Item>::getNumItems() const {
	return myNumItems;
}

/* Inserts a new node containing Item it in the proper place in the BST
 * @params: const Item it
 * Postcondition: BST with new node in the correct place
 */
template <class Item>
void BST<Item>::insert( const Item& it ) {
	if (myRoot == NULL) {
		Node* newNode = new BST::Node(it);
		myRoot = newNode;
		myNumItems++;
		return;
	}
	try {
		myRoot->insert(it);
	} catch (Exception& e) {
		throw Exception("BST::insert", "Item already in BST");
	}
	myNumItems++;
}

/* Called by BST::insert to get the item to the correct place in the binary search tree
 * 			 If either myRight or myLeft are != NULL then this is recursively called on them
 * 			 called on myLeft if it < myItem
 * 			 called on myRight if it > myItem
 * 			 If it == myItem an Exception is thrown
 */
template <class Item>
void BST<Item>::Node::insert(const Item& it) {
	if (it > myItem) {
		if (myRight == NULL) {
			myRight = new BST::Node(it);
		} else {
			myRight->insert(it);
		}
	} else if (it < myItem) {
		if (myLeft == NULL) {
			myLeft = new BST::Node(it);
		} else {
			myLeft->insert(it);
		}
	} else {
		throw Exception("BST::Node::insert(const Item& it)", "Item already in BST");
	}
}

/* Determines whether the BST contains a certain item
 * returns: true if item is in BST otherwise false
 */
template <class Item>
bool BST<Item>::contains(const Item& it) {
	if (myNumItems == 0) {
		return false;
	} else {
		return myRoot->contains(it);
	}
}

/* Called by BST::contains to determine if a certain item is in the BST
 * returns: true if myItem == it
 * 			if myLeft or myRight are not NULL then this is recursively called on those pointers
 * 			Otherwise it returns false
 */
template <class Item>
bool BST<Item>::Node::contains(const Item& it) {
	if (myItem == it) {
		return true;
	} else if (it > myItem) {
		if (myRight != NULL) {
			return myRight->contains(it);
		}
	} else if (it < myItem) {
		if (myLeft != NULL) {
			return myLeft->contains(it);
		}
	}
	return false;
}

/* Outputs the contents of BST into the console
 * Postcondition: Contents are output in the order that they are accessed
 */
template <class Item>
void BST<Item>::traversePreorder() {
	if ( !isEmpty() ) {
		myRoot->traversePreorder();
	}
}

/* Outputs the contents of BST into the cosole
 * Postcondition: Contents are output after the items below them are processed
 */
template <class Item>
void BST<Item>::traversePostorder() {
	if ( !isEmpty() ) {
		myRoot->traversePostorder();
	}
}

/* Outputs the contents of BST into the console
 * Postcondition: Contents are output from lowest to highest
 */
template <class Item>
void BST<Item>::traverseInorder() {
	if ( !isEmpty() ) {
		myRoot->traverseInorder();
	}
}

/* Used in the travers... functions
 * Postcondition: myItem is output to console
 */
template <class Item>
void BST<Item>::Node::processItem() {
		cout << ' ' << myItem;
}

/* Called by BST::traversePreorder to output contents of BST
 * Postcondition: outputs myItem and then recursively calls itself on myRight and myLeft
 */
template <class Item>
void BST<Item>::Node::traversePreorder() {
	processItem();
	if (myLeft != NULL) {
		myLeft->traversePreorder();
	}
	if (myRight != NULL) {
		myRight->traversePreorder();
	}
}

/* Called by BST::traversePostorder to output contenst of BST
 * Postcondition: recursively calls itself on myRight and myLeft and then outputs myItem
 */
template <class Item>
void BST<Item>::Node::traversePostorder() {
	if (myLeft != NULL) {
		myLeft->traversePostorder();
	}
	if (myRight != NULL) {
		myRight->traversePostorder();
	}
	processItem();
}

/* Called by BST::traverseInorder to output contents of BST
 * Postcondition: recursively calls itself on myLeft then outputs myItem
 * 				  then recursively calls itself on myRight
 */
template <class Item>
void BST<Item>::Node::traverseInorder() {
	if (myLeft != NULL) {
		myLeft->traverseInorder();
	}
	processItem();
	if (myRight != NULL) {
		myRight->traverseInorder();
	}
}

/* Returns height of the BST
 */
template <class Item>
unsigned BST<Item>::getHeight() const {
	if (myRoot != NULL) {
		return myRoot->getHeight();
	}
	return 0;

}

/* Called by BST::getHeight to find the height of the BST
 * Recursively calls itself until it gets to the bottom of the tree and then increments a variable on its way up
 * Which ever branch is larger is returned
 */
template <class Item>
unsigned BST<Item>::Node::getHeight() {
	unsigned rightHeight = 0;
	unsigned leftHeight = 0;

	if (myLeft !=  NULL) {
		leftHeight =  myLeft->getHeight();
	}
	if (myRight != NULL) {
		rightHeight = myRight->getHeight();
	}

	if (leftHeight > rightHeight) {
		return leftHeight + 1;
	} else {
		return rightHeight + 1;
	}

}

#endif /*BST_H_*/

