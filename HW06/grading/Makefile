CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
GCC = gcc $(CFLAGS)
VAL = valgrind --tool=memcheck --leak-check=full --verbose
OBJS = $(SRCS:%.c=%.o)

all: testcorrect memcheck

.c.o:
	$(GCC) $(FLAGS) -c $*.c

testcorrect: 
	$(GCC) pa06.c main.c -o pa06 &> test_correct_compile_res.txt
	-timeout 3s ./pa06 SELECT major enrollment WHERE id ">" 199
	-cat output.txt > stu_test1.txt
	-diff -w -i test1.txt stu_test1.txt &> test_res1.txt
	-timeout 3s ./pa06 SELECT enrollment major WHERE id ">" 199
	-cat output.txt > stu_test2.txt
	-diff -w -i test2.txt stu_test2.txt &> test_res2.txt
	-timeout 3s ./pa06 SELECT name WHERE age ">" 20
	-cat output.txt > stu_test3.txt
	-diff -w -i test3.txt stu_test3.txt &> test_res3.txt
	-timeout 3s ./pa06 SELECT name WHERE age ">" 20 AND id "<=" 100
	-cat output.txt > stu_test4.txt
	-diff -w -i test4.txt stu_test4.txt &> test_res4.txt
	-timeout 3s ./pa06 SELECT name WHERE age ">" 20 AND id "<=" 100 AND enrollment "=" Yes
	-cat output.txt > stu_test5.txt
	-diff -w -i test5.txt stu_test5.txt &> test_res5.txt
	-timeout 3s ./pa06 SELECT name WHERE age ">" 20 AND id "<=" 100 AND enrollment "=" Yes AND major "=" ECE
	-cat output.txt > stu_test6.txt
	-diff -w -i test6.txt stu_test6.txt &> test_res6.txt
	-timeout 3s ./pa06 SELECT id enrollment age major name year WHERE id "<" 10
	-cat output.txt > stu_test7.txt
	-diff -w -i test7.txt stu_test7.txt &> test_res7.txt
	-timeout 3s ./pa06 SELECT id enrollment age major name year WHERE id "<" 10 OR major "=" ECE
	-cat output.txt > stu_test8.txt
	-diff -w -i test8.txt stu_test8.txt &> test_res8.txt
	-timeout 3s ./pa06 SELECT id enrollment age major name year WHERE id "<" 10 OR major "=" ECE OR age ">=" 19
	-cat output.txt > stu_test9.txt
	-diff -w -i test9.txt stu_test9.txt &> test_res9.txt
	-timeout 3s ./pa06 SELECT id enrollment age major name year WHERE id "<" 10 OR major "=" ECE OR age ">=" 19 OR enrollment "=" Yes
	-cat output.txt > stu_test10.txt
	-diff -w -i test10.txt stu_test10.txt &> test_res10.txt
	-timeout 3s ./pa06 SELECT id enrollment age major name year WHERE id "<" 10 OR major "=" ECE OR age ">=" 19 OR enrollment "=" Yes OR name = "ECE264"
	-cat output.txt > stu_test11.txt
	-diff -w -i test11.txt stu_test11.txt &> test_res11.txt
	-timeout 3s ./pa06 SELECT name WHERE age ">" 20 AND id "<=" 100 AND enrollment "=" Yes AND major "=" ECE AND year "=" Freshman
	-cat output.txt > stu_test12.txt
	-diff -w -i test12.txt stu_test12.txt &> test_res12.txt
	-timeout 3s ./pa06 SELECT name WHERE age ">" 20 AND id "<=" 100 AND enrollment "=" Yes AND major "=" GG AND year "=" Freshman
	-cat output.txt > stu_test13.txt
	-diff -w -i test13.txt stu_test13.txt &> test_res13.txt
	-timeout 3s ./pa06 SELECT year WHERE age "<" 20 AND id ">=" 100 AND enrollment "=" No AND major "=" ECE AND year "=" Freshman
	-cat output.txt > stu_test14.txt
	-diff -w -i test14.txt stu_test14.txt &> test_res14.txt
	-timeout 3s ./pa06 SELECT major WHERE year "=" Sophomore
	-cat output.txt > stu_test15.txt
	-diff -w -i test15.txt stu_test15.txt &> test_res15.txt
	-timeout 3s ./pa06 SELECT id age WHERE major "=" AA OR year "=" Junior
	-cat output.txt > stu_test16.txt
	-diff -w -i test16.txt stu_test16.txt &> test_res16.txt
	-timeout 3s ./pa06 SELECT name year WHERE major "=" IE AND age ">=" 10
	-cat output.txt > stu_test17.txt
	-diff -w -i test17.txt stu_test17.txt &> test_res17.txt
	-timeout 3s ./pa06 SELECT age year name WHERE name "=" Samatar AND year "=" Senior
	-cat output.txt > stu_test18.txt
	-diff -w -i test18.txt stu_test18.txt &> test_res18.txt
	-timeout 3s ./pa06 SELECT id WHERE age "=" 100 OR major "=" ABE
	-cat output.txt > stu_test19.txt
	-diff -w -i test19.txt stu_test19.txt &> test_res19.txt
	-timeout 3s ./pa06 SELECT enrollment WHERE year "=" Freshman
	-cat output.txt > stu_test20.txt
	-diff -w -i test20.txt stu_test20.txt &> test_res20.txt


memcheck:
	$(GCC) pa06.c main.c -o pa06 &> memcheck_compile_res.txt
	-timeout 3s valgrind --log-file=stu_mem_1.txt ./pa06 SELECT major enrollment WHERE id ">" 199
	-timeout 3s valgrind --log-file=stu_mem_2.txt ./pa06 SELECT enrollment major WHERE id ">" 199
	-timeout 3s valgrind --log-file=stu_mem_3.txt ./pa06 SELECT name WHERE age ">" 20
	-timeout 3s valgrind --log-file=stu_mem_4.txt ./pa06 SELECT name WHERE age ">" 20 AND id "<=" 100
	-timeout 3s valgrind --log-file=stu_mem_5.txt ./pa06 SELECT name WHERE age ">" 20 AND id "<=" 100 AND enrollment "=" Yes
	-timeout 3s valgrind --log-file=stu_mem_6.txt ./pa06 SELECT name WHERE age ">" 20 AND id "<=" 100 AND enrollment "=" Yes AND major "=" ECE
	-timeout 3s valgrind --log-file=stu_mem_7.txt ./pa06 SELECT id enrollment age major name year WHERE id "<" 10
	-timeout 3s valgrind --log-file=stu_mem_8.txt ./pa06 SELECT id enrollment age major name year WHERE id "<" 10 OR major "=" ECE
	-timeout 3s valgrind --log-file=stu_mem_9.txt ./pa06 SELECT id enrollment age major name year WHERE id "<" 10 OR major "=" ECE OR age ">=" 19
	-timeout 3s valgrind --log-file=stu_mem_10.txt ./pa06 SELECT id enrollment age major name year WHERE id "<" 10 OR major "=" ECE OR age ">=" 19 OR enrollment "=" Yes
	-timeout 3s valgrind --log-file=stu_mem_11.txt ./pa06 SELECT id enrollment age major name year WHERE id "<" 10 OR major "=" ECE OR age ">=" 19 OR enrollment "=" Yes OR name = "ECE264" 
	-timeout 3s valgrind --log-file=stu_mem_12.txt ./pa06 SELECT name WHERE age ">" 20 AND id "<=" 100 AND enrollment "=" Yes AND major "=" ECE AND year "=" Freshman
	-timeout 3s valgrind --log-file=stu_mem_13.txt ./pa06 SELECT name WHERE age ">" 20 AND id "<=" 100 AND enrollment "=" Yes AND major "=" GG AND year "=" Freshman
	-timeout 3s valgrind --log-file=stu_mem_14.txt ./pa06 SELECT year WHERE age "<" 20 AND id ">=" 100 AND enrollment "=" No AND major "=" ECE AND year "=" Freshman 
	-timeout 3s valgrind --log-file=stu_mem_15.txt ./pa06 SELECT major WHERE year "=" Sophomore 
	-timeout 3s valgrind --log-file=stu_mem_16.txt ./pa06 SELECT id age WHERE major "=" AA OR year "=" Junior 
	-timeout 3s valgrind --log-file=stu_mem_17.txt ./pa06 SELECT name year WHERE major "=" IE AND age ">=" 10 
	-timeout 3s valgrind --log-file=stu_mem_18.txt ./pa06 SELECT age year name WHERE name "=" Samatar AND year "=" Senior 
	-timeout 3s valgrind --log-file=stu_mem_19.txt ./pa06 SELECT id WHERE age "=" 100 OR major "=" ABE
	-timeout 3s valgrind --log-file=stu_mem_20.txt ./pa06 SELECT enrollment WHERE year "=" Freshman

clean:
	/bin/rm -f input*
	/bin/rm -f *.o
	/bin/rm -f *.gcda *.gcno gmon.out *gcov
	/bin/rm -f pa06
	#/bin/rm -f *.txt
