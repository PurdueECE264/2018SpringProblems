#include "bmpfunc.h"
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#ifndef FUNC_GIVEN

int RGB2Gray(unsigned char red, unsigned char green, unsigned char blue){
	// this is a commonly used formula
	double gray = 0.2989 * red + 0.5870 * green + 0.1140 * blue;
	return (int) gray;
}

#endif


#ifndef IMG_TO_GRAY

BMPImage * ImgToGray(BMPImage * image){

	// allocate space for the image
	// the image has the same size
	// therefore the header has to stay the same

	return gray_image;

}

#endif


#ifndef ADAPTIVE_THRESHOLDING

BMPImage * AdaptiveThresholding(BMPImage * grayImage, int radius, int epsilon){
 	// allocate space for the image
	// the image has the same size
	// therefore the header has to stay the same

	  return adaptive;

}


#endif
