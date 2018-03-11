#include <stdio.h>
#include <stdlib.h>
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


int main(int argc, char** argv){
	FILE* fptr;
	fptr = fopen(argv[1],"rb");
	if(fptr==NULL){
		printf("Fail to read file %s\n",argv[1]);
		return -1;
	}
	int index = 0;
	Student stu;
	while(fread(&stu, sizeof(Student), 1, fptr)) {
		index++;
	}
	Student** student = malloc(sizeof(Student*)*index);
	for(int i=0;i<index;i++){
		student[i] = malloc(sizeof(Student));
	}
	fseek(fptr, 0 ,SEEK_SET);
	index = 0;
	while(fread(student[index], sizeof(Student), 1, fptr)) {
		index++;
	}
	for(int iter = 0; iter < index; iter++){
		printf("ID:%d, Name:%s, Major:%s, Enrollment:%s, Year:%s, Age:%d\n",
			student[iter]->id, student[iter]->name, student[iter]->major,
			student[iter]->enrollment, student[iter]->year, student[iter]->age);
	}
	for(int i=0;i<index;i++){
		free(student[i]);
	}
	free(student);
	fclose(fptr);
	return 0;
}
