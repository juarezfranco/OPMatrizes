#include <stdio.h>
#include <stdlib.h>
#include "lib/matrizes.h"

void hello(void);
void bye(void);


int main(int* argc, char** argv){
	int rows=2, cols=2;
	hello();

	OPMatriz_exemplo(rows,cols);


	bye();
	return 1;
}

void hello(){
	system("clear");
	printf("#####################################################\n");
	printf("####            OPERAÇÃO DE MATRIZES             ####\n");
	printf("####     AUTOR JUAREZ ARCE FRANCO JUNIOR         ####\n");
	printf("#####################################################\n");
}

void bye(){
	printf("\n####################### FIM #######################\n\n");
}
