// * DO NOT MODIFY THIS FILE UNLESS YOU FIND MISTAKES *
// If you modify this file, your program may be incompatible
// in grading and you may lose points.
//
// This program generates cases for testing your program.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


// Generate k clusters of data

// The clusters' centers are regularly spaced between
// [-range, range] in each dimension.
// Thus, the j's cluster's center is at
// -range + 2 * (j+1) * range/(k + 1), 0 <= j < k (to be consistent
// with C because indexes start from 0)

// The data points of the j's cluster are uniformly distributed
// [-range / (2 * (k +1)) + center, range / (2 * (k +1)) +
// center]. This ensures that the clusters do not overlap (with
// distance at least range / (k +1).

// function declaration
void generateData(long kval, long dim, long range, long nval);

int main(int argc, char * * argv)
{
	// argv[1]: random seed (-1 means using time and almost
	// unpredictable)

	// argv[2]: value of k (must be greater than 1)

	// argv[3]: number of data points (must be equal or greater than k)
	// called it n

	// argv[4]: dimension, at least two, called it dim

	// argv[5]: range (the data will be scattered approximately between
	// [-range, range] for each dimension. The value must be positive

	// process the command-line arguments
	if (argc != 6)
	{
		fprintf(stderr, "argc is %d, must be 6\n", argc);
		return EXIT_FAILURE;
	}
	long randseed = strtol(argv[1], NULL, 10);
	if (randseed == -1)
	{
		srand(time(NULL));
	}
	else
	{
		srand(randseed);
	}

	long kval = strtol(argv[2], NULL, 10);
	// do not use a single letter k because it is too easy to mistype
	if (kval < 2)
	{
		fprintf(stderr, "kval is %ld, must be 2 or larger\n", kval);
		return EXIT_FAILURE;
	}

	long nval = strtol(argv[3], NULL, 10);
	if (nval <= kval)
	{
		fprintf(stderr, "nval is %ld smaller than kval\n", nval);
		return EXIT_FAILURE;
	}

	long dim = strtol(argv[4], NULL, 10);
	if (dim < 2)
	{
		fprintf(stderr, "dim is %ld, must be 2 or larger\n", dim);
		return EXIT_FAILURE;
	}

	long range = strtol(argv[5], NULL, 10);
	if (range <= 0)
	{
		fprintf(stderr, "range is %ld, must be positive\n", range);
		return EXIT_FAILURE;
	}

	// all arguments are valid now
	// print the number of data points and the dimension
	// no need to print the other parameters
	fprintf(stdout, "%ld\n", nval);
	fprintf(stdout, "%ld\n", dim);
	generateData(kval, dim, range, nval);
	return EXIT_SUCCESS;
}

void printCentroid(long kval, long dim, double * * centroid);

void generateData(long kval, long dim, long range, long nval)
{
	double * * centroid;
	// create k centroids
	// the centroids are a 2-dimensional array
	// Each row is one centrold with dim dimensions
	// Thus, there are k rows and dim columns
	centroid = malloc(sizeof(* centroid) * kval);
	if (centroid == NULL)
	{
		fprintf(stderr, "malloc fail\n");
		return;
	}
	int kiter;
	for (kiter = 0; kiter < kval; kiter ++)
	{
		centroid[kiter] =
			malloc(sizeof(** centroid) * dim);
		if (centroid[kiter] == NULL)
		{
			// should release memory allocated earlier
			// assume this error does not occur and
			// only print an error message if it does
			fprintf(stderr, "malloc fail\n");
			return;
		}
	}

	// Place the centrold at regular intervals in each dimension
	for (kiter = 0; kiter < kval; kiter ++)
	{
		int dimiter;
		for (dimiter = 0; dimiter < dim; dimiter ++)
		{
			centroid[kiter][dimiter] = -range + 2 * range * (kiter + 1) / (kval + 1);
		}
	}



	// generate the data
	while (nval > 0)
	{
		// chose a cluster randomly
		int cluster = rand() % kval;
		int dimiter;
		for (dimiter = 0; dimiter < dim; dimiter ++)
		{
			double dist = 0.0001 * (rand() % 10000);
			// distance from the centroid, dist is between 0 and 1
			dist -= 0.5; // between -0.5 and 0.5
			dist *= range / (kval + 1);
			fprintf(stdout, "%f\n", centroid[cluster][dimiter] + dist);
		}
		fprintf(stdout, "\n");
		nval --;
	}

}

void printCentroid(long kval, long dim, double * * centroid)
{
	int kiter;
	int diter;
	for (kiter = 0; kiter < kval; kiter ++)
	{
		for (diter = 0; diter < dim; diter ++)
		{
			fprintf(stdout, "%8f ", centroid[kiter][diter]);
		}
		printf("\n\n");
	}
}
