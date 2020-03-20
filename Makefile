CXXFLAGS = -Wall -std=c++11 -O2

all: exLU

clean:
	rm -f exLU *.o *.txt
run:
	 @while [ -z "$$nombre" ]; do \
		read -r -p "Introduce el nombre de los datos: " nombre; \
	done; \
	./exLU "$$nombre" output.txt

list:
	ls -l *.DAT

help:
	@echo "'make all' para compilar."
	@echo "'make clean' para eliminar los ficheros *.o *.txt y el ejecutable."
	@echo "'make list' para mostrar los archivos de datos del directorio."
	@echo "'make run' para ejecutar el programa."

exLU: main.o funciones.o
	$(CXX) $^ -o $@

main.o: main.cc funciones.h

funciones.o: funciones.cc
