
# HW10 grading policy
<strong>  &nbsp; &nbsp; &nbsp;   &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;  &nbsp;  &nbsp; \*\*\*ATTENTION : Read it to the last line before sending any email\*\*\* </strong> </br> <br>
`- If you did not submit a functional makefile (produce executable "output file" called pe10), you will lose 15% of your grade.` <br>
`- If you did not submit main.c, you will get zero` <br>
`- If you did not use the proper flags (i.e forgetting to use -Werror -Wvla) while compiling may lead to compile error. Regrade is not possible for such cases`
`- If you print a new line in josephus() not in print as mentioned in the instruction this will lead to extra line for each print, you may lose points because of it`

## print() function (10 points)
- To test your function we compiled your code with -DJOSEPHUS flag. Your print() function with our josephus() solution in pe10.obj2.</br>
The command used for compiling is : </br>
`gcc -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror -DJOSEPHUS pe10.obj2 main.c pe10.c -o pe10`</br>
Then run the following command:</br>
`./pe10 10 2 1 > sptest.txt`</br>
- The correct output of this case is in `ptest`, your answer in `sptest.txt`, you can `diff` to find the error if there is any.</br>
- To calculate your grade: count the number of different lines (x). your grade=10-(x/n)\*10, where n is the number of lines in the correct output file ( 9 lines for print case). </br>

	
## Josephus() function (90 points)
- To test your function we compiled your code with -DPRINT flag. Your josephus() function with our print() solution in pe10.obj1.</br>
The command used for compiling is : </br>
`gcc -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror -DPRINT pe10.obj1 main.c pe10.c -o pe10` </br>
The test cases for josephus can be found in `tests`, there are 6 cases. 
- To calculate your grade for each case: count the number of different lines (x). your grade=15-(x/n)\*15, where n is the number of lines in the correct output file. </br>



# Testing your code

To test your code you have two options: <br>
1- run each command and `diff`. <br>
2- <strong>run the following command in the grading directory `python p.py`, which will create `Grade.txt` file that has detailed explanation of your grade. But you need to deduct 2 points per hour late yourself, and check if your makefile is working probably. <strong>



