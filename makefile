all: program

program: plik.o macierz.o main.o
			g++ plik.o macierz.o main.o -o program

plik.o: plik.cpp plik.h
			g++ -c -Wall plik.cpp

macierz.o: macierz.cpp macierz.h
			g++ -c -Wall macierz.cpp

program.o: main.cpp
			g++ -c -Wall main.cpp

clean:
	rm -rf *o prog
