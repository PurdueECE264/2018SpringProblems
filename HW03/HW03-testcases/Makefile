CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
GCC = gcc $(CFLAGS) 

SRCS = pa03.c
OBJFILE = obj/closest_centroid.o  obj/dist2.o
OBJS = $(SRCS:%.c=%.o)

VALGRIND = valgrind --tool=memcheck --leak-check=full --error-exitcode=3

all: pa03 testcase

pa03:$(OBJS)
	$(GCC) $(OBJS) $(OBJFILE) -o pa03

.c.o:
	$(GCC) $(FLAGS) -c $*.c

testcase: test1 test2 test3 test4 test5 test6 test7 test8 test9 test10 test11 test12 test13 test14 test15 test16 test17 test18 test19


test1: pa03
	timeout 15s ./pa03 test1.txt 2 tmp.txt 1000
	sort -n tmp.txt > output1.txt
	diff output1.txt expected1.txt

test2: pa03
	timeout 15s ./pa03 test2.txt 3 tmp.txt 1000
	sort -n tmp.txt > output2.txt
	diff output2.txt expected2.txt

test3: pa03
	timeout 15s ./pa03 test3.txt 3 tmp.txt 1000
	sort -n tmp.txt > output3.txt
	diff output3.txt expected3.txt

test4: pa03
	timeout 15s ./pa03 test4.txt 4 tmp.txt 1000
	sort -n tmp.txt > output4.txt
	diff output4.txt expected4.txt

test5: pa03
	timeout 15s ./pa03 test5.txt 6 tmp.txt 1000
	sort -n tmp.txt > output5.txt
	diff output5.txt expected5.txt

test6: pa03
	timeout 15s ./pa03 test6.txt 6 tmp.txt 1000
	sort -n tmp.txt > output6.txt
	diff output6.txt expected6.txt

test7: pa03
	timeout 15s ./pa03 test7.txt 5 tmp.txt 1000
	sort -n tmp.txt > output7.txt
	diff output7.txt expected7.txt

test8: pa03
	timeout 15s ./pa03 test8.txt 4 tmp.txt 1000
	sort -n tmp.txt > output8.txt
	diff output8.txt expected8.txt

test9: pa03
	timeout 15s ./pa03 test9.txt 2 tmp.txt 1000
	sort -n tmp.txt > output9.txt
	diff output9.txt expected9.txt

test10: pa03
	timeout 15s ./pa03 test10.txt 5 tmp.txt 1000
	sort -n tmp.txt > output10.txt
	diff output10.txt expected10.txt

test11: pa03
	timeout 15s ./pa03 test11.txt 8 tmp.txt 1000
	sort -n tmp.txt > output11.txt 
	diff output11.txt expected11.txt

test12: pa03
	timeout 15s ./pa03 test12.txt 3 tmp.txt 1000
	sort -n tmp.txt > output12.txt 
	diff output12.txt expected12.txt
	

test13: pa03
	timeout 15s ./pa03 test13.txt 10 tmp.txt 1000
	sort -n tmp.txt > output13.txt 
	diff output13.txt expected13.txt
	

test14: pa03
	timeout 15s ./pa03 test14.txt 7 tmp.txt 1000
	sort -n tmp.txt > output14.txt 
	diff output14.txt expected14.txt
	

test15: pa03
	timeout 15s ./pa03 test15.txt 3 tmp.txt 1000
	sort -n tmp.txt > output15.txt 
	diff output15.txt expected15.txt
	

test16: pa03
	timeout 15s ./pa03 test16.txt 4 tmp.txt 1000
	sort -n tmp.txt > output16.txt 
	diff output16.txt expected16.txt
	

test17: pa03
	timeout 15s ./pa03 test17.txt 3 tmp.txt 1000
	sort -n tmp.txt > output17.txt 
	diff output17.txt expected17.txt
	

test18: pa03
	timeout 15s ./pa03 test18.txt 7 tmp.txt 1000
	sort -n tmp.txt > output18.txt 
	diff output18.txt expected18.txt
	

test19: pa03
	timeout 15s $(VALGRIND) ./pa03 test4.txt 4 output4.txt


clean:
	/bin/rm -f pa03.o
	/bin/rm -f pa03
	/bin/rm -f output*
