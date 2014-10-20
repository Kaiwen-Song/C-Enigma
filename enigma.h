#ifndef ENIGMA_H
#define ENIGMA_H
#include "Rotor.h"
#include "Reflector.h"
#include "Plugboard.h"

class Enigma{
	
Operator** operators;
int numberOfOperators; 

public: 

	void configurePlugBoard(char* fileDir);

	void configureRotor(char* fildDir, int position);

	Enigma(int numberOfOs);

	int output(int input);

	void rotateRotor();
};

#endif