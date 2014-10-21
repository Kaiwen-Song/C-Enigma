#ifndef PLUGBOARD_H
#define PLUGBOARD_H
#include "Operator.h"


class PlugBoard : public Operator{

private:
	Operator* opr;
	int fmap[ALPHABET_SIZE];

public:
		PlugBoard();
		~PlugBoard();
		void configure(char* fileDir);
		int outputForward(int input);
		int outputBack(int input);
		void setNextOpr(Operator* R);
		void rotate();
};

#endif