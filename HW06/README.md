# Student Database (A)

## This is an assignment.

# Announcements
1. Please read the entire file before you ask any question.
2. You should write your own Makefile to test the code.
3. You will use your own `Connect()` and `Close()` functions from HW04 in this assignment. Those functions are not provided. Please define these two functions in pa06.c.
4. Do not print anything other than the required output (i.e., no debugging output, etc.). <strong>ifndef</strong> is used for grading. Please do not change it.
5. This assignment takes time. You should start earlier.

In this assignment, you will implement a SQL-like statement. SQL is a standard language for storing, manipulating and retrieving data in databases. 
For example, if we want to select certain fields from a table in database following certain conditions, we will type this query
```sql
	SELECT field1, filed2, ... FROM table_name WHERE field1=.., field2=..;	
```
Here, field1, field2, ... are the names of the fields in table you want to select data from. The WHERE clause is used to filter records and extract data that fulfill a specified condition. 

For example, if we want to get the name of students who are in sophemore year and have enrolled this semester. We will type the following SQL query (Assume we have a table named db).
```sql
	SELECT name FROM db WHERE year="Sophemore" AND enrollment="Yes";
```
After running this query, we will get the name of students who meet the specified condidtions.  

# Learning Goals
You will learn to
* Allocate and release memory.
* Write text file.
* Use argc and argv correctly in main.

# Our SQL-like query 
In this assignment, you will implement our version of SELECT statement and WEHRE clause. Before that, you have to understand the SQL syntax we define in this assignment. You should <strong>follow</strong> this syntax.
	```sql
		SELECT field1 field2 ... WHERE field3 = val1 AND field5 < val2
	```
1. The field1 field2 between `SELECT` and `WHERE` are the selected fields. You will use a `SelectedField` object to keep the information of which fields are selected. 
2. We define `field3 = val1`, `field5 < val2` as `Condition`. In this example, you will need to use two `Condition` ojects to store the informations.
3. The `AND` is defined as logic. In this homeowrk, we only have one type of logic in each query. We will not have the case that has `AND` and `OR` in the same query. For example, we only have the cases like 
	```sql
		SELECT field1 field2 ... WHERE condition1 AND condition2 AND condition3 ...
		SELECT field1 field2 ... WHERE condition1 OR condition2 OR condition3 ...
	```
4. Each word is seperated by a space.
5. You don't have to specify table name in the query.
6. You will pass the query in command line. For exapmle, ```./pa06 database.txt output.txt SELECT name age WHERE id "<" 100```. Note that you have to add double quotation marks around `<`, `>`, `<=`, and `>=` when you type the query in command line. 
7. You will use "<", ">", "=", "<=", ">=" operators when doing comparisons in id and age fields. For example, 
	```SQL
		SELECT name WHERE age "<=" 20 AND id ">" 10
	```
8. You will use "=" operator when doing comparisions in name, enrollment, year, and major fields. For example, 
	```SQL
		SELECT name WHERE name = BLABLABLA OR major = ECE
	```
	You will not have the cases like
	```SQL
		SELECT name WHERE name "<=" BLABLABLA OR major "!=" ECE
		SELECT age WHERE enrollment "<=" YES AND name ">=" BLABLABLA
	```
# Steps to complete this homewok
Here is the concept map to help you finish this assignment. Frist, know what information is stored in the sql query using `ParseQuery` function. Second, use those information and pass to `ExecuteQuery()` function to find students who meet the specified conditions. Finally, write the information of matched students to a file using `WriteDb` function.
1. Complete `ParseQuery(int num, char ** query)` function. 
	1. Know what fields are selected and store it in `SelectedField` object. You will use this information in `WriteDb` function to decide what fields you should write to the output file. 
	2. Know what are the conditions and store it in `Condition` objects. You will use this information in `ExecuteQuery` function to find students who meet the specified conditions. 
	3. Know what logic is used in the query (AND or OR).
	4. Store the information above to `ParseResult` object.
2. Complete `ExecuteQuery(StudentDatabase * db, ParseResult * res)` function.
	1. Use info in `ParseResult` object to find the students who meet the specified conditions.
	2. Get the array of matched student's index and store it in `ExecuteResult` object.
3. Complete `WriteDb(StudentDatabase * db, SelectedField * info, ExecuteResult * execute_res, char * filename)` function.
	1. Use `SelectedField` object to know what fields should be written into the output file.
	2. Use `ExecuteResult` object to know the index of students who meet the specified conditions. 
	3. Create a output file with all those students' who meet the specified conditions and only write the selectedfield to the file. 
4. Complete all functions that free memory. 

# Functions you need to complete
In this assignment, you have to complete seven functions - `ConstructField()`, `ParseQuery()`, `ExecuteQuery()`, `FreeParseResult()`, `FreeExecuteResult()`, and `WriteDb()` in `pa06.c`, and `main()` in `main.c`.

1. `SelectedField * ConstructField()`:
	1. This function returns a pointer to `SelectedField` object.
	2. Allocate memory for `SelectedField` object.
	3. Initialize all the fields in this object to "false".
	4. return `NULL` and print "Fail to allocate memory\n" to screen if you fail to allocate memory for `SelectedField` object.
	5. You will call this function in `ParseQuery()`.
2. `ParseResult * ParseQuery(int num, char ** query)`: <br>
	Parse the query and store the information into `ParseResult` object. 
	1. You should pass `argc` and `argv` into this fuction. 
	2. Note that the sql query starts from `argv[3]` since `argv[1] is database.txt and `argv[2]` is the output filename.
	3. This function returns a pointer to `ParseResult` object.
	4. In this function, you should parse the qeury and store the information to `ParseResult` object. Similar to `Connect()` function in HW04, you should allocate memory for the required objects and then update the fields in the objects.
3. `ExecuteResult * ExecuteQuery(StudentDatabase * db, ParseResult * res)`:
	1. This function takes two arguments: First, a pointer to `StudentDatabase` object. Second, a pointer to `ParseResult` object.
	2. This function returns a pointer to `ExecuteResult` object.
	3. The `ExecuteResult` object has two fields: First, an array of matched Student's index. Second, length of the array. For example, if there are six students meet the specified conditions in your sql query, the length of the array should be 6 and the array should store the <strong>index</strong> (<strong>NOT</strong> id) of those students.
4. `void FreeParseResult(ParseResult * res)`: Free the allocated memory in `ParseResult` object.
5. `void FreeExecuteResult(ExecuteResult * res) `: Free the allocated memory in `ExecuteResult` object.
6. `void WriteDb(StudentDatabase * db, SelectedField * info, ExecuteResult * execute_res, char * filename)`:
	1. Only write selected fields of students who meet specified conditions to output file.
	2. Print error message "Failed to open file\n" to monitor if the fopen fail. 
	3. Follow this format "field:%s ", or "field:%d ". Add "\n" when you finish writing the selected fileds of a student. Please look at the files in `expected` folder to make sure you understand the format. We will use diff to test. Make sure your output format is correct.
	4. You should write the info of each student in the following order if that fields are selected. id -> name -> major -> year -> enrollment -> age.
	5. The order in selected fields does not affect the order you write to the file.  e.g., `SELECT id name WHERE ...` and `SELECT name id WHERE ...` should have the same output file. 
7. `main(int argc, char ** argv)`:
	1. `argv[1]`: database name (i.e., database.txt). You should pass `argv[1]` to `Connect()`.
	2. `argv[2]`: output file name. You should pass `argv[2]` to `WriteDb()`.
	3. Pass `argc`, `argv` to `ParseQuery()` and get the parse results.
	4. Call `ExecuteQuery()` function to get the result of students who meet the condition we specify in the query.
	5. Use `WriteDb()` to write a file.
	6. Free memory.
	7. You can assume all input arguments are valid. 
	
# Testing your code
Following are the files we provide:
1. `pa06.c` - Define your functions in this assignment.
2. `pa06.h` - Header file, which has definition for the functions and structures you need in this assignment.
3. `main.c` - main file of this assignment.
4. `database.txt` - This is the database file which stores all student's info.
5. `expected/` - This folder has the expected output of the following commands.
	1. test1.txt -  `./pa06 database.txt output.txt SELECT name age WHERE age ">" 10 AND id = 1`
	2. test2.txt -  `./pa06 database.txt output.txt SELECT age name WHERE age ">" 10 AND id = 1`
	3. test3.txt -  `./pa06 database.txt output.txt SELECT enrollment age major WHERE age "<" 22 OR id = 100`
 	4. test4.txt -  `./pa06 database.txt output.txt SELECT id major enrollment WHERE major = CS AND enrollment = No AND year = Sophomore`
	5. test5.txt -  `./pa06 database.txt output.txt SELECT id WHERE enrollment = Yes`
	6. test6.txt -  `./pa06 database.txt output.txt SELECT id WHERE enrollment = Yes AND name = aa`
	6. test7.txt -  `./pa06 database.txt output.txt SELECT age enrollment year major name id WHERE enrollment = No`
 
To test your code. You have to first compile it and then run the following command. 
```bash
	./pa06 database.txt output.txt SELECT field1 field2 ... WHERE condition1 condition2 ....
```
1. pa06 - This is binary that should get generated
2. field1, field2, ... should only be the fields defined in `Student` structure. We will not use fields that are not is `Student` structue when testing your code. 
3. condition shoud consist of `field`, `optr`, and `val`.
4. You will have a "output.txt" file generated. The file should only have the selected fields of the students who meet the specified conditions. You will have an empty file if no studdents meet the specified conditions. 

# Checking for memory errors
You should also run./pa06 with arguments under valgrind. To do that, you have to use, for example, the following command:
```
valgrind --tool=memcheck --leak-check=full --verbose --log-file=memcheck.log ./pa06 database.txt output.txt YOUR QUERY
```
Note that you should use other input arguments to extensively test your function. If you follow the instructions and keep the malloc and free functions in the right place, you should not have memory problems in this assignment.


# Submitting Your code
** This is a programming assignment, so you would have to submit the code on Blackboard.**
<strong>Follow</strong> this submission instructions:
1. Type
	```bash
	zip pa06.zip pa06.c main.c
	```
2. Submit <strong>pa06.zip</strong> to blackboard.
3. Your assignment will not be graded if you do not follow this instructions.

The **only** way to submit homework is through Blackboard.

The instructor will **never** accept any requestion for exception "*my
submission is only one minute late*".  It is your responsibility to
meet the deadline.  You are strongly encouraged to submit at least ten
minutes before the deadline because submission may take time.

If there is a campus-wide problem (such as network outage or the
Blackboard server is down), the deadline will be extended for the
entire class. If the problem is specific to yourself (for example,
your computer crashes), the deadline will not be extended for
you.

**DO NOT** send your code by email. Your code will not be graded
  if it is sent by email.

The teaching staff is strictly prohibited to look at files on your
computer (or your Purdue account) for grading. Thus, **NEVER** say "I
finished before the deadline but I forgot to submit".  **NEVER** say "I have
not made any change after the submission deadline." because the
teaching staff is not allowed to look at your files that have not been
submitted through Blackboard.

# Grading
If your program has any compilation error or warning (remember to use
`gcc -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror`), you will
receive zero in this assignment.

In absolutely no circumstance can the teaching staff modify your
program for grading.  You cannot say, "If you change this, my program
works." If your program misses a semicolon and cannot compile, you
will receive zero.  Your score depends on what is submitted, nothing
else.

This exercise will be graded as folows:
1. `ParseQuery()`: This function should parse the query and return a pointer to `ParseResult` object with correct information.
2. `ExecuteQuery()` : This function should return a pinter `ExeucuteResult` object with correct information.
3. `WriteDb()` function: This function should write the output of given database to a file.
4.  The correctness of your program: We will use 10 different queries to test the correctness of your program. The score will be proportional to the number of passed test cases
5.  Code that contains memory problems reportable by Valgrind will be subject to a penalty of 40% of the total possible points.

# Q&A
**1. Where should I define `Connect()` and `Close()` function?**

Ans: You should define these functions in pa06.c. 

**2. Why do we need to add double quotation marks around the operator when testing our sql-like query?**

Ans:  The reason for adding double quotation mark is that  `<` and `>` are linux commands. `>` means redirect standard output. `<` means redirect standard input. You have to add double quotation marks in the case such as "<=", ">=", "<", ">" when you type your sql query, so that linux will view it as common string, not the built-in linux commands

**3. What arguments should I pass to `ParseQuery()` function?**

Ans: You will call `ParseQuery()` function in main.c and pass `argc` and `argv` to this function.

**4. Do I need to handle invalid input? (e.g., argv does not has some key words such as wrong of SELECT and WHERE ,or put nothing after WHERE.)**

Ans: You can assume all inputs are valid, meaning no wrong spellings, incorrect format, or fields that does not exist. 
