# edit this makefile so that running make compiles your enigma program

enigma: main.o enigma.o reflector.o rotor.o plugboard.o 
	g++ -std=c++11 -o enigma enigma.o main.o reflector.o rotor.o plugboard.o 

main.o: main.cpp
	g++ -std=c++11 -c $^

enigma.o: enigma.cpp
	g++ -std=c++11 -c $^

reflector.o: reflector.cpp
	g++ -std=c++11 -c $^

rotor.o: rotor.cpp
	g++ -std=c++11 -c $^

plugboard.o: plugboard.cpp 
	g++ -std=c++11 -c $^

clean:
	rm -rf enigma *.o

.PHONY: clean
