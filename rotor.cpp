#include "Rotor.h"
#include <stdexcept>

//maps first int of the pair is the input
//second one is the mapped to value, thus the index 
Rotor::Rotor(char* fileDir){
rotations = 0;
configure(fileDir);
}

Rotor::Rotor(){
	rotations = 0;
}

Rotor::Rotor(char* fileDir, Operator* prev, Operator* nxt){
	rotations = 0;
	configure(fileDir);
	previous = prev;
	next = nxt;
}

//if rotated enough times, tries to rotate the next operator linked
//if the next is a rotor, it rotates, else does nothing.
void Rotor::rotate(){
	if(rotations == 25) next->rotate();
	(++rotations) %= 26;
}

//configure in a similar fashion as plugboard
void Rotor::configure(char* fileDir){
	vector<int> configuration;
	ifstream conFILE(fileDir);
	int valueRead;
	if(!conFILE){
		throw runtime_error("file does not exist");
	} else {
	while(conFILE>>valueRead){
		configuration.push_back(valueRead);
	}
	conFILE.close();

	for(int i = 0; i< ALPHABET_SIZE; i++){
		fmap[i] = configuration[i];
		bmap[configuration[i]] = i; 
		}

	}
}

void Rotor::setPrev(Operator* prev){
	previous = prev;
}

void Rotor::setNext(Operator* nxt){
	next = nxt;
}

//forward pass of the input through the rotor
int Rotor::outputForward(int input){
	int output = fmap[(input+rotations)%26];
	output -= rotations;
	if(output<0){
		output += ALPHABET_SIZE;
	}
	return next->outputForward(output);
}

//backward pass of the input through the rotor
int Rotor::outputBack(int input){
	int output = (bmap[(input+rotations)%26]);
	output -= rotations;
	if(output<0){
		output+= ALPHABET_SIZE;
	}
	return previous->outputBack(output);
}
