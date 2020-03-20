#include "funciones.h"

using namespace std;

int main(int argc, char *argv[]) {

	if(argc < 3) {
		cerr << endl << "-----------------------------------------------------------------------" << endl;
		cerr << "Error: indica el fichero de los datos y el nombre del fichero de salida" << endl;
		cerr << "Ejemplo de uso: ./main.exe DATA OUTPUT.txt" << endl;
		cerr << "-----------------------------------------------------------------------" << endl;
		exit(-1);
	}

	////////////////////////*** [ LECTURA DE DATOS ] ***////////////////////////

	ifstream Datos;
	Datos.open(argv[1], ifstream::in);

	if(Datos.fail()) {
		cerr << endl << "------------------------------------------------" << endl;
		cerr << "Error: no se ha podido abrir el fichero de datos" << endl;
		cerr << "------------------------------------------------" << endl;
		exit(-1);
	}

	//n: dimensión de la matriz A (nxn) y de b (nx1).
	//m: número de componentes diferentes de 0 de la matriz A.
	int n, m, i, j;
	Datos >> n >> m;

	M A(n, V(n, 0));
	V b(n, 0);

	while(m--) Datos >> i >> j >> A[i][j];

	Datos >> m;
	while(m--) Datos >> i >> b[i];

	Datos.close();

	////////////////////////////*** [ BEGIN PROGRAMA ] ***/////////////////////////////

	//Vector de soluciones x
	V x(n, 0);
	x = resuelve(A, b);

	//Matriz de la descomposición LU y el vector de permutaciones.
	M LU = A;
	VI perm(n, 0);
	lu(LU, perm);

	//Matriz U y L de la descomposición.
	M U = LU;
	M L = calculo_LU(U);

	//Vector residuo.
	V r(n, 0);
	r = calculo_res(A, x, b);

	//OUTPUT.
	cout << scientific << setprecision(15);

	cout << endl << "Dim del sistema: " << n << endl << endl;

	cout << "Det A = " << determinante(A) << endl << endl;

	cout << "El vector de permutaciones es: ( ";
	for(int i : perm) cout << i << ' ';
		cout << ")" << endl << endl;

	cout << "[ Estimación del error en la descomposicón PA = LU ]" << endl;
	cout << "||PA - LU||_1 = " << norma_1(resta(calculo_PA(A, perm), producto(L, U))) << endl;
	cout << "||PA - LU||_inf = " << norma_inf(resta(calculo_PA(A, perm), producto(L, U))) << endl << endl;

	cout << "[ Estimación del error en la resolución Ax = b ]" << endl;
	cout << "||Ax - b||_1 = " << norma_1_vector(r) << endl;
	cout << "||Ax - b||_2 = " << norma_2_vector(r) << endl;
	cout << "||Ax - b||_inf = " << norma_inf_vector(r) << endl;


	////////////////////////////*** [ END PROGRAMA ] ***/////////////////////////////


	////////////////////////////*** [ SALIDA DE DATOS ] ***////////////////////////////

	ofstream Resultados;
	Resultados.open(argv[2], ofstream::out);

	if(Resultados.fail()) {
		cerr << endl << "----------------------------------------------------" << endl;
		cerr << "Error: no se ha podido abrir el fichero de reultados" << endl;
		cerr << "----------------------------------------------------" << endl;
		exit(-1);
	}

	Resultados << scientific << setprecision(15);

	for(int i = 0; i < n; ++i) Resultados << setw(4) << i << setw(24) << x[i] << endl;

	Resultados.close();
}	