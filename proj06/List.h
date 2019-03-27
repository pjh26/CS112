/* List.h declares the methods for the List class
 *
 *  Created on: Mar 6, 2018
 *      Author: Peter Haagsma
 *       Class: CS 112L C
 */

#ifndef LIST_H_
#define LIST_H_
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <stdexcept>
#include <cassert>
using namespace std;

template <class Item>
class List {
public:
	List();
	List(const List<Item>& original);
	unsigned getSize() const;
	Item getFirst() const;
	Item getLast() const;
	void append(Item it);
	void prepend(Item it);
	void insert(Item it, int index);
	Item remove(int index);
	List<Item>& operator=(const List<Item>& l2);
	bool operator==(const List<Item>& l2);
	void readFrom(istream& cin);
	void writeTo(const string& fileName);
	bool operator!=(const List<Item>& l2);
	void writeTo(ostream& out) const;
	void readFrom(const string& fileName);
	int  getIndexOf(const Item& it);

	//Project 06
	bool insertAfter(const Item& otherPersonsName, const Item& yourName);
	bool insertBefore(const Item& otherPersonsName, const Item& yourName);

	/* Overloads << operator so that it outputs the desired format for lists
	 * @params: ostream and List object
	 * returns: ostream
	 * Precondition:  List object and empty ostream
	 * Postcondition: List object and ostream containing list in the following format
	 * 				  myItem1=>myItem2=>....=>myLastItem
	 */
	friend ostream& operator<<(ostream& out, const List<Item>& l) {
		for (Node * temp = l.myFirst; temp; temp = temp->myNext) {
			out << temp->myItem << flush;
			if (temp->myNext) {
				out << "=>";
			}
		}
		return out;
	}

	~List();
private:
	unsigned mySize;
	//Defining Node object
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

/* Default constructor for List object
 * Precondition: Nothing
 * Postcondition:List object with no size or nodes
 */
template <class Item>
List<Item>::List() {
	mySize = 0;
	myFirst = NULL;
	myLast = NULL;
}

/* Copy constructor for List object
 * @params: List original
 * Precondition: Nothing
 * Postcondition:New list object that is a deep copy of List original
 */
template <class Item>
List<Item>::List(const List& original) {
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
template <class Item>
List<Item>::Node::Node() {
	myItem = 0;
	myNext = NULL;
}

/* Explicit constructor for Node object
 * @params: Item it and a pointer to the next Node
 * Precondition:  Nothing
 * Postcondition: Node object with value it, pointing at another node
 */
template <class Item>
List<Item>::Node::Node(Item it, Node* next) {
	myItem = it;
	myNext = next;
}

/* Getter for size of List object
 * returns: Size of List object
 */
template <class Item>
unsigned List<Item>::getSize() const {
	return mySize;
}

/* Getter for List object
 * Returns: pointer for first Node
 */
template <class Item>
Item List<Item>::getFirst() const {
	if (mySize != 0) {
		return myFirst->myItem;
	} else {
		throw underflow_error("List is empty cannot access values: getFirst()");
	}
}

/* Getter for List object
 * Returns: pointer for last Node
 */
template <class Item>
Item List<Item>::getLast() const {
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
template <class Item>
void List<Item>::append(Item it) {
	Node* newNodePtr = new List<Item>::Node(it, NULL);
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
template <class Item>
List<Item>& List<Item>::operator=(const List<Item>& original) {
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

/* Prepends a new node with value it to the beginning of the list
 * @params: Item it
 * Precondition:  List object
 * Postcondition: List object with new node holding value 'it' inserted at beginning
 */
template <class Item>
void List<Item>::prepend(Item it) {
	Node* newNodePtr = new List<Item>::Node(it, NULL);
	if (mySize == 0) {
		myLast = newNodePtr;
	} else {
		newNodePtr->myNext = myFirst;
	}
	myFirst = newNodePtr;
	mySize++;
}

/* Inserts new node at 'index' holding value 'it'
 * @params: an Item it and an int index
 * Precondition:  List object
 * Postcondition: List object with new node holding value 'it' at 'index'
 */
template <class Item>
void List<Item>::insert(Item it, int index) {
	if (index <= 0 || mySize == 0) {
		prepend(it);
	} else if (index >= mySize) {
		append(it);
	} else {
		Node* tempPtr = myFirst;
		for (unsigned i = 0; i < index-1; ++i) {
			tempPtr = tempPtr->myNext;
		}
		Node* newNodePtr = new List<Item>::Node(it, tempPtr->myNext);
		tempPtr->myNext = newNodePtr;
		mySize++;
	}
}

/* Defines '==' operator for list objects
 * @params: Const List& object
 * Returns: True if myList and l2 have the same amount of nodes and hold the same values at
 * 			each one of the nodes, otherwise false
 */
template <class Item>
bool List<Item>::operator==(const List<Item>& l2) {
	if (mySize != l2.mySize) {
		return false;
	} else {
		Node* myPtr = myFirst;
		Node* l2Ptr = l2.myFirst;
		while (myPtr != NULL) {
			if (myPtr->myItem != l2Ptr->myItem) {
				return false;
			}
			l2Ptr = l2Ptr->myNext;
			myPtr = myPtr->myNext;
		}
		return true;
	}
}

/* Defines the != operator, returns true if this is not equal to l2, false if it is
 * @param l2, type List, a list to be compared
 * Return: true or false, type bool, the boolean value for the expression
 */
template <class Item>
bool List<Item>::operator!=(const List& l2) {
	if (mySize == l2.mySize) {
		Node * temp2 = l2.myFirst;
		for (Node * temp1 = myFirst; temp1; temp1 = temp1->myNext) {
			if (temp1->myItem != temp2->myItem) {
				return true;
			}
			temp2 = temp2->myNext;
		}
		return false;
	}
	return true;
}

/* Reads a line from an istream and creates a list from that line
 * @params: istream cin
 * Precondition:  istream 'cin' with a line inside containing values for a list
 * Postcondition: List object containing values from istream 'cin'
 */
template <class Item>
void List<Item>::readFrom(istream& cin) {
	string line;
	getline(cin, line);
	stringstream streamLine(line);
	Item tempVal;
	while (streamLine >> tempVal) {
		append(tempVal);
	}

}

/* write the items of the nodes of the list to a file
 * @param out, type ostream, an open file to be written to
 * Precondition: an open ofstream
 */
template <class Item>
void List<Item>::writeTo(ostream& out) const {
	for (Node * temp = myFirst; temp; temp = temp->myNext) {
		out << temp->myItem << endl;
	}
}

/* Writes List object to a file with each value on a new line.
 * @params: const string& 'filename'
 * Precondition:  List object and .txt file
 * Postcondition: List object and .txt file containing the values of List object
 */
template <class Item>
void List<Item>::writeTo(const string& fileName) {
	ofstream fout(fileName.c_str());
	Node* myPtr = myFirst;
	for (unsigned i = 0; i < mySize; i++) {
		fout << myPtr->myItem << endl;
		myPtr = myPtr->myNext;
	}
	fout.close();
}

/* read the elements of a list from a file and put them in a list
 * @param fileName, type string, a filename to a file to be read from
 */
template <class Item>
void List<Item>::readFrom(const string& fileName) {
	delete myFirst;
	ifstream fin(fileName.c_str());
	assert(fin.is_open());
	Item num;
	while (true) {
		if (fin >> num) {
			append(num);
		} else {
			break;
		}
	}
	fin.close();
}

/* find the index of a given item in a list
 * @param it, type Item, an item to find in the list
 */
template <class Item>
int List<Item>::getIndexOf(const Item& it) {
	unsigned i = 0;
	for (Node * temp = myFirst; temp; temp = temp->myNext) {
		if (temp->myItem == it) {
			return i;
		}
		i++;
	}
	return -1;
}

/* remove a node at a given index
 * @param index, type int, an index to a node to be removed
 */
template <class Item>
Item List<Item>::remove(int index) {
	//Throw error if the list is empty
	if (mySize == 0) {
		throw range_error("Cannot remove an item from an empty List!");

	//If the size is 1, delete the list
	} else if (mySize == 1) {
		Item item = myFirst->myItem;
		delete myFirst;
		mySize = 0;
		myFirst = NULL;
		myLast = NULL;
		return item;

	//If the size is greater than 1
	} else {
		//Set indexes out of range to the first or last value
		if (index < 0) {
			index = 0;
		} else if (index > mySize - 1) {
			index = mySize - 1;
		}
		Node* temp = myFirst;
		//When removing first node
		if (index == 0) {
			mySize--;
			Item item = temp->myItem;
			myFirst = temp->myNext;
			temp->myNext = NULL;
			delete temp;
			return item;
		//When removing any other node
		} else {
			for (unsigned i = 0; i < index; i++) {
				//Stop loop when at the node before the index
				if (i == index - 1) {
					mySize--;
					//Pointer to node to be removed
					Node * temp2 = temp->myNext;
					Item item = temp2->myItem;
					temp->myNext = temp->myNext->myNext;
					//Set pointers of node to be removed to NULL to prevent recursion when deleted
					if (temp->myNext) {
						temp->myNext->myNext = NULL;
						temp2->myNext = NULL;
					}
					//Edit my last if the last node is removed
					if (!temp->myNext) {
						myLast = temp;
					}
					delete temp2;
					return item;
				}
				//iterate though the nodes using a pointer
				temp = temp->myNext;
			}
		}
	}
}

/* Searches list for a certain item and inserts our item in a new node after said item if it is found
 * @params: item one is searching for and the item we wish to insert
 * Returns: true if the item we're searching for is in the list, otherwise false
 * Precondition:  List object
 * Postcondition: List object with item inserted after the one we're searching for if it is in the list.
 */
template <class Item>
bool List<Item>::insertAfter(const Item& otherPersonsName, const Item& yourName) {
	if (mySize == 0) {
		return false;
	}

	unsigned index = 0;
	for (Node* tempPtr = myFirst; tempPtr; tempPtr = tempPtr->myNext) {
		if (tempPtr->myItem == otherPersonsName) {
			if ( ++index == mySize ) {
				append(yourName);
			} else {
				Node* newNodePtr = new List<Item>::Node(yourName, tempPtr->myNext);
				tempPtr->myNext = newNodePtr;
				mySize++;
			}
			return true;
		}
	}
	return false;
}

/* Searches list for a certain item and inserts our item in a new node before said item if it is found
 * @params: item one is searching for and the item we wish to insert
 * Returns: true if the item we're searching for is in the list, otherwise false
 * Precondition:  List object
 * Postcondition: List object with item inserted before the one we're searching for if it is in the list.
 */
template <class Item>
bool List<Item>::insertBefore(const Item& otherPersonsName, const Item& yourName) {
	if (mySize == 0) {
		return false;
	}

	unsigned index = 0;
	Node* tempPtrPrev;
	for (Node* tempPtr = myFirst; tempPtr; tempPtr = tempPtr->myNext) {
		if (tempPtr->myItem == otherPersonsName) {
			if (index == 0) {
				prepend(yourName);
			} else if (index >= mySize) {
				append(yourName);
			} else {
				Node* newNodePtr = new List<Item>::Node(yourName, tempPtr);
				tempPtrPrev->myNext = newNodePtr;
				mySize++;
			}
			return true;
		}
		tempPtrPrev = tempPtr;
		index++;
	}
	return false;
}

/* Destructor for Node Objects
 * Precondition:  Node object
 * Postcondition: Node object deleted; recursively calling delete on the next node object
 */
template <class Item>
List<Item>::Node::~Node() {
	delete myNext;
}

/* Destructor for List objects
 * Precondition:  List object
 * Postcondition: Nodes deleted recursively and pointers set to null, size set to 0
 */
template <class Item>
List<Item>::~List() {
	delete myFirst;
	myFirst = myLast = NULL;
	mySize = 0;
}

#endif /* LIST_H_ */
