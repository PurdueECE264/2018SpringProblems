#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pe05.h"

#ifndef TEST_CPRNAME
static int CompareByName(const void * s1, const void * s2) {
	
}
#endif

#ifndef TEST_NAME
void SortDatabaseByName(StudentDatabase * db) {
	// use qsort to sort the database.
}
#endif

#ifndef TEST_CPRAGE
static int CompareByAge(const void * s1, const void * s2) {

}
#endif

#ifndef TEST_AGE
void SortDatabaseByAge(StudentDatabase * db) {
	// use qsort to sort the database.

}
#endif

#ifndef TEST_WRITE
int WriteDatabase(char *filename, StudentDatabase * db) {
	// Write the info storing in db to filename

}
#endif

