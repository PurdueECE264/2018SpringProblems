#ifndef FREQ_H
#define FREQ_H
#include <stdio.h>
#include <stdlib.h>

#define NUMLETTER 256


// Calculating the frequency of the values in the file
typedef struct {
  unsigned char data;
  int freq;
} CharFreq;

// count the Frequency of the each character
int CountFrequency(char * filename, CharFreq * freq);

// Print the frequencies and check
void PrintFreq (CharFreq *freq);

// sort the values in the frequency table
void SortFrequency(CharFreq * freq);


// Single Printing function
void PrintSingleChar(CharFreq charfreq);


#endif
