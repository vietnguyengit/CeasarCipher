#include "ceasar.h"
#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

Ceasar::Ceasar() : charFreqBefore(), charFreqAfter() {}

void Ceasar::mechanism(ifstream& fileInput, ofstream& fileOutput) {
	if (!fileInput) {
		cerr << "Input file cannot be opened" << endl;
		exit(EXIT_FAILURE);
	}
	else if (!fileOutput) {
		cerr << "Output file cannot be processed" << endl;
		exit(EXIT_FAILURE);
	}
	else {
		char oldChar;
		char newChar;
		while (fileInput.get(oldChar)) {
			if (isalpha(oldChar)) {
				bool lLower = islower(oldChar);
				oldChar = toupper(oldChar);
				newChar = newChar = (oldChar - 'A' + 4) % 26 + 'A';
				if (lLower) newChar = tolower(newChar);
				fileOutput.write(reinterpret_cast<const char*>(&newChar), sizeof(newChar));
			}
			else {
				fileOutput.write(reinterpret_cast<const char*>(&oldChar), sizeof(oldChar));
			}
		}
	}
}

