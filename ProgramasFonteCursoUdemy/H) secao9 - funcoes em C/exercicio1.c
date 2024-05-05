/*
 * aula.c
 *
 *  Created on: 20 de abr. de 2024
 *      Author: Bless
 */

#include <stdio.h>
int verificarMaiorValor (int vetor[], int tamanho);

int main(void){
	setbuf(stdout,NULL);

	int tamanho=5, vetor[tamanho], valor;

	for(int i=0;i<tamanho;i++){
		printf("Digite abaixo o %d° numero:\n",i+1);
		scanf("%d", &vetor[i]);
	}
	for(int i=0;i<tamanho;i++){
		printf("%d° numero: %d\n",i+1, vetor[i]);
	}
	valor = verificarMaiorValor(vetor,tamanho);

	printf("O maior valor encontrado foi %d", valor);

	return 0;
}

int verificarMaiorValor (int vetor[], int tamanho){
	int maiorValor = vetor[0];

	for(int i=0;i<tamanho;i++){
		if(vetor[i] > maiorValor){
			maiorValor = vetor[i];
		}
	}

	return maiorValor;
}
