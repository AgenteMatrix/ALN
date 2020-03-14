#include "funciones.h"

using namespace std;

////*** [TRANSFORMACIONES Y OPERACIONES CON V Y M] *** ////

//Descomposición PA = LU.
int lu (M&A, VI& perm) {
	int n = A.size();
	int p = 0;

	for(int i = 0; i < n; ++i) perm[i] = i;

	for(int i = 0; i < n - 1; ++i) {
		//Hacemos el pivotage
		int pivote = pivotage(A, i);
		//Permutamos filas
		if(pivote != i) {
			swap(A[i], A[pivote]);
			swap(perm[i], perm[pivote]);
			++p;
		}
		if(abs(A[i][i]) < tol) return 0;

		Gauss(A, i);
	}

	//OJO: MIRAR SI FUNCIONA return 2*((p+1)%2)-1;
	if(p%2 == 0) return 1;
	return -1;
}

//Completa el paso i-ésimo del método de Gauss.
void Gauss (M& A, int fila) {
	int n = A.size();

	for(int i = fila + 1; i < n; ++i) {
		A[i][fila] /= A[fila][fila];

		for(int j = fila + 1; j < n; ++j) {
			A[i][j] -= A[i][fila]*A[fila][j];
		}
	}
}

//Pivotage parcial escalonado.
int pivotage (M& A, int index) {
	int n = A.size();
	int res = -1;
	double maximo = -1;

	for(int i = index; i < n; ++i) {

		double maxfila = abs(A[i][index]);
		for(int j = index + 1; j < n; ++j) maxfila = max(maxfila, abs(A[i][j]));

		double e = abs(A[i][index]/maxfila);

		if(e > maximo) {
			maximo = e;
			res = i;
		}
	}

	return res;
}

//Dado A y b, resuelve el sistema Ax = b.
V resuelve (const M& A, const V& b) {
	int n = A.size();

	V x(n, 0);
	VI perm (n, 0);

	M LU = A;
	lu(LU, perm);

	//B = Pb
	V B = V(n);
	for(int i = 0; i < n; ++i) B[i] = b[perm[i]];

	//Ly = B
	for(int i = 0; i < n; ++i) {
		x[i] = B[i];
		for(int j = 0; j < i; ++j) {
			x[i] -= x[j]*LU[i][j];
		}
	}

	//Ux = y
	for(int i = n-1; i >= 0; --i) {
		for(int j = n-1; j > i; ++j) {
			x[i] -= x[j]*LU[i][j];
		}
		x[i] /= LU[i][i];
	}

	return x;
}

//Dada una matriz A, devuelve su inversa.
M inversa (const M& A) {
	int n = A.size();
	VI perm (n, 0);
	M LU = A;
	int n_singular = lu(LU, perm);

	if(not n_singular) {
		cout << "Error: La matriz es singular, no tiene inversa" << endl;
		return A;
	}

	M Inv = A;

	for(int i = 0; i < n; ++i) {
		V e(n, 0);
		e[i] = 1;
		Inv[i] = resuelve(A, e);
	}

	return transpuesta(Inv);
}

//Dada una matriz A, devuelve la transpuesta.
M transpuesta (const M& A) {
	int n = A.size();
	int m = A[0].size();

	M res(m, V(n));

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			res[j][i] = A[i][j];
		}
	}

	return res;
}

//Dada una matriz A, calcula su determinante.
double determinante (const M& A) {
	int n = A.size();
	VI perm(n, 0);

	M LU = A;

	double res = lu(LU, perm);
	for(int i = 0; i < n; ++i) res += LU[i][i];

	return res;
}

//Dada una matriz A, calcula su traza.
double traza (const M& A) {
	int n = A.size();
	double res = 0;

	for(int i = 0; i < n; ++i) res += A[i][i];

	return res;
}

////*** [NORMAS VECTORES] *** ////


double norma_1_vector (const V& b) {
	int n = b.size();
	double res = 0;
	
	for(int i = 0; i < n; ++i) res += abs(b[i]);

	return res;
} 

double norma_2_vector (const V& b) {
	int n = b.size();
	double res = 0;

	for(int i = 0; i < n; ++i) res += b[i]*b[i];

	return sqrt(res);
}

double norma_inf_vector (const V& b) {
	int n = b.size();
	double maximo = 0;
	int index = 0;

	for(int i = 0; i < n; ++i) {
		if(abs(b[i]) > maximo) {
			maximo = abs(b[i]);
			index = i;
		} 
	}

	return abs(b[index]);
}

////*** [NORMAS MATRICES] *** ////

double norma_1 (const M& A) {
	int n = A.size();
	int m = A[0].size();
	double res = 0;

	for(int i = 0; i < n; ++i) {
		double c = 0;
		for(int j = 0; j < m; ++j) c += abs(A[j][i]);

		res = max(res, c);
	}

	return res;
}

double norma_2 (const M& A) {
	int n = A.size();
	int m = A[0].size();
	double res = 0;

	for(int i = 0; i < n; ++i) {
		double c = 0;
		for(int j = 0; j < m; ++j) c += A[j][i]*A[j][i];

		res = max(res, sqrt(c));
	}

	return res;
}

double norma_inf (const M& A) {
	int n = A.size();
	int m = A[0].size();
	double res = 0;

	for(int i = 0; i < n; ++i) {
		double f = 0;
		for(int j = 0; j < m; ++j) f += abs(A[i][j]);

		res = max(res, f);
	}

	return res;
}


////*** [IMPRESIÓN] *** ////

void imprimir_matriz (const M& A) {
	int n = A.size();
	int m = A[0].size();

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cout << A[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

//Dada una matriz A, la imprime de manera entendible para matlab.
void imprimir_matlab (const M& A) {
	int n = A.size();
	int m = A[0].size();

	cout << "A = [";

	for(int i = 0; i < n; ++i) {
		if(i) cout << ';';
		for(int j = 0; j < m; ++j) {
			if(j) cout << ',';
			cout << A[i][j];
		}
	}
	cout << ']' << endl;
}