CXXFLAGS = -Wall -std=c++11 -O2

all: exLU

clean:
	rm -f exLU test *.o *.txt
run:
	 @while [ -z "$$nombre" ]; do \
		read -r -p "Introduce el archivo de datos: " nombre; \
	done; \
	./exLU "$$nombre" output.txt

list:
	@echo "Número de ficheros de datos: ";  ls *DAT -1 | wc -l;
	@echo "Lista de ficheros: "; ls  *.DAT;

test:
	g++ -Wall test.cc -o test;
	./test

help:
	@echo "'make all' para compilar."
	@echo "'make clean' para eliminar los ficheros *.o *.txt y el ejecutable."
	@echo "'make list' para mostrar los archivos de datos del directorio."
	@echo "'make run' para ejecutar el programa con una sola entrada de datos."
	@echo "'make test' para ejecutar el programa con todas las entradas de datos."

exLU: main.o funciones.o
	$(CXX) $^ -o $@

main.o: main.cc funciones.h

funciones.o: funciones.cc
