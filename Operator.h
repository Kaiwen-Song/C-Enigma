#ifndef OPERATOR_H
#define OPERATOR_H
#define ALPHABET_SIZE 26
#include <vector>
#include <fstream>
#include <memory>

//the abstract class of Reflector, Plugboard and Rotor
 
class Operator{
	
public:
	//configure the maps using the file at the directory
	virtual void configure(char* fileDir) = 0;

	//forward pass of the input through the system
	virtual int outputForward(int input) = 0;

	//backward pass of the input through the system after the forward pass
	virtual int outputBack(int input) = 0;

	virtual void rotate() =0;
};
#endif