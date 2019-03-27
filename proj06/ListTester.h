/* ListTester.h declares the test-class for class List.
 * Joel Adams, for CS 112 at Calvin College.
 * Continued by Peter Haagsma and Jonathon Ellis
 */

#ifndef LISTTESTER_H_
#define LISTTESTER_H_

class ListTester {
public:
	void runTests();
	void testDefaultConstructor();
	void testNodeDefaultConstructor();
	void testNodeExplicitConstructor();
	void testAppend();
	void testDestructor();
	void testCopyConstructor();
	void testAssignment();
	void testEquality();
	void testReadFromStream();
	void testWriteToString();
	void testPrepend();
	void testInsert();
	void testInequality();
	void testWriteToStream() const;
	void testReadFromFile() const;
	void testGetIndexOf();
	void testRemove();
	void testInsertAfter();
	void testInsertBefore();
	void testOutputOperator();
};

#endif /*LISTTESTER_H_*/
