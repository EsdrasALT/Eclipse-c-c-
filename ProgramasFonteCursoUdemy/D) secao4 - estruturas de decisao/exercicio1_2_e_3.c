/*
 ============================================================================
 Name        : programa3_exercicio_estruturas_de_decisao.c
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

	//Exercicio 3.1
	int primeiroNum=0, segundoNum=0, terceiroNum=0,
		primeiroQuad=0, segundoQuad=0, terceiroQuad=0,
		somaDosQuad=0;
	printf("\nDigite 3 valores abaixo\n");
	printf("\nPrimeiro:");
	scanf("%d", &primeiroNum);
	printf("\nSegundo:");
	scanf("%d", &segundoNum);
	printf("\nTerceiro:");
	scanf("%d", &terceiroNum);
	primeiroQuad = primeiroNum * primeiroNum;
	segundoQuad = segundoNum * segundoNum;
	terceiroQuad = terceiroNum * terceiroNum;
	somaDosQuad = primeiroQuad + segundoQuad + terceiroQuad;
	printf("\nA soma dos quadrados dos valores que voce digitou é: %d", somaDosQuad);

	//Exercicio 3.2
	float matematicaNota, portuguesNota, cienciasNota, artesNota, mediaAritimetica=0;

	printf("\nDigite as 4 notas (matematica|portugues|ciencias|artes) do aluno abaixo: \n");
	scanf("%f %f %f %f", &matematicaNota, &portuguesNota, &cienciasNota, &artesNota );
	printf("\nEstas foram as notas digitadas para:\n"
			"mate: %f |port: %f |cien: %f |arte: %f|"
			"\n", matematicaNota, portuguesNota, cienciasNota, artesNota);
	mediaAritimetica = (matematicaNota + portuguesNota + cienciasNota + artesNota) / 4;
	printf("\nEssa é a media aritimetica das notas: %f", mediaAritimetica);

	//Exercicio 3.3













	return 0;
}
