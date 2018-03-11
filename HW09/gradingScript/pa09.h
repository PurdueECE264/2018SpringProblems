#ifndef PA09_H
#define PA09_H
#define MAX_LEN 80
#pragma pack(1) // tell compiler not to pad any space

/* Do not change code below this line */
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

//Defining a compare function that takes void* as inputs and return int
typedef int (*CompareFunction)(const void *, const void *);
// -------------- The following functions are defined in pa09.c file ------------
//The following function implement quicksort for Student array
void StudentQsort(Student **stuArray, int startIndex, int endIndex , CompareFunction compare );

// This is the Helper function for the StudentQsort functionality and is necessary to implement for
// qsort to work
int Partition(Student **stuArray, int left, int right, CompareFunction compare);

//Swap function for Student structure
void SwapStudent( Student** stu1, Student** stu2);

//Clear out all the memory
void Close(StudentDatabase * studb);


//Functions already defined and need not worry about
void PrintStudent(Student * stu);
void SortDatabaseByName(StudentDatabase * studb);
void SortDatabaseByAge(StudentDatabase * studb);
// ---------------- end of function defined in pa09.c ------------

// ---------------- The following functions are defined in read_write.c file ------------
StudentDatabase * ReadDatabase(char * filename);
int WriteDatabase(char *filename, StudentDatabase * db);

#endif
