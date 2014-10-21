// skeleton C++ file, you will need to edit this and other files to implement your enigma machine
#include <stdexcept>
#include <iostream>
#include <fstream>
#include "Enigma.h"

using namespace std;

int charToInt(char c);
char intToChar(int i);


int main(int argc, char **argv)
{
	unique_ptr<Enigma> enigma (new Enigma(argc));
	enigma->configurePlugBoard(argv[argc-1]);
	
	if(argc>2){
	for(int i = 0; i< argc-2; i++){
		enigma->configureRotor(argv[i+1], i+1);
	  }
	}

	char input;
	while(cin>>input){
		cout<<intToChar(
		(enigma->output(charToInt(input))));
		enigma->rotateRotor();
	}

}

int charToInt(char c){
	if(c < 'A' || c > 'Z'){
		perror("input only between A and Z please!");
	}
	int input = c - 65; 
	return input;

}

char intToChar(int i){
	if(i < 0 || i > 26){
		perror("input only between A and Z please!");
	}
	char output = i + 65;
	return output;

}
