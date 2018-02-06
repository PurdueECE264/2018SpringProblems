## Testing HW03
Before testing the your HW03, please make the code to print till 4 decimal values
To do that change the following part:

In file `pa03.c` please change `writeCentroids` function and change the line
``` 
fprintf(fpout, "%lf ", centroid[kiter][diter]); 

``` 
to
```
  fprintf(fpout, "%0.4lf ", centroid[kiter][diter]);
```

and then use the Makefile to run the tests.

### Grading Policy
* Each test case till testcase 18 is 5
* Testcase 19 is valgrind testcase and the point for that is 10.

For 2nd chance submissions, everything is reducde by 20%. This means each test case for 2nd chance is 4 marks and valgrind test is 8 marks.


