/*
 * PlayListTester.cpp defines the PlayListTester methods
 * Student Name: Peter Haagsma
 * Date: Feb 6, 2018
 * CS112 Calvin College
 */

#include "PlayListTester.h"
#include "PlayList.h"
#include "Song.h"
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;


void PlayListTester::runTests() {
	cout << "\nTesting class PlayList..." << endl;
	testConstructors();
	testSearchByArtist();
	testSearchByYear();
	testSearchByTitlePhrase();
	testAddRemoveSong();
	testSave();
	cout << "All tests passed!" << endl;
}

void PlayListTester::testConstructors() {
	cout << "- constructors..." << flush;
	PlayList pList("testSongs.txt");
	assert( pList.getNumSongs() == 4 );
	cout << " 0 " << flush;

	cout << " Passed!" << endl;
}

void PlayListTester::testSearchByArtist() {
	cout << "- searchByArtist()..." << flush;
	// load a playlist with test songs
	PlayList pList("testSongs.txt");

	// empty case (0)
	vector<Song> searchResult = pList.searchByArtist("Cream");
	assert( searchResult.size() == 0 );
	cout << "0 " << flush;

	// case of 1
	searchResult = pList.searchByArtist("Baez");
	assert( searchResult.size() == 1 );
	assert( searchResult[0].getTitle() == "Let It Be\r" );
	cout << "1 " << flush;

	// case of 2
	searchResult = pList.searchByArtist("Beatles");
	assert( searchResult.size() == 2 );
	assert( searchResult[0].getTitle() == "Let It Be\r" );
	assert( searchResult[1].getTitle() == "Penny Lane\r" );
	cout << "2 " << flush;

	cout << " Passed!" << endl;
}

void PlayListTester::testSearchByYear() {
	cout << "- searchByYear()..." << flush;
	// load a playlist with test songs
	PlayList pList("testSongs.txt");

	// empty case (0)
	vector<Song> searchResult = pList.searchByYear(2018);
	assert( searchResult.size() == 0 );
	cout << "0 " << flush;

	// case of 1
	searchResult = pList.searchByYear(2012);
	assert( searchResult.size() == 1 );
	assert( searchResult[0].getYear() == 2012 );
	cout << "1 " << flush;

	// case of 2
	searchResult = pList.searchByYear(1967);
	assert( searchResult.size() == 2 );
	assert( searchResult[0].getYear() == 1967 );
	assert( searchResult[1].getYear() == 1967 );
	cout << "2 " << flush;

	cout << " Passed!" << endl;
}

void PlayListTester::testSearchByTitlePhrase() {
	cout << "- searchByTitlePhrase()..." << flush;
	// load a playlist with test songs
	PlayList pList("testSongs.txt");

	// empty case (0)
	vector<Song> searchResult = pList.searchByTitlePhrase("Taxman");
	assert( searchResult.size() == 0 );
	cout << "0 " << flush;

	// case of 1
	searchResult = pList.searchByTitlePhrase("Call Me ");
	assert( searchResult.size() == 1 );
	assert( searchResult[0].getTitle() == "Call Me Maybe\r" );
	cout << "1 " << flush;

	// case of 2
	searchResult = pList.searchByTitlePhrase("Let It Be");
	assert( searchResult.size() == 2 );
	assert( searchResult[0].getTitle() == "Let It Be\r" );
	assert( searchResult[1].getTitle() == "Let It Be\r" );
	cout << "2 " << flush;

	cout << " Passed!" << endl;
}

void PlayListTester::testAddRemoveSong() {
	cout << "- addSong() & removeSong()..." << flush;
	// load a playlist with test songs
	PlayList pList("testSongs.txt");
	assert( pList.getNumSongs() == 4 );

	// create a test song
	Song s1("The Wall", "Pink Floyd", 1979);

	// add test song to the end of the playlist
	pList.addSong(s1);
	assert( pList.getNumSongs() == 5 );
	cout << " 0" << flush;

	vector<Song> searchResult = pList.searchByArtist( "Pink Floyd" );
	assert( searchResult.size() == 1 );
	assert( searchResult[0].getTitle() == "The Wall" );
	assert( searchResult[0].getArtist() == "Pink Floyd" );
	assert( searchResult[0].getYear() == 1979 );
	cout << " 1" << flush;

	// remove test song from the PlayList
	Song s2("The Wall", "Pink Floyd", 1979);
	pList.removeSong(s2);
	assert( pList.getNumSongs() == 4 );
	searchResult.clear();
	searchResult = pList.searchByArtist( "Pink Floyd" );
	assert( searchResult.size() == 0 );
	cout << " 2" << flush;

	cout << " Passed!" << endl;
}

void PlayListTester::testSave() {
	cout << "- save()..." << flush;

	// load a playlist with test songs
	PlayList pList("testSongs.txt");
	assert( pList.getNumSongs() == 4 );

	// create a test song and add it
	Song s1("The Wall", "Pink Floyd", 1979);
	pList.addSong(s1);

	// save it and make a new playlist
	pList.save();
	PlayList testpList("testSongs.txt");
	assert( pList.getNumSongs() == testpList.getNumSongs() );
	cout << " 0" << flush;
	// returning file to original state for future tests
	testpList.removeSong( s1 );
	testpList.save();
	assert( testpList.getNumSongs() == 4 );
	cout << " 1" << flush;

	cout << " Passed!" << endl;
}
