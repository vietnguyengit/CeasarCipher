/*
	Author: Viet Nguyen
*/
#include "ceasar.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
	Ceasar newCeasar;
	ifstream fInput{ argv[1], ios::in | ios::binary };
	ofstream fOutput{ argv[2], ios::out | ios::binary };
	newCeasar.mechanism(fInput, fOutput);
	cout << newCeasar;
}