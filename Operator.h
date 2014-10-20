#ifndef OPERATOR_H
#define OPERATOR_H
#define ALPHABET_SIZE 26
#include <vector>
#include <fstream>

//the abstract class of Reflector, Plugboard and Rotor
 
class Operator{
	
protected:
	
	//mapping input to output going forward
	int fmap[ALPHABET_SIZE];

	//mapping input to output going backwards
	int bmap[ALPHABET_SIZE];

	//temporary storage of the input configuration
	std::vector<int>configuration;

public:
	//configure the maps using the file at the directory
	virtual void configure(char* fileDir) = 0;

	//forward pass of the input through the system
	virtual int outputForward(int input) = 0;

	//backward pass of the input through the system after the forward pass
	virtual int outputBack(int input) = 0;

	//for rotating rotors, empty function for plugboard and reflector
	virtual void rotate() = 0;
	};

#endif
