/* Application.h Provides a class to interact with Matrix objects in the console
 *
 *  Created on: Mar 2, 2018
 *      Author: Peter Haagsma & Samuel Poortenga
 */

#ifndef APPLICATION_H_
#define APPLICATION_H_
#include "Matrix.h"
#include <string>
#include <iostream>
#include <cstdlib>

class Application {
public:
	void runApp();
	void printMatrix(const Matrix<double>& matrix) const;

private:
	string myMatrixFile;
	Matrix<double> myMatrix;
	unsigned myRows;
	unsigned myColumns;
};

#endif /* APPLICATION_H_ */
