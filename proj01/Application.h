/*
 * Application.h
 *
 *  Created on: Feb 6, 2018
 *      Author: pjh26
 */

#ifndef APPLICATION_H_
#define APPLICATION_H_
#include <string>
#include "PlayList.h"

using namespace std;

class Application {
public:
	Application();
	void appSearchByArtist() const;
	void appSearchByYear() const;
	void appSearchByTitlePhrase() const;
	void appAddSong();
	void appRemoveSong();
private:
	PlayList myPlayList;
	string myPlayListFileName;
};

#endif /* APPLICATION_H_ */
