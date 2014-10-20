#include "Reflector.h"

Reflector::Reflector(){
	for(int i = 0; i< 26; i++){
		fmap[i] = 26-i;
	}

}

Reflector::Reflector(Operator* R){
	opr = R;
	for(int i = 0; i< 26; i++){
		fmap[i] = 26-i;
	}

}

void Reflector::setNextOperator(Operator* R){
	opr = R;
}


int Reflector::outputForward(int input){
	stored = fmap[input];
	return stored;
}

int Reflector::outputBack(int input){
	return (*opr).outputBack(stored);
}

void Reflector::configure(char* fileDir){};

bool shouldRotate(){
	return false;
}