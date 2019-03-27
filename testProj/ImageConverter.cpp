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
ImageConverter::ImageConverter(const std::string& imageFileName, int width, int height)
 : myCanvas1(0, 0, width, height, imageFileName),
   myImageFileName(imageFileName),
   myWidth(width),
   myHeight(height)
{
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

// Replace this line with the definition of invertImage()

void ImageConverter::blur(int blurFactor) {
	// record starting time
	double startTime = omp_get_wtime();

	Canvas canvasBL(myWidth + 50, 0, myWidth, myHeight,
			myImageFileName + " Inverted");
	canvasBL.start();

	#pragma omp parallel for
	for (int row = 0; row < myHeight; row++) {
		// slow the processing to simulate a very large image
		canvasBL.sleep();
		// loop through the image columns
		for (int col = 0; col < myWidth; col++) {
			// read the pixel at canvas1[row][col]
			int blurR = 0;
			int blurG = 0;
			int blurB = 0;
			int numPixels = 0;
			for (int blurRow = (row-blurFactor); blurRow < row+blurFactor; blurRow++) {
				for (int blurCol = col-blurFactor; blurCol < col+blurFactor; blurCol++) {
					if ((blurRow > 0 && blurRow < myHeight) && (blurCol > 0 && blurCol < myWidth)) {
						ColorInt pixelColor = myCanvas1.getPixel(blurRow, blurCol);
						blurR += pixelColor.R;
						blurG += pixelColor.G;
						blurB += pixelColor.B;
						numPixels++;
					}
				}
			}
			int avgR = blurR/numPixels;
			int avgG = blurG/numPixels;
			int avgB = blurB/numPixels;
			canvasBL.drawPixel(row, col,
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
