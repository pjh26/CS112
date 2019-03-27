/*
 * PlayList.h declares class PlayList
 * Student Name: Peter Haagsma
 * Date: February 6, 2018
 * CS112 Calvin College
 */

#ifndef PLAYLIST_H_
#define PLAYLIST_H_

#include "Song.h"
#include <vector>   //STL vector
#include <string>

using namespace std;

class PlayList {
public:
	PlayList(const string& fileName);
	unsigned getNumSongs() const;
	vector<Song> searchByArtist(const string& artist);
	vector<Song> searchByYear(unsigned year);
	vector<Song> searchByTitlePhrase(const string& titlePhrase);

private:
	vector<Song> mySongs;
};

#endif /* PLAYLIST_H_ */
