#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pa09.h"


#ifndef MAIN_FUNC
/*
	Complete the main function and meet the followin specifications of argc and argv.
	1. argc: If argc is not 4, you should return EXIT_FAILURE and print "Wrong arguments\n".
	2. argv[1]: name of the binary input file. i.e., databaseBinary.bin
	3. argv[2]: should be either "-a", or "-n".
		When argv[2] is "-a", you should sort the database by age in ascending order and print the database and return EXIT_SUCCESS.
		When argv[2] is "-n", you should sort the database by name in descending order and print the dataabse and return EXIT_SUCCESS.
		For example, Student "Allen" should come after "Bob".
	  	If argv[2] is neither "-a" nor "-n", you should print "Wrong arguments\n" and return EXIT_FAILURE.
	4. argv[3]: This is the output filename. You should write the output in the binary format of database into this file.
	5. print "Fail to connect to db\n" if you fail to connect to database.
	6. You should not have memory issues in your code.
*/


int main(int argc, char ** argv) {
	// TODO 1. check the arguments, print "Wrong arguments\n" if anything fails
	// TODO 2. ReadDatabase and get the pointer to StudentDatabase
	// TODO 3. Sort the database according to argument if "-n" then call SortDatabaseByName
	// else if "-a" then call SortDatabaseByAge
	// TODO 4. Write the output to a binary file
	// TODO 5. print "Write to db\n" if `WriteDatabase()` work. Otherwise, print "Fail to write to db\n"
	// TODO 6. Free all the memory


	return EXIT_SUCCESS;
}

#endif
