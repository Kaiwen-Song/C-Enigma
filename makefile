# edit this makefile so that running make compiles your enigma program

enigma: Main.o enigma.o reflector.o rotor.o plugboard.o 
	g++ -o enigma.o Main.o reflector.o rotor.o plugboard.o 

enigma.o: Enigma.cpp
	g++ -c Enigma.cpp

Main.o: Main.cpp
	g++ -c Main.cpp

reflector.o: Reflector.cpp 
	g++ -c Reflector.cpp

rotor.o: Rotor.cpp 
	g++ -c Reflector.cpp

plugboard.o: Plugboard.cpp
	g++ -c Plugboard.cpp



clean:
	rm -rf enigma *.o

.PHONY: clean
