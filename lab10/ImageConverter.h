/*
 * ImageConverter.h declares a class for
 *  various image conversion operations.
 *
 *  Author:  Joel Adams, CS112 @ Calvin College.
 *  Created: March 2015
 *  Revised: November 2016.
 */

#ifndef IMAGECONVERTER_H_
#define IMAGECONVERTER_H_

#include <tsgl.h>     // Canvas, ColorInt, etc.
#include <iostream>   // cout, cerr, ...
#include <string>     // string
#include <omp.h>      // OpenMP functions

using namespace tsgl;
using namespace std;

class ImageConverter {
public:
	ImageConverter(const std::string& imageFileName, int width, int height);
	~ImageConverter();

	void invertImage();
	void invertImage2();
	void invertImage3();

private:
    Canvas      myCanvas1;
    string      myImageFileName;
    int         myWidth;
    int         myHeight;
};


#endif /* IMAGECONVERTER_H_ */
