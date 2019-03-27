/* BST_Tester.cpp defines test-methods for class BST.
 * Joel Adams, for CS 112 at Calvin College.
 */
 
#include "BST_Tester.h"
#include <cassert>

void BST_Tester::runTests() {
	cout << "Testing class BST" << endl;
	testConstructor();
	testInsert();
	testContains();
	testTraverse();
//	testGetHeight();
	cout << "All tests passed!" << endl;
}

//void BST_Tester::testGetHeight() {
//	cout << "Testing getHeight()..." << flush;
//	BST bst;
//	// empty
//	assert( bst.getHeight() == 0 );
//	cout << " 0 " << flush;
//	// balanced
//	bst.insert(44);
//	assert( bst.getHeight() == 1 );
//	cout << " 1 " << flush;
//	bst.insert(22);
//	assert( bst.getHeight() == 2 );
//	cout << " 2 " << flush;
//	bst.insert(66);
//	assert( bst.getHeight() == 2 );
//	cout << " 3 " << flush;
//	bst.insert(77);
//	assert( bst.getHeight() == 3 );
//	cout << " 4a " << flush;
//	bst.insert(55);
//	assert( bst.getHeight() == 3 );
//	cout << " 4b " << flush;
//	bst.insert(33);
//	assert( bst.getHeight() == 3 );
//	cout << " 4c " << flush;
//	bst.insert(11);
//	assert( bst.getHeight() == 3 );
//	cout << " 4d " << flush;
//	bst.insert(88);
//	assert( bst.getHeight() == 4 );
//	cout << " 4e " << flush;
//	// chained ascending
//      BST bst2a;
//      bst2a.insert(11);
//      bst2a.insert(22);
//      bst2a.insert(33);
//      bst2a.insert(44);
//      bst2a.insert(55);
//      bst2a.insert(66);
//      bst2a.insert(77);
//      assert( bst2a.getHeight() == 7 );
//      cout << " 5a " << flush;
//	// chained descending
//      BST bst2b;
//      bst2b.insert(77);
//      bst2b.insert(66);
//      bst2b.insert(55);
//      bst2b.insert(44);
//      bst2b.insert(33);
//      bst2b.insert(22);
//      bst2b.insert(11);
//      assert( bst2b.getHeight() == 7 );
//      cout << " 5b " << flush;
//	// four 4-node permutations
//	BST bst3;
//	bst3.insert(44);
//	assert( bst3.getHeight() == 1 );
//      cout << " 6a " << flush;
//	bst3.insert(22);
//	assert( bst3.getHeight() == 2 );
//      cout << " 6b " << flush;
//	bst3.insert(33);
//	assert( bst3.getHeight() == 3 );
//      cout << " 6c " << flush;
//	bst3.insert(55);
//	assert( bst3.getHeight() == 3 );
//      cout << " 6d " << flush;
//	BST bst4;
//	bst4.insert(44);
//	assert( bst4.getHeight() == 1 );
//      cout << " 7a " << flush;
//	bst4.insert(33);
//	assert( bst4.getHeight() == 2 );
//      cout << " 7b " << flush;
//	bst4.insert(22);
//	assert( bst4.getHeight() == 3 );
//      cout << " 7c " << flush;
//	bst4.insert(55);
//	assert( bst4.getHeight() == 3 );
//      cout << " 7d " << flush;
//	BST bst5;
//	bst5.insert(44);
//	assert( bst5.getHeight() == 1 );
//      cout << " 8a " << flush;
//	bst5.insert(33);
//	assert( bst5.getHeight() == 2 );
//      cout << " 8b " << flush;
//	bst5.insert(55);
//	assert( bst5.getHeight() == 2 );
//      cout << " 8c " << flush;
//	bst5.insert(66);
//	assert( bst5.getHeight() == 3 );
//      cout << " 8d " << flush;
//	BST bst6;
//	bst6.insert(44);
//	assert( bst6.getHeight() == 1 );
//      cout << " 9a " << flush;
//	bst6.insert(33);
//	assert( bst6.getHeight() == 2 );
//      cout << " 9b " << flush;
//	bst6.insert(66);
//	assert( bst6.getHeight() == 2 );
//      cout << " 9c " << flush;
//	bst6.insert(55);
//	assert( bst6.getHeight() == 3 );
//      cout << " 9d " << flush;
//	cout << " Passed!" << endl;
//}


void BST_Tester::testTraverse() {
	cout << "Testing traverse()..." << endl;
	BST bst;
	bst.insert(55);
	bst.insert(33);
	bst.insert(11);
	bst.insert(22);
	bst.insert(44);
	bst.insert(77);
	bst.insert(99);
	bst.insert(88);
	bst.insert(66);

	cout << "- Preorder: expecting: 55 33 11 22 44 77 66 99 88" << endl;
	cout << "- Got                :" << flush;
	bst.traversePreorder(); cout << endl;

	cout << "\n- Postorder: expecting: 22 11 44 33 66 88 99 77 55" << endl;
	cout << "- Got                 :" << flush;
	bst.traversePostorder(); cout << endl;

	cout << "\n- Inorder: expecting: 11 22 33 44 55 66 77 88 99" << endl;
	cout << "- Got               :" << flush;
	bst.traverseInorder(); cout << endl;
		cout << " Passed!" << endl;
}

void BST_Tester::testContains() {
	cout << "Testing contains()... " << flush;
	// empty bst
	BST bst;
	assert( !bst.contains(55) );
	cout << " 1 " << flush;
	// non-empty bst
	bst.insert(55);
	assert( bst.contains(55) );
	cout << " 2 " << flush;

	bst.insert(33);
	bst.insert(77);
	assert( bst.contains(55) );
	assert( bst.contains(33) );
	assert( bst.contains(77) );
	assert( !bst.contains(11) );
	assert( !bst.contains(111) );
	cout << " 3 " << flush;

	bst.insert(11);
	bst.insert(22);
	bst.insert(44);
	bst.insert(66);
	bst.insert(88);
	bst.insert(99);
	for (int i = 1; i <= 100; i++) {
		if ( i % 11 ) {
			assert( !bst.contains(i) );
		} else {
			assert( bst.contains(i) );
		}
	}
	cout << " 4 " << flush;

	cout << " Passed!" << endl;
}

void BST_Tester::testInsert() {
	cout << "Testing insert()... " << flush;
	BST bst;
	assert( bst.isEmpty() );
	cout << " 0 " << flush;
	bst.insert(55);
	assert( !bst.isEmpty() );
	assert( bst.myRoot != NULL );
	assert( bst.myRoot->myItem == 55 );
	assert( bst.myRoot->myLeft == NULL );
	assert( bst.myRoot->myRight == NULL );
	assert( bst.getNumItems() == 1 );
	cout << " 1 " << flush;

	bst.insert(33);
	assert( bst.getNumItems() == 2 );
	assert( bst.myRoot->myRight == NULL );
	assert( bst.myRoot->myLeft != NULL );
	assert( bst.myRoot->myRight == NULL );
	assert( bst.myRoot->myLeft->myItem == 33 );
	cout << " 2 " << flush;

	bst.insert(44);
	assert( bst.getNumItems() == 3 );
	assert( bst.myRoot->myRight == NULL );
	assert( bst.myRoot->myLeft->myRight != NULL );
	assert( bst.myRoot->myLeft->myRight->myItem == 44 );
	cout << " 3 " << flush;

	bst.insert(11);
	assert( bst.getNumItems() == 4 );
	assert( bst.myRoot->myRight == NULL );
	assert( bst.myRoot->myLeft->myLeft != NULL );
	assert( bst.myRoot->myLeft->myLeft->myItem == 11 );
	cout << " 4 " << flush;

	bst.insert(22);
	assert( bst.getNumItems() == 5 );
	assert( bst.myRoot->myRight == NULL );
	assert( bst.myRoot->myLeft->myLeft->myRight != NULL );
	assert( bst.myRoot->myLeft->myLeft->myRight->myItem == 22 );
	cout << " 5 " << flush;

	bst.insert(77);
	assert( bst.getNumItems() == 6 );
	assert( bst.myRoot->myRight != NULL );
	assert( bst.myRoot->myRight->myItem == 77 );
	cout << " 6 " << flush;

	bst.insert(66);
	assert( bst.getNumItems() == 7 );
	assert( bst.myRoot->myRight->myLeft->myItem == 66 );
	cout << " 7 " << flush;

	bst.insert(99);
	assert( bst.getNumItems() == 8 );
	assert( bst.myRoot->myRight->myRight->myItem == 99 );
	cout << " 8 " << flush;

	bst.insert(88);
	assert( bst.getNumItems() == 9 );
	assert( bst.myRoot->myRight->myRight->myLeft->myItem == 88 );
	cout << " 9 " << flush;

	try {
		bst.insert(55);
	} catch (Exception& e) {
		cout << " 10 " << flush;
	}

	try {
		bst.insert(11);
	} catch (Exception& e) {
		cout << " 11 " << flush;
	}

	try {
		bst.insert(88);
	} catch (Exception& e) {
		cout << " 12 " << flush;
	}

	bst.insert(111);
	assert( bst.getNumItems() == 10 );
	assert( bst.myRoot->myRight->myRight->myRight->myItem == 111 );
	cout << " 13 " << flush;

	cout << " Passed!" << endl;
}

void BST_Tester::testConstructor() {
	cout << "Testing constructor... " << flush;
	BST bst;
	assert( bst.isEmpty() );
	assert( bst.getNumItems() == 0 );
	assert( bst.myRoot == NULL );
	assert( bst.myNumItems == 0 );
	cout << "Passed!" << endl;
}

