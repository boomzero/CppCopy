main: main.o
	cc main.o -o main

main.o: main.cpp
	cc -c main.cpp -o main.o
