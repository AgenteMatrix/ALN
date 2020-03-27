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

Como ya se ha enseñado este proyecto esta separado en varios ficheros. El **main.cc** es el programa principal y el que se ejecuta en primer lugar. Es en este donde se leen los datos de entrada, se determina qué se quiere que realice el programa y en último lugar, imprime la salida. Después está el fichero **funciones.h**, que es donde están definidas las diferentes funciones de este proyecto así como otras constantes y variables que intervienen en el proyecto. Es en **funciones.cc** donde están escritas e implementadas las funciones anteriormente mencionadas. Finalmente, este proyecto consta de un archivo **Makefile** para hacer el funcionamiento de todo más sencillo, y el archivo **test.cc**, que funciona juntamente con el **Makefile**, sirve para probar todas las entradas disponibles de una ejecución.

## Explicación de uso

Para compilar, haz

<tt>g++ main.cc funciones.h funciones.cc -o exLU</tt>

Y para ejecutar el programa, siendo MXX.DAT el archivo de entrada y OUTPUT.txt el de salida, haz 

<tt>./exLU MXX.DAT OUTPUT.txt </tt>

El proceso anterior se puede simplificar mucho gracias al **Makefile**. Entonces para compilar. haz

<tt>make all</tt> 

Para ejecutar el programa haz,

<tt>make test</tt> Y te pedirá el nombre de el fichero de datos de entrada. 

En el **Makefile** se han programado otras funcionalidades como:

* <tt>make clean</tt> ~ Para eliminar los archivos creados al compilar y ejecutar el programa.

* <tt>make list</tt> ~ Para mostrar la cantidad de ficheros de datos disponibles.

* <tt>make test</tt> ~ Para ejecutar el programa con todas las entradas de datos disponibles. De esta forma también creeará un archivo de salida <tt>outputXX.txt</tt> para cada entrada de datos.

Y finalmente

* <tt>make help</tt> ~ Para que se muestre por terminal los posibles comandos 'make' que puedes llevar a cabo y una breve descripción de ellos.

Es importante saber que el programa hará lo que sea especificado en el **main.cc** y este está abierto a ser modificado. También cabe recalcar que se debe indicar manualmente en el archivo **test.cc** la cantidad de ficheros de datos se poseen y como es su estructura de nombre (en el estado actual solo se contempla la estructura <tt>MXX.DAT</tt> y <tt>MSINGULARXX.DAT</tt> con <tt>XX</tt> = 00, 01, ..., 99).

## Otras consideraciones

### Formato de los datos

Es necesario que los ficheros de datos tengan un cierto formato para ser leídos correctamente. Lo primero que tiene que aparecer es la dimensión de la matriz (cuadrada) que tiene que coincidir con la del vector de términos independientes. A continuación se determinan los elementos diferentes de 0 de la matriz, después y precedido por su fila y columna los elementos diferentes de 0. A continuación se sigue el mismo procedimiento para el vector, primero la cantidad de elementos diferentes de 0, después fila, columna y el elemento diferente de 0. Todos los indices empiezan en 0.

### Decimales en la salida y tolerancia admitida

El número de decimales impresos en la salida es por defecto **15**, pero se puede modificar en el inicio de *funciones.h*, donde los comentarios lo indican.

La tolerancia utilizada por defecto es **1e-12**, pero se puede modificar en el inicio de *funciones.h*, donde los comentarios lo indican.
