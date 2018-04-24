TARGET = pa14
GCC = gcc
CFLAGS = -g -std=c99 -Wshadow -Wvla -Werror -pedantic -Wall -I.
CC = $(GCC) $(CFLAGS)

SRCSChk = pa14.c frequency.c list_node.c tree.c
SRCS = $(SRCSSol) $(SRCSChk)

OBJS = $(SRCS:%.c=%.o)

VALGRIND = valgrind --error-exitcode=1 --tool=memcheck --leak-check=full --verbose --log-file

#all: $(TARGET) testall

#testall: test1 test2 test3 test4 test5 test6 test7 valtest

# $(TARGET): $(OBJS)
# 	$(CC) $(OBJS) -o $(TARGET)

test1: $(clean)
	$(CC) $(SRCS) -o $(TARGET)
	echo "Testing Main Function "
	timeout 5s $(TARGET) test/simple1.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedSimple1.txt
	timeout 5s $(TARGET) test/simple2.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedSimple2.txt
	timeout 5s $(TARGET) test/wiki2.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedWiki2.txt
	timeout 5s $(TARGET) > tmp.txt || true
	diff -i -w tmp.txt expected/wrongarguments.txt
	echo "Main Function Passed "

test2: $(clean)
	$(CC) $(SRCS) -o $(TARGET)
	echo "Testing Sort Function "
	timeout 5s $(TARGET) test/simple1.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedSimple1.txt
	timeout 5s $(TARGET) test/simple2.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedSimple2.txt
	timeout 5s $(TARGET) test/wiki2.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedWiki2.txt
	timeout 5s $(TARGET) test/wiki1.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedWiki1.txt
	timeout 5s $(TARGET) test/wiki3.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedWiki3.txt
	timeout 5s $(TARGET) test/bookexample.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedBookExample.txt
	echo "Sort Function Passed "

test3: $(clean)
	$(CC) $(SRCS) -o $(TARGET)
	echo "Testing Count Function "
	timeout 5s $(TARGET) test/simple1.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedSimple1.txt
	timeout 5s $(TARGET) test/simple2.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedSimple2.txt
	timeout 5s $(TARGET) test/wiki2.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedWiki2.txt
	timeout 5s $(TARGET) test/wiki1.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedWiki1.txt
	timeout 5s $(TARGET) test/wiki3.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedWiki3.txt
	timeout 5s $(TARGET) test/bookexample.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedBookExample.txt
	echo "Count Function Passed "

test4: $(clean)
	$(CC) $(SRCS) -o $(TARGET)
	echo "Testing Tree Node Create Function "
	timeout 5s $(TARGET) test/simple1.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedSimple1.txt
	timeout 5s $(TARGET) test/simple2.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedSimple2.txt
	timeout 5s $(TARGET) test/wiki2.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedWiki2.txt
	timeout 5s $(TARGET) test/wiki1.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedWiki1.txt
	timeout 5s $(TARGET) test/wiki3.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedWiki3.txt
	timeout 5s $(TARGET) test/bookexample.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedBookExample.txt
	echo "Tree Node create Function Passed "

test5: $(clean)
	$(CC) $(SRCS) -o $(TARGET)
	echo "Testing Tree Merge Function "
	timeout 5s $(TARGET) test/simple1.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedSimple1.txt
	timeout 5s $(TARGET) test/simple2.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedSimple2.txt
	timeout 5s $(TARGET) test/wiki2.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedWiki2.txt
	timeout 5s $(TARGET) test/wiki1.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedWiki1.txt
	timeout 5s $(TARGET) test/wiki3.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedWiki3.txt
	timeout 5s $(TARGET) test/bookexample.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedBookExample.txt
	echo "Tree Merge Function Passed "


test6: $(clean)
	$(CC) $(SRCS) -o $(TARGET)
	echo "Testing Print Prefix Function "
	timeout 5s $(TARGET) test/simple1.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedSimple1.txt
	timeout 5s $(TARGET) test/simple2.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedSimple2.txt
	timeout 5s $(TARGET) test/wiki2.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedWiki2.txt
	timeout 5s $(TARGET) test/wiki1.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedWiki1.txt
	timeout 5s $(TARGET) test/wiki3.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedWiki3.txt
	timeout 5s $(TARGET) test/bookexample.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedBookExample.txt
	echo "Print Prefix Function Passed "

test7: $(clean)
	$(CC) $(SRCS) -o $(TARGET)
	echo "Testing Tree Clean Function "
	timeout 5s $(VALGRIND)=memcheck.log ./pa14 test/wiki1.txt > /dev/null
	timeout 5s $(VALGRIND)=memcheck.log ./pa14 test/wiki2.txt > /dev/null
	echo "Tree Clean Function Passed "


test8: $(clean)
	$(CC) $(SRCS) -o $(TARGET)
	echo "Testing List Node Create Function "
	timeout 5s $(TARGET) test/simple1.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedSimple1.txt
	timeout 5s $(TARGET) test/simple2.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedSimple2.txt
	timeout 5s $(TARGET) test/wiki2.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedWiki2.txt
	timeout 5s $(TARGET) test/wiki1.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedWiki1.txt
	timeout 5s $(TARGET) test/wiki3.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedWiki3.txt
	timeout 5s $(TARGET) test/bookexample.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedBookExample.txt
	echo "List Node Create Function Passed "


test9: $(clean)
	$(CC) $(SRCS) -o $(TARGET)
	echo "Testing List Build Node Create Function "
	timeout 5s $(TARGET) test/simple1.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedSimple1.txt
	timeout 5s $(TARGET) test/simple2.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedSimple2.txt
	timeout 5s $(TARGET) test/wiki2.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedWiki2.txt
	timeout 5s $(TARGET) test/wiki1.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedWiki1.txt
	timeout 5s $(TARGET) test/wiki3.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedWiki3.txt
	timeout 5s $(TARGET) test/bookexample.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedBookExample.txt
	echo "List Build Function Passed "


test10: $(clean)
	$(CC) $(SRCS) -o $(TARGET)
	echo "Testing List Insert Create Function "
	timeout 5s $(TARGET) test/simple1.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedSimple1.txt
	timeout 5s $(TARGET) test/simple2.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedSimple2.txt
	timeout 5s $(TARGET) test/wiki2.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedWiki2.txt
	timeout 5s $(TARGET) test/wiki1.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedWiki1.txt
	timeout 5s $(TARGET) test/wiki3.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedWiki3.txt
	timeout 5s $(TARGET) test/bookexample.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedBookExample.txt
	echo "List Insert Function Passed "



test12: $(clean)
	$(CC) $(SRCS) -o $(TARGET)
	echo "Testing List Clean Function "
	timeout 5s $(VALGRIND)=memcheck.log ./pa14 test/wiki1.txt > /dev/null
	timeout 5s $(VALGRIND)=memcheck.log ./pa14 test/wiki2.txt > /dev/null
	echo "List Clean Function Passed "

test11: $(clean)
	$(CC) $(SRCS) -o $(TARGET)
	echo "Testing Build Huffman Function "
	timeout 5s $(TARGET) test/simple1.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedSimple1.txt
	timeout 5s $(TARGET) test/simple2.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedSimple2.txt
	timeout 5s $(TARGET) test/wiki2.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedWiki2.txt
	timeout 5s $(TARGET) test/wiki1.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedWiki1.txt
	timeout 5s $(TARGET) test/wiki3.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedWiki3.txt
	timeout 5s $(TARGET) test/bookexample.txt > tmp.txt
	diff -i -w tmp.txt expected/expectedBookExample.txt
	echo "Build Huffman Function Passed "


test13: $(clean)
	echo "Testing Memory Leaks and Memory errors"
	$(CC) $(SRCS) -o $(TARGET)
	timeout 5s $(VALGRIND)=memcheck.log ./pa14 test/wiki1.txt > /dev/null
	timeout 5s $(VALGRIND)=memcheck.log ./pa14 test/wiki2.txt > /dev/null
	echo "Memory Leaks and Memory errors passed"

.c.o:
	$(GCC) $(CFLAGS) -c $*.c

clean:
	rm -f $(OBJS) $(TARGET)
