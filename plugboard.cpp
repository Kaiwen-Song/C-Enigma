#include "Plugboard.h"
#include <stdexcept>

using namespace std;

PlugBoard::PlugBoard(){
	for(int i = 0; i<ALPHABET_SIZE; i++){
		fmap[i] = i;
	}
}


void PlugBoard::configure(char* fileDir){

//this vector loads the immediate numbers retrieved from the input stream
	vector<int> configuration;
	ifstream conFILE(fileDir);

	//counter for the number of values stored
	int noOfValues = 0;
	int valueRead;

	//if file doesnt exist, throw an exception
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

		//configure the fmap.
		fmap[value1] = value2;
		fmap[value2] = value1;
		}

	}

}

void PlugBoard::setNextOpr(Operator* R){
	opr = R;
}

//invoke the next operator to output after matching input with map
int PlugBoard::outputForward(int input){
	return opr->outputForward(fmap[input]);
}

int PlugBoard::outputBack(int input){
	return fmap[input];
}

void PlugBoard::rotate(){};