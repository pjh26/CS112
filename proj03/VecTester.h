/* VecTester.h provides unit tests for Vec, a simple vector class.
 * Student Name:Peter Haagsma & Mitchell Brill
 * Date:February 26
 * Begun by: Peter Haagsma & Mitchell Brill, for CS 112 at Calvin College.
 */
 
#ifndef VECTESTER_H_
#define VECTESTER_H_

#include "Vec.h"

class VecTester {
public:
	void runTests() const;
	void testDefaultConstructor() const;
	void testExplicitConstructor() const;
	void testDestructor() const;
	void testGetSize() const;
	void testSetItem() const;
	void testGetItem() const;
	void testSetSize() const;
	void testCopyConstructor() const;
	void testAssignment() const;
	void testEquality() const;
	void testWriteToStream() const;
	void testReadFromStream() const;
	void testInequality() const;
	void testAddition() const;
	void testSubtraction() const;
	void testDotProduct() const;
	void testReadFromFile() const;
	void testWriteToFile() const;
	void testSubscriptGetter() const;
	void testSubscriptAssign() const;
};

#endif /*VECTESTER_H_*/
