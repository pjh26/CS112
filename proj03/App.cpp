/*
 * App.cpp
 *
 *  Created on: Feb 26, 2018
 *      Author: pjh26
 */

#include "App.h"

App::App() {
	myDimensions = 0;

}


void App::runApp() {
	cout << "Welcome, please enter the number of dimensions" << endl;
	cin >> myDimensions;


	cout << "Please enter starting position." << flush;
	Vec v0 = createVec(myDimensions);

	cout << "\nSelect one:" << endl;

	while(true) {
		cout << "\n1 - Add new vector\n" << "2 - See final position\n" << "3 - Quit\n" << endl;
		unsigned userInput;
		cin >> userInput;

		if (userInput == 1) {
			Vec v1 = createVec(myDimensions);
			v0 = (v0 + v1);
		} else if (userInput == 2) {
			cout << "\n" << flush;
			for (unsigned i = 0; i < myDimensions; ++i) {
				cout << v0[i] << flush;
				if (i < myDimensions-1) { cout << "," << flush; }
			}
		} else if (userInput == 3) {
			break;

		} else {continue;}
	}
}

Vec App::createVec(unsigned dim) {
	cout << "Please enter Vec values." << endl;
	Vec vec(dim);
	for (unsigned i = 0; i < dim; ++i) {
		cin >> vec[i];
	}
	return vec;
}

