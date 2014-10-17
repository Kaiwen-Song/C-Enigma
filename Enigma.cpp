#include "enigma.h"

	Enigma::Enigma(int numberOfOps){
		numberOfOperators = numberOfOps;
		operators = new Operator[numberOfOperators];
		operators[0] = new PlugBoard();
		operators[numberOfOps - 1] = new Reflector();
		for(int i = 0; i < numberOfOps-2; i++){
			operators[i+1] = new Rotor();
		}
	}

	void configurePlugBoard(char* configuration){
		pluboard.configure(configuration);
	}

	void configureRotor(char* configuration, int position){

		rotors[position].configure(configuration)
	};

	int output(int input){
		return operators[numberOfOperators-1].outputBack(operators[0].outputForward(input));
	};