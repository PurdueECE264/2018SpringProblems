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

// sort the values in the frequency table
void SortFrequency(CharFreq * freq);


#endif
