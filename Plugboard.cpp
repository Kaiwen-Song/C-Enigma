#include "Plugboard.h"
using namespace std;

PlugBoard::PlugBoard(){
	defaultConfig = true;
	for(int i = 0; i<ALPHABET_SIZE; i++){
		configuration[i] = i;
	}
}

void PlugBoard::configure(char* fileDir){

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
		int value1; 
		int value2;
		for(int i = 0; i< noOfValues; i+=2){
		value1 = configuration[i];
		value2 = configuration[i+1];
		fmap[value1] = value2;
		bmap[value2] = value1; 
			}

	}

	conFILE.close();
}

void PlugBoard::setNextOpr(Operator* R){
	opr = R;
}

int PlugBoard::outputForward(int input){
	if(defaultConfig)return (*opr).outputForward(input);
	else return (*opr).outputForward(fmap[input]);
}

int PlugBoard::outputBack(int input){
	if(defaultConfig)return (*opr).outputForward(input);
	else return (*opr).outputForward(fmap[input]);
}

bool shouldRotate(){
	return false;
}