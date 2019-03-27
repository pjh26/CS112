/*
 * SongTester.h declares a test-class for class Song.
 *	Student Name: Peter Haagsma
 *  Date: Feb 5, 2018
 *  Author: Peter Haagsma
 */

#ifndef SONGTESTER_H_
#define SONGTESTER_H_

class SongTester {
public:
	SongTester();

	void runTests();

	void testConstructors();

	void testReadFrom();

	void testWriteTo();
};

#endif /* SONGTESTER_H_ */
