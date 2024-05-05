/*
 * exercicio.c
 *
 *  Created on: 14 de abr. de 2024
 *      Author: Bless
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);

	int vetorA[6] = {1, 0, 5, -2, -5, 7};
	int soma = (vetorA[0] + vetorA[1] + vetorA[5]);
	printf("\nSoma dos vetores na variavel soma é de: %d ", soma);

	vetorA[4] = 100;

	int posicao=0;
	for(int i=0;i<6;i++){
		printf("\nNa posição %d o valor é de: %d",posicao,vetorA[i]);
		posicao++;
	}

	return 0;
}
