#ifndef PE05_H
#define PE05_H
#define MAX_LEN 80

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

StudentDatabase * Connect(char * filename);
Student * SearchByName(StudentDatabase * studb, char * name);
void Close(StudentDatabase * studb);
void PrintDatabase(StudentDatabase * studb);
void PrintStudent(Student * stu);
void SortDatabaseByName(StudentDatabase * studb);
void SortDatabaseByAge(StudentDatabase * studb);
int WriteDatabase(char *filename, StudentDatabase * db);
#endif
