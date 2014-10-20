#ifndef ENIGMA_H
#define ENIGMA_H
#include "Rotor.h"
#include "Reflector.h"
#include "Plugboard.h"

class Enigma {
	
Operator** operators;
int numberOfOperators; 

public: 
	Enigma(int numberOfOs);
	~Enigma();
	
	void configurePlugBoard(char* fileDir);

	void configureRotor(char* fildDir, int position);

	int output(int input);

	void rotateRotor();

	void setLinks();
};

#endif
