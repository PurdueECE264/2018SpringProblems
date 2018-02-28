#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pa09.h"

#ifndef CONNECT

StudentDatabase * ReadDatabase(char * filename) {
	StudentDatabase* db = NULL;
	//TODO 1. Open the file in read and binary format

	//TODO 2. Allocate memory for db

	//TODO 3. Find number to entries of Student structure

	//TODO 4. Set the value of db->number to the number of students


	// TODO 5. Allocate the memory for the db->students structure

	//TODO 6. Read the file again from start and assign value to each student in the data base

	//close the file

	//return the StudentDatabase
	return db;
}

#endif

#ifndef WRITE_DB
//This function is to write to a file in binary format
int WriteDatabase(char *filename, StudentDatabase * db) {
	//TODO 1. Open the file in write and binary format
	//TODO 2. check if the StudentDatabase is not null
	//TODO 3. write into the file and if not possible return 0
	return 1;


}
#endif
