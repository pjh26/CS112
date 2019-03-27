/* NanoTimer.h provides a simple nano-scale timer.
 *
 * Begun by: John Kloosterman, for CS 232 at Calvin College.
 * Enhanced by: Prof. Adams.
 *
 * To use this class, compile/link with the '-lrt' switch.
 *
 * In Eclipse: Project > Properties > GCC C++ Linker > Libraries > Libraries > +, add 'rt'
 */

#ifndef NANO_TIMER_H_
#define NANO_TIMER_H_

#include <ctime>        // timespec, clock_gettime(), etc.
#include <iostream>     // C++ I/O
#include <iomanip>      // setprecision()
#include <sstream>      // stringstream for in-memory formatting
using namespace std;

class NanoTimer {
public:
	NanoTimer()                  { myTotalTime = 0.0; }
	void start();
	void stop();
	void reset()                 { myTotalTime = 0.0; }
    string asString() const;
	double getTotalTime() const  { return myTotalTime; }
	double asDouble() const;

private:
	struct timespec myStart;
	struct timespec myEnd;
	double myTotalTime;
};


/* start the timer.
 * Postcondition: myStart contains the current time.
 */
inline
void NanoTimer::start() {
	clock_gettime(CLOCK_MONOTONIC, &myStart);
}

/* stop the timer.
 * Postcondition: myStop contains the current time.
 */
inline
void NanoTimer::stop() {
	clock_gettime(CLOCK_MONOTONIC, &myEnd);
	myTotalTime += this->asDouble();
}

const long NSEC_PER_SEC = 1000000000;

/* Utility function to compute time differences
 *  (used by asString(), asDouble(), etc.
 * Receive: end, begin, two timespec values.
 * Return: end - begin
 * Based on: http://www.gnu.org/s/libc/manual/html_node/Elapsed-Time.html
 */
inline
timespec operator-(const timespec& end, const timespec& begin)
{
	timespec result = begin;
	/* Perform the carry for the later subtraction. */
	if (end.tv_nsec < begin.tv_nsec) {
		int nsec = (begin.tv_nsec - end.tv_nsec) / NSEC_PER_SEC + 1;
		result.tv_nsec -= NSEC_PER_SEC * nsec;
		result.tv_sec += nsec;
	}
	if (end.tv_nsec - begin.tv_nsec > NSEC_PER_SEC) {
		int nsec = (end.tv_nsec - begin.tv_nsec) / NSEC_PER_SEC;
		result.tv_nsec += NSEC_PER_SEC * nsec;
		result.tv_sec -= nsec;
	}

	/* Compute the time remaining to wait.
            tv_usec is certainly positive. */
	result.tv_sec = end.tv_sec - result.tv_sec;
	result.tv_nsec = end.tv_nsec - result.tv_nsec;

	return result;
}

/* String representation.
 * Return: the processor time (user + system) 
 *    used in the interval between calls to start() and stop(),
 *    with nanosecond granularity, as a string.
 */
inline
string NanoTimer::asString() const {
    struct timespec diff = myEnd - myStart;
    stringstream sstr;
    sstr << diff.tv_sec 
         << ( (diff.tv_sec == 1) ? " sec, " : " secs, " )
         << diff.tv_nsec 
         << " nsecs";
    return sstr.str();
}

/* Double representation.
 * Return: the processor time (user + system)
 *    used in the interval between calls to start() and stop(),
 *    with nanosecond granularity, as a double.
 */
inline
double NanoTimer::asDouble() const {
   struct timespec diff = myEnd - myStart;
   return double(diff.tv_sec) + double(diff.tv_nsec) / double(NSEC_PER_SEC);
}


/* ostream output
 * Receive: out, an ostream; aTimer, a NanoTimer.
 * Postcondition: aTimer's double representation
 *      has been inserted into out.
 * Return: out (for chaining).
 */
inline
ostream& operator<<(ostream& out, const NanoTimer& aTimer) {
   out << fixed << showpoint << setprecision(9)
	   << aTimer.getTotalTime();
   return out;
}

/* Utility function to display a timespec structure's values
 *  (for debugging purposes)
 */
inline
ostream& operator<<(ostream& out, const struct timespec& ts) {
   out << ts.tv_sec 
       << ( (ts.tv_sec == 1) ? " sec, " : " secs, " )
       << ts.tv_nsec 
       << " nsecs";
   return out;
}

#endif /* NANO_TIMER_H_ */

