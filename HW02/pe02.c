#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "pe02.h"
#define RANGE 1000000

void cleanup(FILE * fpin, FILE * fpout)
{
  fclose (fpin);
  fclose (fpout);
}

// read the data, return true if success, false if fail
bool readData(FILE * fpin, double * * data, int nval, int dim)
{
  int niter, diter;
  for (niter = 0; niter < nval; niter ++)
    {
      for (diter = 0; diter < dim; diter ++)
	{
	  if (fscanf(fpin, "%lf", & data[niter][diter]) == 0)
	    {
	      return false;
	    }
	}
    }
  return true;
}

// write the output centroids to the file
// check for all the NULL before calling this function, it does not check
void writeCentroids(FILE * fpout, double * * centroid, int kval, int dim){
  int kiter,diter;
  for (kiter = 0; kiter < kval; kiter ++)
    {
      for (diter = 0; diter < dim; diter ++)
	{
	  //write to the file
	  fprintf(fpout, "%lf\n", centroid[kiter][diter]);
	}
      fprintf(fpout, "\n");
    }
}

//initilize function is to initilize the values for centroid
void initialize(double * * centroid, int kval, int dim)
{
  int kiter, diter;
  for (kiter = 0; kiter < kval; kiter ++)
    {
      for (diter = 0; diter < dim; diter ++)
	{
	  int randval = - RANGE + (rand() % (2 * RANGE));
	  centroid[kiter][diter] = randval;
	}
    }
}

int main(int argc, char * * argv)
{
  // argv[1]: name of input file
  // argv[2]: value of k
  // argv[3]: name of output file
  // argv[4]: (optional) seed for random numbers, use time if absent

  if (argc < 4)
    {
      fprintf(stderr, "argc is %d, not 4\n", argc);
      return EXIT_FAILURE;
    }
  FILE * fpin = fopen(argv[1], "r");
  if (fpin == NULL)
    {
      fprintf(stderr, "fopen %s fail\n", argv[1]);
      return EXIT_FAILURE;
    }
  int kval = (int) strtol(argv[2], NULL, 10);
  // convert long to in
  if (kval <= 0)
    {
      fprintf(stderr, "kval is %d, must be positive\n", kval);
      return EXIT_FAILURE;
    }
  FILE * fpout = fopen(argv[3], "w");
  if (fpout == NULL)
    {
      fclose (fpin);
      // was open successfully and needs to be closed
      fprintf(stderr, "fopen %s fail\n", argv[3]);
      return EXIT_FAILURE;
    }

  if (argc == 5)
    {
      int randseed = (int) strtol(argv[4], NULL, 10);
      if (randseed == -1)
	{
	  srand(time(NULL));
	}
      else
	{
	  srand(randseed);
	}
    }

  int nval;
  fscanf(fpin, "%d", & nval);
  if (nval < kval)
    {
      fprintf(stderr, "nval= %d must be greater than kval = %d\n",
	      nval, kval);
      cleanup(fpin, fpout);
      return EXIT_FAILURE;
    }
  int dim;
  fscanf(fpin, "%d", & dim);
  if (dim < 2)
    {
      fprintf(stderr, "nval= %d must be greater than kval = %d\n",
	      nval, kval);
      cleanup(fpin, fpout);
      return EXIT_FAILURE;

    }

  // allocate memory for the data points
  double * * datapoint = allocateMemory(nval, dim);
  if (datapoint == NULL)
    {
      cleanup(fpin, fpout);
      return EXIT_FAILURE;
    }
  // allocate memory for the centroid
  double * * centroid = allocateMemory(kval, dim);
  if (centroid == NULL)
    {
      cleanup(fpin, fpout);
      return EXIT_FAILURE;
    }

  // read the data from the file
  if (readData(fpin, datapoint, nval, dim) == false)
    {
      cleanup(fpin, fpout);
      return EXIT_FAILURE;
    }

  // initialize centroids within [-RANGE, RANGE] of every dimension
  initialize(centroid, kval, dim);

  //allocate memory for cluster
  int * cluster;
  cluster = malloc(sizeof(*cluster)*nval);
  if(cluster == NULL)
    {
      cleanup(fpin, fpout);
      return EXIT_FAILURE;
    }
  // initilize cluster values
  for(int niter = 0; niter < nval; niter++)
    {
      cluster[niter] = -1;
    }

  //now we will run our kmean algorithm
  kmean(kval, nval, dim, datapoint, centroid, cluster);


  //print all the centroids into a file
  writeCentroids(fpout, centroid, kval, dim);

  //free all the allocated spaces
  releaseMemory(datapoint, nval);
  releaseMemory(centroid, kval);
  free(cluster);
  //close all the files
  cleanup(fpin, fpout);
  return EXIT_SUCCESS;
}



//distanc2 function calculates Euclidean distance between a datapoint and a centroid
//Following are the arguments for the distance2 function
//1. const double * datapoint - this is pointer to datapoint from which distance 
//	 needs to be calculated. It is const because we don't want the function to change the value of data.
//2. double * centroid - As the name suggests this is pointer to the a particular centroid.
//3. int dim - this is the dimension of the datapoint.

// Since the distances are for comparison only, it is unnecessary to calculate the real distance,
// as long as the orders are correct. Thus, do not call sqrt. If you do call sqrt, you need to add
// -lm after -o pe02 in Makefile to link the math library
double distance2(const double * datapoint, double * centroid, int dim)
{
  // since this is for comparison only, there is no need to call sqrt
  double sum = 0; // must initialize to zero
  //Please complete the 
  return sum;
}




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
int closestCentroid(int kval, int dim, const double * data, double * * centroid)
{
  int mindex = 0;
  return mindex;
}

