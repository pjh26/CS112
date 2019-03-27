/*
 * PlayListTester.h tests the PlayList class.
 * Student Name: Peter Haagsma
 * Date: Feb 6, 2018
 * CS112 Calvin College
 */

#ifndef PLAYLISTTESTER_H_
#define PLAYLISTTESTER_H_

class PlayListTester {
public:
	void runTests();
	void testConstructors();
	void testSearchByArtist();
	void testSearchByYear();
	void testSearchByTitlePhrase();
	void testAddRemoveSong();
	void testSave();
};

#endif /* PLAYLISTTESTER_H_ */
