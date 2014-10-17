// skeleton C++ file, you will need to edit this and other files to implement your enigma machine
#include <stdexcept>
#include <iostream>
#include <fstream>
//#include "enigma.h"
#include "reflector.h"
using namespace std;

int main(int argc, char **argv)
{
 	
  /*return 0;

  


	Enigma enigma = new Enigma(argc + 1);
	enigma.configurePlugBoard(argv[argc-1]);
	for(int i = 0; i< argc-2; i++){
		enigma.configurateRotor(argv[i+1], i+1);
	}

*/



Reflector ref;
int input;
cin>>input;
cout<<ref.output(input);


}
