# HW10. Josephus problem using array.
## This is an Exercise, and it is related to HW11 and HW12.

<strong>Please read the entire file before you ask any question.</strong><br>

In this Exercise you will solve a problem related to a certain counting-out game (Josephus problem).
https://www.youtube.com/watch?v=uCsD3ZGzMgE
 

# Learning Goals
* Solve Josephus problem.
* Understand permutation.
* Deepen your understanding of the use of loops.

## Josephus problem
 Josephus Problem (or Josephus permutation) has the following problem statement:
 
There are n elements in a array to be counted out (one element per step). The counting out begins at index=0 and proceeds through the array in a fixed direction. In each step, a certain number of elements are skipped and the next element is eliminated. When reaching the end of the array, the process wraps around to the beginning of the array. This proceeds through the array (which is becoming smaller and smaller as elements are counted out), until one last element remains (wins the game). Given the total number of elements n and a number k which indicates that k-1 elements are skipped and kth element is out.

`Note: when element is removed, you will start again from the next element that succeeds the removed one.`

For example, let assume that the array size(n) is 6, and k=2. <br>
`Note: ruled out numbers will be marked by (X)`
<pre>
0 1 2 3 4 5 // at the begining, start from index=0, counting k, you will stop at 2, then 2 will be out.
0 1 X 3 4 5 // after counting out number 2, the next index to start from will be index=3. Then, you will stop at 5, the 5 will be out.
0 1 X 3 4 X // index=0, next element to be out is 3
0 1 X X 4 X // index=4, next element to be out is 1.
0 X X X 4 X // index=4, next element to be out is 4.
0 X X X X X // 0 wins.
</pre>

`Note: k can be greater than n`

For example, let assume that the array size(n) is 6, and k=7.<br> 
`Note:ruled out numbers will be marked by (X)`
<pre>
0 1 2 3 4 5 // index=0, counting k, you will stop at 1, then 1 will be out.
0 X 2 3 4 5 // index=2, counting k, you will stop at 4, the 4 will be out.
0 X 2 3 X 5 // index=5, next element to be out is 3.
0 X 2 X X 5 // index=5, next element to be out is 0.
X X 2 X X 5 // index=2, next element to be out is 5.
X X 2 X X X // 2 wins.
</pre>

`Note: n and k both have to be greater than one.`


# TO DO
<strong>josephus()</strong> </br>
In this function you will implement the solution for Josephus problem. To do so, you will be using a boolean array that you have to initialize to 1's (true) beforehand. Based on the value of `k`, the values of the array will start flipping to 0's (false). The function should stop iterating when the array has only one value as 1 (true) left. Also, whenever the number of remaining elements (number of 1's) is divisible by `p` you should print out the array as will be shown next (call print() function).</br>

<strong>print()</strong>  </br>
This function will print the boolean array in the following format: <br>
* Print the index if its corresponding value in the array is true, Otherwise print X instead. For instance, If the array is of length
   4, and it has values of true(index=0),false(index=1),true(index=2),false(index=3).<br> // the output should look like this: `0,X,2,X`  </br>
* There should be no extra comma at the end nor at the beginning. For example, `,0,X,2,X` or `0,X,2,X,` formats are both wrong. </br>
* Make sure that there is a new line at the end of the output.

`NOTE: Violating this format will get you zero for this function`

# Testing your code
Following are the files we provide:
1. `pe10.c` This file should have josephus() and print() functions implemented.
2. `pe10.h` 
3. `main.c`This file should have the main() function implemented.

`NOTE:Please follow the printing format you find in the cases .txt files.`<br>
To test your code, we provide you with 6 different cases:<br>

The following command should create a boolean array of length 10, k=3, p=1. The output of this command is in case1.txt
`./pe10 10 3 1 > case1.txt`<br>

The following command should create a boolean array of length 10, k=4, p=2. The output of this command is in case2.txt
`./pe10 10 4 2 > case2.txt`<br>

The following command should create a boolean array of length 8, k=5, p=3. The output of this command is in case3.txt
`./pe10 8 5 3  > case3.txt`<br>

The following command should create a boolean array of length 8, k=9, p=1. The output of this command is in case4.txt
`./pe10 8 9 1  > case4.txt`<br>

The following command should create a boolean array of length 41, k=3, p=1. The output of this command is in case5.txt
`./pe10 41 3 1 > case5.txt`<br>

The following command should create a boolean array of length 100, k=3, p=20. The output of this command is in case6.txt
`./pe10 100 3 20 > case6.txt`<br>


To test your code. You have to first compile it and then run one of the following commands. <br>

`Note: There is a 15% penalty of your final grade, if you do not submit a Makefile. Also, your makefile should create "pe10" output file. Your makefile will be tested if it creates an output file with name "pe10". "pe10.o" or "main.o" are not acceptable as output file name`

Type the following command to zip your file.
```bash
	zip pe10.zip pe10.c main.c Makefile
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



**All Test cases will be released later.


