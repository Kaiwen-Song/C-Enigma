# edit this makefile so that running make compiles your enigma program

enigma: main.o enigma.o reflector.o rotor.o plugboard.o 
	g++ -o enigma enigma.o main.o reflector.o rotor.o plugboard.o 

main.o: main.cpp
	g++ -c $^

enigma.o: enigma.cpp
	g++ -c $^

reflector.o: reflector.cpp
	g++ -c $^

rotor.o: rotor.cpp
	g++ -c $^

plugboard.o: plugboard.cpp 
	g++ -c $^


clean:
	rm -rf enigma *.o

.PHONY: clean
