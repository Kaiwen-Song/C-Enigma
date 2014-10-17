#ifndef PLUGBOARD_H
#define PLUGBOARD_H
#include "operator.h"


class Plugboard : public Operator{

private:
	bool defaultConfig;
	operator& op;

public:
		Plugboard();
		void configure(char* configuration);
		void outputForward(int input);
		void outputBack(int input);
};
#endif