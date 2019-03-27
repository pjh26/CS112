/* QueueTester.cpp defines the test-methods for class Queue.
 * Joel Adams, for CS 112 at Calvin College.
 */
 
#include "ArrayQueueTester.h"
#include <iostream>
#include <cassert>
#include <cstdlib>
using namespace std;

void ArrayQueueTester::runTests() {
	cout << "Testing class ArrayQueue..." << endl;
	testConstructor();
	testAppend();
	testRemove();
	testCopyConstructor();
	testAssignment();
	cout << "All tests passed!\n" << endl;
}

void ArrayQueueTester::testAssignment() {
	cout << "- testing assignment... " << flush;
	// empty, smaller-to-bigger;
	ArrayQueue q1(4);
	ArrayQueue q2(3);
	q1 = q2;
	assert( q1.isEmpty() );
	assert( q1.myCapacity == 3 );
	assert( q1.getSize() == 0 );
	assert( q1.myFirstIndex == q2.myFirstIndex );
	assert( q1.myLastIndex == q2.myLastIndex );
	assert( q1.myArrayPtr != q2.myArrayPtr );
	cout << " 1 " << flush;
	//empty, bigger to smaller
	ArrayQueue q3(3);
	ArrayQueue q4(4);
	q3 = q4;
	assert( q3.isEmpty() );
	assert( q3.myCapacity == 4 );
	assert( q3.getSize() == 0 );
	assert( q3.myFirstIndex == q4.myFirstIndex );
	assert( q3.myLastIndex == q4.myLastIndex );
	assert( q3.myArrayPtr != q4.myArrayPtr );
	cout << " 2 " << flush;
	// full, same-sized
	ArrayQueue q5(4);
	q5.append(11);
	q5.append(22);
	q5.append(33);
	q5.append(44);
	ArrayQueue q6(4);
	q6 = q5;
	assert( q6.isFull() );
	assert( !q6.isEmpty() );
	assert( q6.myCapacity == 4 );
	assert( q6.getSize() == 4 );
	assert( q6.myFirstIndex == q5.myFirstIndex );
	assert( q6.myLastIndex == q5.myLastIndex );
	for (unsigned i = 0; i < q6.myCapacity; i++) {
		assert( q6.myArrayPtr[i] == q5.myArrayPtr[i] );
	}
	assert( q6.myArrayPtr != q5.myArrayPtr );
	cout << " 3 " << flush;
	// full, smaller-to-larger
	ArrayQueue q7(3);
	q7 = q5;
	assert( q7.isFull() );
	assert( !q7.isEmpty() );
	assert( q7.myCapacity == 4 );
	assert( q7.getSize() == 4 );
	assert( q7.myFirstIndex == q5.myFirstIndex );
	assert( q7.myLastIndex == q5.myLastIndex );
	for (unsigned i = 0; i < q7.myCapacity; i++) {
		assert( q7.myArrayPtr[i] == q5.myArrayPtr[i] );
	}
	assert( q7.myArrayPtr != q5.myArrayPtr );
	cout << " 4 " << flush;
	// full, larger-to-smaller
	ArrayQueue q8(5);
	q8 = q5;
	assert( q8.isFull() );
	assert( !q8.isEmpty() );
	assert( q8.myCapacity == 4 );
	assert( q8.getSize() == 4 );
	assert( q8.myFirstIndex == q5.myFirstIndex );
	assert( q8.myLastIndex == q5.myLastIndex );
	for (unsigned i = 0; i < q8.myCapacity; i++) {
		assert( q8.myArrayPtr[i] == q5.myArrayPtr[i] );
	}
	assert( q8.myArrayPtr != q5.myArrayPtr );
	cout << " 5 " << flush;
	// self assignment
	q5 = q5;
	assert( q5.isFull() );
	assert( !q5.isEmpty() );
	assert( q5.myCapacity == 4 );
	assert( q5.getSize() == 4 );
	assert( q5.myArrayPtr[0] == 11 );
	assert( q5.myArrayPtr[1] == 22 );
	assert( q5.myArrayPtr[2] == 33 );
	assert( q5.myArrayPtr[3] == 44 );
	cout << " 6 " << flush;
	// chaining
	q1 = q3 = q5;
	assert( q1.isFull() );
	assert( !q1.isEmpty() );
	assert( q1.myCapacity == 4 );
	assert( q1.getSize() == 4 );
	assert( q1.myArrayPtr[0] == 11 );
	assert( q1.myArrayPtr[1] == 22 );
	assert( q1.myArrayPtr[2] == 33 );
	assert( q1.myArrayPtr[3] == 44 );
	assert( q1.myArrayPtr != q3.myArrayPtr );
	assert( q1.myArrayPtr != q5.myArrayPtr );
	assert( q3.myArrayPtr != q5.myArrayPtr );
	cout << " 7 " << flush;
	cout << "Passed!" << endl;
}

void ArrayQueueTester::testCopyConstructor() {
	cout << "- testing copy constructor... " << flush;
	// empty queue
	ArrayQueue q1(4);
	ArrayQueue q2(q1);
	assert( q2.isEmpty() );
	assert( !q2.isFull() );
	assert( q2.myCapacity == q1.myCapacity);
	assert( q2.myFirstIndex == q1.myFirstIndex );
	assert( q2.myLastIndex == q1.myLastIndex );
	assert( q2.myArrayPtr != q1.myArrayPtr );
	cout << " 1 " << flush;
	// queue of 1 item
	ArrayQueue q3(4);
	q3.append(11);
	ArrayQueue q4(q3);
	assert( !q4.isFull() );
	assert( !q4.isEmpty() );
	assert( q4.myCapacity == q3.myCapacity);
	assert( q4.myFirstIndex == q3.myFirstIndex );
	assert( q4.myLastIndex == q3.myLastIndex );
	assert( q4.myArrayPtr != q3.myArrayPtr );
	assert( q4.getFirst() == 11 );
	assert( q4.getLast() == 11 );
	assert( q4.myArrayPtr != q3.myArrayPtr );
 	cout << " 2 " << flush;
 	// full queue
 	q3.append(22);
 	q3.append(33);
 	q3.append(44);
 	ArrayQueue q5(q3);
	assert( q5.isFull() );
	assert( !q5.isEmpty() );
	assert( q5.myCapacity == q3.myCapacity);
	assert( q5.myFirstIndex == q3.myFirstIndex );
	assert( q5.myLastIndex == q3.myLastIndex );
	assert( q5.myArrayPtr != q3.myArrayPtr );
 	assert( q5.getFirst() == 11 );
	assert( q5.getLast() == 44 );
	assert( q5.myArrayPtr != q3.myArrayPtr );
 	cout << " 3 " << flush;
	cout << "Passed!" << endl;
}

void ArrayQueueTester::testRemove() {
	cout << "- testing remove()... " << flush;
	ArrayQueue q1(4);
	cout << " 0 " << flush;
	// check with empty queue
	try {
		q1.remove();
		cerr << "\nremove() worked on empty Queue - 1\n";
		exit(1);
	} catch (EmptyQueueException& eqe) {
		cout << " 1 " << flush;
	}
	// check with 1 item
	q1.append(1);
	assert( !q1.isEmpty() );
	assert( q1.remove() == 1 );
	assert( q1.isEmpty() );
	cout << " 2 " << flush;
	// check with 2 items
	q1.append(11);
	q1.append(22);
	assert( !q1.isEmpty() );
	assert( q1.getFirst() == 11 );
	assert( q1.getLast() == 22 );
	assert( q1.remove() == 11 );
	assert( q1.getFirst() == 22 );
	assert( q1.getLast() == 22 );
	assert( q1.remove() == 22 );
	assert( q1.isEmpty() );
	cout << " 3 " << flush;
	// load it up
	q1.append(111);
	q1.append(222);
	q1.append(333);
	q1.append(444);
	assert( q1.isFull() );
	assert( !q1.isEmpty() );
	assert( q1.getFirst() == 111 );
	assert( q1.getLast() == 444 );
	// start removing items
	assert( q1.remove() == 111 );
	assert( !q1.isFull() );
	assert( !q1.isEmpty() );
	assert( q1.getFirst() == 222 );
	assert( q1.getLast() == 444 );
    cout << " 4a " << flush;
	assert( q1.remove() == 222 );
	assert( !q1.isFull() );
	assert( !q1.isEmpty() );
	assert( q1.getFirst() == 333 );
	assert( q1.getLast() == 444 );
    cout << " 4b " << flush;
	assert( q1.remove() == 333 );
	assert( !q1.isFull() );
	assert( !q1.isEmpty() );
	assert( q1.getFirst() == 444 );
	assert( q1.getLast() == 444 );
    cout << " 4c " << flush;
	assert( q1.remove() == 444 );
	assert( !q1.isFull() );
	assert( q1.isEmpty() );
    cout << " 4d " << flush;
	// recheck empty queue
	try {
		q1.remove();
		cerr << "\nremove() worked on empty Queue - 2\n";
		exit(1);
	} catch (EmptyQueueException& eqe) {
		cout << " 5 " << flush;
	}
      ArrayQueue q2(5000);
    cout << " 6a " << flush;
      for (Item i = 5000; i > 0; i--) {
          q2.append(i);
      }
      assert( q2.isFull() );
    cout << " 6b " << flush;
      for (Item i = 5000; i > 0; i--) {
          assert( q2.remove() == i );
      }
      assert( q2.isEmpty() );
    cout << " 6c " << flush;
	cout << "Passed!" << endl;
}

void ArrayQueueTester::testAppend() {
	cout << "- testing append(), getFirst(), getLast() ... " << flush;
	ArrayQueue q1(4);
	assert( q1.isEmpty() );
	assert( !q1.isFull() );
	try {
		q1.getFirst();
		cerr << "\ngetFirst() worked on empty queue\n";
		exit(1);
	} catch (EmptyQueueException& eqe) {
		cout << " 0a " << flush;
	}
	try {
		q1.getLast();
		cerr << "\ngetLast() worked on empty queue\n";
		exit(1);
	} catch (EmptyQueueException& eqe) {
		cout << " 0b " << flush;
	}
	q1.append(11);
	assert( !q1.isEmpty() );
	assert( !q1.isFull() );
	assert( q1.getFirst() == 11 );
	assert( q1.getLast() == 11 );
	cout << " 1 " << flush;
	q1.append(22);
	assert( !q1.isEmpty() );
	assert( !q1.isFull() );
	assert( q1.getFirst() == 11 );
	assert( q1.getLast() == 22 );
	cout << " 2 " << flush;
	q1.append(33);
	assert( !q1.isEmpty() );
	assert( !q1.isFull() );
	assert( q1.getFirst() == 11 );
	assert( q1.getLast() == 33 );
	cout << " 3 " << flush;
	q1.append(44);
	assert( !q1.isEmpty() );
	assert( q1.isFull() );
	assert( q1.getFirst() == 11 );
	assert( q1.getLast() == 44 );
	cout << " 4 " << flush;
	// append to full queue
	try {
		q1.append(55);
		cerr << "\nappend() worked on full queue\n";
		exit(1);
	} catch (FullQueueException& fqe) {
		cout << " 5 " << flush;
	}
	cout << "Passed, but wrap-around not tested..." << endl;
}

void ArrayQueueTester::testConstructor() {
	cout << "- testing constructor... " << flush;
	// try with capacity zero
	try {
		ArrayQueue q1(0);
		cerr << "Constructed Queue with capacity zero" << endl;
		exit(1);
	} catch (QueueException& qe) {
	    cout << " 1 " << flush;
	}

	// positive capacity
	ArrayQueue q2(3);
	assert( q2.isEmpty() );
	assert( !q2.isFull() );
	assert( q2.myCapacity == 3 );
	cout << " 2 " << flush;
	cout << " Passed!" << endl;
}

