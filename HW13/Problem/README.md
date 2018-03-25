# Huffman Part 1 (E)

## This is an Exercise
This exercise you will be implementing the first part of Huffman code which requires you to
create sorted frequency table
<strong>Please read the entire file before you ask any question.</strong><br>
<strong>You should write your own Makefile to test the code.</strong>


# Learning Goals
You will learn to
* Starting Huffman code
* Reading from file
* Creating structures


# Functions you need to complete
In this exercise, you have to complete six functions - `CountFrequency()`, `SortFrequency()`, `PrintFreq()` `frequency.c`; `CharFreq` structure in `frequency.h` file; and `main()` in `pe13.c`.
**Do not hardcode the name of the files in your code**
1. `CountFrequency()` - Counts the frequencies of the characters except newline character i.e. '\n' from input file and stores in the frequency array
2. `SortFrequency()` - Sort function for sorting frequencies. Sort the frequencies in the ascending order.
if frequencies are same then the character with lower ascii value should be first.
3. `PrintFreq()` - This should print all the characters and their respective frequencies in the sorted order as mentioned in `SortFrequency()` description.
4. `CharFreq` -  this is the data structure that you need to define in frequency.h file. **This should be the first thing that you should complete**
5. `main()` - In this exercise, you will learn to use `argc` and `argv`. Here are the specifications.
	1. argc: If argc is not 2, you should return `EXIT_FAILURE` and print "Wrong arguments\n".
	2. argv[1]: name of the input file. eg. test1.txt

# Function given to you - DO NOT modify this functions.
You will call the below function to Print character and frequency.

1. `PrintSingleCharFreq` - This function takes `CharFreq` as input and prints the result on terminal. Do not modify this function but use it from `PrintFreq()` function.


# Testing your code
Following are the files we provide:
1. `pe13.c` - main file for this assignment.
2. `frequency.h` - Header file, which has definition for the functions and structures you need in this assignment. Do not modify this file.
3. `frequency.c` - Define your functions in this file. You can use any helper function you need but do not put them in the header file. Do not modify the functions that we have given you.
4. `test/` - folder containing input test files
5. `expected/` - This directory contains the expected output as generalted by the commands shown
	1. `expectedSimple1.txt` - ./pe13 test/simple1.txt > expected/expectedSimple1.txt
	2. `expectedSimple2.txt` - ./pe13 test/simple2.txt > expected/expectedSimple2.txt
	3. `expectedTest1.txt` - ./pe13 test/test1.txt > expected/expectedTest1.txt
	4. `expectedTest2.txt` - ./pe13 test/test2.txt > expected/expectedTest2.txt
  5. `expectedWiki1.txt` - ./pe13 test/test3.txt > expected/expectedWiki1.txt
  6. `expectedWiki2.txt` - ./pe13 test/test1.txt > expected/expectedWiki2.txt
  7. `expectedWiki3.txt` - ./pe13 test/test1.txt > expected/expectedWiki3.txt
  8. `valgrind.log` - valgrind --tool=memcheck --verbose --log-file=valgrind.log ./pe13 test/wiki1.txt > /dev/null


# Checking for memory errors
You should also run./pa13 with arguments under valgrind. To do that, you have to use, for example, the following command:
```
valgrind --tool=memcheck --verbose --log-file=valgrind.log ./pe13 test/wiki1.txt > /dev/null
```

Note that you should use other input arguments to extensively test your function. If you follow the instructions and keep the malloc and free functions in the right place, you should not have memory problems in this assignment.


# Submitting Your code
** This is a programming assignment, so you would have to submit the code on Blackboard.**

You have to submit the following file in a <strong>zip</strong> folder on the blackboard:
* `pe13.c` - This file should have `main()` function completed.
* `frequency.c` - This file should have `CountFrequency()`, `SortFrequency()` and `PrintFreq()` functions completed.
* `frequency.h` - This file should have `CharFreq` structure completed.

The command to create zip file is as follows:
```

zip HW13.zip pe13.c frequency.c frequency.h

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


# Grading
If your program has any compilation error or warning (remember to use
`gcc -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror`), you will
receive zero in this assignment.

In absolutely no circumstance can the teaching staff modify your
program for grading.  You cannot say, "If you change this, my program
works." If your program misses a semicolon and cannot compile, you
will receive zero.  Your score depends on what is submitted, nothing
else.
**The grading test cases will be made available along with the grades**
