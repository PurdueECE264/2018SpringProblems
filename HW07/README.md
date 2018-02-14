# HW7. Recursion (Regular Expression) Exercise
## This is an Excercise. It is related to HW8.

<strong>Please read the entire file before you ask any question.</strong><br>

In this exercise you will learn how to use recursion for solving problems, and regular expressions (RegEx). RegEx is used mainly for pattern-matching, parsing, and filtering. Most importantly it is used by compilers such as gcc (C compiler) to translate the high level language to machine language. https://www.tutorialspoint.com/compiler_design/compiler_design_lexical_analysis.htm

More about RegEx : https://www.tutorialspoint.com/java/java_regular_expressions.htm


# Learning Goals
* Use recursion to solve problems by dividing the problem into smaller problems.
* Understanding regular expressions.


## Some of regular expression metacharacter syntax 
|    Pattern    |               Description                              |  
| ------------- | ------------------------------------------------------ |
|       ^       | Match the beginning of the string                      | 
|       $       | Match the end of the string                            |
|  \[a-zA-Z]    | Match English alphabet charachter                      |
|      \d	      | Match the digits                                       |
|      re*	    | Match 0 or more occurrences of the preceding expression|
|      re+	    | Match 1 or more occurrences of the preceding expression                 |
| \[re1\|re2]    | Match either expression re1 or re2                     |

## Examples
`NOTE : The regular expression matches as long as possible`<br/> 

A- "\d" This RegEx will match any digit in a String.<br/>
- "a2b" The matcher will return 2.<br/>
- "a2b3" The matcher will return 2 first, then it will return 3.<br/>
- "123b" The matcher will return 1 first, then it will return 2, and last it will return 3.<br/>

B- "\d+" This Regex will match any sequance of digits with length of one or more.<br/>
- "123b45" The matcher will return 123 first, then it will return 45.
- "1A4856.12" The matcher will return 1 first, then it will return 4856, and last it will return 12.

C- "\d*" This Regex will match any sequance of digits with length of zero or more.<br/>
- "123b45" The matcher will return 123 first, then it will return empty string for 'b', and last it will return 45.
- "1A4856.12" The matcher will return 1 first, then it will return empty string for 'A', then it will return 4856, then it will return empty string for '.', and last it will return 12.

D- "\[a-zA-z]+" This Regex will match any sequance of english alphabet with length of one or more.<br/>
- "ABC1DEFG2Q" The matcher will return ABC first, the it will return DEFG, and last it will return Q.
- "1234" The matcher will return NULL (no match, not empty string).

E- "^\d+" This Regex will match any sequance of digits with length of one or more at the start of the string. Note the (^) at the beginning of the RegEx.<br/>
- "123AA34Af412" The matcher will return 123 only.
- "A12345" The matcher will return nothing.

F- "\d+$" This Regex will match any sequance of digits with length of one or more at the end of the string. Note the ($) at the end of the RegEx.<br/>
- "123AA34Af412" The matcher will return 412 only.
- "12345A" The matcher will return NULL (no match, not empty string).
- "A12345" The matcher will return 12345.

G- "^\d+$" This Regex will match any sequance of digits with length of one or more that starts and ends the string.<br/>
- "A12345" The matcher will return NULL (no match, not empty string), the string starts with A.
- "123A45" The matcher will return NULL (no match, not empty string), the "123" does not end the string, and the "45" does not start the string .
- "12345A" The matcher will return NULL (no match, not empty string), the string ends with A.
- "12345" The matcher will return 12345.

H- "\[ \d | \[a-zA-Z] ]+" This Regex will match any sequance of digits and english alphabet with length of one or more. <br/>
- "A12s2345" The matcher will return A12s2345.
- "A12s2.34A5" The matcher will return A12s2 first, then it will return 34A5.

# Rules To Implement

A - "^\\d+$". This RegEx will match any Integer number.<br/>
- 5449 is a match.
- 45.5 is not a match because it has '.'.
- a448 is not a match because it has 'a'.
	
B - "^\\d+\[.]\\d+$". This RegEx will match any number that starts with 1+ numbers followed by '.' followed by and ends by 1+ numbers and must end with a number.<br/>
- 215.565 is a match.
- 0.25 is a match.
- .25 is not a match because it does not start with a number.
- 25\. is not a match because it does not end with a number.

C - "^\[ \[a-zA-Z] | \_ ] \[ \[a-zA-Z] | \\d| \_ ]*$". This RegEx will match a vaild identifier which is any word that start with '\_' or alphabetical character followed by 0+ alphanumerical characters or '\_'. <br/>
- _12 is a match.<br/>
- _A23A2____54 is a match.
- 1_asdj21 is not a match because it does not start with '\_' or alphabetical character. 
- _qas@ is not a match because it contains '@' which is not alphanumerical nor '\_'.


# Implementation
In this exercise you will implement three functions, for three different regex formulas (A,B, and C from the Rules To Implement). IsInteger(), IsDouble(), and IsValidIdentifier().


1. `IsInteger()` - This function will return true if the passed string is an integer and false otherwise.
2. `IsDouble()` - This function will return true if the passed string is a double and false otherwise.
3. `IsValidIdentifier()` - This function will return true if the passed string is a vaild identifier and false otherwise.
4. `main()` - in the main file you will read the test file which has 'n' number of strings, and you will print on a file for each of the strings in the file 'Integer', 'Double', 'Identifier', or 'None' if the string does not match any of the rules. 

`HINT : You can use isdigit() to check if the passed character is a decimal digit character. And, isalpha() to check if the passed character is alphabetic`<br/> 

# Testing your code
Following are the files we provide:
1. `pe07.c` 
2. `pe07.h` 
3. `main.c`
4. `test.txt` - This file has n strings to match.

`NOTE : Each line in any test file is a single string`<br/> 

To test your code. You have to first compile it and then run one of the following commands. <br>

./pe07 testAll.txt <br/>
Match all strings in test.txt with all rules. Print "Integer".'Double', 'Identifier', or 'None' if the string does not match any of the rules. Expected output for this command in expOutAll.txt

./pe07 testInt.txt -I <br/>
"-I" To match all strings in test.txt with Integer rule. If it is integer, print "Integer". Otherwise,print "Not integer". Expected output for this command in expOutInt.txt

./pe07 testDbl.txt -D <br/>
"-D" To match all strings in test.txt with Double rule. If it is double, print "Double". Otherwise,print "Not double". Expected output for this command in expOutDbl.txt

./pe07 testVID.txt -VID <br/>
"-VID" To match all strings in test.txt with Vaild Identifier rule. If it is Identifier, print "Identifier". Otherwise, print "Not identifier". Expected output for this command in expOutVID.txt

# Submitting Your code
** This is a programming exercise, so you would have to submit the code on Blackboard.**

You have to submit the following file in a <strong>zip</strong> folder on the blackboard:
* `pe07.c` - This file should have `IsInteger()`, `IsDouble()`, and `IsValidIdentifier()`. functions implemented.
* `main.c` - This file should have `main()` function implemented.<br/>
* `cases.txt` - This file has at least 50 lines as a test input that you have to create.
* `OutCases.txt` - This file has the corresponding output for your cases. By running the following command <br>  `./pe07 cases.txt`

Type the following command to zip your file.
```bash
	zip pe07.zip pe07.c main.c cases.txt OutCases.txt
```
<strong>You will not get any credits if the submitted file is not zipped</strong>

The **only** way to submit homework is through Blackboard.

The instructor will **never** accept any requestion for exception "*my
submission is only one minute late*".  It is your responsibility to
meet the deadline.  You are strongly encouraged to submit at least ten
minutes before the deadline because submission may take time.

If there is a campus-wide problem (such as network outage or the
Blackboard server is down), the deadline will be extended for the
entire class. If the problem is specific to yourself (for example,
your computer crashes), the deadline will not be extended for
you.

**DO NOT** send your code by email. Your code will not be graded
  if it is sent by email.

The teaching staff is strictly prohibited to look at files on your
computer (or your Purdue account) for grading. Thus, **NEVER** say "I
finished before the deadline but I forgot to submit".  **NEVER** say "I have
not made any change after the submission deadline." because the
teaching staff is not allowed to look at your files that have not been
submitted through Blackboard.

# Grading
If your program has any compilation error or warning (remember to use
`gcc -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror`), you will
receive zero in this assignment.

In absolutely no circumstance can the teaching staff modify your
program for grading.  You cannot say, "If you change this, my program
works." If your program misses a semicolon and cannot compile, you
will receive zero.  Your score depends on what is submitted, nothing
else.

Your code will be tested as following : <br/>
1- 40 test cases using ./pe07 testAll.txt command line. 1 point for each test case.<br/>
2- 15 test cases ./pe07 testInt.txt -I/-D/-VID  each, sums up to 45 cases. 1 point for each test case.<br/>
3- 5 test cases for the main.c and Makefile. 1 point for each test case.<br/>
4- If you do not submit a test input, you will lose 10 points. If your expected output is wrong, you will lose at most 5 points.<br/>
**All Test cases will be released later.


