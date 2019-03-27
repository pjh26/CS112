/*
 * App.h
 * * Student Name:Peter Haagsma & Mitchell Brill
 * Date:February 26
 * Begun by: Peter Haagsma & Mitchell Brill, for CS 112 at Calvin College.
 */


#ifndef APP_H_
#define APP_H_
#include <iostream>
#include "Vec.h"

using namespace std;

class App {
public:
	App();
	void runApp();
	Vec createVec(unsigned int);

private:

	unsigned myDimensions;
};

#endif /* APP_H_ */
