/*
 * funcoesRecursivas.c
 *
 *  Created on: 29 de jun. de 2024
 *      Author: Bless
 */

#include <stdio.h>
#include <stdlib.h>

void numeroDeUmADezRecursivo(int numero){
	if(numero > 10) return;
	printf("%d - ",numero);
	numeroDeUmADezRecursivo(numero + 1);
}

int somaDosPrimeirosNumeroRecursivo(int numero){
	if(numero < 1) return 0;
	printf("%d - ",numero);
	return numero + somaDosPrimeirosNumeroRecursivo(numero - 1);
}

int fatorialDeUmNumeroRecursiva(int fatorial){

	if (fatorial < 1) return 1;
	printf("%d - ",fatorial);
	return fatorial * fatorialDeUmNumeroRecursiva(fatorial - 1);
}

int tabuadaNumericaRecursiva(int num, int mult){
	if (mult < 1){
		return 0;
	}
	return num + tabuadaNumericaRecursiva(num,mult-1);
}

int main(void){
	setbuf(stdout,NULL);

	printf("1° Função\n");
	numeroDeUmADezRecursivo(1);

	printf("\n\n");
	printf("2° Função\n");
	int total = somaDosPrimeirosNumeroRecursivo(5);
	printf("= %d",total);

	printf("\n\n");
	printf("3° Função\n");
	int fatorial = fatorialDeUmNumeroRecursiva(7);
	printf("= %d",fatorial);

	printf("\n\n");
	printf("4° Função\n");
	int tabuada = tabuadaNumericaRecursiva(5,5);
	printf("= %d",tabuada);

	return 0;
}
