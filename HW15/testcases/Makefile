TARGET = pa15
GCC = gcc
CFLAGS = -g -std=c99 -Wall -Wshadow -Wvla -Werror -pedantic -I.

CC = $(GCC) $(CFLAGS) 
SRCSChk = pa15.c tree.c
SRCS = $(SRCSSol) $(SRCSChk)
OBJS = $(SRCS:%.c=%.o)

VALGRIND = valgrind --error-exitcode=1 --tool=memcheck --leak-check=full --verbose 

all: $(TARGET) testall

testall: test1 test2 test3 test4 test5 test6 test7 valtest

$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(DEFINE) -o $(TARGET)

test1: clean
	echo "Testing Main Function "
	$(CC) $(SRCS) -o $(TARGET)
	timeout 5s ./pa15 125 20 output/tmp.bin
	diff expected/expected1.bin output/tmp.bin 
	timeout 5s ./pa15 125 100 output/tmp.bin
	diff expected/expected2.bin output/tmp.bin
	timeout 5s ./pa15 125 1000 output/tmp.bin
	diff expected/expected3.bin output/tmp.bin
	timeout 5s ./pa15 45 200 output/tmp.bin 
	diff expected/expected4.bin output/tmp.bin
	timeout 5s ./pa15 79 1200 output/tmp.bin
	diff expected/expected5.bin output/tmp.bin
	timeout 5s ./pa15 67 1160 output/tmp.bin
	diff expected/expected6.bin output/tmp.bin
	timeout 5s ./pa15 23 50 output/tmp.bin
	diff expected/expected7.bin output/tmp.bin
	timeout 5s ./pa15 asd 2 output/tmp.bin > tmp.txt || true
	diff -i -w tmp.txt expected/wrongInputs.txt
	timeout 5s ./pa15 23 poq output/tmp.bin > tmp.txt || true
	diff -i -w tmp.txt expected/wrongInputs.txt

	echo "Main Function Passed"

test2: $(clean)
	echo "Testing Unsigned Function "
	$(CC) $(SRCS) -o $(TARGET)
	timeout 5s ./pa15 122 200 output/tmp.bin
	diff expected/expected8.bin output/tmp.bin 
	timeout 5s ./pa15 15 10 output/tmp.bin
	diff expected/expected9.bin output/tmp.bin
	timeout 5s ./pa15 132 2000 output/tmp.bin
	diff expected/expected10.bin output/tmp.bin
	timeout 5s ./pa15 1245 20 output/tmp.bin 
	diff expected/expected11.bin output/tmp.bin
	timeout 5s ./pa15 87 567 output/tmp.bin
	#diff expected/expected12.bin output/tmp.bin
	timeout 5s ./pa15 97 1241 output/tmp.bin
	diff expected/expected13.bin output/tmp.bin
	timeout 5s ./pa15 12 5000 output/tmp.bin
	diff expected/expected14.bin output/tmp.bin
	echo "Unsigned Function Passed"

test3: clean
	echo "Testing Creating Binary Function "
	$(CC) $(SRCS) -o $(TARGET)
	timeout 5s ./pa15 122 200 output/tmp.bin
	diff expected/expected8.bin output/tmp.bin 
	timeout 5s ./pa15 15 10 output/tmp.bin
	diff expected/expected9.bin output/tmp.bin
	timeout 5s ./pa15 132 2000 output/tmp.bin
	diff expected/expected10.bin output/tmp.bin
	timeout 5s ./pa15 1245 20 output/tmp.bin 
	diff expected/expected11.bin output/tmp.bin
	timeout 5s ./pa15 87 567 output/tmp.bin
	#diff expected/expected12.bin output/tmp.bin
	timeout 5s ./pa15 97 1241 output/tmp.bin
	diff expected/expected13.bin output/tmp.bin
	timeout 5s ./pa15 12 5000 output/tmp.bin
	diff expected/expected14.bin output/tmp.bin
	timeout 5s ./pa15 12 2500 output/tmp.bin
	diff expected/expected15.bin output/tmp.bin 
	timeout 5s ./pa15 145 1000 output/tmp.bin
	diff expected/expected16.bin output/tmp.bin
	timeout 5s ./pa15 123 201 output/tmp.bin
	diff expected/expected17.bin output/tmp.bin
	timeout 5s ./pa15 12 2942 output/tmp.bin 
	diff expected/expected18.bin output/tmp.bin
	timeout 5s ./pa15 879 5670 output/tmp.bin
	diff expected/expected19.bin output/tmp.bin
	timeout 5s ./pa15 971 1200 output/tmp.bin
	diff expected/expected20.bin output/tmp.bin
	timeout 5s ./pa15 123 5100 output/tmp.bin
	diff expected/expected21.bin output/tmp.bin
	echo "Creating Binary Function Passed"

test4: clean
	echo "Testing Clean Function "
	$(CC) $(SRCS) -o $(TARGET)
	timeout 5s $(VALGRIND) ./pa15 122 200 output/tmp.bin
	timeout 5s $(VALGRIND) ./pa15 15 10 output/tmp.bin
	timeout 5s $(VALGRIND) ./pa15 132 2000 output/tmp.bin
	timeout 5s $(VALGRIND) ./pa15 1245 20 output/tmp.bin 
	timeout 5s $(VALGRIND) ./pa15 97 1241 output/tmp.bin
	timeout 5s $(VALGRIND) ./pa15 123 5100 output/tmp.bin
	echo "Clean Function Passed"


.c.o:
	$(CC) $(DEFINE) -c $*.c

clean:
	rm -f $(OBJS) $(TARGET)
