#include<iostream> 
#include<vector> 
#include<fstream>	//Leer archivos de entrada
#include<iomanip>	//Setprecision

using namespace std;

//Simplificación del lenguaje y comprensión del código
using V = vector<double>;
using M = vector<V>;

int main(int argc, char *argv[]) {

	//DETECCIÓN DE ERRORES EN LA ENTRADA

	if(argc < 2) {
		cerr << "Error: indica el fichero de los datos" << endl;
		cerr << "Ejemplo de uso: ./main.exe DATA" << endl;
		exit(-1);
	}

	//Declaración Datos como un objeto de la clase ifstream.
	ifstream Datos;

	//Abrimos el archivo para leerlo.
	Datos.open(argv[1], ifstream::in);

	//Comprovacion de que se ha podido abrir el fichero
	if(Datos.fail()) {
		cerr << "Error: no se ha podido abrir el fichero de datos" << endl;
		exit(-1);
	}

	//LECTURA DE LOS DATOS

	//n: dimensión de la matrix A (nxn) y de b (nx1).
	//m: número de componentes diferentes de 0 de la matriz A.
	int n, m, i, j;
	Datos >> n >> m;

	//Declaración de la matriz A y el vector b.
	M A(n, V(n, 0));
	V b(n, 0);

	while(m--) Datos >> i >> j >> A[i][j];

	Datos >> m;
	while(m--) Datos >> i >> b[i];

	Datos.close();

	//FUNCIONES

	//Declaración del vector de soluciones x.
	V x(n);

	//CÁLCULO DE NORMAS

	//ESCRITURA DE LOS RESULTADOS POR PANTALLA

	//ESCRITURA DE LOS RESULTADOS EN UN FICHERO

	//Declaramos Resultados como un objeto de la classe ofstream.
	ofstream Resultados;

	//Abrimos el fichero para escribir.
	Resultados.open("output.txt", ofstream::out);

	//Comprovacion que se ha podido abrir el fichero.
	if(Resultados.fail()) {
		cerr << "Error: no se ha podido abrir el fichero de reultados" << endl;
		exit(-1);
	}

	//Precisión en los resultados.
	Resultados << scientific << setprecision(15);

	//Salida de resultados con 'Resultados >> *'.

	//Cerramos el fichero con los resultados.
	Resultados.close();
}