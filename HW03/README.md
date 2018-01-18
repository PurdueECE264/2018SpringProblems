# Clustering Data

## This is a programming assignment. A programming assignment is worth four times of points of an exercise.

*Please read the entire file before you ask any question.*


Learning Goals
==============

You will learn to
* Understand the k-mean algorithm and implement it in C.
* Implement memory management in C
* Understand working with valgrind - a simple tool for checking memory
* Write a test generator for creating test cases.
* Develop a strategy for debugging.


Learning Valgrind
-----------------
An important part of mastering C is working with memory allocations and deallocations. We all make mistakes when we code, sometimes even the best 
software programers make mistake of not freeing the memory. But they always check their code before they submit. One of the tool to help you
check the memory management of a C program is valgrind. 

If you have compeleted your HW02, you can try to run `valgrind` on the binary to see its working:

```
  valgrind --tool=memcheck --leak-check=full ./pe02 test1.txt 2 output1.txt
```

You will see lot of output. But important thing is to look for line:
```
  ERROR SUMMARY: 0 errors from 0 contexts
```
If you get this line, then you don't have any memory leaks and probably shouldn't worry. But if you get erros, 
that means there are possible leaks and the tool tell you where you can look for possible errors. 
There are may tutorials that you can search online for
it, one such is [valgrind's](http://valgrind.org/docs/manual/manual-core.html#manual-core.started) 
own documentation. You can search more if you don't find it useful for you.

Functions you need to complete
---------------------------------
This is the last part of your assignment for the K-means algorithm. In this part you have to complete 
three functions - `kmeans`, `allocateMemory` & `releaseMemory`. 
All these functions needs to be implemented in `pa03.c` file. Skeletons of these functions are given to you in the pa03.c file.

Note:

**Please use the initialized centroids value only, do not initialize the centroids yourself.**


Following are the fuctions that you have to complete:

1. `kmean` - This function is the main function as it implements the algorithm for K-means. This function accepts the following arguments : 
  * kval: the number of clusters
  * nval: the number of data pointers
  * dim: dimension of the data
  * data: two-dimensional array of the data, nval rows, dim columns
  * centroid: two-dimensional array of the data, kval rows, dim columns
  * cluster: one-dimensional array of n elements, the assignments of data to the clusters. cluster[i] = j means the i-th data pointer is 
    assigned to the j-th cluster. 0 <= i < nval; 0 <= j < kval
2. `allocateMemory` - This function allocates memory for the 2D array data and then return that data. It accepts the following arguments:
  * nrow: number of rows for which memory is to be allocated
  * ncol: number of columns for which memory needs to be allocated
  * **A word of caution**: Please do not use `x` & `y` for allocating or working with 2D arrays. The memory allocated in a 2D array is in such a way that
  the columns represents `x` and rows represents `y`, leads to errors. Instead use `rows` and `columns` as identifier, it keeps the code clean and understandable. 
3. `releaseMemory` - This function releases the memory of the data. 
  Not completing this function will lead to memory leak. This functions has two arguments:
  * data: the pointer to data whose memory needs to be freed
  * nrow: number of rows that needs to be freed


Generating testcases
---------------------------------
Please follow the same steps as in HW02 for Generating testcases for this assignment too. 
You can also use TestGenerator that is being provided to you.

Testing your code
---------------------------------
Please do not delete the obj folder, it contains the `dist2.o` file which has `distance2` function and `closest_centroid.o` file which has `closestCentroid` function. It is given to you for Homework 3, if you were not able to complete in HW02. If you delete it then your code will not compile.

Following are the files that you will see with the code:
1. pa03.c - main file for this assignment
2. pa03.h - header file, which has definition for `kmean` and `closestCentroid` function. Please do not modify it.
3. Makefile - this is the make file for the assignment. It also has code to test your code for the provided testcases.
4. obj/dist2.o - this is the object file, please do not delete it. This object file is generated using a Linux machine
in ECN (i.e., ecegrid).  If you use another other machine, it may not work.
5. obj/closest_centroid.o - this is another object file has implementation of closestCentroid function. This object file is generated using a Linux machine in ECN (i.e., ecegrid).  If you use another other machine, it may not work. 
6. test(x).txt - these are some of the generated test cases for you. First line of test1.txt will have number of data points that are in the file. Second line will have dimension of the data point. From 3rd line the data points will start. Please do not modify this file.
7. expected(x).txt - these are the expected output for the test cases given to you.

To test your code. You have to first compile it and the run the following command.

```
./pa03 test1.txt 6 output1.txt
```
1. `pa03` - This is binary that should have generated after compilation
2. `test1.txt` - this is the input file which contains data points for which K mean algorithm needs to run
3. `6` - this is the value of `K`, this should be same as what used which generating test1.txt file
4. `output1.txt` - this is the name of the file in which output of your algorithm will be written. This will contain the centroids found by the algorithm. You can give any name to it.


Getting different answer?
---------
Your answer may be different from ours due to several reasons. First,
you may use a different seed for the random number generator; as a
result, the initial locations of the centroids are different. Also,
floating points have finite precision; thus, the computation results
may depend on the order of calculation.  You need to think carefully
about whether your program is correct if the results are different
from the sample outputs given by the teaching staff


Submitting Your code
--------
**This is a programming assignment, so you would have to submit the code on Blackboard**

You have to submit the zip file containing `pa03.c` on the blackboard: 
* `pa03.c` - this file should have with `kmean`, `allocateMemory` and `releaseMemory` function completed.  

To create zip file on terminal, you can use the `zip` command in the following way:
```
 zip <filename>.zip pa03.c
```
To know the location/path of the folder that you are in, you can use `pwd` on terminal
```
pwd
```

Following commands will be helpful if you are using remote terminal and want to copy code to your local machine:

To copy code from a remote machine to your local machine:
* Open terminal in your local machine
* `cd` to the folder in your local machine to which you want to copy the file
* Use `scp` command to get the file to your local machine. See below for details
```
scp username@<remote machine>:<path to the file>/filename .
```

This copies the file to your current folder. eg. if I am working on a remote machine at ecegrid-thin1.ecn.purdue.edu, 
and my file is `pa03.c` at the location /home/min/a/abc/2018Spring/, then I will use the following command :

```
scp abc@ecegrid-thin1.ecn.purdue.edu:/home/min/a/abc/2018Spring/pa03.c .
```
Please note that end of the command has `.`. This in linux commands refers to present folder.

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

k-mean Algorithm
----------------
This algorithm was already discussed in HW02, in this we will be implementing it.
We are giving it again here for your reference.
This assignment uses the *k-mean clustering* algorithm.  This
algorithm works in the following way:

1. Read the data and the given value k
2. Pick k points (called *centroids*) randomly as the initial centers
of the k groups
3. For each data point, find the closet centroid. Assign this data point to the group represented by this centroid.
4. For each group, recompute the location of the centroid as the center of all data points belonging to this group.
5. Repeat steps 3 and 4 until the convergence condition is met.

This algorithm has many different interpretations. First, it does not
specify how to calculate the distance between a data point and a
centroid.  The data is likely high-dimensional.  The most common
definition is the *Euclidean distance* but other definitions may be
adopted.  Also, the convergence condition can be (a) when no data
point changes to another group, (b) when steps 3-4 have executed a
fixed number of iterations (say 1,000), or (c) something else.

This assignment uses the Euclidean distance and convergence condition
(a).

You can assume that all data points fall within [-1000000, 1000000] in
   each dimension. You should initilize centroids within this range.


Grading
-------

If your program has any compilation error or warning (remember to use
`gcc -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror`), you will
receive zero in this assignment.

If your program gives memory leaks i.e. fails valgrind test, 
we will deduct marks. Remember to always free the memory you have allocated. This
is an important trait of a good C programmer.

In absolutely no circumstance can the teaching staff modify your
program for grading.  You cannot say, "If you change this, my program
works." If your program misses a semicolon and cannot compile, you
will receive zero.  Your score depends on what is submitted, nothing
else.  

This assignment has given you many test cases.  It is possible (and
likely) that additional test cases will be used for grading.  If your
program passes  some test cases and
fails the others, the score will be proportional to the number of
passed test cases.


Comment Your Code
-----------------

ECE 264 does not grade your comments because you *should* write
comments for your own benefits.  You do many things (such as eating
dinner or exercise) even though you receive no point from any course.
Writing comments is the same. You need to do it because it is good for
you.

