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
	//memory is freed after exiting the program
	unique_ptr<Enigma> enigma (new Enigma(argc));
	enigma->configurePlugBoard(argv[argc-1]);
	

	if(argc>2){
	for(int i = 0; i< argc-2; i++){
		enigma->configureRotor(argv[i+1], i+1);
	  }
	}

//continously load the input into the variable, using the enigma to encode
	char input;
	while(cin>>input){
		cout<<intToChar(
		(enigma->output(charToInt(input))));
		enigma->rotateRotor();
	}

}


//process the input char, turning it into an int and passed into the enigma
int charToInt(char c){
	if(c < 'A' || c > 'Z'){
		perror("input only between A and Z please!");
	}
	int input = c - 65; 
	return input;

}


//process the output int, turning it into a char and output it through terminal
char intToChar(int i){
	if(i < 0 || i > 26){
		perror("input only between A and Z please!");
	}
	char output = i + 65;
	return output;

}
