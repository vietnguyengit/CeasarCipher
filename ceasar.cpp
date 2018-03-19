/*
	Author: Viet Nguyen
*/
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
				charFreqBefore[oldChar - 'A']++;
				newChar = newChar = (oldChar - 'A' + 4) % 26 + 'A';
				charFreqAfter[newChar - 'A']++;
				if (lLower) newChar = tolower(newChar);
				fileOutput.write(reinterpret_cast<const char*>(&newChar), sizeof(newChar));
			}
			else {
				fileOutput.write(reinterpret_cast<const char*>(&oldChar), sizeof(oldChar));
			}
		}
	}
}

ostream& operator<<(ostream& stOutput, const Ceasar& ceasar) {
	stOutput << "Character frequencies: <before, after>" << endl;
	for (int i = 0; i < 26; i++) {
		stOutput << char(i + 'A') << ":\t" << ceasar.charFreqBefore[i] << "," << ceasar.charFreqAfter[i] << endl;
	}
	return stOutput;
}

