# HW05 grading policy

## This is how we grade your HW05

Same as HW04. We use your function in the grading script and only test that function.
For example, if we are testing `SortByDatabaseName()` function. We call your SortByDatabaseName() and check whether it meets the requirements.
```bash
CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
GCC = gcc $(CFLAGS)
OBJ = obj/pe04.o
```
1. Compare functions (40 points): Use your compare functions and run the following commands.
	```bash
		cp pe05.c stu_cpr.c
		cat test_cpr.c >> stu_cpr.c
		$(GCC) stu_cpr.c $(OBJ) -o pe05
		./pe05 > stu_cpr.txt
		diff expected_cpr.txt stu_cpr.txt
	```
	If the output is different, you fail this test. 20 points/function.

2. Sorting functions (20 points): Use your sort functions and run the following commands.
	```bash
		./pe04 database.txt -a > stu_name.txt
		diff -i -w expected_name.txt stu_name.txt
	```
	If the output is different, you fail this test. 10 points/function. 

3. WriteDatabase() function (30 points).  Use your WriteDatabase() function and run the following commands. 
	```bash
		# compile your code with grading scripts.
		$(GCC) pe05.c test_write.c $(OBJ) -o pe05
		./pe05 > stu_write.txt
		diff expected_write_output.txt stu_write.txt # This is to test whether you return 0 and print error message when this function failed.
		diff expected_write_content.txt write_success.txt # This is to test whether your write function works. Your file is named as "write_success.txt" in the testing script.
	```
	15 points for correct return values (includes the error message). 15 points for correct write content. 

4. argc, argv (10 points)
	```bash
		 ./pe05 blablabla -n dbnotexist.txt &>> stu_argc.txt
		 ./pe05 database.txt -k notaorn.txt &>> stu_argc.txt
		 ./pe05 database.txt &>> stu_argc.txt
		 ./pe05 database.txt -a write_fail.txt &>> stu_argc.txt
		 diff expected_argc.txt stu_argc.txt
	```
	If the output is different, you fail this test.

5. Memory check.
	```bash
		valgrind --log-file=stu_mem_1.txt ./pe05 database.txt -n mem_outout.txt
		valgrind --log-file=stu_mem_2.txt ./pe05 database.txt -a write_fail.txt
		valgrind --log-file=stu_mem_3.txt ./pe05 blabla -n dbnotexist.txt
		valgrind --log-file=stu_mem_4.txt ./pe05 database.txt -k notaorn.txt
		valgrind --log-file=stu_mem_5.txt ./pe05 database.txt
	```
	If there are memory errors, you will be penalized 40% of the total grade.

## Contact TA for grading

I noticed that some students used different ways to write the compare functions. Therefore, they passed the sorting functions test but failed compare functions test. If you are losing points in compare functions becasue of this, please contact me.　
