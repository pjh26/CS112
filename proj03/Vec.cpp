/* Vec.cpp defines the methods for Vec, a simple vector class.
 * Student Name:Peter Haagsma & Mitchell Brill
 * Date:February 26
 * Begun by: Peter Haagsma & Mitchell Brill, for CS 112 at Calvin College.
 */
 
#include "Vec.h"
#include <stdexcept>
#include <string>
#include <fstream>
#include <cstdlib>
// Default Constructor
Vec::Vec() {
	mySize = 0;
	myArray = NULL;
}


/* Explicit Constructor
 * @param a size for the array
 */
Vec::Vec(unsigned size) {
	mySize = size;

	if (mySize > 0) {
		myArray = new Item[mySize];
		for(unsigned i = 0; i < mySize; ++i ) {
			myArray[i] = 0;
		}
	} else { myArray = NULL; }

}


/* Copy constructor, takes a Vec object and creates a deep copy of it
 * @params: Vec original
 */
Vec::Vec(const Vec &original) {
	mySize = original.mySize;
	myArray = new Item[mySize];

	if (original.mySize > 0) {
		for (unsigned i = 0; i < mySize; ++i) {
			myArray[i] = original.myArray[i];
		}
	} else { myArray = NULL; }
}


/* operator[]: returns value of location in Vec object to be used
 * @params: unsigned index
 */
const Item& Vec::operator[](unsigned index) const{
	if (index >= 0 && index <= mySize) {
		return myArray[index];
	}
	throw range_error("Outside Vec Range");
}


/* operator[]: returns location in Vec object to be changed
 * @params: unsigned index
 */
Item& Vec::operator[](unsigned index) {
	if (index >= 0 && index <= mySize) {
		return myArray[index];
	}
	throw range_error("Outside Vec Range");
}



/* operator=: takes a Vec object and creates a deep copy of it
 * @params: Vec original
 * Precondition: Two Vec objects on either side of = operator
 * Postcondition: Two equal Vec objects
 */
Vec& Vec::operator=(const Vec& original) {
	if (myArray == original.myArray ) {
		return *this;
	} else if (original.mySize == 0) {
		mySize = 0;
		delete [] myArray;
		myArray = NULL;
		return *this;
	} else {
		mySize = original.mySize;
		delete [] myArray;
		myArray = new Item[mySize];

		for (unsigned i = 0; i < mySize; ++i) {
			myArray[i] = original.myArray[i];
		}
		return *this;
	}
}


/* getSize: getter for size of Vec object
 * Return: mySize
 */
unsigned Vec::getSize() const {
	return mySize;
}


/* setItem: sets a certain index of Vec object to a certain value
 * @params: unsigned index position, Item it (value index will be set to)
 * Precondition: Vec object
 * Postcondition: Vec with one index location changed
 */
void Vec::setItem(unsigned index, const Item& it) {
	if (index >= mySize || index < 0 || mySize == 0) {
		throw range_error("Selected index is outside of Vec Range.");
	} else {
		myArray[index] = it;
	}
}


/* getItem: getter for the value of a certain index position of Vec object
 * @params: unsigned index
 * Return: value of myArray index
 */
Item Vec::getItem(unsigned index) const {
	if (index >= mySize || index < 0 || mySize == 0) {
		throw range_error("Selected index is outside of Vec Range.");
	} else {
		return myArray[index];
	}
}


/* setSize: Changes size of Vec; either adding zeros to the end or truncating values
 * @params: unsigned newSize of Vec
 * Precondition: Vec object
 * Postcondition: Vec object of size newSize that has either been truncated or had zeros added to the end
 */
void Vec::setSize(unsigned newSize) {
	if (mySize == 0) {
		mySize = newSize;
		myArray = new Item[mySize];
		for (unsigned i = 0; i < mySize; ++i) {
			myArray[i] = 0;
		}
	} else if (newSize == 0) {
		mySize = 0;
		delete [] myArray;
		myArray = NULL;
	} else  if (newSize == mySize) {

	} else {
		Item* temp = myArray;
		myArray = new Item[newSize];
		unsigned oldSize = mySize;
		mySize = newSize;

		if (oldSize < newSize) {
			for (unsigned i = 0; i < oldSize; ++i) {
				myArray[i] = temp[i];
			}
			for (unsigned i = oldSize; i < newSize; ++i) {
				myArray[i] = 0;
			}
		} else {
			for (unsigned i = 0; i < newSize; ++i) {
				myArray[i] = temp[i];
			}
		}
	delete [] temp;
	}
}


/* operator==: Compares two Vec object testing for equality
 * @params: Vec v2
 * Returns: True if the Vec objects are equal and false otherwise
 */
bool Vec::operator==(const Vec &v2) {
	if (mySize != v2.mySize) {
		return false;
	} else {
		for (unsigned i = 0; i < mySize; ++i) {
			if (myArray[i] != v2.myArray[i]) {
				return false;
			}
		}
		return true;
	}
}


/* WriteTo: Writes the values of Vec object sequentially into a .txt file
 * @params: ostream out
 * Precondition: Vec object and open .txt file
 * Postcondition: Vec object and .txt file with values of Vec object copied in it.
 */
void Vec::writeTo(ostream& out) const {
	for (unsigned i = 0; i < mySize; ++i) {
		out << myArray[i] << endl;

	}
}


/* readFrom: Reads values from .txt file and places them in a Vec object
 * @params: istream in
 * Precondition: Vec object and .txt file with values in it
 * Postcondition: Vec object with values from .txt file in it
 */
void Vec::readFrom(istream& in) const {
	for (unsigned i = 0; i < mySize; ++i) {
	in >> myArray[i];
	}
}











/* readFrom: Reads values from .txt file and places them in a Vec object
 * @params: istream in
 * Precondition: Vec object and .txt file with values in it
 * Postcondition: Vec object with values from .txt file in it
 */
bool Vec::operator!=(const Vec &v2) {
	if (mySize != v2.mySize) {
		return true;
	} else {
		for (unsigned i = 0; i < mySize; ++i) {
			if (myArray[i] != v2.myArray[i]) {
				return true;
			}
		}
		return false;
	}
}


/* readFrom: Reads values from .txt file and places them in a Vec object
 * @params: istream in
 * Precondition: Vec object and .txt file with values in it
 * Postcondition: Vec object with values from .txt file in it
 */
Vec Vec::operator+(const Vec& v2) {
	if (mySize != v2.mySize) {
		throw invalid_argument("Vec objects must be of equal size to add.");
	} else {
		Vec v3(mySize);
		for (unsigned i = 0; i < mySize; ++i) {
			v3.myArray[i] = myArray[i] + v2.myArray[i];
		}
		return v3;
	}
}


/* readFrom: Reads values from .txt file and places them in a Vec object
 * @params: istream in
 * Precondition: Vec object and .txt file with values in it
 * Postcondition: Vec object with values from .txt file in it
 */
Vec Vec::operator-(const Vec& v2){
	if (mySize != v2.mySize) {
		throw invalid_argument("Vec objects must be of equal size to subtract.");
	} else {
		Vec v3(mySize);
		for (unsigned i = 0; i < mySize; ++i) {
			v3.myArray[i] = myArray[i] - v2.myArray[i];
		}
		return v3;
	}
}


/* readFrom: Reads values from .txt file and places them in a Vec object
 * @params: istream in
 * Precondition: Vec object and .txt file with values in it
 * Postcondition: Vec object with values from .txt file in it
 */
Item Vec::operator*(const Vec& v2) {
	if (mySize != v2.mySize) {
		throw invalid_argument("Vec objects must be of equal size to get dot product.");
	} else if (mySize == 0) {
		return 0;
	} else {
		Item product;
		for (unsigned i = 0; i < mySize; ++i) {
			product += myArray[i] * v2.myArray[i];
		}
		return product;
	}
}


/* readFrom: Reads values from .txt file and places them in a Vec object
 * @params: istream in
 * Precondition: Vec object and .txt file with values in it
 * Postcondition: Vec object with values from .txt file in it
 */
void Vec::readFrom(const string& filename) {
    ifstream fin( filename.c_str() );
    fin >> mySize;
    delete [] myArray;
    myArray = new Item[mySize];
    for (unsigned i = 0; i < mySize; ++i) {
    	fin >> myArray[i];
    }
	fin.close();
}


/* readFrom: Reads values from .txt file and places them in a Vec object
 * @params: istream in
 * Precondition: Vec object and .txt file with values in it
 * Postcondition: Vec object with values from .txt file in it
 */
void Vec::writeTo(const string& filename) {
    ofstream fout( filename.c_str() );
    fout << mySize << "\r";
    for (unsigned i = 0; i < mySize; ++i) {
    	fout << myArray[i] << "\r";
    }
	fout.close();
}



/* ~Vec: Destructor for the Vec object
 * Precondition: Vec object with values, size and location
 * Postcondition: Memory is freed and Vec no longer has values, location and size = 0
 */
Vec::~Vec() {
	mySize = 0;
	delete [] myArray;
	myArray = NULL;
}
