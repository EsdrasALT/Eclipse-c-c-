/*
 ============================================================================
 Name        : programa2-exercicios.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	//Declaração de Variavel
	int numeroInteiro = 0;
	int primeroNumInteiro = 0;
	int segundoNumInteiro = 0;
	int terceiroNumInteiro = 0;
	int somaDeInteiros = 0;
	int outroNumInt = 0;
	int quadradoDeInt = 0;

	//1° Exercicio
	printf("\nDigite um numero inteiro que iremos mostra-lo: ");
	scanf("%d", &numeroInteiro);
	printf("\nEsse foi o numero %d que voce digitou: ", numeroInteiro);

	//2° Exercicio
	printf("\nDigite agora 3 valores inteiros para serem somados\n");
	printf("\nO primeiro: \n");
	scanf("%d", &primeroNumInteiro);
	printf("\nO segundo: \n");
	scanf("%d", &segundoNumInteiro);
	printf("\nO terceiro: \n");
	scanf("%d", &terceiroNumInteiro);
	somaDeInteiros = primeroNumInteiro + segundoNumInteiro + terceiroNumInteiro;
	printf("\nA soma dos 3 numeros que voce digitou é de: %d", somaDeInteiros);

	//3° Exercicio
	printf("\nDigite um numero inteiro que iremos calcular o seu quadrado: \n");
	scanf("%d", &outroNumInt);
	quadradoDeInt = outroNumInt * outroNumInt;
	printf("\nAqui o seu numero elevado ao quadrado: %d\n", quadradoDeInt);

	return 0;
}
