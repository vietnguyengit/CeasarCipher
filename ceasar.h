#ifndef CEASAR_H_
#define CEASAR_H_

#include <iostream>
#include <fstream>

class Ceasar {
private:
	int charFreqBefore[26];
	int charFreqAfter[26];
public:
	Ceasar();
	void mechanism(std::ifstream&, std::ofstream&);
	friend std::ostream& operator<<(std::ostream&, const Ceasar&);
};

#endif CEASAR_H_