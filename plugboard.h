#ifndef PLUGBOARD_H
#define PLUGBOARD_H
#include "Operator.h"


class PlugBoard : public Operator{

private:
	bool defaultConfig;
	Operator* opr;

public:
		PlugBoard();
		void configure(char* fileDir);
		int outputForward(int input);
		int outputBack(int input);
		void setNextOpr(Operator* R);
		bool shouldRotate();
};
#endif