/*ArrayTester.h provides a class to test C-style array operations.
 * Student:
 * Date:
 * By: Joel Adams, for CS 112 at Calvin College.
 */
#ifndef ARRAY_TESTER_H_
#define ARRAY_TESTER_H_

#include "array.h"  // the functions we are testing
#include <iostream>
#include <cassert>
using namespace std;

class ArrayTester
{
public:
	ArrayTester();
	virtual ~ArrayTester();
	void runTests();
	void setup();
	void cleanup();
	void testInitialize();
	void testPrint();
	void testAverage();
	void testSum();
	void testResize();
	void testConcat();
	void testFill();
	void testRead();
private:
	double * a1;
	double * a2;
	double * a3;
};

#endif /*ARRAY_TESTER_H_*/
