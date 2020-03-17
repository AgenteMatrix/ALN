CXXFLAGS = -Wall -std=c++11 -O2

all: exLU

clean:
	rm -f exLU *.o *.txt
run:
	./exLU M01.DAT output.txt

help: 
	@echo "'make all' para compilar "
	@echo "'make clean' para eliminar los ficheros *.o *.txt"
	@echo "'make run' para ejecutar el programa"
exLU: main.o funciones.o
	$(CXX) $^ -o $@

main.o: main.cc funciones.h
funciones.o: funciones.cc 
