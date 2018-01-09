# Welcome to ECE 264

## This is an exercise.

ECE 264 has two types of homework: exercise and programming
   assignment. An exercise has 1/4 of the points of an assignment.

You will find this course challenging and rewarding. You will learn
many things.  ECE264 can be a turning point in learning the
methodologies, tools, and skills in writing larger programs.  It is
critical to plan before typing any code.  When writing small
programs, many people adopt the "coding and then debugging" approach.
This will not work in ECE 264. The programs in ECE 264 are too complex
and too many places can be wrong. Without a plan, it is extremely
difficult to write correct programs.

A general rule in ECE 264 is **the sooner you start coding, the more
time you spend**.  Many (millions) people have learned programming and
become professional software developers. They understand the
importance of planning before coding.  You will not be the first
exception.  DO NOT EVEN TRY. You must plan before coding.

It is important to understand the difference between "learning" and
"re-inventing" (or "re-discovery"). Some students think
"trial-and-error" is learning.  This is wrong.  You should read the
textbook before attempting to write any code.  You can save a lot of
time by reading the book and learning what is correct without making
common mistakes.  You should also attend **every** lecture because the
instructor has seen many common mistakes and will tell students how to
avoid these mistakes.

This course will cover a wide variety of programming topics; one of
the most important things you will learn is how to use tools that will
make writing correct large programs easier.  These tools are the
software equivalents of oscilloscopes, telescope, ultrasounds, x-ray,
MRI...  These tools help engineers, doctors, and researchers see
things that cannot be seen by eyes.

Before you learn any tool, you need to understand the purposes of
these tools.  These tools can help you improve your programs and
detect potential problems.  Even though learning these tools takes
time, the benefits of these tools can save you much more time. Some
students skip learning these tools hoping to save time, but they spend
much more time debugging their programs.

If you think you can save time by not learning tools, you are wrong.
 This following story may help you understand why it is so important
 using the right tools. Imagine that two Purdue students want to
 attend a conference in Seattle (latitude 47.6062N). West Lafayette's
 latitude is 40.4259N. In other words, Seattle is north of West
 Lafayette. Student A drives along I-65 North. Student B drives along
 I-65 South to the Indianapolis Airport.  After one hour, A is closer
 to Seattle than B.  After two hours, B is still waiting at the gate
 and A is even closer to Seattle than B.  B will land in the Seattle
 Airport several hours later and A is still driving.  Why can B reach
 Seattle earlier than A?  Because B uses a better tool called
 *airplane*.  A thinks driving north will make progress sooner but A
 will spend several days driving to Seattle.  The point is that you
 **need to learn tools and when to use the right tools**.

This exercise will help you learn some most widely used tools:
`git`, `gcc` and `make`.

Learning Goals 
==============

You will learn to
* Manage source code using the git version control tools
* Detect likely mistakes using gcc warnings
* Write a program that has multiple files
* Understand how programming assignments are graded
* Build a program and run multiple tests at once
* Use conditional compilation to turn on and off sections of code
* Use gcov to find untested code

Background
==========

Version Control
---------------

Have you ever spent hours writing code (or a report) only to realize,
when your computer crashes, that you haven't saved your progress? Have
you ever spent an hour making a change to a program only to realize
that the new features did not work wrong and you had to go back to the
way the code was an hour ago? Version control helps solve these
problems.

Every non-trivial program is written in stages. To write a good
program, you need to divide it into stages and finish one stage at a
time. After you finish one stage, test it to ensure that it works
and then **commit** a version so that you have a record. Version
control provides many advantages. One of them is a simple way to back
up your code.  If, for any reason, you want to go back to a previous
version, it is very easy. Version control does many more things than
backing up your code.

Please understand that you must commit changes often if you want
to use version control. If you do not commit, version control cannot
help you.

Some people send their programs to themselves as email
attachments. Some other people create zip files called v1.zip, v2.zip,
.... If you are one of them, it is time to change.  Version control
provides *line-by-line* comparison of different versions.  This
feature is unavailable when you use email attachments or zip files.

This class uses `git` for version control. Git is a distributed
version control system. That means there are two repositories: local
and remote. When you **commit** changes, only the local repository is
changed. This makes commits fast without network connections.  If your
computer is damaged, you still lose the local repository.

To change the remote repository, you need to **push** the changes.  If
your computer is damaged, you can retrieve the code from the remote
repository.

Github is a cloud-based service for remote repositories.

Please read the guide at github about how to use version control.

https://guides.github.com/

In this class, homework assignments are distributed using a *public*
repository in github: everyone can see the files but only the teaching
staff can modify the files.

You are *encouraged* but *not required* to use version control
managing your own code. If you do use version control (in particular
github), it **absolutely critical** that your repository is
**private**.  You can request *free* [private repositories]
(https://education.github.com/) by using your Purdue account.  You
**must** keep your repository for ECE 264 private.  If your repository
is public, everyone can see your solutions.  If anyone copies your
solutions, you will receive penalty because you give away your
solutions.  "I do not know that my repository is public" is not an
acceptable execuse because this paragraph already explains to you how
to make it private.

Since you already know how to use version control, the instructors
will not accept any excuse like "I accidentally deleted my code" or
"my computer crashed" for an extension.

If there is any doubt about academic dishonesty, your commit history
would be an important piece of evidence proving your innocence.
Version control can demonstrate that you make small and steady
progress (instead copying a large chunk of code at once).  This is
another reason why you must commit and push often.

gcc warnings
------------

Before you write any program, you must assume that the program will
have many mistakes and develop strategies to prevent, detect, and
remove the mistakes.

When you write a program, you create text files. These text files are
not computer programs.  To convert the text files from human-readable
to machine-readable format, you need to use a *compiler*. This class
uses `gcc` for the compiler.

`gcc` takes one or several `.c` files as input. You can  specify
the output file's name by adding

`-o name`

If you do not specify the name, the default name is called `a.out`

Please be careful not to use the file you write as the output's name, 
for example

`> gcc myprogram.c -o myprogram.c`

This will **erase** `myprogram.c`.  You definitely do not want to do this.

Also, do not use `test` as the name of the ouput because `test` is a
command in Linux.  When you run `test`, is it your program or the
Linux command? The answer depends on your *path* settings. 

If you read the manual (also called the "man page") of `gcc`, you can
find many options.  In this class, you should *always* use `gcc` in the
following way.

`> gcc -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror`

* `-std=c99` means using the C standard announced in 1999
* `-g` means enabling debugging
* `-Wall` means enable warning messages
* `-Wshadow` means detecting shadow variables
* `-pedantic` means restricting standard C
* `-Wvla` means detecting variable length array
* `-Werror` means treating warnings as errors 

You should create an *alias* in Linux (or use `make` as explained
below) so that whenever you use `gcc`, all these options are
automatically added.  If you do not know how to create an alias in
Linux, look it up on the Internet.  If you do not create an alias, it
is very likely that you forget some parts of the long command.  It is
very important to use `gcc` this way to detect mistakes. In almost all
cases, the warnings by `gcc` indicate serious problems.  This is your
first "line of defense" writing good programs.  There were many cases
when students forgot to use these options, failed to detect these
problems early, and spent many hours debugging.

Here are some common warning messages:

* create a variable but never use it (most likely it is mistyped)
* create a function but never use it (most likely it is mistyped)
* read a variable before a value is assigned (C does not initialize
   variables. If a variable is not assigned, its value is garbage, not
   necessarily zero.)  Please be aware that `gcc` does not *always* detect
   uninitialized variables. You cannot rely on `gcc` completely.
* write code that can never be reached (for example, after `return`)
* assign a value to a wrong type
* create two variables that have overlapping scopes (called *shadow variables*)

Conditional Compilation
-----------------------

In some cases, you want to turn on or off sections of code. For
example, you may want to print messages showing the progress and
status of your programs, such as

`printf("The value of x is %d\n", x);`

Such a message should not occur after you finish the
programs. Deleting these messages manually can be tedious.  Moreover,
when you delete the messages, you may *accidentally* delete other
lines and the program does not work any more. (This occurs quite often
in ECE 264.)

Fortunately, there is an easy solution: enclose the message by
conditions using `ifdef` and `endif`:

```
#ifdef MESSAGE
printf("The value of x is %d\n", x);
#endif
```

If you add `-DMESSAGE` after `gcc`, this line is included in the program.
If you do not add `-DMESSAGE` after `gcc`, this line is excluded in the
program. What does `-DMESSAGE` mean? `-D` means defining the `MESSAGE`
symbol.  If `MESSAGE` is defined, the `#ifdef` condition is true and that
line is included.

You can define multiple symbols. For example, if you want to test two
different solutions of the same function, you can do the following:

```
#ifdef SOLUTION1
void func(....) // solution 1
{
	....
}
#endif

#ifdef SOLUTION2
void func(....) // solution 2
{
	....
}
#endif
```

If you have `-DSOLUTION1` after `gcc`, the first solution is included.
If you have `-DSOLUTION2` after `gcc`, the second solution is included.

If you have neither, neither solution is included.  You will get an error message
because `gcc` does not know how to handle the call of `func`.

If you have both `-DSOLUTION1` and `-DSOLUTION2`, you will get another
error message because `gcc` has two options and does not know which
one to use.

Multiple Files
--------------

Every non-trivial system is composed of multiple components.

C uses two types of files: header (`.h`) and source (`.c`). Header
files contain declarations of functions and types. Source files
implement functions. Header files are "included" and source files are
"compiled" and "linked".  To link source files, simply put the list of
source files after `gcc`.

As your programs become even larger, compiling every source file after
only a few changes becomes problematic.  Imagine that you need to
spend an hour compiling a large program (such as an operating
system) if you have changed only one line.  To solve this problem, C
adopts a two-stage process: source files (.c extension) can be
converted (called *compilation*) into an intermediate format called
*object files* (.o extension).  Then, object files are *linked* to
create the program (also called *executable*).  By convention, an
executable file in Linux has no extension (no `.c`, no `.h`, no
`.exe`).  If only one line in one source file is changed, only this
source file needs to be compiled.  Then, the object files are linked.
Compilation has done a lot of work already and linking object files
can be much faster (maybe only a few seconds).

make
----

By now, you may feel that there is a lot of work to do before you
write any code.  If you feel that you need to type a lot of things
after `gcc`, you are correct.  Fortunately, many tools have been created
to greatly simplify things.

All you need to do is five keystrokes: `make [Enter]`.

`make` is a Linux command.  You need to write a file telling `make` what
to do. This file, by convention, is called `Makefile`.

`Makefile` can also specify the sets of tests to run.

A Makefile may contain multiple sections.  Each section has three parts:

```
target: dependence
[TAB] action
```

For example

```
testgen: testgen.c testgen.h
	 gcc testgen.c -o testgen
```

This means the program `testgen` depends on `testgen.c` and
`testgen.h`. If either `testgen.c` or `testgen.h` is changed, `gcc`
will be called to compile `testgen.c` and generate `testgen`. Note
that it is important that there be a TAB character before the action
(not spaces).

You can define symbols in Makefile. For example,

`GCC = gcc -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror`

defines the flags mentioned earlier.

Please carefully study the Makefile included in this exercise. Note,
especially, the first few lines of the Makefile. These define symbols
that can be used elsewhere to avoid typing the same thing over and
over again. We use `GCC` in the rest of `Makefile` to make sure that
whenever we invoke `gcc`, we use the command line flags specified above.

Test Coverage
-------------

You would not write code for no purpose. You would think every line of
code does something meaningful. However, sometimes, a program's
conditions make certain portions of code unreachable. This is called
"dead code". Here are two examples of dead code.

```
if ((x > 1) && (x < 0))
{  
   // cannot reach here
}

int func(...)
{
    return ...;
    // whatever after return cannot be reached
}
```

Sometimes, the program's execution flow is not expected. Consider the
following example.

```
if (x > 0)
{
    // do something 
}
else
{
    // do something else
}
```

You may expect that `x` is greater than zero and the program should
"do something".  However, `x` is actually not greater than zero and
the program does "something else".  You can use many methods to detect
such an unexpected program execution flow. One of the methods is
called *test coverage*.  If `x` is not greater than zero, then the
code `do something` within the braces is not tested.

To use `gcov`, add

`-fprofile-arcs -ftest-coverage`

after `gcc`.

Then, execute the program as normal.  To see the coverage of a particular
source file type

`> gcov filename.c `

If any line is marked `#####`, this line is not tested.

How to Write High-Quality Software
----------------------------------

If you ask the students that have taken ECE 264, many will tell you
that ECE 264 "transformed" them from casual programmers to serious
software developers.  To put it another way, in ECE 264, you learn how
to develop serious software that may be used by others.

Do you notice the selection of words? Programmer and Software
Developer?  Are they different? Yes, they are different.

Developing software is much more than writing code (i.e.,
programming).  As a rough analogy, developing software is like
building a house and writing code is like laying bricks. Building a
house is much more than laying bricks.  Before laying down bricks, you
need to design the house. How many floors? Is there a basement?  How
many rooms? Is there a garage?  How would electrical wires, air flow,
and water pipes be connected?

Imagine laying bricks for a house before you have a design. It would
be a total disaster.  Many students, however, want to start writing
code before they have designed the software.  The results would not be
desirable.

Many students mistakenly believe that they should spend most time
debugging.  They want to write code quickly and then debug. This is
completely wrong.  You should spend most time designing, not
debugging.  Imagine that a house has been built and the owner
discovers that there is no electric sockets for the kitchen. How much
effort (and money) would be needed to correct this mistake?

Design before writing code. This is the rule. You will not be the
first person to break this rule. Do not try.

Many students think developing software is about creativity and they
cannot be restricted by rules.  This is also wrong.  Every creative
person must fully understand their tools and the boundaries of these
tools.  A musician must know many melodies. A painter must know how
colors interact. A gymnast needs to follow the law of gravity.  An
interior designer must understand sunlight and seasons.  A software
developer needs to understand the process of creating software.

Remember: spend time on design, not on debugging.  

Another common mistake is to start coding without reading and
understanding the entire exercise's requirements.

Every software developer needs to know debugging process.  The best
strategy, however, is to prevent bugs through careful design. Then, it
is important to detect bugs *automatically* by writing testing code.

Testing and 1-5 Rule
--------

When you design software, you need to think about how to test. 

Software developers frequently write code that is *never* shipped to
customers.  Why? The software developers write code to test the
functionality that is actually shipped to the customers.  The testing
code ensures that the customers get correct programs.

How to write testing code?  There are a few rules.  First, **do not
embedd testing code inside the functional code**. What does this mean? Suppose
you need to write a function called `func`, **do not** write it this way

```
... func(...)
{
   // do some work
   // test whether everything is correct so far
   // do some more work
   // test whether everything is still correct
   ...
}
```

Why is this bad? 
It mixes real work and tests. When you need to ship the finished
  program to your customers (or submit for grading), your program will
  be full of testing code that can potentially slow down your program
  and make it unuseable.  Some 264 students print debugging messages
  (that's all right) but submit the programs with these additional
  messages and lose points.

Some students say they should not lose points by printing *additional*
  message. This is wrong.  Imagine that you want to attend a friend's
  wedding in London and take a flight from Chicago.  The plane does
  not land in London and instead lands in Berlin.  The captain says,
  "We fly longer than what you wanted. Do not complain."  Would you be
  unhappy when this occurs and you miss the wedding?  If so, you
  should not be surprised when you lose points when your program
  prints additional, unwanted, messages.

Some students said that they would remove the testing code. They
(almost) always forgot. Worse, they often deleted additional code and
made the programs incorrect.

Some books encourage readers to use `assert`. **THIS IS WRONG. DO NOT
USE `assert`**.  The problem of `assert` is that the program stops
immediately.  Imagine that flight control software uses `assert` and
stops when a plane is flying!  Some people say "I use `assert` because
I know it must be right." This sentence is self-contrdictory.  A
programmer puts `assert` because the programmer *think* it is right
but is not completely sure.  If this programmer is 100% certain it is
right, the programmer would not put `assert` there (because there is
no need).  Thus, putting `assert` inside a program is a bad idea.

If putting testing code inside a function is bad, what is the correct
way of testing code?  The correct way is to **create another function
(or several functions)** and call the function being tested, for example,

```
... func(...)
{
   // do some work
   // do some more work
   ...
}

... test_func(...) // in another file
{
   // prepare data needed by func
   // call func and get the result
   // check whether the result from func is correct
}
```

When you ship the finished software (or submit an assignment), you can
simply remove the file for `test_func` without touching `func`.

"This is a lot of work.", you may say. Of course. Who said writing
good software would be easy?

Some people in software industry would tell you the "1-5 rule": for
every line of code that produces the final software shipped to
customers, software developers write another five lines of code for
testing and are never shipped to customers. 

Limit Core
----------

Coredump may be generated when your program terminates abnormally.
Coredump can be a very large file and use up your disk quota.  It is
unlikely that you would debug using coredump. Thus, it is recommended
that you limit the size of coredump to zero.

Additional Tools to Learn
--------------------------

You already know how to use Linux (since CS 159 uses Linux through
Putty). If you unfamiliar with Linux, please learn at least the
following tools:

* A good editor. You are encouraged to learn how to use *hot keys*
  (for example, for copy-paste) without using a mouse. Using hot keys
  can *dramatically* reduce the time you spend on editing.

* shell commands, such as `grep`, `awk`, `find`, `mkdir`, `cd`, `mv`,
  `ssh`, `scp`, `diff`, `sort`, `rm`, `cp`, `cat -n`, `man`, `head`,
  `tail`, `more`, `less`.

* Touch typing. If you use only one or two fingers in typing and need
  to look at the keyboard, you will spend a lot of time on
  typing. There are many on-line tutorials about touch typing. Spend a
  few hours learning touch typing and save many thousand hours in the
  coming years.

Grading
-------

If your program has any compilation error or warning (remember to use
`gcc -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror`), you will
receive zero.

In **absolutely no circumstance can the teaching staff modify your
program for grading**.  You cannot say, "If you change this, my
program works." If your program misses a semicolon and cannot compile,
you will receive zero.  Your score depends on what is submitted,
nothing else.

It is possible (and likely) that additional test cases will be used
for grading.  If your program fails any of the additional tests, you
will lose points.  It is your responsibility to create additional test cases.

Submitting Your Code through Blackboard
====================

**This exercise (HW01) is not a programming homework. You need to
answer questions in Blackboard.**

Homework exercises and assignments are submitted through Blackboard.
Before the submission deadline, you can withdraw and submit new
versions. Please understand that once you withdraw a submission,
**there is no record of prior submissions**.  You must submit as soon
as possible.  It is your responsibility submitting before the
deadlines. Blackboard automatically marks submissions as late based on
the clock of the machine that runs Blackboard (not your own watch).

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

OFFICE and LAB HOURS
--------------------

It is strongly encouraged to go to the office or lab hours for your
questions. Face-to-face discussion is  much more
efficient than writing long emails.

The teaching staff will NOT answer your questions by email, unless the questions are personal. 

DO NOT SEND YOUR CODE TO TEACHING STAFF
---------------------------------------

Under absolutely no circumstance will the teaching staff (instructors
and teaching assistants) debug your programs without your presence.
Such email is **ALWAYS** ignored.   

If you need help, go to office or lab hours.

EXCEPTIONAL SITUATIONS
----------------------

If there is a campus-wide situation (such as severe weather or power
outage), the instructors will extend submission deadlines for the
entire class.

If you encounter an exceptional situation (such as injury in a traffic
accident), the instructor will grant extensions based on the
recommendations of the proper authorities (such as medical doctors or
police).  You are responsible providing proper documents requesting
the extensions.

The teaching staff will **NOT** respond to email marked "URGENT".  For
all emergencies, please call 911.  All email marked **URGENT** is
automatically ignored because ECE 264 teaching staff is not trained as
first responders.

**DO NOT ASK FOR AN EXTENSION** because you will not get it. Do not
  waste your time asking a question whose answer is already known. It
  is **extremely rare** that a particular student receives an
  extension. A general principle is that if you *can* ask for an
  extension, you will *not* get it. If you truly need an extension
  (and can receive one), you are probably in a situation (such as a
  traffic accident) where asking for an extension is not your first
  priority. DO NOT WASTE YOUR TIME AND ASK FOR AN EXTENSION.

It is possible that an extension is given to the entire class, not a
specific person.

The instructor reserves the right to reject any request of
extension. Students have the right to request to the department, the
college, or the unversity to examine the instructor's decision.

FAIRNESS
--------

Before you ask the instructor for any special treatment, please ask
yourself the following question:

*"If the instructor does this to another student but not me, would it be fair?"*

If the answer is no, then do not ask.  

DIFFICULTY OF HOMEWORK
----------------------

**DO NOT UNDERESTIMATE THE DIFFICULTY OF THIS CLASS**.

The first several homework exercises are intentionally easier than
the others. The purpose is to give you time to set up your programming
environment, familiarize yourself with the tools, and review the
topics from CS 159 (if necessary).  Later exercises are considerably
more difficult.  It is important that you do well at the beginning of
the semester.  If you do poorly at the beginning, it would be almost
impossible to gain enough points later and get a good grade.

