CXX = g++
CXXFLAGS = -std=c++11 -g3 -Wall -fopenmp
MKDIR = mkdir -p
LIBS = -lm

directorios:
	$(MKDIR) build dist

clean:
	rm -fr *.o a.out build dist

Monomio.o: directorios Monomio.cpp Monomio.h
	$(CXX) $(CXXFLAGS) -c Monomio.cpp -o build/Monomio.o

utils.o: directorios utils.cpp utils.h
	$(CXX) $(CXXFLAGS) -c utils.cpp -o build/utils.o 

main.o: directorios main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o build/main.o

all: clean directorios main.o Monomio.o utils.o
	$(CXX) $(CXXFLAGS) -o dist/programa build/main.o build/Monomio.o build/utils.o $(LIBS)
	rm -fr build

.DEFAULT_GOAL := all