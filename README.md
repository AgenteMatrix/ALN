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

Primeor de todo es necesario descargar la carpeta de este proyecto y situarse a través de la consola en el directorio donde lo hayamos hecho. Recordamos que también es necerasio tener los ficheros de datos (que no constan en este proyecto) en el mismo directorio. Una vez hecho esto, entonces:

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

* <tt>make test</tt> ~ Para ejecutar el programa con todas las entradas de datos disponibles. De esta forma también creeará un archivo de salida <tt>outputXX.txt</tt> para cada entrada de datos.

Y finalmente

* <tt>make help</tt> ~ Para que se muestre por terminal los posibles comandos 'make' que puedes llevar a cabo y una breve descripción de ellos.

Es importante saber que el programa hará lo que sea especificado en el <tt>main.cc</tt> y este está abierto a ser modificado. También cabe recalcar que se debe indicar manualmente en el archivo <tt>test.cc</tt> la cantidad de ficheros de datos se poseen y como es su estructura de nombre (en el estado actual solo se contempla la estructura <tt>MXX.DAT</tt> y <tt>MSINGULARXX.DAT</tt> con <tt>XX</tt> = (00, 01, ..., 99)).

## Funciones

Este proyecto consta de las siguientes funciones, escritas como ya se ha indicado en <tt>funciones.cc</tt>. Fijemonos que estas estan separadas en diferentes clases dentro del programa, en **Transformaciones y operaciones con V y M**, **Normas vectores**, **Normas matrices**, **Número de condición** e **Impresión**.

#### lu
#### pivotage
#### resuelve
#### Gauss
#### calculo_res
#### calculo_PA
#### calculo_LU
#### determinante
#### traza
#### suma, resta, producto
#### suma_vectores, resta_vectores
#### inversa
#### transpuesta
#### identidad

#### norma_1_vector, norma_2_vector, norma_inf_vector
#### norma_1, norma_inf
#### condicion_1, condicion_inf
#### imprimir_matriz, imprimir_matlab

## Otras consideraciones

### Formato de los datos

Es necesario que los ficheros de datos tengan un cierto formato para ser leídos correctamente. Lo primero que tiene que aparecer es la dimensión de la matriz (cuadrada) que tiene que coincidir con la del vector de términos independientes. A continuación se determinan los elementos diferentes de 0 de la matriz, después y precedido por su fila y columna los elementos diferentes de 0. A continuación se sigue el mismo procedimiento para el vector, primero la cantidad de elementos diferentes de 0, después fila, columna y el elemento diferente de 0. Todos los indices empiezan en 0.

### Decimales en la salida y tolerancia admitida

El número de decimales impresos en la salida es por defecto **15**, pero se puede modificar en el inicio de <tt>funciones.h</tt>, donde los comentarios lo indican.

La tolerancia utilizada por defecto es **1e-12**, pero se puede modificar en el inicio de <tt>funciones.h</tt>, donde los comentarios lo indican.