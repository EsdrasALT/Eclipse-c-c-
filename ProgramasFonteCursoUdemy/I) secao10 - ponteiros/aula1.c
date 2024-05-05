/*
 * aula.c
 *
 *  Created on: 21 de abr. de 2024
 *      Author: Bless
 */

#include <stdio.h>

void incrementa (int *contador);

int main(){
	setbuf(stdout,NULL);

	int contador = 10;

	printf("Main\n");
	printf("Antes de incrementar\n");
	printf("O contador vale %d\n", contador);
	printf("O endereço de memoria é %p\n", &contador);
	printf("Main\n\n");

	incrementa(&contador); // o & serve para enviar um endereço de memoria

	printf("Main\n");
	printf("Depois de incrementar\n");
	printf("O contador vale %d\n", contador);
	printf("O endereço de memoria é %p\n", &contador);
	printf("Main\n\n");

	return 0;
}

void incrementa (int *contador){ // o * serve para receber o endereço de memoria
	printf("Função\n");
	printf("Antes de incrementar\n");
	printf("O contador vale %d\n", (*contador));
	printf("O endereço de memoria é %p\n", contador);
	printf("Função\n\n");

	printf("Função\n");
	printf("Depois de incrementar\n");
	printf("O contador vale %d\n", ++(*contador));
	printf("O endereço de memoria é %p\n", contador);
	printf("Função\n\n");
}
