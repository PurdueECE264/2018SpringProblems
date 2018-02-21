#ifndef PA08_H_
#define PA08_H_
typedef enum { false=0, true } bool;



typedef struct{
char digit_start; // This variable will be used to deterime the start range of the digits for identifier.
char digit_end;   // This variable will be used to deterime the end range of the digits for identifier.
char upper_case_start; // This variable will be used to deterime the start of the range of the upper case alphabet for identifier.
char upper_case_end; // This variable will be used to deterime the end of the range of the upper case alphabet for identifier.
char lower_case_start;// This variable will be used to deterime the start of the range of the lower case alphabet for identifier.
char lower_case_end;// This variable will be used to deterime the end of the range of the lower case alphabet for identifier.
}VIDVar; 

typedef struct{
char digit_start; // This variable will be used to deterime the start range of the digits for double .
char digit_end;   // This variable will be used to deterime the end range of the digits for double.

}DoubleVar;

//string: contains the value of the double, you need to build it up. Before calling the function string will be empty
// as you keep going this array of char will get filled. i.e first call string="", second call string="1", thrid call="1.", and so on ...
//index: used to determine which index of the string to fill.
//bool : used to determine whether the string has a dot or not so far. If string="1", dot will be false, string="1.", dot is true now.
//len: the length of the string you want to create, so if the len=4, and string="11.1", then you need print string, and return.
void createDouble(char * string,DoubleVar* var,int index,bool dot,int len);


void createVID(char * string,VIDVar *var,int index,int len);





#endif
