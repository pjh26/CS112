/* Application.cpp defines methods of Application.h
 *
 *  Created on: Mar 2, 2018
 *      Author: Peter Haagsma & Samuel Poortenga
 */

#include "Application.h"

/* Runs application gives user option of
 * 		1. Adding a matrix
 * 		2. Subtracting a matrix
 * 		3. Transposing a matrix
 * 		4. Quitting
 */
void Application::runApp() {
	cout << "Welcome to the Matrix Manager!" << endl;
	cout << "Select the file for the matrix you wish to open" << endl;
	cin >> myMatrixFile;
	myMatrix.readFrom(myMatrixFile);
	myRows = myMatrix.getRows();
	myColumns = myMatrix.getColumns();
	while (true) {
		cout << "Select what you want to do with your Matrix" << endl;
		cout << "    1 -\t Addition\n"
			 << "    2 -\t Subtraction\n"
			 << "    3 -\t Transpose\n"
			 << "    4 -\t Quit\n";
		string userInputStr;
		unsigned userInput;
		cin >> userInputStr;

		userInput = atoi( userInputStr.c_str() );

		if (userInput == 1) {
			cout << "Select the matrix that you wish to add to your matrix." << endl;
			cin >> userInputStr;
			Matrix<double> tempMatrix;
			tempMatrix.readFrom(userInputStr);
			tempMatrix = myMatrix + tempMatrix;
			printMatrix(tempMatrix);
			cout << endl;

		} else if (userInput == 2) {
			cout << "Select the matrix that you wish to subtract from your matrix." << endl;
			cin >> userInputStr;
			Matrix<double> tempMatrix;
			tempMatrix.readFrom(userInputStr);
			tempMatrix = myMatrix - tempMatrix;
			printMatrix(tempMatrix);
			cout << endl;

		} else if (userInput == 3) {
			Matrix<double> tempMatrix;
			tempMatrix = myMatrix.getTranspose();
			printMatrix(tempMatrix);
			cout << endl;

		} else if (userInput == 4) {
			exit(0);

		} else {
			cout << "Invalid input: Please select another option.\n" << endl;
		}
	}
}

/* Outputs matrix to the console with clean formatting
 * @params: Matrix object
 */
void Application::printMatrix(const Matrix<double>& matrix) const {

	unsigned rows = matrix.getRows();
	unsigned columns = matrix.getColumns();
	cout << "{" << flush;
	for (unsigned i = 0; i < rows; ++i){
		for (unsigned j = 0; j < columns; ++j){
			if (i != (rows-1) || j != (columns-1)) {
				cout << matrix[i][j] << ",\t"<< flush;
			} else { cout << matrix[i][j]; }
		}
		if (i != (rows-1)) {
			cout << "\n " << flush;
		}
	}
	cout << "}" << endl;
}

