#ifndef OPERATOR_H
#define OPERATOR_H
#define ALPHABET_SIZE 26
#include <memory>

class Operator{
	
protected:
	
	int fmap[ALPHABET_SIZE];
	int bmap[ALPHABET_SIZE];
	std::unique_ptr<int[ALPHABET_SIZE]>configuration(int[ALPHABET_SIZE]);

public:
	Operator();
	virtual void configure(char* configurations) = 0;
	virtual int outputForward(int input) = 0;
	virtual int outputBack(int input) = 0;

	};

#endif