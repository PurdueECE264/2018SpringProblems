#ifndef PE07_H_
#define PE07_H_

// This will define bool data type for C
typedef enum { false=0, true } bool;




// This function will return true if the string "str" is an integer, false otherwise.
// str : is the string (char array)
// index : is the index ( to keep track of which character to check next)

bool IsInteger(char* str, int index);



// This function will return true if the string "str" is a Double, false otherwise.
// str : is the string (char array)
// index : is the index ( to keep track of which character to check next)
// dot : is a flag that will be set true once you find the first dot in the string.
bool IsDouble(char* str, int index,bool dot);


// This function will return true if the string "str" is a valid identifier, false otherwise.
// str : is the string (char array)
// index : is the index ( to keep track of which character to check next)
bool IsValidIdentifier(char* str, int index);


#endif
