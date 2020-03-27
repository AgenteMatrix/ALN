CXXFLAGS = -Wall -std=c++11

all: exLU test.out

clean:
	rm -f exLU test.out *.o *.txt

run:
	 @while [ -z "$$nombre" ]; do \
		read -r -p "Introduce el archivo de datos: " nombre; \
	done; \
	./exLU "$$nombre" output.txt

list:
	@echo "Número de ficheros de datos: ";  ls *DAT -1 | wc -l;
	@echo "Lista de ficheros: "; ls  *.DAT;

test:
	./test.out

help:
	@echo "'make all' 	para compilar."
	@echo "'make clean' 	para eliminar los ficheros innecesarios"
	@echo "'make list' 	para listar los archivos de datos del directorio."
	@echo "'make run' 	para ejecutar el programa con una entrada de datos."
	@echo "'make test' 	para ejecutar el programa con todas las entradas de datos."

exLU: main.o funciones.o
	$(CXX) $^ -o $@

main.o: main.cc funciones.h

funciones.o: funciones.cc

test.out: test.o
	$(CXX) $^ -o $@

test.o: test.cc