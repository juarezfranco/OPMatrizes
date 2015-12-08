/**
* Biblioteca de funções para operações de matrizes (OPMatriz)
* @author Juarez Arce Franco Junior
*/


/**
* MULTIPLICA MATRIZ[m][n] X MATRIZ[n][z] E RETORNA UMA MATRIZ [m][z]
* @author Juarez A. Franco Jr
*/
Matriz* OPMatriz_multiplicar(Matriz* matrizA, Matriz* matrizB){
	int i, j, k,rows;
	//cria matriz resultante que deve ter o nmr de linhas da matrizA e o nmr de colunas da matriz B
	Matriz* resultado = OPMatriz_criar(matrizA->rows,matrizB->cols);

	/** aqui foi foda pra caraioooo quase 1 hora pra chegar no resultado correto **/
	for(i=0; i< matrizA->rows ; i++){
		for(j=0 ; j < matrizA->cols ; j++){
			for(k=0; k < matrizB->cols ; k++){
				resultado->val[i][k]+= matrizA->val[i][j] * matrizB->val[j][k];
			}
		}
	}
	return resultado;
}

/**
* IMPRIME CORPO DA MATRIZ
* @author Juarez A. Franco Jr
*/
void OPMatriz_imprimir(Matriz* matriz){
	int i, j;
	//imprime MatrizA
	for(i=0 ; i< matriz->rows ; i++){
		printf("\n| ");
		for(j=0 ; j < matriz->cols ; j++){
			printf("%d |", matriz->val[i][j]);
		}
	}
	printf("\n");
}



/**
* INICIALIZA MATRIZ COM VALORES RANDOMICOS
* @author Juarez A. Franco Jr
*/
void OPMatriz_iniciar(Matriz *matriz){
	int i ,j ;
	srand((unsigned)time(NULL));
	for (i=0 ; i< matriz->rows ; i++){
		for(j=0 ; j < matriz->cols ; j++){
			matriz->val[i][j] = (int)rand()%10;
		}
	}
}


/**
* CRIA MATRIZ NA MEMÓRIA E INICIALIZA VALORES COM 0
* @author Juarez A. Franco Jr
*/
Matriz* OPMatriz_criar(int rows, int cols) {
	int i, j;

    // Aloca a memória para todas as linhas.
	int **matriz = (int**) malloc(rows * sizeof(int*));
	for (i = 0; i < rows; i++) {
        // Para cada linha, eu aloco o número de colunas.
		matriz[i] = (int*) malloc(cols * sizeof(int));
        // Inicializa.
		for(j = 0; j < cols; j++) {
			matriz[i][j] = 0;
		}
	}

	Matriz *resultado = (Matriz *) malloc(sizeof(Matriz));
	resultado->rows = rows;
	resultado->cols = cols;
	resultado->val = matriz;
	return resultado;
}

/**
* Libera matriz da memória
*/
void OPMatriz_free(Matriz* matriz){
	int i;
	for (i = 0; i < matriz->rows; i++) {
		free(matriz->val[i]);
	}
	free(matriz->val);
	free(matriz);
}

/**
* Roda um exemplo de operações com matrizes que esta biblioteca é capaz.
*/
void OPMatriz_exemplo(int rows, int cols){
	printf("\n# Função de exemplo da biblioteca de operações de matrizes foi iniciado #\n");
	/** Cria matrizes alocando em memória **/
	Matriz* matrizA 	= OPMatriz_criar(rows , cols);
	Matriz* matrizB  	= OPMatriz_criar(cols , 1);//limita a vetor
	Matriz* resultado;

	/** Inicializar matrizes com numeros randomicos **/
	OPMatriz_iniciar(matrizA);
	OPMatriz_iniciar(matrizB);

	/** faz operação de multiplicação entre matrizA e matrizB gerando matriz resultante **/
	resultado  = OPMatriz_multiplicar(matrizA, matrizB);

	/** imprime matrizes **/
	OPMatriz_imprimir(matrizA);
	OPMatriz_imprimir(matrizB);
	OPMatriz_imprimir(resultado);

	
	OPMatriz_free(matrizA);
	OPMatriz_free(matrizB);
	OPMatriz_free(resultado);
	printf("# Fim exemplo da biblioteca de operações de matrizes\n");
}