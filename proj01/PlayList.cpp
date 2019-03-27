/*
 * PlayList.cpp defines the PlayList methods
 * Student Name: Peter Haagsma
 * Date: Feb 6, 2018
 * CS112 Calvin College
 */

#include "PlayList.h"
#include "Song.h"
#include <fstream>    // iofstream
#include <cassert>    // assert()
#include <string>     // strings
using namespace std;


/* Default PlayList constructor
 * @param: none
 * Precondition: none
 * Postcondition: a playlist object is created.
 */
PlayList::PlayList() {
}

/*PlayList constructor
 * @param: fileName, a string
 * Precondition: fileName contains the name of a PlayList file.
 */
PlayList::PlayList(const string& fileName) {
	// open a stream to the PlayList file
	myPlayListFile = fileName;
	ifstream fin( fileName.c_str() );
	assert( fin.is_open() );

	// read each song and append it to mySongs
	Song s;
	string separator;
	while (true) {
		s.readFrom(fin);
		if ( !fin ) { break; }
		mySongs.push_back(s);
	}

	// close the stream
	fin.close();
}

/* Retrieve length of the playlist
 * Return: the number of songs in the playlist
 */
unsigned PlayList::getNumSongs() const {
	return mySongs.size();
}

/* Search By artist
 * @param: artist, a string
 * Return: a vector containing all the Songs in mySongs by artist.
 */
vector<Song> PlayList::searchByArtist(const string& artist) const {
	vector<Song> v;

	for (unsigned i = 0; i < mySongs.size(); i++) {
		if ( mySongs[i].getArtist().find(artist) != string::npos ) {
			v.push_back( mySongs[i] );
		}
	}
	return v;
}

/* Search By Year
 * @param: year, unsigned
 * Return: a vector containing all the Songs in mySongs from year.
 */
vector<Song> PlayList::searchByYear(unsigned year) const {
	vector<Song> v;

	for (unsigned i = 0; i < mySongs.size(); i++ ) {
		if ( mySongs[i].getYear() == year ) {
			v.push_back( mySongs[i] );
		}
	}
	return v;
}

/* Search By Title Phrase
 * @param: titlePhrase, a string
 * Return: a vector containing all the Songs in mySongs with titlePhrase.
 */
vector<Song> PlayList::searchByTitlePhrase (const string& titlePhrase) const {
	vector<Song> v;

	for (unsigned i = 0; i < mySongs.size(); i++ ) {
		if ( mySongs[i].getTitle().find(titlePhrase) != string::npos ) {
			v.push_back( mySongs[i] );
		}
	}
	return v;
}

/* Adds a song to playlist object
 * @param: newSong, a Song
 * Return: none
 */
void PlayList::addSong(const Song& newSong) {
	mySongs.push_back(newSong);
}

void PlayList::removeSong(const Song& aSong) {

	for ( unsigned i = 0; i < mySongs.size(); i++ ) {
		if ( mySongs[i] ==  aSong ) {
			mySongs.erase( mySongs.begin() + i );
		}
	}
}

/* Saves the playlist to the file that it was originally made from
 * No paramaters
 * Returns none
 */
void PlayList::save() const {
	ofstream fout( myPlayListFile.c_str() );
	for (unsigned i = 0; i < mySongs.size(); i++ ) {
		mySongs[i].writeTo( fout );
	}
}
