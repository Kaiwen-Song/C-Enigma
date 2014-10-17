#ifndef	ROTOR_H
#define ROTOR_H
#include "operator.h"

class Rotor: public Operator{
private: 
	int rotations;
	std::map<int, int> backwards_map;
	Operator& previous;
	Operator& next;

public: 
	Rotor(char* configuration);
	void rotate();
	int outputForward(int input);
	int outputBack(int input);
};
#endif