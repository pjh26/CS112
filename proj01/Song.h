/*
 * Song.h declares a class for storing song information
 * Student Name: Peter Haagsma
 * Date: Feb 5, 2018
 * CS 112 Project 1
 */

#ifndef SONG_H_
#define SONG_H_
#include <string>
#include <fstream>
using namespace std;

class Song {
public:
	Song();
	Song(const string& title, const string& artist, unsigned year);
	string getTitle() const;
	string getArtist() const;
	unsigned getYear() const;
	void readFrom(istream& in);
	void writeTo(ostream& out) const;
	bool operator==(const Song& song2) const;
private:
	string myTitle;
	string myArtist;
	unsigned myYear;
};

#endif /* SONG_H_ */
