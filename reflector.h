#ifndef REFLECTOR_H
#define REFLECTOR_H
#include "Operator.h"

class Reflector : public Operator{
private: 
	Operator* opr;
	int stored;

public: 
	Reflector();
	Reflector(Operator* R);
	~Reflector();
	void setNextOperator(Operator* R);
	void configure(char* fileDir);
	int outputForward(int input);
	int outputBack(int input);
	bool shouldRotate();
};

#endif