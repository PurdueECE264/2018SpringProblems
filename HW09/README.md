# Student Database (A)

## This is an assignment

<strong>Please read the entire file before you ask any question.</strong><br>
<strong>You should write your own Makefile to test the code.</strong>

In this assignment, you will be implementing **qsort** algorithm in C.

# Learning Goals
You will learn to
* Reading/Writing from binary file.
* Writing qsort algorithm
* Understanding recursion and Partitioning
* Writing Swap functions for structures

# qsort() funciton
Before doing this homework, you should understand how [`qsort()`](https://linux.die.net/man/3/qsort) function works. Please go to the link and read the explanation. You will be implementing (almost)the same function.

# Functions you need to complete
In this exercise, you have to complete six functions - `StudentQsort()`, `Partition()`, `SwapStudent()`, `Close` in `pa09.c`; `ReadDatabase()`, `WriteDatabase()` in `read_write.c`; and `main()` in `main.c`.

1. `StudentQsort()` -
	This is the basic function which should be called recursively to implement `qsort` for Students DB. The output from this should be in ***Ascending order*** The way to use it is as follows :
	1. Calls the Partition function and get the value of `partition index` (This is basically the final index on which partitioned of array happened - if you don't understand what partition is Please refer to qsort documentation/algorithm details which explains the partition).
	**Note: partition index and pivot are different**
	2. Call the StudentQsort recursively in the following way:
		* First call will be to `StudentQsort`  with range from `startIndex` to `partition index -1`
		* Second call will be to `StudentQsort`  with range from `partition index + 1` to `endIndex`;

	**Please maintain the above order otherwise your output will not match and you will get a 0**

	3. `qsort` is a deterministic function, thus the values that are provided to you in the expected file should match the values of your Implementation of qsort with the same way to partition.
2. `Partition()` -
	1. Use the pivot i.e. the last element to divide the array into three parts: smaller than the pivot,
  equal to the pivot, and greater than the pivot. Please be aware that the first (or the third) part could be empty, if the pivot is the
  smallest (or the largest) element in the array. (if you do not understand pivot then refer to the working of `qsort` algorithm).
	2. **You Should print the value of the pivot on the terminal** i.e. use `PrintStudent` which is provided to you
	3. Swap the elements such that the final array has values smaller than pivot on the left of the pivot(not necessarily sorted) and values greater than pivot (not necessarily sorted) to be on the right of the pivot. Please see FAQ 7. for an example
	4. Return the partition index i.e. index where the pivot will move eventually after Partitioning. Please see FAQ 7. for an example
3. `SwapStudent()` - This should swap the two `Student` structs - Please be very careful about the working of this. As Prof. Lu told in class, there is only **one Swap** function that works.
4. `Close` : This should clear out the memory associated with storing the values of StudentDatbase
5. `WriteDatabase()` - This function writes the info in database to a **binary** file. You will need to use `fwrite()` function. This function has the following features:
	1. filename as argument: the name of the file you are writing to.
	2. studb as argument: studb is pointer to `StudentDatabase` object.
	3. You should return 1 when you successfully write a file. Otherwise, you should return 0.
	4. You should return 0 and print "Fail to open a file\n" when fopen fails and the output file should not be created.
	5. You should use `fwrite` function to write to the file. You should directly write each Student into the file. There should not be anything other than students values written to the file.

	**If the output file written by your WriteDatabase function is not binary and a simple text file, you will not get credit for that, we expect you to learn to read and write from binary files**
6. `ReadDatabase()` : Read the content in the file and allocate appropriate memory to store the content. This function accepts only one argument. Some information about this function:
	1. filename: the binary file from which you are going to read.
	2. You may want to use: `fread` and size of each read is size of Student structure.
	3. This function returns a pointer to a StudentDatabase object.
	4. Please note that in this case you will not be able to use `fgetc`,`fscanf` etc to get the characters. You will have to use `fread` to get the correct values.

	**Do not hardcode the name of the binary files in your code**
7. `main()` - In this exercise, you will learn to use `argc` and `argv`. Here are the specifications.
	1. argc: If argc is not 4, you should return `EXIT_FAILURE` and print "Wrong arguments\n".
	2. argv[1]: name of the input file. i.e., databaseBinary.bin
	3. argv[2]: should be either "-a", or "-n".
		When argv[2] is "-a", you should sort the database by age in ascending order and print the database in a binary file which is argv[3] and return `EXIT_SUCCESS`.
		When argv[2] is "-n", you should sort the database by name in ascending order and print the database in a binary file which is argv[3] and return `EXIT_SUCCESS`.
		For example, Student "Alice" should come before "Bob".
	4. If argv[2] is neither "-a" nor "-n", you should print "Wrong arguments\n" and return `EXIT_FAILURE`.
	5. argv[3]: This is the output filename. You should write the output of database into this file.
	6. print "Write to db\n" if `WriteDatabase()` work. Otherwise, print "Fail to write to db\n"

# Functions Given to you - DO NOT modify these functions.
You might need to call these functions from the `main.c` but you should not modify these functions.

1. `SortDatabaseByName` - This function uses `StudentQsort` function and compare function. Do not modify this function but complete `StudentQsort` properly.
2. `SortDatabaseByAge` - This function also uses `StudentQsort` function and compare function. Do not modify this function but complete `StudentQsort` properly.
3. `PrintStudent` - This function prints the student value to the terminal. You might need to use this function in `Partition` function to print the pivot to the terminal.
4. `CompareByName` and `CompareByAge` - these functions are needed by `SortDatabaseByName` and `SortDatabaseByAge` respectively.


# Testing your code
Following are the files we provide:
1. `pa09.c` - Define your functions in this file. You can use any helper function you need but do not put them in the header file. Do not modify the functions that we have given you.
2. `pa09.h` - Header file, which has definition for the functions and structures you need in this assignment. Do not modify this file.
3. `read_write.c` - Define your functions to read and write from a binary file
4. `main.c` - main file for this assignment.
5. `databaseBinary.bin` - This is the database file which stores all student's info.
6. `smallDbBinary.bin` - This is the smaller database of 30 students. Given to you for debugging/testing purpose
7. `expectedTxt/` - This directory contains expected output of the following commands.
	1. expectedSmallPivotName.txt - ./pa09 smallDbBinary.bin -n sortSmallbyname.bin > expectedSmallPivotName.txt
	2. expectedSmallPivotAge.txt: ./pa09 smallDbBinary.bin -a sortSmallbyage.bin > expectedSmallPivotAge.txt
	3. expectedPivotName.txt : ./pa09 databaseBinary.bin -n sortbyname.bin > expectedPivotName.txt
	4. expectedPivotAge.txt : ./pa09 databaseBinary.bin -a sortbyage.bin > expectedPivotAge.txt
	5. memcheckage.txt - valgrind --tool=memcheck --log-file=memcheckage.txt --leak-check=full --verbose ./pa09 databaseBinary.bin -n sortbyname.bin > expectedPivotAge.txt

	**Please note that the last line of expected files have line "Write to db". This line comes from the print statement of the main function and is present because of redirection of the output of the terminal i.e. using `>`**
8. `expectedBin/` - This directory contains the expected binary output. These binary files are generated by running the following commands
	1. `sortSmallbyage.bin` - ./pa09 smallDbBinary.bin -a sortSmallbyage.bin
	2. `sortSmallbyname.bin` - ./pa09 smallDbBinary.bin -n sortSmallbyname.bin
	3. `sortbyage.bin` - ./pa09 databaseBinary.bin -a sortbyage.bin
	4. `sortbyname.bin` - ./pa09 databaseBinary.bin -n sortbyname.bin
9. `database` - This folder contains more binary input files for testing the code. 
-------
To test your code. You have to first compile it and then run the following command.

Sort the database by age in ascending order and write it to a file.
```
./pa09 databaseBinary.bin -a outputSortAge.bin > outputPivotsAge.txt
```
Sort the database by name in ascending order and write it to a file.
```
./pa09 databaseBinary.bin -n outputSortName.bin > outputPivotsName.txt
```
1. pa09 - This is binary that should get generated
2. databaseBinary.bin - This is the database file which stores all students' information.
3. "-a", "-n" - These are the arguments you should specify. "-a" means to sort the database by age. "-n" means to sort the database by name.
4. outputSort(Age/Name).bin - name of the binary file your are writing to.
5. outputPivots(Age/Name).txt - These are files of expected pivots

# Checking for memory errors
You should also run./pa09 with arguments under valgrind. To do that, you have to use, for example, the following command:
```
valgrind --tool=memcheck --log-file=memcheckage.txt --leak-check=full --verbose ./pa09 databaseBinary.bin -a filename
```
and
```
valgrind --tool=memcheck --log-file=memcheckage.txt --leak-check=full --verbose ./pa09 databaseBinary.bin -n filename
```
Note that you should use other input arguments to extensively test your function. If you follow the instructions and keep the malloc and free functions in the right place, you should not have memory problems in this assignment.


# Submitting Your code
** This is a programming assignment, so you would have to submit the code on Blackboard.**

You have to submit the following file in a <strong>zip</strong> folder on the blackboard:
* `pa09.c` - This file should have `StudentQsort()`, `Partition()`, `SwapStudent()` and `Close` functions completed.
* `read_write.c` - This file should have `ReadDatabase()`, `WriteDatabase()` functions completed
* `main.c` - This file should have `main()` function completed.

The command to create zip file is as follows:
```

zip HW09.zip pa09.c read_write.c main.c

```
<strong>You will not get any credits if the submitted file is not zipped</strong>

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

# FAQ
**1. diff -i -w outputSortAge.bin sortbyage.bin doesn't give right output**

A: `diff` command doesn't work properly on binary file. It does tell there is difference but doesn't tell as explicitly as it does with text file. Please do not use this function to directly compare. Read the binary expected files through a function and then compare.

**2. vi/vim/emacs/sublime/atom sortbyage.bin is showing files to be corrupted. I can't understand the files**

A: `sortbyage.bin` is a binary file. The usual editors will not display them properly. You will have to read the files as binary files.

**3. What is difference between files in expectedTxt and expectedBin?**

A: Files in `expectedTxt` stores the intermediate output of pivots used in `Partition` and `StudentQsort`. The `expectedBin` folder stores the final output of the sorting in the binary format.

**4. Are we suppose to sort in Ascending order or Descending order?**

A: Answers should be in ascending order. Which means that if sorting by age the students with smaller age will comes first and if sorting by name, students with name starting with 'A' comes first compared to one whose name starts with 'B'.
**You will not get marks if your sorting order is reverse**

**5. I am using a function similar to the Connect function from HW04/05/06 and it is not working. What should I do?**

A: Please read README again, you will need to change your function to take input as binary files and store the values directly into a Student structure.

**6. I am using fscanf/fgetc and my code is not working properly.**

A: We expect you to understand `fread` and `fwrite` for this assignment. Please use these functions.

**7. What is the difference between pivot and partition index**

A: Pivot is the value on which you will divide your array. Partition index is the index such that the values on right side of which will be numbers greater than pivot and on left side will be numbers smaller than pivot.
eg. Consider the following

```
array = [1 2 3 11 34 9 23 18 32 21 15]
pivot = array[10] = 15
after Partitioning array will be [1 2 3 11 9 15 23 18 32 21 34] and partition index = 5
i.e. array[5] = 15 (pivot used for Partitioning)

```


# Grading
If your program has any compilation error or warning (remember to use
`gcc -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror`), you will
receive zero in this assignment.

In absolutely no circumstance can the teaching staff modify your
program for grading.  You cannot say, "If you change this, my program
works." If your program misses a semicolon and cannot compile, you
will receive zero.  Your score depends on what is submitted, nothing
else.

This exercise will be graded as follows:
1. `StudentQsort()`: 25 marks
2. `Partition()` : 30 marks
3. `SwapStudent()`: 10 marks
4. `Close()` : 10 marks - If we get errors in Valgrind , this will mean this function is not correct
5. `WriteDatabase()` : 10 marks
6. `ReadDatabase()`: 10 marks
7. `main()` : 5 marks  
