CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
GCC = gcc $(CFLAGS) 

SRCS = pe02.c
KMEANOBJFILE = obj/kmean.o obj/mem_mgmt.o
OBJS = $(SRCS:%.c=%.o)

all: pe02 testcase

pe02:$(OBJS)
	$(GCC) $(OBJS) $(KMEANOBJFILE) -o pe02

.c.o:
	$(GCC) $(FLAGS) -c $*.c

testcase: test1 test2 test3 test4 test5


test1: pe02
	./pe02 test1.txt 2 output1.txt
	diff output1.txt expected1.txt

test2: pe02
	./pe02 test2.txt 3 output2.txt
	diff output2.txt expected2.txt

test3: pe02
	./pe02 test3.txt 3 output3.txt
	diff output3.txt expected3.txt

test4: pe02
	./pe02 test4.txt 4 output4.txt
	diff output4.txt expected4.txt

test5: pe02
	./pe02 test5.txt 6 output5.txt
	diff output5.txt expected5.txt

clean:
	/bin/rm -f input*
	/bin/rm -f pe02.o
	/bin/rm -f pe02
	/bin/rm -f output*
