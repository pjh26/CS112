/* Experiment2.cpp defines the methods that measure the time required
 *  to prepend an item to a vector or list.
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 * Student name:
 * Date:
 */
#include "Experiment2.h"

#include <iostream>
#include <iomanip>    // setw()
#include <vector>
#include <list>
using namespace std;

void Experiment2::run() {
	cout << "\n2a. Timing vector prepend operations using the average over " << REPS << " repetitions:"
		 << endl;

//	timePrependToVectorOfSize(10);
//	timePrependToVectorOfSize(100);
//	timePrependToVectorOfSize(1000);
//	timePrependToVectorOfSize(10000);
//	timePrependToVectorOfSize(100000);
//	timePrependToVectorOfSize(1000000);
//
//	timeRepeatedPrependUntilVectorIsSize(1000000);

	timePrependToListOfSize(10);
	timePrependToListOfSize(100);
	timePrependToListOfSize(1000);
	timePrependToListOfSize(10000);
	timePrependToListOfSize(100000);
	timePrependToListOfSize(1000000);

	timeRepeatedPrependUntilListIsSize(1000000);

	cout << "\nExperiment 2 complete." << endl;

}

void Experiment2::timePrependToVectorOfSize(unsigned size) {
	cout << " - time to prepend to a full vector of size "
	     << setw(8) 
	     << size << ":\t" << flush;
	myTimer.reset();
	for (unsigned i = 0; i < REPS; i++) {          // repeatedly...
		vector<unsigned> v(size);                  // construct new size-n vector
		myTimer.start();                           // start timer
		v.insert( v.begin(), i);                   // prepend item
		myTimer.stop();                            // stop timer
	}
	cout << fixed << showpoint << setprecision(9)  // compute average time
	     << myTimer.getTotalTime() / REPS << " secs"
	     << endl;
	
}


void Experiment2::timeRepeatedPrependUntilVectorIsSize(unsigned maxSize) {
	cout << "\n ** average time to prepend " << maxSize 
             << " items to an initially empty vector: " << flush;
	myTimer.reset();                                 // clear timer
	vector<unsigned> v;                              // construct new empty vector
	for (unsigned i = 0; i < maxSize; i++) {         // repeatedly...
		myTimer.start();                             // start timer
		v.insert( v.begin(), i );                    // prepend item
		myTimer.stop();                              // stop timer
	}
	cout << fixed << showpoint << setprecision(9)    // compute average time
	     << myTimer.getTotalTime() / maxSize << " secs"
	     << endl;
}

void Experiment2::timePrependToListOfSize(unsigned size) {
	cout << " - time to prepend to a full list of size "
	     << setw(8)
	     << size << ":\t" << flush;
	myTimer.reset();
	for (unsigned i = 0; i < REPS; i++) {          // repeatedly...
		list<unsigned> l(size);                    // construct new size-n list
		myTimer.start();                           // start timer
//		l.insert( l.begin(), i);                   // prepend item
		l.push_front(i);
		myTimer.stop();                            // stop timer
	}
	cout << fixed << showpoint << setprecision(9)  // compute average time
	     << myTimer.getTotalTime() / REPS << " secs"
	     << endl;

}


void Experiment2::timeRepeatedPrependUntilListIsSize(unsigned maxSize) {
	cout << "\n ** average time to prepend " << maxSize
             << " items to an initially empty list: " << flush;
	myTimer.reset();                                 // clear timer
	list<unsigned> l;                                // construct new empty list
	for (unsigned i = 0; i < maxSize; i++) {         // repeatedly...
		myTimer.start();                             // start timer
//		l.insert( l.begin(), i );                    // prepend item
		l.push_front(i);
		myTimer.stop();                              // stop timer
	}
	cout << fixed << showpoint << setprecision(9)    // compute average time
	     << myTimer.getTotalTime() / maxSize << " secs"
	     << endl;
}
