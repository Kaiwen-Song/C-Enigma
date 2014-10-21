#include "Plugboard.h"
#include <stdexcept>

using namespace std;

PlugBoard::PlugBoard(){
	for(int i = 0; i<ALPHABET_SIZE; i++){
		fmap[i] = i;
	}
}

void PlugBoard::configure(char* fileDir){
	vector<int> configuration;
	ifstream conFILE(fileDir);
	int noOfValues = 0;
	int valueRead;
	if(!conFILE){
		throw runtime_error("file name does not exist");
	} else {
		while(conFILE>>valueRead){
			configuration.push_back(valueRead);
			++noOfValues;
		}
		conFILE.close();
		int value1; 
		int value2;
		for(int i = 0; i< noOfValues; i+=2){
		value1 = configuration[i];
		value2 = configuration[i+1];
		fmap[value1] = value2;
		fmap[value2] = value1;
		}

	}

}

void PlugBoard::setNextOpr(Operator* R){
	opr = R;
}

int PlugBoard::outputForward(int input){
	return opr->outputForward(fmap[input]);
}

int PlugBoard::outputBack(int input){
	return fmap[input];
}

void PlugBoard::rotate(){};