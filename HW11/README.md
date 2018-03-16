# HW11. Linkedlist
## This is an Exercise, and it is related to HW10 and HW12.

<strong>Please read the entire file before you start working on this exercise.</strong><br>

In this Exercise you will build your own linkedlist data structure. Also, you will be implementing linkedlist operations.
 

## Learning Goals
* Understand linkedlist.
* Deepen your understanding of pointers and memory addresses.
* Deepen your understanding of memory allocation and deallocation.


## LinkedList
 Linked list is a data structure consisting of a group of nodes which together represent a sequence or a chain. Each node has a link or a pointer to the next node in the chain except for the last node (tail) in the linkedlist which is pointing at NULL. The first node in the linkedlist is the head node.
 
 Why linkedlist?
 - Nodes don't have to be stored in contiguous memory locations.
 - The allocation is dynamic not static. The size of the linkedlist can be changed during the running time of the program (the size is not required to be known in advance).
 - insertion at (or deletion from) any position in constant time.

## TO DO
Mainly you have to work on impelementing four main operations:
 * Insert nodes to the linkedlist. </br>
 * Delete node from the linkedlist. </br>
 * Traverese the linkedlist to compute its length. </br>
 * Allocate memory for the nodes within the linkedlist, and deallocate nodes from memory. </br></br>
 
### Insertion of nodes
For this part you have to implement three functions:<br><br>
`insertFirst()`- In this function you will insert node n to the head of the linkedlist. For example, if the linkedlist has 3 nodes A, B, and C. And you want to `insertFirst()` node D. The linkedlist after insertion should look like this D, A, B, C. <br>

`insertLast()`- In this function you will insert node n to the tail of the linkedlist. For example, if the linkedlist has 3 nodes A, B, and C. And you want to `insertLast()` node D. The linkedlist after insertion should look like this A, B, C, D.<br>

`insertAt()`- In this function you will insert node n at index i in the linkedlist if possible. For example, if the linkedlist has 3 nodes A, B, and C. And you want to insert node D at index=0. The linkedlist after insertion should look like this D, A, B, C. Another example, if the linkedlist has 3 nodes A, B, and C. And you want to insert node D at index=3. The linkedlist after insertion should look like this A, B, C, D. But, if the linkedlist has 3 nodes A, B, and C. And you want to insert node D at index=4. It is not possible. So,  the linkedlist will not change and it will look like this A, B, C.<br>

`Note: we access the linkedlist as array, the first index is index=0 which is the head of the linkedlist.`<br><br>

### Deletion of nodes
For this part you have to implement three functions:<br><br>
`deleteFirstMatch()`- In this function you will delete the first node n that has value equals to v. If none of the nodes have a value equals to v, there will be no change made on the linkedlist. For example, if the linkedlist has 3 nodes A(3), B(2), and C(3). And you want to `deleteFirstMatch()` with value equals to 3. The linkedlist after deletion should look like this B(2), C(3). <br>

`deleteAllMatches()`- In this function you will delete the all nodes which have a value equals to v. If none of the nodes have a value equals to v, there will be no change made on the linkedlist. For example, if the linkedlist has 3 nodes A(3), B(2), and C(3). And you want to `deleteAllMatches()` with value equals to 3. The linkedlist after deletion should look like this B(2). <br>

`deleteAt()`- In this function you will delete the node at index i if possible. For example, if the linkedlist has 3 nodes A(3), B(2), and C(3). And you want to `deleteAt()` with index=0. The linkedlist after deletion should look like this B(2), C(3). Another example, if the linkedlist has 3 nodes A(3), B(2), and C(3). And you want to `deleteAt()` with index=3. It is not possible. So,  the linkedlist will not change and it will look like this A(3), B(2), C(3).<br><br>

### Length of the linkedList
For this part you have to implement one function:<br><br>
`getLength()`- In this function you will traverse the linkedlist to count the number of nodes, and return it. For example, if the linkedlist has 3 nodes A(3), B(2), C(3), and D(5). And you want to `getLength()`. The function will return 4.<br><br>

### Deallocation of linkedlist
For this part you have to implement one function:<br><br>
`freeMemory()`- In this function you will deallocate the linkedlist from memory.<br><br>

### Printing linkedlist
For this part you have to implement one function:<br><br>
`print()`- In this function you will print the content of the linkedlist. For example, if the linkedlist has 3 nodes A(3), B(2), C(3), and D(5). Calling `print()` will output `3,2,3,5`. Note that there is no extra comma at the beginning nor at the end. <br>

`Note: If the linkedlist is empty you have to print an empty line '\n' `


# Testing your code
Following are the files we provide:
1. `pe11.c` This file has all the functions to be implemented.
2. `pe11.h`
3. `main.c`This file has the main() function to be implemented.

### Commands
`insF v` - This command means you have to insert a node n at the head of the linkedlist with value v. For example, If the linkedlist has 2, and 3. After `insF 11`, the linkedlist should look like this 11, 2, 3. (`insertFirst()`)<br>

`insL v` - This command means you have to insert a node n at the tail of the linkedlist with value v. For example, If the linkedlist has 2, and 3. After `insL 11`, the linkedlist should look like this 2, 3, 11. (`insertLast()`)<br>

`insA v i` - This command means you have to insert a node n with value v at the index i. For example, If the linkedlist has 2, and 3. After `insA 11 1`, the linkedlist should look like this 2, 11, 3. (`insertAt()`)<br>

`delFM v` - This command means you have to delete the first node with value v. For example, If the linkedlist has 2, 3, 2. After `delFM 2`, the linkedlist should look like this 3, 2. (`deleteFirstMatch()`)<br>

`delAM v` - This command means you have to delete all nodes with value v. For example, If the linkedlist has 2, 3, 2. After `delAM 2`, the linkedlist should look like this 3. (`deleteAllMatches()`)<br>

`delA i` - This command means you have to delete the node at index i. For example, If the linkedlist has 2, 3, 2. After `delA 1`, the linkedlist should look like this 2, 2. (`deleteAt()`)<br>

`L ` - This command means you have to print the length of the linkedlist. For example, If the linkedlist has 2, 3, 2. After `L `, you should print 3. (`getLength()`)<br>

`Note: After each command you have to call print() function except for "L ". If the linkedlist is empty you should print a new line` <br>

`Hint: you can use fgets() for reading commands from test files (command per line), and strtok() for parsing the command by spaces` <br>


`NOTE:Please follow the printing format you find in the cases .txt files.`<br>
To test your code, we provide you with 3 different tese cases:<br>

The following command will use the commands in the test1.txt, and operate the linkedlist as the commands suggest. The output is in outTest1.txt
`./pe10 test1.txt`<br>

The following command will use the commands in the test2.txt, and operate the linkedlist as the commands suggest. The output is in outTest2.txt
`./pe10 test2.txt`<br>

The following command will use the commands in the test3.txt, and operate the linkedlist as the commands suggest. The output is in outTest3.txt
`./pe10 test3.txt`<br>


`Attention: There is a 15% penalty of your final grade, if you have a memory leak. Also if you don't submit a makefile you will lose 5 points`

Type the following command to zip your file.
```bash
	zip pe11.zip pe11.c main.c Makefile
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


