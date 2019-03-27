/* Experiment0.cpp defines methods for timing the vector subscript operation.
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 * Student name:
 * Date:
 */

#include "Experiment0.h"
#include <iomanip>    // setw()
using namespace std;
	
void Experiment0::run() {
	cout << "\n0. Timing vector subscript operations, using the average over "
			<< REPS << " repetitions:" << endl;
	timeAccessesForVectorOfSize(10);
	timeAccessesForVectorOfSize(100);
	timeAccessesForVectorOfSize(1000);
	timeAccessesForVectorOfSize(10000);
	timeAccessesForVectorOfSize(100000);
	timeAccessesForVectorOfSize(1000000);
	cout << "\nExperiment 0 complete." << endl;
}

void Experiment0::timeAccessesForVectorOfSize(int size) {
	cout << "* timing accesses for vector of size " << size << endl;
	myVector.resize(size);                    // set vector's size
	                                          // then time access to
	timeAccessAtIndex(0);                     // - first  item
	timeAccessAtIndex( myVector.size() / 2 ); // - middle item
	timeAccessAtIndex( myVector.size() - 1 ); // - last item
}

void Experiment0::timeAccessAtIndex(int index) {
	cout << "-- Average time to access value at index "
	     << setw(6) << index << ": " << flush;
	myTimer.reset();                                 // clear the timer
	for (int i = 0; i < REPS; i++) {                 // repeatedly...
		myTimer.start();                             //   start it
		myVector[index];                             //   access item at index
		myTimer.stop();                              //   stop it
	}
	cout << fixed << showpoint << setprecision(9)    // show results
		     << myTimer.getTotalTime() / REPS << " secs"
		     << endl;
}

