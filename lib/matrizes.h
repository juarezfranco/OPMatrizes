/**
* Cabeçalho das funções de operações com matrizes (OPMatriz)
*
* Dependencias: "stdio.h" e "stdlib.h"
* @author Juarez Arce Franco Junior
*/


/**
* Estrutura representa matriz
*/
typedef struct {
    int rows;
    int cols;
    int** val;
} Matriz;


/**
* Cria nova matriz alocando memoria
* @param rows, numero de linhas da matriz
* @param cols, numero de colunas da matriz
* @return Matriz*, retorna ponteiro para a matriz que foi criada
*/
Matriz* OPMatriz_criar (int rows, int cols);

/** 
* Inicia matriz com valores randomicos 
* @param Matriz*, ponteiro da matriz que deve ser inicializada
*/
void OPMatriz_iniciar (Matriz*);

/** 
* Multiplica duas matrizes
* @param Matriz*, matriz A[m][n]
* @param Matriz*, matriz B[n][x]
* @return Matriz*, matriz resultante[m][x] da multiplicação
*/
Matriz* OPMatriz_multiplicar(Matriz*, Matriz*);

/** 
* Imprime matriz na tela em forma de grid 
* @param Matriz*, matriz a ser imprimida na tela
*/
void OPMatriz_imprimir(Matriz*);

/**
* Roda um exemplo de operações com matrizes que esta biblioteca é capaz.
* @param rows, numero de linhas da matriz
* @param cols, numero de colunas da matriz
*/
void OPMatriz_exemplo(int rows, int cols);

/**
* Libera matriz da memória
* @param Matriz*, matriz a ser leberada da memória
*/
void OPMatriz_free(Matriz*);

/**
* Inclui biblioteca com as funções
*/ 
#include "matrizes.c"