#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "restore_comparisons.h"

int replace_comparisons(char* inputString, char* resultString);
int getNextSymbol(char* inputString, int inputIndex, char* resultSymbol);
bool checkForEncoding(char* inputString, int startIndex, const char* encoding);

char* restore_comparisons(char* str) {
  int inputLength = strlen(str);
	char* toReturn = calloc(inputLength + 1, sizeof(char)); // Need one more space for null character
	int resultLength = replace_comparisons(str, toReturn); // Includes the null character
	toReturn = realloc(toReturn, resultLength * sizeof(char)); // Shrinks the memory allocated to fit the data.
  return toReturn;
}

int replace_comparisons(char* inputString, char* resultString) {
	int inputLength = strlen(inputString);
	int resultIndex = 0;
	int inputIndex = 0;

	while (inputIndex < inputLength) {
		char resultSymbol; // Used to retrieve an encoded symbol
		int encodingLength = getNextSymbol(inputString, inputIndex, &resultSymbol);
		resultString[resultIndex] = resultSymbol;
		resultIndex++;
		inputIndex += encodingLength;
	}
	resultString[resultIndex] = '\0';
	return resultIndex + 1; // The total length (including null character) of resultString
}

int getNextSymbol(char* inputString, int startIndex, char* resultSymbol) {
	// encodings and their corresponding symbols, add more if you want and be sure to update numberOfEncodings to match!
	int numberOfEncodings = 2;
	const char* encodings[] = {"&lt;", "&gt;"};
	const char translatedSymbols[] = {'<', '>'};
	
	bool found = false;
	int counter = 0;
	while (!found && counter < numberOfEncodings) {
		found = checkForEncoding(inputString, startIndex, encodings[counter]);
		if (!found) {
			counter++;
		}
	}
	
	if (found) {
		*resultSymbol = translatedSymbols[counter];
		return strlen(encodings[counter]); // return length of the encoding
	} else {
		*resultSymbol = inputString[startIndex]; // pass out the unencoded character
		return 1;
	}
}

bool checkForEncoding(char* inputString, int startIndex, const char* encoding) {
	// Gets the index of the last relevant char in the string (before the terminating null character)
	int inputLength = strlen(inputString);
	int encodingLength = strlen(encoding);
	int inputIndex = startIndex;
	int encodingIndex = 0;
	while (inputIndex < inputLength && encodingIndex < encodingLength) {
		if (inputString[inputIndex] != encoding[encodingIndex]) {
			return false;
		}
		inputIndex++;
		encodingIndex++;
	}
	return encodingIndex == encodingLength; // only true if we've matched the entire encoding
}
