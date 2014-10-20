#include "Enigma.h"

	Enigma::Enigma(int numberOfOps){
		numberOfOperators = numberOfOps;
		operators = new Operator* [numberOfOperators];
		operators[0] = new PlugBoard();
		operators[numberOfOps - 1] = new Reflector();
		for(int i = 0; i < numberOfOps-2; i++){
			operators[i+1] = new Rotor();
		}
	}

	void Enigma::configurePlugBoard(char* fileDir){
		operators[0]->configure(fileDir);
	}

	void Enigma::configureRotor(char* fileDir, int position){

		operators[position-1]->configure(fileDir);
	};

	int Enigma::output(int input){
		return (operators[numberOfOperators-1])->outputBack((operators[0])->outputForward(input));
	};

	void Enigma::rotateRotor(){
		if(numberOfOperators > 2){
		operators[1]->rotate();
		}
	}

	void Enigma::setLinks(){
		dynamic_cast<PlugBoard*>(operators[0])->setNextOpr(operators[1]);
		dynamic_cast<Reflector*>(operators[numberOfOperators-1])-> 
			setNextOperator(operators[numberOfOperators-2]);
		for(int i = 1; numberOfOperators-1; ++i){
		dynamic_cast<Rotor*>(operators[i]) -> setPrev(operators[i-1]);
		}	
	}
