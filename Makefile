# Makefile for compilation of gcc and cuda version of pmuca ising2D

FLAGS=-pedantic -Wall -Wextra -O3 -std=c++0x -I ./Random123/include/ -I Random123/include/Random123

all: testrng_c testrng_cpp

testrng_c: testrng.c
	g++ testrng.c $(FLAGS) -o $@
	
testrng_cpp: testrng.cpp
	g++ testrng.cpp $(FLAGS) -o $@


clean:
	rm -f testrng_c
	rm -f testrng_cpp
