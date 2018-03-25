#include "frequency.h"

// Counting the frequencies of the characters in the frequency table
int CountFrequency(char * filename, CharFreq * freq){
  // open the file
  // get through each element of the file and get each character
  // read each character from the file
  // put the value in the freq table except for the newline character i.e '\n'
	// close the file and return success
  return EXIT_SUCCESS;
}


// Print statement for the print the frequency table
void PrintFreq (CharFreq *charFreqArray){
	// for each element of charFreqArray call PrintSingleCharFreq
}



// Sort function for sorting frequencies
void SortFrequency(CharFreq * freq){
	// sort the frequencies in the ascending order
	// if frequencies are same then the character with lower ascii value will be first
}

// Print frequency function
//
void PrintSingleCharFreq(CharFreq charfreq){
	printf("char=%c, freq=%d\n",charfreq.data, charfreq.freq );
}
