#ifndef PE01_H
#define PE01_H
#include <stdio.h>

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
//closestCentroid function does the following:
// 1. calculate the distance between the data point and the first
// centroid, set it to the minimum distance
// 2. go through the other centroids, if the distance is smaller,
// update the minimum distance and the index of this centroid
// data 

int closestCentroid(int kval, int dim, const double * data, double * * centroid);


//distance2 function finds the distance between the data point and centroid for a given dimension
//It accespts the follwing arguments:
//1. datapoint - pointer to datapoint for which we are finding the distance
//2. centroid - pointer to centroid with which we are finding the distance
//3. dim - dimension of the datapoint and centroid
double distance2(const double * datapoint, double * centroid, int dim);



#endif
