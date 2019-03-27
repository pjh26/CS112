/* Vec.h provides a simple vector class named Vec.
 * Student Name:Peter Haagsma & Mitchell Brill
 * Date:February 26
 * Begun by: Peter Haagsma & Mitchell Brill, for CS 112 at Calvin College.
 * operator[] read	Peter
 * operator[] write	Mitch
 * operator!=		Peter
 * readFrom			Peter
 * writeTo			Mitch
 * operator+		Mitch
 * operator-		Peter
 * operator*		Mitch
 */

#ifndef VEC_H_
#define VEC_H_

#include <iostream>
using namespace std;

typedef double Item;

class Vec {
public:
	Vec();
	Vec(unsigned size);
	Vec(const Vec &original);
	Vec& operator=(const Vec& original);
	unsigned getSize() const;
	void setItem(unsigned index, const Item& it);
	Item getItem(unsigned index) const;
	void setSize(unsigned newSize);
	bool operator==(const Vec &v2);
	void writeTo(ostream& out) const;
	void readFrom(istream& in) const;
	bool operator!=(const Vec &v2);
	Vec operator+(const Vec& v2);
	Vec operator-(const Vec& v2);
	Item operator*(const Vec& v2);
	void readFrom(const string& filename);
	void writeTo(const string& filename);

	const Item& operator[](unsigned index) const;
	Item& operator[](unsigned index);


	virtual ~Vec();
	
private:
	unsigned mySize;
	Item*    myArray;
	friend class VecTester;
};

#endif /*VEC_H_*/
