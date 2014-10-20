#ifndef OPERATOR_H
#define OPERATOR_H
#define ALPHABET_SIZE 26
#include <vector>
#include <fstream>

class Operator{
	
protected:
	
	int fmap[ALPHABET_SIZE];
	int bmap[ALPHABET_SIZE];
	std::vector<int>configuration;

public:
	//Operator();
	//~Operator();
	virtual void configure(char* fileDir) = 0;
	virtual int outputForward(int input) = 0;
	virtual int outputBack(int input) = 0;
	virtual void rotate() = 0;
	};

#endif
