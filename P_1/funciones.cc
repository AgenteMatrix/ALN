#include "funciones.h"

using namespace std;

////*** [ TRANSFORMACIONES Y OPERACIONES CON V Y M ] ***////

//Descomposición PA = LU.
int lu (M&A, VI& perm) {
	int n = A.size();
	int p = 0;

	for(int i = 0; i < n; ++i) perm[i] = i;

	for(int i = 0; i < n - 1; ++i) {
		int pivote = pivotage(A, i);
		if(pivote != i) {
			swap(A[i], A[pivote]);
			swap(perm[i], perm[pivote]);
			++p;
		}

		if(abs(A[i][i]) < tol) return 0;

		Gauss(A, i);
	}

	if(abs(A[n-1][n-1]) < tol) return 0;

	return 2*((p+1)%2)-1;
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
	double maximo = -1.0;

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

	V x(n, 0.0);
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
		for(int j = n-1; j > i; --j) {
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
		cerr << endl << "-------------------------------------------------------" << endl;
		cerr << "Error inversa: La matriz es singular, no tiene inversa." << endl;
		cerr << "-------------------------------------------------------" << endl;
		return A;
	}

	M Inv = A;

	for(int i = 0; i < n; ++i) {
		V e(n, 0);
		e[i] = 1.0;
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
	for(int i = 0; i < n; ++i) res *= LU[i][i];

	return res;
}

//Dada una matriz A, calcula su traza.
double traza (const M& A) {
	int n = A.size();
	double res = 0.0;

	for(int i = 0; i < n; ++i) res += A[i][i];

	return res;
}

//Dadas una matriz A y B, calcula su producto.
M producto (const M& A, const M& B) {
	int n = A.size(), m = A[0].size();
	int p = B.size(), q = B[0].size();

	if(m != p) {
		cerr << endl << "------------------------------------------" << endl;
		cerr << "Error producto: las dimensiones no cuadran" << endl;
		cerr << "------------------------------------------" << endl;
		return A;
	}

	M res(n, V(q, 0.0));

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < q; ++j) {
			for(int k = 0; k < m; ++k) res[i][j] += A[i][k]*B[k][j];
		}
	}

	return res;
}

//Dadas una matriz A y B, calcula su suma.
M suma (const M& A, const M& B) {
	int n = A.size(), m = A[0].size();
	int p = B.size(), q = B[0].size();

	if(n != p or m != q) {
		cerr << endl << "--------------------------------------" << endl;
		cerr << "Error suma: las dimensiones no cuadran" << endl;
		cerr << "--------------------------------------" << endl;
		return A;
	}

	M res = A;

	for(int i = 0; i < p; ++i) {
		for(int j = 0; j < q; ++j) res[i][j] += B[i][j];
	}
	
	return res;
}

//Dadas una matriz A y B, calcula su resta.
M resta (const M& A, const M& B) {
	int n = A.size(), m = A[0].size();
	int p = B.size(), q = B[0].size();

	if(n != p or m != q) {
		cerr << endl << "---------------------------------------" << endl;
		cerr << "Error resta: las dimensiones no cuadran" << endl;
		cerr << "---------------------------------------" << endl;
	}

	M res = A;

	for(int i = 0; i < p; ++i) {
		for(int j = 0; j < q; ++j) res[i][j] -= B[i][j];
	}

	return res;
}

//Dados unos vectores u y v, calcula su suma.
V suma_vectores (const V& u, const V& v) {
	int n = u.size();
	int m = v.size();

	if(n != m) {
		cerr << endl << "-----------------------------------------------" << endl;
		cerr << "Error suma_vectores: las dimensiones no quadran" << endl;
		cerr << "-----------------------------------------------" << endl;
		return u;
	}

	V res(n, 0.0);
	for(int i = 0; i < n; ++i) res[i] = u[i] + v[i];

	return res;
}

//Dados unos vectores u y v, calcula su resta.
V resta_vectores (const V& u, const V& v) {
	int n = u.size();
	int m = v.size();

	if(n != m) {
		cerr << endl << "------------------------------------------------" << endl;
		cerr << "Error resta_vectores: las dimensiones no quadran" << endl;
		cerr << "------------------------------------------------" << endl;
		return u;
	}

	V res(n, 0.0);
	for(int i = 0; i < n; ++i) res[i] = u[i] - v[i];

	return res;
}

//Dada una dimensión n, devuelve una matriz identidad de dim nxn.
M identidad (int n) {
	M res(n, V(n, 0.0));
	for(int i = 0; i < n; ++i) res[i][i] = 1.0;
	return res;
}

//Devuelve r = Ax - b.
V calculo_res (M& A, V& x, V& b) {
	int n = A.size();
	int m = A[0].size();

	if(m != (int) x.size()) {
		cerr << endl << "---------------------------------------------" << endl;
		cerr << "Error calculo_res: las dimensiones no cuadran" << endl;
		cerr << "---------------------------------------------" << endl;
		return x;
	}

	if(n != (int) b.size()) {
		cerr << endl << "---------------------------------------------" << endl;
		cerr << "Error calculo_res: las dimensiones no cuadran" << endl;
		cerr << "---------------------------------------------" << endl;
		return x;
	}

	V r(n);

	for(int i = 0; i < n; ++i) {
		r[i] = -b[i];
		for(int j = 0; j < n; ++j) r[i] += A[i][j]*x[j];
	}

	return r;

}

//Devuelve la matriz P*A.
M calculo_PA (M& A, VI& perm) {
	int n = A.size();
	int m = A[0].size();

	if(n != (int) perm.size()) {
		cerr << endl << "--------------------------------------------" << endl;
		cerr << "Error calculo_PA: las dimensiones no cuadran" << endl;
		cerr << "--------------------------------------------" << endl;
		return A;
	}

	M PA(n, V(m));

	for(int i = 0; i < n; ++i) {
		PA[i] = A[perm[i]];
	}

	return PA;
}

//Dada una descomposición LU, devuelve la matriz L y por referencia la matriz U.
M calculo_LU (M& A) {
	int n = A.size();

	M L(n, V(n, 0.0));

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if(j < i) {
				L[i][j] = A[i][j];
				A[i][j] = 0.0;
			}
			if(i == j) L[i][j] = 1.0;
		}
	}

	return L;
}

////*** [ NORMAS VECTORES ] ***////

double norma_1_vector (const V& b) {
	int n = b.size();
	double res = 0.0;
	
	for(int i = 0; i < n; ++i) res += abs(b[i]);

	return res;
} 

double norma_2_vector (const V& b) {
	int n = b.size();
	double res = 0.0;

	for(int i = 0; i < n; ++i) res += b[i]*b[i];

	return sqrt(res);
}

double norma_inf_vector (const V& b) {
	int n = b.size();
	double maximo = 0.0;
	int index = 0;

	for(int i = 0; i < n; ++i) {
		if(abs(b[i]) > maximo) {
			maximo = abs(b[i]);
			index = i;
		} 
	}

	return abs(b[index]);
}

////*** [ NORMAS MATRICES ] ***////

double norma_1 (const M& A) {
	int n = A.size();
	int m = A[0].size();
	double res = 0.0;

	for(int i = 0; i < n; ++i) {
		double actual = 0.0;
		for(int j = 0; j < m; ++j) actual += abs(A[j][i]);

		res = max(res, actual);
	}

	return res;
}

double norma_inf (const M& A) {
	int n = A.size();
	int m = A[0].size();
	double res = 0.0;

	for(int i = 0; i < n; ++i) {
		double actual = 0;
		for(int j = 0; j < m; ++j) actual += abs(A[i][j]);

		res = max(res, actual);
	}

	return res;
}

////*** [ NÚMERO DE CONDICIÓN ] ***////

//Dada una matriz A, devuelve su número de condición_1 y si es singular devuelve 0 y un mensaje de error.
double condicion_1 (const M& A) {
	int n = A.size();
	M LU = A;
	VI perm(n, 0);

	if(not lu(LU, perm)) {
		cerr << endl << "-----------------------------------------------------------------" << endl;
		cerr << "Error condicion_1: matriz singular, número de condición infinito." << endl;
		cerr << "-----------------------------------------------------------------" << endl;
		return 0;
	}

	return norma_1(A) * norma_1(inversa(A));
}

//Dada una matriz A, devuelve su número de condición_inf y si es singular devuelve 0 y un mensaje de error.
double condicion_inf (const M& A) {
	int n = A.size();
	M LU = A;
	VI perm(n, 0);

	if(not lu(LU, perm)) {
		cerr << endl << "-------------------------------------------------------------------" << endl;
		cerr << "Error condicion_inf: matriz singular, número de condición infinito." << endl;
		cerr << "-------------------------------------------------------------------" << endl;
		return 0;
	}

	return norma_inf(A) * norma_inf(inversa(A));
}

////*** [ IMPRESIÓN ] ***////

//Dada una matriz A, la imprime por terminal.
void imprimir_matriz (const M& A) {
	int n = A.size();
	int m = A[0].size();

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cout << setw(15) << A[i][j] << ' ';
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