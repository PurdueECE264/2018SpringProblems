TARGET = pe13
GCC = gcc
CFLAGS = -g -std=c99 -Wall -Wshadow -Wvla -Werror -pedantic
CC = $(GCC) $(CFLAGS)
SRCS = pe13.c frequency.c 
OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --tool=memcheck --verbose --log-file

all: $(TARGET) testall

testall: test1 test2 test3 test4 test5 test6 test7 valtest

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

test1: $(TARGET)
	./pe13 test/simple1.txt > expected/expectedSimple1.txt

test2: $(TARGET)
	./pe13 test/simple2.txt > expected/expectedSimple2.txt

test3: $(TARGET)
	./pe13 test/test1.txt > expected/expectedTest1.txt

test4: $(TARGET)
	./pe13 test/test2.txt > expected/expectedTest2.txt

test5: $(TARGET)
	./pe13 test/wiki1.txt > expected/expectedWiki1.txt

test6: $(TARGET)
	./pe13 test/wiki2.txt > expected/expectedWiki2.txt

test7: $(TARGET)
	./pe13 test/wiki3.txt > expected/expectedWiki3.txt

valtest: $(TARGET)
	$(VALGRIND)=expected/valgrind.log ./pe13 test/wiki1.txt > /dev/null

.c.o:
	$(GCC) $(CFLAGS) -c $*.c

clean:
	rm -f $(OBJS) $(TARGET)
