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
	PlayList();
	PlayList(const string& fileName);

	unsigned getNumSongs() const;

	vector<Song> searchByArtist(const string& artist) const;
	vector<Song> searchByYear(unsigned year) const;
	vector<Song> searchByTitlePhrase(const string& titlePhrase) const;

	void addSong(const Song& newSong);
	void removeSong(const Song& aSong);
	void save() const;
private:
	vector<Song> mySongs;
	string myPlayListFile;
};

#endif /* PLAYLIST_H_ */
