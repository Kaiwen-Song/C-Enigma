#ifndef ENIGMA_H
#define ENIGMA_H
#include "rotor.h"
#include "reflector.h"
#include "plugboard.h"

class Enigma{
	
Operator[] operators;
PlugBoard plugboard;
Reflector reflector;
int numberOfOperators; 

public: 

	void configurePlugBoard(char* configuration);

	void configureRotor(char* configuration, int position);

	Enigma(int numberOfOs);

	void output(int input);
};

#endif