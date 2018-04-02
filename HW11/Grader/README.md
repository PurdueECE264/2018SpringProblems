
# HW11 grading policy
<strong>  &nbsp; &nbsp; &nbsp;   &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;  &nbsp;  &nbsp; \*\*\*ATTENTION : Read it to the last line before sending any email\*\*\* </strong> </br> <br>
`- If you did not use the proper flags (i.e forgetting to use -Werror -Wvla) while compiling may lead to compile error. Regrade is not possible for such cases`

<br/>

<strong>Please copy the main.c and pe11.c you submitted to this directory</strong>

## print() function (10 points)
\- To test your function we compiled your code using the following command:</br>
`gcc -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror -DINSL -DINSF -DINSA -DDelA -DDELFM -DDELAM -DFREEMEM -DL main.c pe11.c ./cases/testp.obj -o pe11`</br>
\- Then run the following command:</br>
`./pe11 ./cases/testp`</br>
\- The correct output of this case is in `./cases/testpsol`. <br>
\- To calculate your grade: count the number of different lines (x). your grade=10-(x/10)\*10. </br>

	
## getLength() function (6 points)
\- To test your function we compiled your code using the following command:</br>
`gcc -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror -DPRINT -DINSL -DINSF -DINSA -DDelA -DDELFM -DDELAM -DFREEMEM main.c pe11.c ./cases/testl.obj -o pe11`</br>
\- Then run the following command:</br>
`./pe11 ./cases/testl`</br>
\- The correct output of this case is in `./cases/testlsol`. <br>
\- To calculate your grade: count the number of different lines (x). your grade=6-(x/3)\*6. </br>

## insertFirst() function (14 points)
\- To test your function we compiled your code using the following command:</br>
`gcc -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror -DPRINT -DINSA -DINSL -DDELFM -DDelA -DDELAM -DL -DFREEMEM main.c pe11.c ./cases/test1.obj -o pe11`</br>
\- Then run the following command:</br>
`./pe11 ./cases/test1`</br>
\- The correct output of this case is in `./cases/test1sol`. <br>
\- To calculate your grade: count the number of different lines (x). your grade=14-(x/10)\*14. </br>

## insertLast() function (14 points)
\- To test your function we compiled your code using the following command:</br>
`gcc -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror -DPRINT -DINSA -DINSF -DDELFM -DDelA -DDELAM -DL -DFREEMEM main.c pe11.c ./cases/test2.obj -o pe11`</br>
\- Then run the following command:</br>
`./pe11 ./cases/test2`</br>
\- The correct output of this case is in `./cases/test2sol`. <br>
\- To calculate your grade: count the number of different lines (x). your grade=14-(x/10)\*14. </br>

## insertAt() function (14 points)
\- To test your function we compiled your code using the following command:</br>
`gcc -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror -DPRINT -DINSL -DINSF -DDELFM -DDelA -DDELAM -DL -DFREEMEM main.c pe11.c ./cases/test3.obj -o pe11`</br>
\- Then run the following command:</br>
`./pe11 ./cases/test3`</br>
\- The correct output of this case is in `./cases/test3sol`. <br>
\- To calculate your grade: count the number of different lines (x). your grade=14-(x/10)\*14. </br>

## deleteAt() function (14 points)
\- To test your function we compiled your code using the following command:</br>
`gcc -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror -DPRINT -DINSL -DINSF -DINSA -DDELFM -DDELAM -DL -DFREEMEM main.c pe11.c ./cases/test4.obj -o pe11`</br>
\- Then run the following command:</br>
`./pe11 ./cases/test4`</br>
\- The correct output of this case is in `./cases/test4sol`. <br>
\- To calculate your grade: count the number of different lines (x). your grade=14-(x/10)\*14. </br>

## deleteFirstMatch() function (14 points)
\- To test your function we compiled your code using the following command:</br>
`gcc -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror -DPRINT -DINSL -DINSF -DINSA -DDelA -DDELAM -DL -DFREEMEM main.c pe11.c ./cases/test5.obj -o pe11`</br>
\- Then run the following command:</br>
`./pe11 ./cases/test5`</br>
\- The correct output of this case is in `./cases/test5sol`. <br>
\- To calculate your grade: count the number of different lines (x). your grade=14-(x/10)\*14. </br>

## deleteAllMatches() function (14 points)
\- To test your function we compiled your code using the following command:</br>
`gcc -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror -DPRINT -DINSL -DINSF -DINSA -DDelA -DDELFM -DL -DFREEMEM main.c pe11.c ./cases/test6.obj -o pe11`</br>
\- Then run the following command:</br>
`./pe11 ./cases/test6`</br>
\- The correct output of this case is in `./cases/test6sol`. <br>
\- To calculate your grade: count the number of different lines (x). your grade=14-(x/10)\*14. </br>

## freeMemory() function (10%)
\- To test your function we compiled your code using the following command:</br>
`gcc -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror -DPRINT -DINSL -DINSF -DINSA -DDelA -DDELFM -DDELAM -DL main.c pe11.c ./cases/testmem.obj -o pe11`</br>
\- Then run the following command:</br>
`valgrind ./pe11 ./cases/test1`</br>
\- If there is any memory leak you will lose 10% of your final grade.

## Late penalty
- You will lose 2 points per hour late.




