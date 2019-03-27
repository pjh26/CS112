/*
 * Application.cpp
 *
 *  Created on: Feb 6, 2018
 *      Author: pjh26
 */

#include "Application.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cassert>
#include <ios>      // I included these two to clear
#include <limits>   // the cin buffer

#include "Song.h"
#include "PlayList.h"

using namespace std;

/* Constructor for the PlayList manager application
 * This opens the selected file and stores it in a playlist then reads the user input for which function to run
 *
 */
Application::Application() {
	cout << "\nWelcome to the PlayList Manager!" << endl;
	cout << "Please enter the PlayList you would like to open..." << endl;
	cin >> myPlayListFileName;

	PlayList tempPlayList(myPlayListFileName);
	myPlayList = tempPlayList;

//	unsigned userInput;
	string userInputStr;
	while (true) {
//		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout << "\nPlease Enter:" << endl;
		cout << "   1 - to search the PlayList for songs by a given artist" << endl;
		cout << "   2 - to search the PlayList for songs from a given year" << endl;
		cout << "   3 - to search the PlayList for songs with a given phrase in their title" << endl;
		cout << "   4 - to add a new song to the PlayList" << endl;
		cout << "   5 - to remove a song from the PlayList" << endl;
		cout << "   0 - to quit" << endl;

		cin >> userInputStr;
//		userInputStr = to_string(userInput);

		if (userInputStr == "1") {
			appSearchByArtist();
		}

		else if (userInputStr == "2") {
			appSearchByYear();
		}

		else if (userInputStr == "3") {
			appSearchByTitlePhrase();
		}

		else if (userInputStr == "4") {
			appAddSong();
		}

		else if (userInputStr == "5") {
			appRemoveSong();
		}

		else if (userInputStr == "0") {
			break;
		}
		else {
			cout << "Please enter a valid option." << endl;
		}
	}
	cout << "Exiting PlayList Manager..." << endl;
	myPlayList.save();
	cout << "Goodbye!" << flush;
}

/* Prompts the user to enter a name to search myPlayList for an artist
 * lists the songs out in the console if any are found.
 */
void Application::appSearchByArtist() const {
	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	cout << "Enter Artist name to search..." << endl;
	string songArtist;

	getline(cin, songArtist);
	vector<Song> searchResults;

	searchResults = myPlayList.searchByArtist( songArtist );
	if (searchResults.size() == 0 ) { cout << "No songs by this artist." << endl;}
	for ( unsigned i = 0; i < searchResults.size(); i++ ) {
		cout << "\n" << searchResults[i].getTitle() << flush;
		cout << searchResults[i].getArtist() << flush;
		cout << searchResults[i].getYear() << endl;
	}
}

/* Prompts the user to enter a year to search myPlayList
 * lists the songs out in the console if any are found.
 */
void Application::appSearchByYear() const {
	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	cout << "Enter song year to search..." << endl;
	string songYear;

	getline(cin, songYear);
	vector<Song> searchResults;

	searchResults = myPlayList.searchByYear( atoi( songYear.c_str() ) );
	if (searchResults.size() == 0 ) { cout << "No songs from this year." << endl;}
	for ( unsigned i = 0; i < searchResults.size(); i++ ) {
		cout << "\n" << searchResults[i].getTitle() << flush;
		cout << searchResults[i].getArtist() << flush;
		cout << searchResults[i].getYear() << endl;
	}
}

/* Prompts the user to enter a title phrase to search myPlayList
 * lists the songs out in the console if any are found.
 */
void Application::appSearchByTitlePhrase() const {
	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	cout << "Enter title phrase to search..." << endl;
	string songTitlePhrase;
	getline(cin, songTitlePhrase);

	vector<Song> searchResults;
	searchResults = myPlayList.searchByTitlePhrase( songTitlePhrase );
	if (searchResults.size() == 0 ) { cout << "No songs of this title." << endl;}
	for ( unsigned i = 0; i < searchResults.size(); i++ ) {
		cout << "\n" << searchResults[i].getTitle() << flush;
		cout << searchResults[i].getArtist() << flush;
		cout << searchResults[i].getYear() << endl;
	}
}

/* Prompts user for artist, year, and title of a song then creates that song
 * adds said song to the playlist and saves it
 */
void Application::appAddSong() {
	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	string songTitle, songArtist, yearString;
	unsigned songYear;

	cout << "Enter the Title of the song you wish to add to the PlayList..." << endl;
	getline(cin, songTitle);

	cout << "Enter the Artist of the song you wish to add to the PlayList..." << endl;
	getline(cin, songArtist);

	cout << "Enter the Year of the song you wish to add to the PlayList..." << endl;
	getline(cin, yearString);
	songYear = atoi( yearString.c_str() );

	Song newSong( songTitle, songArtist, songYear );

	myPlayList.addSong(newSong);
	myPlayList.save();

	cout << "Addition Successful!" << endl;
}

/* Prompts user for artist, year, and title of a song then creates that song
 * removes said song from the playlist and saves it
 */
void Application::appRemoveSong() {
	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	string songTitle, songArtist, yearString;
	unsigned songYear;

	cout << "Enter the Title of the song you wish to remove to the PlayList..." << endl;
	getline(cin, songTitle);

	cout << "Enter the Artist of the song you wish to remove to the PlayList..." << endl;
	getline(cin, songArtist);

	cout << "Enter the Year of the song you wish to remove to the PlayList..." << endl;
	getline(cin, yearString);
	songYear = atoi( yearString.c_str() );

	Song removeSong(songTitle, songArtist, songYear);
	myPlayList.removeSong(removeSong);
	myPlayList.save();

	cout << "Song removal successful!" << endl;
}
