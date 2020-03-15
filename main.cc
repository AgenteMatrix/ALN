#include "funciones.h"

using namespace std;

int main(int argc, char *argv[]) {

	//DETECCIÓN DE ERRORES EN LA ENTRADA

	if(argc < 3) {
		cerr << "Error: indica el fichero de los datos y el nombre del fichero de salida" << endl;
		cerr << "Ejemplo de uso: ./main.exe DATA OUTPUT.txt" << endl;
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



	/////////////////////////////////  PROGRAMA  /////////////////////////////////

	V x(n, 0);
	x = resuelve(A, b);

	M LU = A;
	VI perm(n, 0);
	lu(LU, perm);

	V r(n, 0);
	r = calculo_res(A, x, b);

	M PA(n, V(n));


	cout << "Dim del sistema: " << n << endl << endl;

	cout << "[Estimación del error en la descomposicón PA = LU]" << endl;
	cout << "||PA - LU||_1 = " << norma_1(resta(calculo_PA(A, perm), LU)) << endl;
	cout << "||PA - LU||_2 = " << norma_2(resta(calculo_PA(A, perm), LU)) << endl;
	cout << "||PA - LU||_inf = " << norma_inf(resta(calculo_PA(A, perm), LU)) << endl << endl;

	cout << "El vector de permutaciones es: ( ";
	for(int i : perm) cout << i << ' ';
		cout << ")" << endl << endl;

	cout << "Det A = " << determinante(A) << endl << endl;

	cout << "[Estimación del error en la resolución Ax = b]" << endl;
	cout << "||Ax - b||_1 = " << norma_1_vector(r) << endl;
	cout << "||Ax - b||_2 = " << norma_2_vector(r) << endl;
	cout << "||Ax - b||_inf = " << norma_inf_vector(r) << endl;

	/////////////////////////////////  PROGRAMA  /////////////////////////////////



	//Declaramos Resultados como un objeto de la classe ofstream.
	ofstream Resultados;

	//Abrimos el fichero para escribir.
	Resultados.open(argv[2], ofstream::out);

	//Comprovacion que se ha podido abrir el fichero.
	if(Resultados.fail()) {
		cerr << "Error: no se ha podido abrir el fichero de reultados" << endl;
		exit(-1);
	}

	//Precisión en los resultados.
	Resultados << scientific << setprecision(15);

	//Salida de resultados con 'Resultados >> *'.
	for(int i = 0; i < n; ++i) Resultados << setw(4) << i << setw(24) << x[i] << endl;
	//Cerramos el fichero con los resultados.
	Resultados.close();
}