#include <stdlib.h>
#include <stdio.h>
#include "pa06.h"

int main(int argc, char **argv) {
	StudentDatabase * db = Connect("database.txt");
	ParseResult * parse_res = ParseQuery(argc, argv);
	ExecuteResult * execute_res = ExecuteQuery(db, parse_res);
	printf("len: %d\n", execute_res -> len);
	printf("index: ");
	for (int i = 0; i < execute_res -> len; i ++) {
		printf("%d ", execute_res -> arr[i]);	
	}
	FreeParseResult(parse_res);
	FreeExecuteResult(execute_res);
	Close(db);
    return EXIT_SUCCESS;
}

