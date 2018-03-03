CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror -DCDOUBLE -DCVID
GCOV= -fprofile-arcs -ftest-coverage
GCC = gcc $(CFLAGS) $(GCOV)
SRCS = Spa08.c pa08.c main.c
OBJS = $(SRCS:%.c=%.o)

all: pa08

pa08: $(OBJS)
	$(GCC) $(OBJS) -o pa08

.c.o:
	$(GCC) $(FLAGS) -c $*.c



clean:
	/bin/rm -f input*
	/bin/rm -f *.o
	/bin/rm -f *.gcda *.gcno gmon.out *gcov
	/bin/rm -f pa08
	/bin/rm -f *.txt
	
