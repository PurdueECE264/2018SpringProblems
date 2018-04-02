# HW12. Josephus problem using LinkedList.
## This is an Assignment, and it is related to HW10 and HW11.

<strong>Please read the entire file before you ask any question.</strong><br>

In this assignment you will solve a problem related to a certain counting-out game (Josephus problem) using linkedlist.

# Learning Goals
* Use linkedlist to solve josephus problem.
* Use and learn doubly linkedlist.

## Jospehus problem
You will be solving jospehus problem in HW10 using linkedlist instead of arrays. The values of the nodes within the linkedlist will be the same as array indices. For example, if the linkedlist is of length is 5, then the values of nodes will be 0,1,2,3,4.

For example, lets assume that we have a linkedlist of length 7, and k=2.

<pre>
0 1 2 3 4 5 6  //start at head (index=0), count 2, 2 will be out.
0 1 3 4 5 6    //index=3, 5 is out
0 1 3 4 6      //index=6, 1 is out
0 3 4 6	       //index=3, 6 is out
0 3 4	       //index=0, 4 is out
0 3	       //index=0, 0 is out
3	       // 3 wins the game
</pre>


## Josephus problem V2 (optional) 50 points
You will solve a modified jospehus problem using doubly linkedlist. The modifiction is that you will count `k` before taking out the  element but if you come across a number that is divisable by `q` while counting, you will take that number out, flip your direction (if you were moving forward you will go backward, vice versa), and keep counting but in the opposite direction.

for example, lets assume that we have a linkedlist of length 10, k=5, and q=4.

<pre>
0 1 2 3 4 5 6 7 8 9 //index=0, 4 is divisable by 4. So, it will be out (count=4),direction flipped.
0 1 2 3 5 6 7 8 9   //count=4, going backward. 3 is out (count=5).
0 1 2 5 6 7 8 9     //index=2, 0 is divisable by 4. So, it will be out (count=2), direction flipped.
1 2 5 6 7 8 9	    //count=2, going forward. 5 is out (count=5)
1 2 6 7 8 9	    //index=6, 8 is divisable by 4. So, it will be out (count=2), direction flipped.
1 2 6 7 9	    //count=2, going backward. 2 is out (count=5)
1 6 7 9		    //index=1, 9 is out (count=5).
1 6 7		    //index=7, 1 is out (count=5).
6 7		    //index=7, 6 is out (count=5).
7		    //7 wins the game

</pre>

Another example, lets assume that we have a linkedlist of length 7, k=2, and q=3.

<pre>
0 1 2 3 4 5 6 //index=0, count 2, 2 will be out.
0 1 3 4 5 6   //index=3 (3 won't be out because you have not reached it while counting; even though it is divisible by 3), 5 is out.
0 1 3 4 6     //index=6 (6 won't be out for the same reason as 3), 0 is divisable by 3 (count=1). Direction flipped.
1 3 4 6       //keep counting but in backward, 6 is out (count=2), also 6 is divisable by 3. Direction flipped.
1 3 4	      //index=1, 3 is out (count=1). Direction flipped.
1 4 	      //keep couting but in backward, 1 is out.
4	      //4 wins the game.
</pre>





# TO DO "Josephus"
<strong>init()</strong> </br>
In this function you will create and intialize a singly linkedlist of length `L`. For example, if the linkedlist has a length 7; the values of the nodes within linkedlist will be `0,1,2,3,4,5,6`.<br>

<strong>josp()</strong>  </br>
In this function you will implement the solution for josephus problem using singly linkedlist. 

<strong>print()</strong> </br>
In this function you will print the values of the nodes within the singly linkedlist if the number of remaining nodes is divisable by `p`. The values will be separated by commas. For example, if the nodes within the linkedlist have the following values `1 3 4 6`, the output should be like this `1,3,4,6`. Please make sure that you don't have an extra comma at the beginning nor at the end. 

# TO DO "Josephus V2" (Optional) 50 points
<strong>init2()</strong> </br>
In this function you will create and intialize a doubly linkedlist of length `L`. For example, if the linkedlist has a length 7; the values of the nodes within linkedlist will be `0,1,2,3,4,5,6`.<br>

<strong>josp2()</strong>  </br>
In this function you will implement the solution for the modified verison of josephus problem using doubly linkedlist. 

<strong>print2()</strong> </br>
In this function you will print the values of the nodes within the doubly linkedlist after any delete operation (caused by value of the node being divisible by 'q' or count=`k`). The values will be separated by commas. For example, if the nodes within the linkedlist have the following values `1 3 4 6`, the output should be like this `1,3,4,6`. Please make sure that you don't have an extra comma at the beginning nor at the end. 

`NOTE: head->prev is NULL as well as tail->next`

# Testing your code
Following are the files we provide:
1. `pa12.c`.
2. `pa12.h`. 
3. `main.c`.

`NOTE:Please follow the printing format you find in the cases .txt files.`<br>
To test your code, we provide you with 10 different cases:<br>
#### Josephus cases
The following command should create and initialize a singly likedlist of length 10, k=3, p=1. `-J` to solve Josephus problem using the created linkedlist. The output of this command is in case1.txt
`./pa12 -J 10 3 1 > case1.txt`<br>

The following command should create and initialize a singly likedlist of length 10, k=4, p=2. `-J` to solve Josephus problem using the created linkedlist. The output of this command is in case2.txt
`./pa12 -J 10 4 2 > case2.txt`<br>

The following command should create and initialize a singly likedlist of length 8, k=5, p=3. `-J` to solve Josephus problem using the created linkedlist. The output of this command is in case3.txt
`./pa12 -J 8 5 3 > case3.txt`<br>

The following command should create and initialize a singly likedlist of length 8, k=9, p=1. `-J` to solve Josephus problem using the created linkedlist. The output of this command is in case4.txt
`./pa12 -J 8 9 1 > case4.txt`<br>

The following command should create and initialize a singly likedlist of length 41, k=3, p=1. `-J` to solve Josephus problem using the created linkedlist. The output of this command is in case5.txt
`./pa12 -J 41 3 1 > case5.txt`<br>

The following command should create and initialize a singly likedlist of length 100, k=3, p=20. `-J` to solve Josephus problem using the created linkedlist. The output of this command is in case6.txt
`./pa12 -J 100 3 20 > case6.txt`<br>

#### Josephus V2 cases

The following command should create and initialize a doubly likedlist of length 8, k=5, q=4. `-J2` to solve the modified Josephus problem using the created doubly linkedlist. The output of this command is in case7.txt
`./pa12 -J2 8 5 4 > case7.txt` <br>

The following command should create and initialize a doubly likedlist of length 15, k=3, q=4. `-J2` to solve the modified Josephus problem using the created doubly linkedlist. The output of this command is in case8.txt
`./pa12 -J2 15 3 4 > case8.txt` <br>

The following command should create and initialize a doubly likedlist of length 8, k=3, q=9. `-J2` to solve the modified Josephus problem using the created doubly linkedlist. The output of this command is in case9.txt
`./pa12 -J2 8 3 9 > case9.txt` <br>

The following command should create and initialize a doubly likedlist of length 20, k=4, q=5. `-J2` to solve the modified Josephus problem using the created doubly linkedlist. The output of this command is in case9.txt
`./pa12 -J2 20 4 5 > case10.txt` <br>


To test your code. You have to first compile it and then run one of the following commands. <br>
`Attention: There is a 10% penalty of your final grade, if you have a memory leak. Also if you don't submit a makefile you will lose 5 points`



Type the following command to zip your file.
```bash
	zip pa12.zip pa12.c main.c Makefile
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


