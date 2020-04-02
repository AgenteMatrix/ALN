# Práctica 1 de Álgebra Lineal Numérica
Descomposición LU

Eduardo Peña Royuela ~
2020

## Introducción

El programa cumple el siguiente objetivo principal: **Resolver un sistema lineal determinado Ax = b**, y se caracteriza por hacerlo mediante la **descomposición LU** de la matriz A. Además de esto, también se han programado otras varias utilidades que pueden ser útiles en otras circunstancias.

## Códigos fuente

El proyecto consta de los siguientes códigos:
* <tt>main.cc</tt> 
* <tt>funciones.cc</tt> 
* <tt>funciones.h</tt> 
* <tt>Makefile</tt> 
* <tt>test.cc</tt> 

## Arquitectura

Como ya se ha enseñado este proyecto esta separado en varios ficheros. El <tt>main.cc</tt> es el programa principal y el que se ejecuta en primer lugar. Es en este donde se leen los datos de entrada, se determina qué se quiere que realice el programa y en último lugar, imprime la salida. Después está el fichero <tt>funciones.h</tt>, que es donde están definidas las diferentes funciones de este proyecto así como otras constantes y variables que intervienen en el proyecto. Es en <tt>funciones.cc</tt> donde están escritas e implementadas las funciones anteriormente mencionadas. Finalmente, este proyecto consta de un archivo <tt>Makefile</tt> para hacer el funcionamiento de todo más sencillo, y el archivo <tt>test.cc</tt>, que funciona juntamente con el <tt>Makefile</tt>, sirve para probar todas las entradas de datos disponibles en una ejecución.

## Explicación de uso

Primero de todo es necesario descargar la carpeta de este proyecto y situarse a través de la consola en el directorio donde lo hayamos hecho. Recordamos que también es necesario tener los ficheros de datos (que no constan en este repositorio) en el mismo directorio. Una vez hecho esto, entonces:

Para compilar, haz

* <tt>g++ main.cc funciones.h funciones.cc -o exLU</tt>

Y para ejecutar el programa, siendo *MXX.DAT* el nombre del archivo de entrada y *OUTPUT.txt* el nombre del de salida, haz 

* <tt>./exLU MXX.DAT OUTPUT.txt </tt>

El proceso anterior se puede simplificar mucho gracias al **Makefile**. Entonces para compilar. haz

* <tt>make all</tt> 

Para ejecutar el programa haz,

<tt>make run</tt> ~ Y te pedirá el nombre de el fichero de datos de entrada. El nombre del archivo de salida por defecto es **output.txt**.

En el **Makefile** se han programado otras funcionalidades como:

* <tt>make clean</tt> ~ Para eliminar los archivos creados al compilar y ejecutar el programa.

* <tt>make list</tt> ~ Para mostrar la cantidad de ficheros de datos disponibles.

* <tt>make test</tt> ~ Para ejecutar el programa con todas las entradas de datos disponibles. De esta forma también creara un archivo de salida <tt>outputXX.txt</tt> para cada entrada de datos.

Y finalmente

* <tt>make help</tt> ~ Para que se muestre por terminal los posibles comandos 'make' que puedes llevar a cabo y una breve descripción de ellos.

Es importante saber que el programa hará lo que sea especificado en el <tt>main.cc</tt> y este está abierto a ser modificado, indicando que funciones deben ser ejecutadas. También cabe recalcar que se debe indicar manualmente en el archivo <tt>test.cc</tt> la cantidad de ficheros de datos se poseen y como es su estructura de nombre (en el estado actual solo se contempla la estructura <tt>MXX.DAT</tt> y <tt>MSINGULARXX.DAT</tt> con <tt>XX</tt> = (00, 01, ..., 99)).

## Funciones

Este proyecto consta de las siguientes funciones, escritas como ya se ha indicado en <tt>funciones.cc</tt>. Fijémonos que estas están separadas en diferentes clases dentro del programa, en **Transformaciones y operaciones con V y M**, **Normas vectores**, **Normas matrices**, **Número de condición** e **Impresión**.

### Transformaciones y operaciones con V y M

- **lu**

Dada una matriz *A* y un vector de enteros *perm*, la función devuelve 0 si *A* es singular, 1 si se han realizado una cantidad par de permutaciones en la **descomposición LU** de *A*, y -1 si se han realizado una cantidad impar. Además, la matriz *A* acaba siendo expresada en su forma **LU** y el vector *perm* asaba siendo el vector de permutaciones. Estos dos parámetros están pasados por referencia.

- **pivotage**

Dada una matriz *A* y un *index* (variable entera), esta función realiza el **Pivotage parcial escalonado** y devuelve el i-ésimo pivote de *A*.

- **Gauss**

Dada una matriz *A* y un entero *fila*, realiza el i-éssimo paso del método de Gauss.

- **resuelve**

Dada una matriz *A* y un vector de términos independientes *b*, esta función devuelve el vector *x* de la resolución **Ax = b**.

- **calculo_res**

Dada una matriz *A*, un vector de términos independientes *b* y un vector de soluciones *x*, devuelve **r = Ax - b**.

- **calculo_PA**

Dada una matriz *A* y un vector de permutaciones *perm*, devuelve la matriz resultante del producto **PA**.

- **calculo_LU**

Dada una matriz *A* en su descomposición **LU**, devuelve la matriz *L* de esta descomposición y la matriz *A*, que es pasada por referencia, la transforma en la matriz *U*.

- **determinante**

Dada una matriz *A*, calcula su determinante mediante a la **descomposición LU**.

- **traza**

Dada una matriz *A*, calcula su traza.

- **suma, resta, producto**

Dadas dos matrices *A* y *B*, devuelven la matriz resultante de su suma, resta y producto respectivamente.

- **suma_vectores, resta_vectores**

Dados dos vectores *v* y *u*, devuelven el vector resultante de su suma y resta respectivamente.

- **inversa**

Dada una matriz *A*, devuelve su inversa (si es que tiene) haciendo uso de la función **resuelve**.

- **transpuesta**

Dada una matriz *A*, devuelve su transpuesta.

- **identidad**

Dada una dimensión *n*, devuelve una matriz identidad de dimensión *nxn*.

###  Normas vectores

- **norma_1_vector, norma_2_vector, norma_inf_vector**

Dado un vector *b*, devuelve su norma_1, norma_2 y norma_inf respectivamente.

### Normas matrices

- **norma_1, norma_inf**

Dada una matriz *A*, devuelve su norma_1 y norma_2 respectivamente.

### Número de condición

- **condicion_1, condicion_inf**

Dada una matriz *A*, devuelve su número de condición sub 1 y sub inf respectivamente. Si la matriz *A* es singular, entonces devuelve 0 y un mensaje de error indicando que el número de condición es *infinito*.

### Impresión

- **imprimir_matriz**

Dada una matriz *A*, la escribe por terminal.

- **imprimir_matlab**

Dada una matriz *A*, la escribe por terminal de manera leíble para Matlab.

## Otras consideraciones

### Formato de los datos

Es necesario que los ficheros de datos tengan un cierto formato para ser leídos correctamente. Lo primero que tiene que aparecer es la dimensión de la matriz (cuadrada) que tiene que coincidir con la del vector de términos independientes. A continuación se determinan los elementos diferentes de 0 de la matriz, después y precedido por su fila y columna los elementos diferentes de 0. A continuación se sigue el mismo procedimiento para el vector, primero la cantidad de elementos diferentes de 0, después fila, columna y el elemento diferente de 0. Todos los indices empiezan en 0.

### Decimales en la salida y tolerancia admitida

El número de decimales impresos en la salida es por defecto **15**, pero se puede modificar en el inicio de <tt>funciones.h</tt>, donde los comentarios lo indican.

La tolerancia utilizada por defecto es **1e-12**, pero se puede modificar en el inicio de <tt>funciones.h</tt>, donde los comentarios lo indican.
