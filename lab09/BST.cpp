/* BST.cpp defines binary search tree methods.
 * Joel Adams, for CS 112 at Calvin College.
 * Student Name:
 * Date:
 */
 
#include "BST.h"

/* Default constructor for the BST class
 * Postcondition: BST object created with size of zero and root set to NULL
 */
BST::BST() {
	myRoot = NULL;
	myNumItems = 0;
}

/* Destructor for the BST class
 * Postcondition: All nodes deleted and root set to NULL and size set to 0
 */
BST::~BST() {
	delete myRoot;
	myRoot = NULL;
	myNumItems = 0;
}

/* Constructor for BST::Node class
 * @params: const Item it
 * Postcondition: Object with item set to 'it' and two NULL pointers myRight and myLeft created
 */
BST::Node::Node(const Item& it) {
   myItem = it;
   myLeft = NULL;
   myRight = NULL;
}

/* Destructor for BST::Node class
 * Postcondition: recursively called on all nodes causing all nodes to be deleted
 */
BST::Node::~Node() {
	delete myLeft;
	delete myRight;
}

/* Checks if the BST is empty
 * returns: False if the number of items is 0, otherwise it returns true
 */
bool BST::isEmpty() const {
	return myNumItems == 0;
}

/* Getter for the number of items in the BST
 * returns: number of items (myNumItems)
 */
unsigned BST::getNumItems() const {
	return myNumItems;
}

/* Inserts a new node containing Item it in the proper place in the BST
 * @params: const Item it
 * Postcondition: BST with new node in the correct place
 */
void BST::insert( const Item& it ) {
	if (myRoot == NULL) {
		Node* newNode = new BST::Node(it);
		myRoot = newNode;
		myNumItems++;
		return;
	}
	try {
		myRoot->insert(it);
	} catch (Exception& e) {
		cout << e << endl;
		return;
	}
	myNumItems++;
}

/* Called by BST::insert to get the item to the correct place in the binary search tree
 * 			 If either myRight or myLeft are != NULL then this is recursively called on them
 * 			 called on myLeft if it < myItem
 * 			 called on myRight if it > myItem
 * 			 If it == myItem an Exception is thrown
 */
void BST::Node::insert(const Item& it) {
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
bool BST::contains(const Item& it) {
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
bool BST::Node::contains(const Item& it) {
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
void BST::traversePreorder() {
	if ( !isEmpty() ) {
		myRoot->traversePreorder();
	}
}

/* Outputs the contents of BST into the cosole
 * Postcondition: Contents are output after the items below them are processed
 */
void BST::traversePostorder() {
	if ( !isEmpty() ) {
		myRoot->traversePostorder();
	}
}

/* Outputs the contents of BST into the console
 * Postcondition: Contents are output from lowest to highest
 */
void BST::traverseInorder() {
	if ( !isEmpty() ) {
		myRoot->traverseInorder();
	}
}

/* Used in the travers... functions
 * Postcondition: myItem is output to console
 */
void BST::Node::processItem() {
		cout << ' ' << myItem;
}

/* Called by BST::traversePreorder to output contents of BST
 * Postcondition: outputs myItem and then recursively calls itself on myRight and myLeft
 */
void BST::Node::traversePreorder() {
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
void BST::Node::traversePostorder() {
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
void BST::Node::traverseInorder() {
	if (myLeft != NULL) {
		myLeft->traverseInorder();
	}
	processItem();
	if (myRight != NULL) {
		myRight->traverseInorder();
	}
}
