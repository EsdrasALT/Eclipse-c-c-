#include <stdio.h>
#include <stdlib.h>

int main(){

	int *ponteiro, linhas=3, colunas=3;

	ponteiro = (int*) malloc (linhas * colunas * sizeof(int));

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
