CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
GCC = gcc $(CFLAGS)

SRCS = testgen.c 
OBJS = $(SRCS:%.c=%.o)

all: testgen testcase

testgen:$(OBJS)
	$(GCC) $(OBJS) $(KMEANOBJFILE) -o testgen

.c.o:
	$(GCC) $(FLAGS) -c $*.c

testcase: testgen test1 test2 test3 test4 test5

test1: testgen
	./testgen 1000 2 21 2 100 > test1.txt

test2: testgen
	./testgen 2000 3 100 3 200 > test2.txt

test3: testgen
	./testgen 3000 3 300 4 1000 > test3.txt

test4: testgen
	./testgen 4000 4 100 3 100 > test4.txt

test5: testgen
	./testgen 1001 6 2000 2 500 > test5.txt

clean:
	/bin/rm -f *.txt
	/bin/rm -f testgen.o
	/bin/rm -f testgen
