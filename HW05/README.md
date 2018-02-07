# Student Database (E)

## This is an exercise and is related to HW04 and HW06.

<strong>Please read the entire file before you ask any question.</strong><br>
<strong>You should write your own Makefile to test the code.</strong>

In this exercise, you will learn to sort database by using qsort() function in c. You are allowed to use `Connect()`, `Close()` functions from previous homework. These functions are provided in the obj/pe04.o file, you do not need to define the function again. 

# Learning Goals
You will learn to
* Use function pointer.
* Write text file.
* Use argc and argv correctly in main.

# qsort() funciton 
Before doing this homework, you should understand how [`qsort()`](https://linux.die.net/man/3/qsort) function works. Please go to the link and read the explaination.  
The last argument of qsort requires you to pass a function as an argument. Let's understand the meaning of 
 `int(*compar)(const void *, const void *)`.
Here, it says that compar is the name of the location storing something. The * in front of compar says that compar is going to store an address. It is important that the parentheses enclose `*func`. Without the parentheses around `*func`, it becomes a declaration of a function called compar and compar returns `int *`.

The parentheses following `(*compar)` indicate that compar is going to store an address pointing to a function, and that function expects two input variables. The `void *` means that the memory address can point to any type. This is important for a general-purpose function. It allows us to use qsort to sort any type of array. It can be `int *`, or `char *`, or `doulbe *`, as long as it is an address of a valid array.
. Now, the int before `(*compar)` indicates that the function returns an int.

Essentially, the statement declare compar to be a variable that would store an address pointing to a function that accepts any two data type, and returns an int.

# Functions you need to complete
In this exercise, you have to complete six functions - `CompareByName()`, `SortDatabaseByName()`, `CompareByAge()`, `SortDataBaseByAge()`, `WriteDatabase()` in `pe05.c`, and `main()` in `main.c`.

1. `CompareByName()` and `CompareByAge()` - 
	1. These are the comparison functions you will call in `qsort()`.
	2. The comparison function must return an integer less than, equal to, or greater than zero if the first argument is considered to be respectively less than, equal to, or greater than the second. If two members compare as equal, their order in the sorted array is undefined.
2. `SortDatabaseByName()` and `SortDatabaseByAge()` 
	1. studb: the pointer to `StudentDatabase` object.
	2. You should sort the database by name in <strong>descending</strong> order when calling `SortDatabaseByName()`.
	3. You should sort the database by age in <strong>ascending</strong> order when calling `SortDatabaseByAge()`.
	4. You will call `qsort()` in these functions. 
3. `WriteDatabase()` - This function writes the info in database to a file. You will need to use `fprintf()` function.
	1. filename: the name of the file you are writing to.
	2. studb: the pointer to `StudentDatabase` object.
	3. You should return 1 when you successfully write a file. Otherwise, you should return 0.
	4. You should return 0 and print "Fail to open a file\n" when fopen fails and the output file should not be created.
	5. See expected/sortbyage.txt or expected/sortbyname.txt for the format you have to use in `fprintf()`.
4. `main()` - In this exercise, you will learn to use `argc` and `argv`. Here are the specifications.
	1. argc: If argc is not 4, you should return `EXIT_FAILURE` and print "Wrong arguments\n".
	2. argv[1]: name of the database. i.e., database.txt.
	3. argv[2]: should be either "-a", or "-n".
		When argv[2] is "-a", you should sort the database by age in ascending order and write the database to a file and return `EXIT_SUCCESS`.
		When argv[2] is "-n", you should sort the database by name in descending order and write the dataabse to a file and return `EXIT_SUCCESS`. 
		For example, Student "Allen" should come after "Bob".
	  	If argv[2] is neither "-a" nor "-n", you should print "Wrong arguments\n" and return `EXIT_FAILURE`.
	4. argv[3]: This is the output filename. You should write the output of database into this file.
	5. print "Write to db\n" to screen if `WriteDatabase()` work. Otherwise, print "Fail to write to db\n"

# Testing your code
Following are the files we provide:
1. `pe05.c` - Define your functions in this assignment.
2. `pe05.h` - Header file, which has definition for the functions and structures you need in this assignment.
3. `main.c` - main file of this assignment.
4. `database.txt` - This is the database file which stores all student's info.
5. `obj/pe04.o` - This object stores the definition of functions in previous homework, you should include this file when using gcc to compile your code. Otherwise, you can not use the `Connect()` and `Close()` functions from previous homework.
6. expected/ - This directroy contains expected output of the following commands. 
	1. sortbyage.txt - ./pe05 database.txt -a sortbyage.txt. You will print "Write to db\n" or "to screen and create a file named sortbyage.txt with database info sorted by age.
	2. sortbyname.txt - ./pe05 database.txt -n sortbyname.txt. You will print "Write to db\n" to screen and create a file named sortbyname.txt with database info sorted by name.
	3. dbnotexist.txt - ./pe05 blablabla -n dbnotexist.txt. You will print "Fail to open database.\n Fail to connect to db.\n" to screen and no file will be created.
	4. notaorn.txt - ./pe05 database.txt -k notaorn.txt. You will print "Wrong arguments\n" to screen and no file will be created.
	5. argcnot4.txt - ./pe05 database.txt. You will print "Wrong arguments\n" to screen and no file will be created.
	6. filefail.txt - ./pe05 database.txt -a file.txt. You will print "Fail to open a file\n Fail to write to db\n" to screen and no file will be created. <br>
		To test this you can create "file.txt" first and make it not writable by typing "chmod 444 file.txt" to change the file permission. 
	7. We will run valgrind for each command and check whether your code has memory issues. 
	

To test your code. You have to first compile it and then run the following command. 

Sort the database by age in ascending order and write it to a file.
```
./pe05 database.txt -a filename
```
Sort the database by name in descending order and write it to a file.
```
./pe05 database.txt -n filename
```
1. pe05 - This is binary that should get generated
2. database.txt - This is the database file which stores all students' information.
3. "-a", "-n" - These are the arguments you should specify. "-a" means to sort the database by age. "-n" means to sort the database by name.
4. filename - name of the file your are writing to.

# Checking for memory errors
You should also run./pe05 with arguments under valgrind. To do that, you have to use, for example, the following command:
```
valgrind --log-file=memcheck.log -tool=memcheck --leak-check=yes --verbose ./pe05 database.txt -a filename
```
and
```
valgrind --log-file=memcheck.log -tool=memcheck --leak-check=yes --verbose ./pe05 database.txt -n filename
```
Note that you should use other input arguments to extensively test your function. If you follow the instructions and keep the malloc and free functions in the right place, you should not have memory problems in this assignment.


# Submitting Your code
** This is a programming exercise, so you would have to submit the code on Blackboard.**
You have to submit the following files in a <strong>zip</strong> folder on the blackboard:
* `pe05.c` - This file should have `CompareByName()`, `SortDatabaseByName()`, `CompareByAge()`, `SortDataBaseByAge()`, `WriteDatabase()` functions completed.
* `main.c` - This file should have `main()` function completed.<br>
Type the following command to zip your file.
```bash
	zip pe05.zip pe05.c main.c
```
Submit <strong>pe05.zip</strong> to blackboard. 
<strong>You will not get any credits if you do not follow the submission instructions </strong>

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

<strong>Do not print anything other than the required output (i.e., no debugging output, etc.). ifndef is used for grading. Please do not change it.</strong>

This exercise will be graded as folows:
1. `SortDatabaseByName()`: This function should sort the database by name in descending order using `qsort()`.
2. `SortDatabaseByAge()` : This function should sort the database by age in ascending order using `qsort()`.
3. `CompareByName()`: Correctness of your comparison function.
4. `ComprareByAge()`: Correctness of your comparison funciton.
5. `WriteDatabase()` function: This function should write the output of given database to a file. 
6. `argc` and `argv`: whether the main function meets the specifications as described above.
7.  Code that contains memory problems reportable by Valgrind will be subject to a penalty of 40% of the total possible points.
