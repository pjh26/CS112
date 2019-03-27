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
using namespace std;

typedef double Item;

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
		

            Item myItem;
            Node* myLeft;
            Node* myRight;
	};
	Node* myRoot;
	unsigned myNumItems;
	friend class BST_Tester;
};

#endif /*BST_H_*/

