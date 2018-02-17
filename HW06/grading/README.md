# HW06 grading policy

## This is how we grade your HW06


Your grade on HW06 is propotional to the number of test case you pass.
There are 20 testcases in toal. 5 point/testcase.

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
2. Memory check using all the queries above.

If there are memory errors, you will be penalized 40% of the total grade.


