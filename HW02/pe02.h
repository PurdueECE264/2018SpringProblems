#ifndef PE01_H
#define PE01_H
#include <stdio.h>

/*Caution:
 * Do not modify any functions in this file.
 * */


// The k-mean method to cluster data
// kval: the number of clusters
// nval: the number of data pointers
// dim: dimension of the data
// data: two-dimensional array of the data, nval rows, dim columns
// centroid: two-dimensional array of the data, kval rows, dim columns

// cluster: one-dimensional array of n elements, the assignments of
// data to the clusters. cluster[i] = j means the i-th data pointer is
// assigned to the j-th cluster. 0 <= i < nval; 0 <= j < kval
void kmean(int kval, int nval, int dim, double * * data, double * * centrold,
	   int * cluster);


// for a data point, find the closest centroid
// method:
// 1. calculate the distance between the data point and the first
// centroid, set it to the minimum distance
// 2. go through the other centroids, if the distance is smaller,
// update the minimum distance and the index of this centroid
// data 


// Following are the arguments that for this function:
// 1. int kval - this is the number of clusters i.e. `K` in K-means.
// 2. int dim - this is the dimension of the data points
// 3. const double * data -  this is the datapoint for which we are calculating the closest centroid.
// 4. double * * centroid - you can think of it as array of centroids.

int closestCentroid(int kval, int dim, const double * data, double * * centroid);


//allocateMemory function is used to allocate the memory for 2D arrays.
//Following arguments are used for this
//1. nrow - number of rows in 2D array
//2. ncol - number of columns in 2D array
double * * allocateMemory(int nrow, int ncol);

//releaseMemory function is used to release memory for 2D arrays
//It takes 2 arguments:
//1. double **data - this is pointer to the 2D array
//2. nrow - number of rows. Please be careful, it is number of rows and not number of cols
void releaseMemory(double * * data, int nrow);



#endif
