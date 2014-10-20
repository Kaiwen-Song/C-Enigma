#include "Rotor.h"
using namespace std;

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

	
	void Rotor::rotate(){
		next->rotate();
		++rotations %= 26;
	}

	void Rotor::configure(char* fileDir){
		ifstream conFILE;
		int noOfValues = 0;
		int valueRead;
		conFILE.open(fileDir, ios::in);
		if(conFILE.fail()){
			perror("error printing files");
		} else {
		while(conFILE>>valueRead){
			configuration.push_back(valueRead);
			++noOfValues;
		}
		for(int i = 0; i< ALPHABET_SIZE; i++){
			fmap[i] = configuration[i];
			bmap[configuration[i]] = i; 
			}

		}

	conFILE.close();
	}
	
	void Rotor::setPrev(Operator* prev){
		previous = prev;
	}

	void Rotor::setNext(Operator* nxt){
		next = nxt;
	}

	int Rotor::outputForward(int input){
		return (*next).outputForward(fmap[input+rotations]);
	}

	int Rotor::outputBack(int input){
		return (*previous).outputBack(bmap[input+rotations]);
	}
