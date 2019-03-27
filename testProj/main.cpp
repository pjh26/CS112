/*
 * main.cpp is a driver for an ImageConverter program
 *  using OpenMP to parallelize the image processing
 *  and TSGL to view the processing in near real time.
 *
 * Author: Joel Adams, for CS 112 at Calvin College.
 * Date: March 2015.
 * Revised: November 2016.
 */

#include "ImageConverter.h"
#include <omp.h>

int main() {
	omp_set_num_threads(800);

    ImageConverter iConverter("pics/coloredMarkers.jpg", 800, 800);
//    iConverter.blur(1);
//    iConverter.blur(2);
//    iConverter.blur(3);
//    iConverter.blur(5);
    iConverter.blur(60);
}
