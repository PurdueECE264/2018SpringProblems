#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pe05.h"


/*
	Complete the main function and meet the followin specifications of argc and argv.
	1. argc: If argc is not 4, you should return `EXIT_FAILURE` and print "Wrong arguments\n".
	2. argv[1]: name of the database. i.e., database.txt.
	3. argv[2]: should be either "-a", or "-n".
		When argv[2] is "-a", you should sort the database by age in ascending order and write the database to a file and return `EXIT_SUCCESS`.
		When argv[2] is "-n", you should sort the database by name in descending order and write the dataabse to a file and return `EXIT_SUCCESS`. 
		For example, Student "Allen" should come after "Bob".
	  	If argv[2] is neither "-a" nor "-n", you should print "Wrong arguments\n" and return `EXIT_FAILURE`.
	4. argv[3]: This is the output filename. You should write the output of database into this file.
	5. print "Write to db\n" to screen if `WriteDatabase()` work. Otherwise, print "Fail to write to db\n"

*/ 

int main(int argc, char ** argv) {
	
	return EXIT_SUCCESS;
}

