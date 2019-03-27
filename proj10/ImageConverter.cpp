/*
 * ImageConverter.cpp declares a class for
 *  various image conversion operations.
 *
 *  Author:  Joel Adams, CS112 @ Calvin College.
 *  Created: March 2015
 *  Revised: November 2016
 */

#include "ImageConverter.h"
#include <unistd.h>            // sleep()
#include <cmath>			   // ceil()
//-----------------  Method definitions ------------------------------

/* explicit constructor
 *
 * @param imageFileName, a string.
 * @param width, an int.
 * @param height, an int.
 *
 * Precondition: imageFileName contains the name of a valid image file
 *               && width > 0 && height > 0
 * Postcondition: myImageFileName == imageFileName
 *                && myWidth == width && myHeight = height
 *                && width x height Canvas containing the image
 *                    from imageFileName has been displayed on screen.
 */
ImageConverter::ImageConverter(const std::string& imageFileName, int width,
		int height) :
		myCanvas1(0, 0, width, height, imageFileName), myImageFileName(
				imageFileName), myWidth(width), myHeight(height) {
	myCanvas1.start();
	myCanvas1.drawImage(myImageFileName, 0, 0, width, height);
	sleep(1);
}

/* destructor
 *
 * Precondition: this ImageConverter object is going out of scope.
 * Postcondition: myCanvas1 has disappeared from the screen.
 */
ImageConverter::~ImageConverter() {
	myCanvas1.wait();
	cout << "\nImageConverter terminated normally." << endl;
}

/* invertImage() inverts the image from myImageFileName.
 *
 * Precondition: myCanvas1 contains a TSGL Image that is to be inverted
 *               && myWidth contains the number of columns in which to display the image
 *               && myHeight contains the number of rows in which to display the image.
 *
 * Postcondition: a myWidth x myHeight Canvas has been displayed
 *                 containing the inverse of the image from myCanvas1
 *                 (which contains the image from myImageFileName).
 */
void ImageConverter::invertImage() {
	// record starting time
	double startTime = omp_get_wtime();

	Canvas canvas2(myWidth + 50, 0, myWidth, myHeight,
			myImageFileName + " Inverted");
	canvas2.start();

	// loop through the image rows
	#pragma omp parallel for
	for (int row = 0; row < myHeight; row++) {
		// slow the processing to simulate a very large image
		canvas2.sleep();
		// loop through the image columns
		for (int col = 0; col < myWidth; col++) {
			// read the pixel at canvas1[row][col]
			ColorInt pixelColor = myCanvas1.getPixel(row, col);
			// compute its inverse
			int invertedR = 255 - pixelColor.R;
			int invertedG = 255 - pixelColor.G;
			int invertedB = 255 - pixelColor.B;
			// draw the inverse at the same spot in canvas2
			canvas2.drawPixel(row, col,
					ColorInt(invertedR, invertedG, invertedB));
		} // inner for
	} // outer for

	// compute and display the time difference
	double totalTime = omp_get_wtime() - startTime;
	cout << "\n\nImage inversion took " << totalTime << " seconds.\n" << endl;

	//save converted image
//	canvas2.takeScreenShot();

	canvas2.wait();
} // invertImage

void ImageConverter::invertImage2() {
	// record starting time
	double startTime = omp_get_wtime();

	Canvas canvas3(myWidth + 50, 0, myWidth, myHeight,
			myImageFileName + " Inverted, Chunk-Size 1");
	canvas3.start();

	// launch additional threads
#pragma omp parallel
	{
		// how many workers do we have?
		unsigned numThreads = omp_get_num_threads();
		// which one am I?
		unsigned id = omp_get_thread_num();

		// loop through the image rows
		for (int row = id; row < myHeight; row += numThreads) {
			// slow the processing to simulate a very large image
			canvas3.sleep();
			// loop through the image columns
			for (int col = 0; col < myWidth; col++) {
				// read the pixel at canvas1[row][col]
				ColorInt pixelColor = myCanvas1.getPixel(row, col);
				// compute its inverse
				int invertedR = 255 - pixelColor.R;
				int invertedG = 255 - pixelColor.G;
				int invertedB = 255 - pixelColor.B;
				// draw the inverse at the same spot in canvas2
				canvas3.drawPixel(row, col,
						ColorInt(invertedR, invertedG, invertedB));
			} // inner for
		} // outer for
	} // #pragma omp parallel

	// compute and display the time difference
	double totalTime = omp_get_wtime() - startTime;
	cout << "\n\nImage inversion took " << totalTime << " seconds.\n" << endl;

	canvas3.wait();
} // invertImage2

void ImageConverter::invertImage3() {
	// record starting time
	double startTime = omp_get_wtime();

	Canvas canvas4(myWidth + 50, 0, myWidth, myHeight,
			myImageFileName + " Inverted, Equal-Sized Chunks ");
	canvas4.start();

	// launch additional threads
	#pragma omp parallel
	{
		// how many workers do we have?
		unsigned numThreads = omp_get_num_threads();
		// which one am I?
		unsigned id = omp_get_thread_num();

		// compute size of chunks (iterations % numThreads may != 0)
		double iterations = myHeight;
		unsigned chunkSize = (unsigned) ceil(iterations / numThreads);

		// compute starting and stopping index values
		int start = id * chunkSize;
		int stop = 0;
		if (id < numThreads - 1) {
			stop = start + chunkSize;
		} else {
			stop = myHeight;
		}

		// loop through image rows in equal-sized chunks
		for (int row = start; row < stop; row++) {
			// slow the processing to simulate a very large image
			canvas4.sleep();
			// loop through the image columns
			for (int col = 0; col < myWidth; col++) {
				// read the pixel at canvas1[row][col]
				ColorInt pixelColor = myCanvas1.getPixel(row, col);
				// compute its inverse
				int invertedR = 255 - pixelColor.R;
				int invertedG = 255 - pixelColor.G;
				int invertedB = 255 - pixelColor.B;
				// draw the inverse at the same spot in canvas2
				canvas4.drawPixel(row, col,
						ColorInt(invertedR, invertedG, invertedB));
			} // inner for
		} // outer for
	} // #pragma omp parallel

	// compute and display the time difference
	double totalTime = omp_get_wtime() - startTime;
	cout << "\n\nImage inversion took " << totalTime << " seconds.\n" << endl;

	canvas4.wait();
} // invertImage3

/* Horizontally flips the iimage from myImageFileName
 * 				Creates a second canvas and then iterates through the first canvas
 * 				and paints a image that is horizontally flipped
 *
 * Precondition:  Canvas open with selected image on it
 * Postcondition: Second canvas open with the image flipped horizontally on it
 */
void ImageConverter::flipHorizontal() {
	// record starting time
	double startTime = omp_get_wtime();

	Canvas canvasFH(myWidth + 50, 0, myWidth, myHeight,
			myImageFileName + " Inverted");
	canvasFH.start();


	#pragma omp parallel for
	for (int row = 0; row < myHeight; row++) {
		// slow the processing to simulate a very large image
		canvasFH.sleep();
		// loop through the image columns
		for (int col = myWidth; col > 0; col--) {
			// read the pixel at canvas1[row][col]
			ColorInt pixelColor = myCanvas1.getPixel(row, col);

			int flippedR = pixelColor.R;
			int flippedG = pixelColor.G;
			int flippedB = pixelColor.B;

			canvasFH.drawPixel(row, myWidth - col,
					ColorInt(flippedR, flippedG, flippedB));
		}
	}
	// compute and display the time difference
	double totalTime = omp_get_wtime() - startTime;
	cout << "\n\nImage inversion took " << totalTime << " seconds.\n" << endl;

	//save converted image
	//canvasFH.takeScreenShot();

	canvasFH.wait();
}

/* Vertically flips the iimage from myImageFileName
 * 				Creates a second canvas and then iterates through the first canvas
 * 				and paints a image that is vertically flipped
 *
 * Precondition:  Canvas open with selected image on it
 * Postcondition: Second canvas open with the image flipped vertically on it
 */
void ImageConverter::flipVertical() {
	// record starting time
	double startTime = omp_get_wtime();

	Canvas canvasFV(myWidth + 50, 0, myWidth, myHeight,
			myImageFileName + " Inverted");
	canvasFV.start();


	#pragma omp parallel for
	for (int row = 0; row < myHeight; row++) {
		// slow the processing to simulate a very large image
		canvasFV.sleep();
		// loop through the image columns
		for (int col = 0; col < myWidth; col++) {
			// read the pixel at canvas1[row][col]
			ColorInt pixelColor = myCanvas1.getPixel(row, col);

			int flippedR = pixelColor.R;
			int flippedG = pixelColor.G;
			int flippedB = pixelColor.B;

			canvasFV.drawPixel(myHeight - row, col,
					ColorInt(flippedR, flippedG, flippedB));
		}
	}
	// compute and display the time difference
	double totalTime = omp_get_wtime() - startTime;
	cout << "\n\nImage inversion took " << totalTime << " seconds.\n" << endl;

	//save converted image
	//canvasFV.takeScreenShot();

	canvasFV.wait();
}

void ImageConverter::blur(unsigned blurfactor) {
	cout << "Got into the function";
	// record starting time
	double startTime = omp_get_wtime();

	Canvas canvasBL(myWidth + 50, 0, myWidth, myHeight,
			myImageFileName + " Inverted");
	canvasBL.start();

	cout << "\nStarted canvans" << endl;
	#pragma omp parallel for
	for (unsigned row = 0; row < myHeight; row++) {
		// slow the processing to simulate a very large image
		canvasBL.sleep();
		// loop through the image columns
		for (unsigned col = 0; col < myWidth; col++) {
			// read the pixel at canvas1[row][col]
			int blurR = 0;
			int blurG = 0;
			int blurB = 0;
			int numPixels = 0;
			cout << "Accessed pixel" << endl;
			for (unsigned blurRow = row-blurfactor; blurRow < row+blurfactor; blurRow++) {
				for (unsigned blurCol = col-blurfactor; blurCol < col+blurfactor; blurCol++) {
					ColorInt pixelColor = myCanvas1.getPixel(blurRow, blurCol);
					blurR += pixelColor.R;
					blurG += pixelColor.G;
					blurB += pixelColor.B;
					numPixels++;
				}
			}
			int avgR = blurR/numPixels;
			int avgG = blurG/numPixels;
			int avgB = blurB/numPixels;
			canvasBL.drawPixel(myHeight - row, col,
					ColorInt(avgR, avgG, avgB));
		}
	}

	// compute and display the time difference
	double totalTime = omp_get_wtime() - startTime;
	cout << "\n\nImage inversion took " << totalTime << " seconds.\n" << endl;

	//save converted image
	//canvasFV.takeScreenShot();

	canvasBL.wait();
}
