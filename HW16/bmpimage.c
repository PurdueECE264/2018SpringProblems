#include "bmpimage.h"

/* check whether a header is valid
 * assume that header has been read from fptr
 * the position of the indicator of fptr is not certain
 * could be at the beginning of the file, end of the file or
 * anywhere in the file
 * note that the check is only for this exercise/assignment
 * in general, the format is more complicated
 */

#ifndef HEADER_VALID

int Is_BMPHeader_Valid(BMPHeader* header, FILE *fptr) {
	// Make sure this is a BMP file
	// skip the two unused reserved fields

	// check the offset from beginning of file to image data
	// essentially the size of the BMP header
	// BMP_HEADER_SIZE for this exercise/assignment
	// printf("header->offset %d\n",header->offset );

	// check the DIB header size == DIB_HEADER_SIZE
	// For this exercise/assignment
	// printf("header->DIB_header_size %d\n",header->DIB_header_size );
	// Make sure there is only one image plane
	// Make sure there is no compression

	// skip the test for xresolution, yresolution

	// ncolours and importantcolours should be 0

	// Make sure we are getting 24 bits per pixel
	// only for this assignment
	// fill in extra to check for file size, image size
	// based on bits, width, and height

		return TRUE;
}

#endif



#ifndef BMP_OPEN_FILE
/* The input argument is the source file pointer.
 * The function returns an address to a dynamically allocated BMPImage
 * only if the file contains a valid image file
 * Otherwise, return NULL
 * If the function cannot get the necessary memory to store the image,
 * also return NULL
 * Any error messages should be printed to stderr
 */


BMPImage *BMP_Open(const char *filename) {
	// open file 	
	//Allocate memory for BMPImage*;

	//Read the first 54 bytes of the source into the header


	//Compute data size, width, height, and bytes per pixel;


	// Allocate memory for image data


	// read in the image data

	return bmpImage;
}
#endif


#ifndef BMP_WRITE_FUNC
/* The input arguments are the destination file , BMPImage *image.
 * The function write the header and image data into the destination file.
 */
int BMP_Write(const char * outfile, BMPImage* image){
	// write header to the file
	// write image data to the file 
}

#endif



/* The input argument is the BMPImage pointer. The function frees memory of
 * the BMPImage.
 */
#ifndef BMP_FREE_FUNC
void BMP_Free(BMPImage* image) {
	//free the data
}

#endif
