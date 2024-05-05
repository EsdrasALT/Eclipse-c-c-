/*
 * exercicio3.c
 *
 *  Created on: 14 de abr. de 2024
 *      Author: Bless
 */
#include <stdio.h>
#include <stdlib.h>

int main (void) {
	setbuf(stdout,NULL);

	int numero, maior, menor = 0;

	for(int i=0; i<10; i++){
		printf("Informe o valor %d de 10 numeros: ", i + 1);
		scanf("%d", &numero);

		if( i == 0){
			maior = numero;
			menor = numero;
		}

		if (numero > maior){
			maior = numero;
		}

		if (numero < menor){
			menor = numero;
		}
	}
	printf("O maior valor é %d e o menor valor %d", maior, menor);

	return 0;
}

