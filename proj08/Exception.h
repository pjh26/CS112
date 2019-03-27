/* Exception.h defines a class to consolidate the functionality
 *  that different kinds of exceptions have in common.
 * Joel Adams, for CS 112 at Calvin College.
 */

#ifndef EXCEPTION_H_
#define EXCEPTION_H_

#include <string>    // string
#include <iostream>  // ostream
using namespace std;

class Exception {
public:
   /* construct an Exception
    * Parameters: whereThrown, a string naming the method that threw me.
    *              message, a description of the problem.
    */
   Exception(const string& whereThrown, const string& message) { 
      myLocation = whereThrown; 
      myMessage = message; 
   }
   
   virtual ~Exception() {}
   
   /* build a string representation of myself
    * (polymorphic, in case you want to override it)
    */
   virtual string asString() const { 
   	  return "*** " + className() + " in " + myLocation + ": "
                  + myMessage; 
   }
   
   /* polymorphic method to retrieve the name of the class
    *  (used by asString() above)
    */
   virtual string className() const {
   	  return "Exception";
   }

private:
   string myLocation;    // the method where I was thrown
   string myMessage;     // a description of the problem
};  // Exception

/* insert an Exception (or its subclass) into an ostream
 * Parameters: out, an ostream;
 *             e, an Exception.
 * Postcondition: out contains e's string representation
 *               && out is the return-value.
 */
inline ostream& operator<<(ostream& out, const Exception& e) {
	out << e.asString();
	return out;
}
      
#endif /*EXCEPTION_H_*/

