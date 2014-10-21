#include "Reflector.h"

Reflector::Reflector(){
}

Reflector::Reflector(Operator* R){
	opr = R;
}


void Reflector::setNextOperator(Operator* R){
	opr = R;
}


int Reflector::outputForward(int input){
	return opr->outputBack((input+13)%26);
}

int Reflector::outputBack(int input){};

void Reflector::configure(char* fileDir){};

void Reflector::rotate(){};