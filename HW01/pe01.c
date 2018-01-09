#include <stdio.h>   // declare functions for IO
#include <stdlib.h>  // define EXIT_FAILURE and EXIT_SUCCESS
#include <string.h>  // for strcmp
#include <stdbool.h> // for Boolean type (true or false)
// For header files provided by C, use < >
// gcc looks for these header files in /usr/include

#include "pe01.h"
// For a header file defined by you, use " "
// gcc looks for the file in the current directory

int main(int argc, char * * argv)
{
  // argv is an array of strings. You can think of it as string *,
  // even though C does not have string as a type.
  // Each string is an array of characters (i.e., char *); thus,
  // argv's type is char * *

  // argc is the number of strings in argv. argc is at least
  // 1 (the program's name). argv[0] is always the program's name

  // This program needs three arguments
  // argv[1]: a long integer for a
  // argv[2]: a long integer for b
  // argv[3]: A, S, M, or D for add, sub, mul, or divide

  if (argc != 4)
    {
      fprintf(stderr, "argc is %d, not 4\n", argc);
      // stderr means standard error, usually it is the computer
      // screen but it is possible to save the messages to a file
      // by using ">&" (without the quotation marks)
      
      return EXIT_FAILURE;
      // Since the program cannot do what it needs to do (add,
      // subtract, multiply, or divide), it returns EXIT_FAILURE.
      // Use EXIT_FAILURE or EXIT_SUCCESS
      // Do NOT use return 0, -1, or 1
    }

  // At this point, there are enough arguments (argc is 4).
  // Get the value of a and b
  // Check which operation to do

  long vala = strtol(argv[1], NULL, 10);
  long valb = strtol(argv[2], NULL, 10);
  // strtol converts a string to a long integer
  // strtol is more flexible than atoi because strtol supports
  // different number bases. In this example, the base is 10 (the
  // third argument). strtol allows the base to be 2 to 36
  // (inclusively).

  long valresult = 0;
  bool valid = false;
  // determine the operation to perform
  // If the operation is not "A", "S", "M", or "D". it is an error.
  if (strcmp(argv[3], "A") == 0)
    {
      valresult = addop (vala, valb);
      valid = true;
    }
  if (strcmp(argv[3], "S") == 0)
    {
      valresult = subop (vala, valb);
      valid = true;
    }
  if (strcmp(argv[3], "M") == 0)
    {
      valresult = mulop (vala, valb);
      valid = true;
    }
  if (strcmp(argv[3], "D") == 0)
    {
      valresult = divop (vala, valb);
      valid = true;
    }

  if (valid == false) // unknown operation
    {
      fprintf(stderr, "unknown opeartion %s\n", argv[3]);
      return EXIT_FAILURE;
    }

  printf("The result is %ld\n", valresult);
  return EXIT_SUCCESS;
}
