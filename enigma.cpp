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

//delete every operator stored within the operation.
Enigma::~Enigma(){
	for(int i = 0; i<numberOfOperators; ++i){
		delete operators[i];
	}
}

void Enigma::configurePlugBoard(char* fileDir){
	operators[0]->configure(fileDir);
}

//configure a rotor at a specified position with dir to a configuration file
void Enigma::configureRotor(char* fileDir, int position){
	operators[position]->configure(fileDir);
}

//the output gets bounced back at the reflector
int Enigma::output(int input){
	return (operators[0])->outputForward(input);
}

//rotate the rotor after each calculation
void Enigma::rotateRotor(){
	if(numberOfOperators > 2){
	dynamic_cast<Rotor*>(operators[1])->rotate();
	}
}

/*this goes through the array of pointers to objects, sets up their 
linkers to the next, and in other cases the previous objects
*/
void Enigma::setLinks(){
	dynamic_cast<PlugBoard*>(operators[0])->setNextOpr(operators[1]);
	dynamic_cast<Reflector*>(operators[numberOfOperators-1])-> 
		setNextOperator(operators[numberOfOperators-2]);
	for(int i = 1; i < numberOfOperators-1; ++i){
	  dynamic_cast<Rotor*>(operators[i]) -> setNext(operators[i+1]);
	  dynamic_cast<Rotor*>(operators[i]) -> setPrev(operators[i-1]);
	}	
}
