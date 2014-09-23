all: calcey.o mathey.o matrixey.o mathey

calcey.o: calcey.c mathey.hpp
	gcc -c calcey.c

mathey.o: mathey.cpp mathey.hpp
	g++ -c mathey.cpp

matrixey.o: matrixey.c
	gcc -c matrixey.c

mathey: mathey.o matrixey.o calcey.o
	g++ calcey.o mathey.o matrixey.o -o mathey
