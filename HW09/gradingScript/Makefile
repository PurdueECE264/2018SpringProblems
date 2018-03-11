CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
GCC = gcc $(CFLAGS) 
VAL = valgrind --error-exitcode=1 --tool=memcheck --leak-check=full --verbose
FILE = database.txt
SRCS = pa09.c main.c read_write.c 
OBJS = $(SRCS:%.c=%.o)

pa09: $(OBJS)
	$(GCC) $(OBJS) $(DEFINE) -o pa09

.c.o:
	$(GCC) -c $*.c

test1: fileread
	$(GCC) $(DEFINE_MAIN) $(SRCS) -o pa09
	echo "Testing Main Function "
	timeout 5s ./pa09 database/testdb1.bin -n output1.bin > tmp.txt
	timeout 5s ./pa09 database/testdb2.bin -k output2.bin > tmp.txt || true
	diff expectedTxt/mainWrongArgs.txt tmp.txt
	timeout 5s ./pa09 asddf3.bin > tmp.txt || true
	diff expectedTxt/mainWrongArgs.txt tmp.txt
	echo "Main Function Passed "
	

test2: fileread
	$(GCC) $(DEFINE_SORT) $(SRCS) -o pa09
	echo "Testing StudentQSort Function "
	timeout 5s ./pa09 database/testdb1.bin -n output1.bin > tmp.txt
	diff -i -u tmp.txt expectedTxt/expectedDB1Name.txt
	./fileread output1.bin > output1.txt
	diff -i -u output1.txt expectedTxt/sortDB1Name.txt
	
	timeout 5s ./pa09 database/testdb2.bin -a output2.bin > tmp.txt
	diff -i -u tmp.txt expectedTxt/expectedDB2Age.txt
	./fileread output2.bin > output2.txt
	diff -i -u output2.txt expectedTxt/sortDB2Age.txt
	
	timeout 5s ./pa09 database/testdb3.bin -n output3.bin > tmp.txt
	diff -i -u tmp.txt expectedTxt/expectedDB3Name.txt
	./fileread output3.bin > output3.txt
	diff -i -u output3.txt expectedTxt/sortDB3Name.txt
	
	timeout 5s ./pa09 database/testdb4.bin -a output4.bin > tmp.txt
	diff -i -u tmp.txt expectedTxt/expectedDB4Age.txt
	./fileread output4.bin > output4.txt
	diff -i -u output4.txt expectedTxt/sortDB4Age.txt
	
	timeout 5s ./pa09 database/testdbLarge.bin -n output5.bin > tmp.txt
	diff -i -u tmp.txt expectedTxt/expectedDBLargeName.txt
	./fileread output5.bin > output5.txt
	diff -i -u output5.txt expectedTxt/sortDBLargeName.txt
	
	timeout 5s ./pa09 database/testdbLarge.bin -a output6.bin > tmp.txt
	diff -i -u tmp.txt expectedTxt/expectedDBLargeAge.txt
	./fileread output6.bin > output6.txt
	diff -i -u output6.txt expectedTxt/sortDBLargeAge.txt
	echo "StudentQSort Function Passed"
	
test3: fileread
	$(GCC) $(DEFINE_PART) $(SRCS) -o pa09
	echo "Testing Partition Function "
	timeout 5s ./pa09 database/testdb1.bin -a output1.bin > tmp.txt
	diff -i -u tmp.txt expectedTxt/expectedDB1Age.txt
	./fileread output1.bin > output1.txt
	diff -i -u output1.txt expectedTxt/sortDB1Age.txt
	
	timeout 5s ./pa09 database/testdb2.bin -n output2.bin > tmp.txt
	diff -i -u tmp.txt expectedTxt/expectedDB2Name.txt
	./fileread output2.bin > output2.txt
	diff -i -u output2.txt expectedTxt/sortDB2Name.txt
	
	timeout 5s ./pa09 database/testdb3.bin -a output3.bin > tmp.txt
	diff -i -u tmp.txt expectedTxt/expectedDB3Age.txt
	./fileread output3.bin > output3.txt
	diff -i -u output3.txt expectedTxt/sortDB3Age.txt
	
	timeout 5s ./pa09 database/testdb4.bin -n output4.bin > tmp.txt
	diff -i -u tmp.txt expectedTxt/expectedDB4Name.txt
	./fileread output4.bin > output4.txt
	diff -i -u output4.txt expectedTxt/sortDB4Name.txt
	
	timeout 5s ./pa09 database/testdbLarge.bin -n output5.bin > tmp.txt
	diff -i -u tmp.txt expectedTxt/expectedDBLargeName.txt
	./fileread output5.bin > output5.txt
	diff -i -u output5.txt expectedTxt/sortDBLargeName.txt
	
	timeout 5s ./pa09 database/testdbLarge.bin -a output6.bin > tmp.txt
	diff -i -u tmp.txt expectedTxt/expectedDBLargeAge.txt
	./fileread output6.bin > output6.txt
	diff -i -u output6.txt expectedTxt/sortDBLargeAge.txt
	echo "Partition Function Passed"



test3a: fileread
	$(GCC) $(DEFINE_PART) $(SRCS) -o pa09
	echo "Testing Partition Function - Type 2 "
	timeout 5s ./pa09 database/testdb1.bin -a output1.bin > tmp.txt
	diff -i -u tmp.txt expectedPart2/expectedDB1Age.txt
	./fileread output1.bin > output1.txt
	diff -i -u output1.txt expectedPart2/sortDB1Age.txt
	
	timeout 5s ./pa09 database/testdb2.bin -n output2.bin > tmp.txt
	diff -i -u tmp.txt expectedPart2/expectedDB2Name.txt
	./fileread output2.bin > output2.txt
	diff -i -u output2.txt expectedPart2/sortDB2Name.txt
	
	timeout 5s ./pa09 database/testdb3.bin -a output3.bin > tmp.txt
	diff -i -u tmp.txt expectedPart2/expectedDB3Age.txt
	./fileread output3.bin > output3.txt
	diff -i -u output3.txt expectedPart2/sortDB3Age.txt
	
	timeout 5s ./pa09 database/testdb4.bin -n output4.bin > tmp.txt
	diff -i -u tmp.txt expectedPart2/expectedDB4Name.txt
	./fileread output4.bin > output4.txt
	diff -i -u output4.txt expectedPart2/sortDB4Name.txt
	
	timeout 5s ./pa09 database/testdbLarge.bin -n output5.bin > tmp.txt
	diff -i -u tmp.txt expectedPart2/expectedDBLargeName.txt
	./fileread output5.bin > output5.txt
	diff -i -u output5.txt expectedPart2/sortDBLargeName.txt
	
	timeout 5s ./pa09 database/testdbLarge.bin -a output6.bin > tmp.txt
	diff -i -u tmp.txt expectedPart2/expectedDBLargeAge.txt
	./fileread output6.bin > output6.txt
	diff -i -u output6.txt expectedPart2/sortDBLargeAge.txt
	echo "Partition Function - Type 2  Passed"
	
test4: fileread
	$(GCC) $(DEFINE_CLOSE) $(SRCS) -o pa09
	echo "Testing Close Function "
	timeout 5s $(VAL) ./pa09 database/testdbLarge.bin -a output.bin > tmp.txt
	echo "Close Function Passed"

test5: fileread
	$(GCC) $(DEFINE_SWAP) $(SRCS) -o pa09
	echo "Testing Swap Function "
	timeout 5s ./pa09 database/testdb1.bin -n output1.bin > tmp.txt
	diff -i -u tmp.txt expectedTxt/expectedDB1Name.txt
	./fileread output1.bin > output1.txt
	diff -i -u output1.txt expectedTxt/sortDB1Name.txt 
	
	timeout 5s ./pa09 database/testdb2.bin -a output2.bin > tmp.txt
	diff -i -u tmp.txt expectedTxt/expectedDB2Age.txt
	./fileread output2.bin > output2.txt
	diff -i -u output2.txt expectedTxt/sortDB2Age.txt
	
	timeout 5s ./pa09 database/testdb3.bin -n output3.bin > tmp.txt
	diff -i -u tmp.txt expectedTxt/expectedDB3Name.txt
	./fileread output3.bin > output3.txt
	diff -i -u output3.txt expectedTxt/sortDB3Name.txt 
	
	timeout 5s ./pa09 database/testdb4.bin -a output4.bin > tmp.txt
	diff -i -u tmp.txt expectedTxt/expectedDB4Age.txt
	./fileread output4.bin > output4.txt
	diff -i -u output4.txt expectedTxt/sortDB4Age.txt 
	echo "Swap Function Passed"

test6: fileread
	$(GCC) $(DEFINE_CONNECT) $(SRCS) -o pa09
	echo "Testing ReadDatabase Function "
	timeout 5s ./pa09 database/testdb1.bin -n output1.bin > tmp.txt
	diff -i -u tmp.txt expectedTxt/expectedDB1Name.txt
	./fileread output1.bin > output1.txt
	diff -i -u output1.txt expectedTxt/sortDB1Name.txt
	
	timeout 5s ./pa09 database/testdb2.bin -a output2.bin > tmp.txt
	diff -i -u tmp.txt expectedTxt/expectedDB2Age.txt
	./fileread output2.bin > output2.txt
	diff -i -u output2.txt expectedTxt/sortDB2Age.txt
	
	timeout 5s ./pa09 database/testdb3.bin -n output3.bin > tmp.txt
	diff -i -u tmp.txt expectedTxt/expectedDB3Name.txt
	./fileread output3.bin > output3.txt
	diff -i -u output3.txt expectedTxt/sortDB3Name.txt
	
	timeout 5s ./pa09 database/testdb4.bin -a output4.bin > tmp.txt
	diff -i -u tmp.txt expectedTxt/expectedDB4Age.txt
	./fileread output4.bin > output4.txt
	diff -i -u output4.txt expectedTxt/sortDB4Age.txt
	echo "ReadDatabase Function Passed"
	

test7: fileread
	$(GCC) $(DEFINE_WRITE) $(SRCS) -o pa09
	echo "Testing WriteDatabase Function "
	timeout 5s ./pa09 database/testdb1.bin -n output1.bin > tmp.txt
	diff -i -u tmp.txt expectedTxt/expectedDB1Name.txt
	./fileread output1.bin > output1.txt
	diff -i -u output1.txt expectedTxt/sortDB1Name.txt
	
	timeout 5s ./pa09 database/testdb2.bin -a output2.bin > tmp.txt
	diff -i -u tmp.txt expectedTxt/expectedDB2Age.txt
	./fileread output2.bin > output2.txt
	diff -i -u output2.txt expectedTxt/sortDB2Age.txt
	
	timeout 5s ./pa09 database/testdb3.bin -n output3.bin > tmp.txt
	diff -i -u tmp.txt expectedTxt/expectedDB3Name.txt
	./fileread output3.bin > output3.txt
	diff -i -u output3.txt expectedTxt/sortDB3Name.txt
	
	timeout 5s ./pa09 database/testdb4.bin -a output4.bin > tmp.txt
	diff -i -u tmp.txt expectedTxt/expectedDB4Age.txt
	./fileread output4.bin > output4.txt
	diff -i -u output4.txt expectedTxt/sortDB4Age.txt
	echo "WriteDatabase Function Passed"
	

fileread:
	$(GCC) fileread.c -o fileread


clean:
	/bin/rm -f *.o
	/bin/rm -f *.txt
	/bin/rm -f output*
	/bin/rm -f pa09 sort*
	/bin/rm -f fileread filewrite
