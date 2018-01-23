CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
GCC = gcc $(CFLAGS) 
SRCS = pa03.c 
OBJFILES = obj/closest_centroid.o obj/dist2.o
OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --tool=memcheck --leak-check=full

all: pa03 testcase

pa03:$(OBJS)
	$(GCC) $(OBJS) $(OBJFILES) -o pa03

.c.o:
	$(GCC) $(FLAGS) -c $*.c

testcase: test1 test2 test3 test4 test5 test6

test1: pa03
	./pa03 test1.txt 2 tmp.txt
	sort -n tmp.txt > output1.txt
	diff output1.txt expected1.txt

test2: pa03
	./pa03 test2.txt 3 tmp.txt
	sort -n tmp.txt > output2.txt
	diff output2.txt expected2.txt

test3: pa03
	./pa03 test3.txt 3 tmp.txt
	sort -n tmp.txt > output3.txt
	diff output3.txt expected3.txt

test4: pa03
	./pa03 test4.txt 4 tmp.txt
	sort -n tmp.txt > output4.txt
	diff output4.txt expected4.txt

test5: pa03
	./pa03 test5.txt 6 tmp.txt
	sort -n tmp.txt > output5.txt
	diff output5.txt expected5.txt
	rm tmp.txt

test6: pa03
	$(VALGRIND) ./pa03 test4.txt 4 output4.txt

clean:
	/bin/rm -f pa03.o pa03
	/bin/rm -f input* output*
