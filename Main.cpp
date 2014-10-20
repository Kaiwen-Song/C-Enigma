// skeleton C++ file, you will need to edit this and other files to implement your enigma machine
#include <stdexcept>
#include <iostream>
#include <fstream>
#include "Enigma.h"

using namespace std;

int processInputChar(char c);
char processOutputInt(int i);


int main(int argc, char **argv)
{
	Enigma* enigma = new Enigma(argc + 1);
	enigma->configurePlugBoard(argv[argc-1]);
	for(int i = 0; i< argc-2; i++){
		enigma->configureRotor(argv[i+1], i+1);
	}

	char input;
	while(cin>>input){
			cout<<processOutputInt(
				(enigma->output(processInputChar(input))));
			enigma->rotateRotor();
		}

}

int processInputChar(char c){
	if(c < 'A' || c > 'Z'){
		//perror;
	}
	int input = c; 
	return input;

}

char processOutputInt(int i){
	if(i < 65 || i > 90){
		//perror;
	}
	char output = i;
	return output;

}
