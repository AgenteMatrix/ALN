CXXFLAGS = -Wall -std=c++11 -O2

all: exLU

clean:
	rm -f exLU *.o *.txt

exLU: main.o funciones.o
	$(CXX) $^ -o $@

main.o: main.cc funciones.h
funciones.o: funciones.cc 
