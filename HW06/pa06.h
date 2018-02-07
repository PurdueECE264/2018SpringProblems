#ifndef PA06_H
#define PA06_H
#include <stdbool.h>
#define MAX_LEN 80

/* Do not change code below this line  */

/*
	There are six fields in this structure.
	It stores the information of which fields are selected in query.
*/
typedef struct {
	bool id;
	bool name;
	bool major;
	bool year;
	bool enrollment;
	bool age;
} SelectedField;

/*
	There are three fields in this structue.
	It stores the information of each condition.
*/
typedef struct {
	char field[MAX_LEN];
	char optr[MAX_LEN];
	char val[MAX_LEN];
} Condition;

typedef struct {
	SelectedField * field; // pointer to a SelectedField object that stores of info of which fields are selected.
	int condition_num;  // num of the condition array.
	Condition ** conditions; // Array of pointers to Condition objects.
	char logic[MAX_LEN]; // Which logic does this query use. ("AND" or "OR")
} ParseResult;

typedef struct {
	int * arr; // An array of matched Student's index.
	int len;  // Length of the array.
} ExecuteResult;

typedef struct {
	int id;
	char name[MAX_LEN];
	char major[MAX_LEN];
	char year[MAX_LEN];
	char enrollment[MAX_LEN];
	int age;
} Student;

typedef struct {
	int number; // Total number of students in the database.txt
	Student **students; // A 2D array that stores the Stduent structure of each student in database.txt
} StudentDatabase;

SelectedField * ConstructField();
ParseResult * ParseQuery(int num, char ** query);
bool Compare(Student * stu, Condition * condition);
ExecuteResult * ExecuteQuery(StudentDatabase * db, ParseResult * res);
void FreeParseResult(ParseResult * res);
void FreeExecuteResult(ExecuteResult * res);
void WriteDb(StudentDatabase * db, SelectedField * info, ExecuteResult * execute_res, char * filename);

StudentDatabase * Connect(char * filename);
Student * SearchByName(StudentDatabase * studb, char * name);
void Close(StudentDatabase * studb);
void PrintDatabase(StudentDatabase * studb);
void PrintStudent(Student * stu);
void SortDatabaseByName(StudentDatabase * studb);
void SortDatabaseByAge(StudentDatabase * studb);
int WriteDatabase(char *filename, StudentDatabase * db);
#endif
