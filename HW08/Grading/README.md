# HW08 grading policy

`- If you did not submit makefile, you will lose 15% of your grade.` <br>
`- If you did not submit main.c, you will get zero` <br>
`- If you did not use the proper flags (i.e forgetting to use -Werror) while compiling may lead to compile error. Regrade is not possible for such cases`

## createDouble() function (100 points)
- To test this function we used five commands (20 each) which are : 
<pre>
./pa08 -D 1 9 3 | sort >stest1.txt  #right output in test1
./pa08 -D 1 1 20 | sort>stest2.txt  #right output in test2
./pa08 -D 5 6 7 | sort >stest3.txt  #right output in test3
./pa08 -D 7 9 6 | sort >stest4.txt  #right output in test4
./pa08 -D 4 8 5 | sort >stest5.txt  #right output in test5
</pre>

The grade for each command is calculated as following : (20 - 20\*(The number of different lines between your output and the right output, divided by the number of lines in the right output)). For example, `./pa08 -D 1 9 3 | sort >stest1.txt` has 81 lines, if the number of different lines is 10; your grade will be ( 20-(10/81)\*20) = 17.5 out of 20. 


	
## createVID() function (50 points)
- To test this function we used three commands which are : 
<pre>
./pa08 -VID a a B B 3 3 4 | sort > svtest1.txt #(20 points) #right output in vtest1
./pa08 -VID a z A Z 1 9 1 | sort > svtest2.txt #(10 points) #right output in vtest2
./pa08 -VID g h M N 5 6 3 | sort > svtest3.txt #(20 points) #right output in vtest3
</pre>

The grade for each command is calculated similar to the createDouble() function.

# Testing your code

To test your code you have two options: <br>
1- run each command and `diff`. <br>
2- run the following command in the grading directory `python p.py`, which will create `yourGrade.txt` file that has detailed explanation of your grade. But you need to deduct 2 points per hour late yourself.



