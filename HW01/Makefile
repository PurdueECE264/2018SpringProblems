GCC = gcc -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror -fprofile-arcs -ftest-coverage
# This is a comment (starting with #)
# By defining a symbol for GCC, it is not necessary typing
# the long command with flags all the time.

# Which operations to test by defining the symbols
FLAGS = -DTEST_ADD -DTEST_SUB -DTEST_MUL -DTEST_DIV

# list all .c files
SRCS = add.c div.c mul.c  pe01.c solution.c sub.c

# object files are created by converting .c to .o
OBJS = $(SRCS:%.c=%.o)

pe01: $(OBJS) 
	$(GCC) $(FLAGS) $(OBJS) -o pe01
	# without -c means linking to create the executable
	# the executable is after -o and is called pe01
	# By convention, executable in Linux has no extension
	# (no .exe)

# convert .c to .o 
.c.o: 
	$(GCC) $(FLAGS) -c $*.c 
	# -c means compilation only (creating object file)
	# no linking

testall: testadd testsub testmul testdiv

testadd: pe01
	# pe01 here to ensure the executable is up-to-date
	./pe01 4 5 A > add1.out
	diff add1.out add1.correct
	./pe01 -2 17 A > add2.out
	diff add2.out add2.correct

testsub: pe01
	./pe01 4 5 S > sub1.out
	diff sub1.out sub1.correct
	./pe01 7 26 S > sub2.out
	diff sub2.out sub2.correct

testmul: pe01
	./pe01 4 5 M > mul1.out
	diff mul1.out mul1.correct
	./pe01 7 26 M > mul2.out
	diff mul2.out mul2.correct

testdiv: pe01
	./pe01 240 5 D > div1.out
	diff div1.out div1.correct
	./pe01 70 26 D > div2.out
	diff div2.out div2.correct

coverage: testall
	gcov $(SRCS)

clean: # remove all machine generated files
	rm -f pe01 *.o *.out *gcda *gcno *gcov




