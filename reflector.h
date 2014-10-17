#ifndef REFLECTOR_H
#define REFLECTOR_H
#include "operator.h"

class Reflector : public Operator{
private: 
	Operator& opr;
	int stored;

public: 
	Reflector();
	Reflector(Operator* R);
	~Reflector();
	void setNextOperator(Operator* R);
	int output(int input);
	void configure(char* configuration);
	int outputForward(int input);
	int outputBack(int input);
};

#endif