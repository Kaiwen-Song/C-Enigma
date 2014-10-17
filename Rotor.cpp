#include "rotor.h"


	//maps first int of the pair is the input
	//second one is the mapped to value, thus the index 
	Rotor::Rotor(char* configuration){
		rotations = 0;
		configure(configuration);
	}

	

	
	void rotate(){
		rotations = ++rotations % 26;
	}

	void Rotor::configure(char* configurations){

	}
	

	int Rotor::output(int input){
		return fmap[input+rotations];
	}

	int outputBack(int input){
		return previous.outputBack(bmap[intput+rotations]);
	}