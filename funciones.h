#ifndef funciones_h
#define funciones_h

#include<iostream>
#include<vector>
#include<fstream>	//Lee archivos de entrada, escribe archivos de salida
#include<iomanip>	//Setprecision
#include<math.h>
#include<cstdlib>

using namespace std;

using V = vector<double>;
using VI = vector<int>;
using M = vector<V>;

//Tolerancia
const double tol = 1e-12;

//TRANSFORMACIONES Y OPERACIONES CON V Y M
int lu (M& A, VI& perm);
int pivotage (M& A, int index);
V resuelve (const M& A, const V& b);
void Gauss (M& A, int fila);
M inversa (const M& A);
double determinante (const M& A); 
M producto (const M& A, const M& B);
M transforma (const V& b);
M suma (const M& A, const M& B);
M resta (const M& A, const M& B);
M transpuesta (const M& A);
V suma_vectores (const V& u, const V& v);
double traza (const M& A);
M identidad (int n);

//NORMAS VECTORES
double norma_1_vector (const V& b);
double norma_2_vector (const V& b);
double norma_inf_vector (const V& b);

//NORMAS MATRICES
double norma_1 (const M& A);
double norma_2 (const M& A);
double norma_inf (const M& A);

//IMPRESIÓN
void imprimir_matriz (const M& A);
void imprimir_matlab (const M& A);

#endif