# edit this makefile so that running make compiles your enigma program

enigma: clean Main.o
	g++ -o enigma Main.o

Main.o: Main.cpp
	g++ -std=c++11 -c Main.cpp

clean:
	rm -rf enigma *.o

.PHONY: clean
