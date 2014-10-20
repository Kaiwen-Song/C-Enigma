# edit this makefile so that running make compiles your enigma program

enigma: Main.o enigma.o reflector.o rotor.o plugboard.o 
	g++ -o enigma.o Main.o reflector.o rotor.o plugboard.o 

enigma.o: enigma.cpp Enigma.h
	g++ -c enigma.cpp 

Main.o: main.cpp 
	g++ -c main.cpp

reflector.o: reflector.cpp Reflector.h 
	g++ -c reflector.cpp

rotor.o: rotor.cpp Rotor.h
	g++ -c rotor.cpp

plugboard.o: plugboard.cpp Plugboard.h
	g++ -c plugboard.cpp



clean:
	rm -rf enigma *.o

.PHONY: clean
