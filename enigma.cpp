#include "Enigma.h"

Enigma::Enigma(int numberOfOps){
	numberOfOperators = numberOfOps;	
	operators = new Operator* [numberOfOperators];
	operators[0] = new PlugBoard();
	operators[numberOfOps - 1] = new Reflector();
	for(int i = 0; i < numberOfOps-2; ++i){
		operators[i+1] = new Rotor();
	}
	setLinks();
}

Enigma::~Enigma(){
	for(int i = 0; i<numberOfOperators; ++i){
		delete operators[i];
	}
}

void Enigma::configurePlugBoard(char* fileDir){
	operators[0]->configure(fileDir);
}

void Enigma::configureRotor(char* fileDir, int position){
	operators[position]->configure(fileDir);
}

int Enigma::output(int input){
	return (operators[0])->outputForward(input);
}

void Enigma::rotateRotor(){
	if(numberOfOperators > 2){
	dynamic_cast<Rotor*>(operators[1])->rotate();
	}
}

void Enigma::setLinks(){
	dynamic_cast<PlugBoard*>(operators[0])->setNextOpr(operators[1]);
	dynamic_cast<Reflector*>(operators[numberOfOperators-1])-> 
		setNextOperator(operators[numberOfOperators-2]);
	for(int i = 1; i < numberOfOperators-1; ++i){
	  dynamic_cast<Rotor*>(operators[i]) -> setNext(operators[i+1]);
	  dynamic_cast<Rotor*>(operators[i]) -> setPrev(operators[i-1]);
	}	
}
