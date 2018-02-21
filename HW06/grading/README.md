# HW06 grading policy

## This is how we grade your HW06


Due to a mistake in previous grading program, HW06 was not graded properly.
If your new score is lower than the previously posted score, you will keep the higher score. If the new score is higher, your score will be updated.

Your grade on HW06 is graded as follow:
1. ParseQuery() function (30 points):
	We use your function, compile and run
	```BASH
	./pa06 SELECT id WHERE age ">" 20 AND id "<" 100
	mv output.txt stu_parse.txt
	diff -w -i exp_parse.txt stu_parse.txt &> parse_res.txt
	```
2. ExecuteQuery() function (30 points):
	We use your function, compile and run
	```BASH
	./pa06 SELECT id WHERE age ">" 20 AND id "<" 100 &> stu_execute.txt
    diff -w -i exp_execute.txt stu_execute.txt &> execute_res.txt	
	```

3. WriteDb() function (20 points):
	We ue your function, compile and run
	```BASH
	./pa06 SELECT id enrollment age major name year WHERE age ">" 21 OR id "<" 10
    mv output.txt stu_write.txt
    diff -w -i exp_write.txt stu_write.txt &> write_res.txt
	```
	
4. Correctness of your program (20 points):
The exepcted output of the following commands are named as test1.txt, test2.txt, ...test20.txt
```SQL
	1. SELECT major enrollment WHERE id ">" 199
	2. SELECT enrollment major WHERE id ">" 199
	3. SELECT name WHERE age ">" 20
	4. SELECT name WHERE age ">" 20 AND id "<=" 100
	5. SELECT name WHERE age ">" 20 AND id "<=" 100 AND enrollment "=" Yes
	6. SELECT name WHERE age ">" 20 AND id "<=" 100 AND enrollment "=" Yes AND major "=" ECE
	7. SELECT id enrollment age major name year WHERE id "<" 10
	8. SELECT id enrollment age major name year WHERE id "<" 10 OR major "=" ECE
	9. SELECT id enrollment age major name year WHERE id "<" 10 OR major "=" ECE OR age ">=" 19
	10. SELECT id enrollment age major name year WHERE id "<" 10 OR major "=" ECE OR age ">=" 19 OR enrollment "=" Yes
	11. SELECT id enrollment age major name year WHERE id "<" 10 OR major "=" ECE OR age ">=" 19 OR enrollment "=" Yes OR name = ECE264 
	12. SELECT name WHERE age ">" 20 AND id "<=" 100 AND enrollment "=" Yes AND major "=" ECE AND year "=" Freshman
	13. SELECT name WHERE age ">" 20 AND id "<=" 100 AND enrollment "=" Yes AND major "=" GG AND year "=" Freshman
	14. SELECT year WHERE age "<" 20 AND id ">=" 100 AND enrollment "=" No AND major "=" ECE AND year "=" Freshman
	15. SELECT major WHERE year "=" Sophomore
	16. SELECT id age WHERE major "=" AA OR year "=" Junior
	17. SELECT name year WHERE major "=" IE AND age ">=" 10
	18. SELECT age year name WHERE name "=" Samatar AND year "=" Senior
	19. SELECT id WHERE age "=" 100 OR major "=" ABE
	20. SELECT enrollment WHERE year "=" Freshman

```
5. Memory check using all the queries above.

If there are memory errors, you will be penalized 40% of the total grade.


