#include <stdio.h>
#include <stdlib.h>

int main(){

	int *ponteiro,quantidade=3, linhas=3, colunas=3;

	ponteiro = (int*) calloc (quantidade,sizeof(int));

	for (int i=0; i<linhas; i++){
		for (int j=0;j<colunas;j++){
			ponteiro[i*colunas+j] = 3*i+j;
		}
	}

	for (int i=0; i<linhas; i++){
		for (int j=0;j<colunas;j++){
			printf("| %d |",ponteiro[i*colunas+j]);
		}
		printf("\n");
	}

	return 0;
}
