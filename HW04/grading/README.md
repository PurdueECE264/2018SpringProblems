# HW04 grading policy

## This is how we grade your HW04

We use your function in the grading script and only test that function.
For example, if we are testing `Connect()` function. We call your Connect() and check whether it meets the requirements.

1. Structure (5 points): Use the structure you define in pe04.h and run the following commands.
```bash
	./pe04 database.txt -a > student_struct.txt
	diff -i -w expected_struct.txt student_structure.txt
```
If the output is different, you fail this test.<br>
2. Connect() function (60 points).  Use your Connect() function and run the following commands.
```bash
	./pe04 database.txt -a > student_con.txt
	diff -i -w expected_con.txt student_connect.txt
```
If the output is different, you fail this test.<br>
3. Close() function (15 points).  Use your Close() function and run the following commands. 
```bash
	valgrind --log-file=student_close.txt ./pe04 database.txt -a
```
If there are memory errors, your Close() function fail. <br>

4. Search() function (10 points). Use your Search() function and run the following commands. 
```bash
	NAMES = Azeriah Remick Ken Ezreal Aarvi Nataley Tai Joe Apple Daeson
    	for n in $(NAMES); do ./pe04 $(FILE) -s $$n; done &> student_search.txt
	diff -i -w student_search.txt expected_search.txt
```
If the output is different, you fail this test.<br>
5. argc, argv (10 points)
```bash
	./pe04 &>> student_argc.txt
	./pe04 database.txt -s &>> student_argc.txt
	./pe04 database.txt -k &>> student_argc.txt
	diff -i -w expected_argc.txt student_argc.txt
```
If the output is different, you fail this test.<br>

6. Memory check.
```bash
	./pe04 --log-file=student_memeory.txt -a
```
If there are memory errors, you will be penalized 40% of the total grade.


## Contact TA for grading

1. Many students claimed they created their testcase and did not find any errors. However, I found that <strong>their outputs were different to the expected output</strong>. A common mistake is that the field of Enrollment and field of Year are wrong and they did not find it. Please double check whether your output is same as the expected output before you send an email to me.  
<br>

2. The homework submission instrucitons is not clear this time. If you are getting 0 becasue of submission file issue, please send an email to me. 
Normally, this is what we expect you to do for submission.
Firs type
```bash
	zip target.zip pe04.c pe04.h main.c
```
Then submit the target.zip to blackboard. If you are not submitting in this way and get 0 in HW04, please send an email to me. This is my email: wu784@purdue.edu. I will regrade the homework only for students who have this issue. 



