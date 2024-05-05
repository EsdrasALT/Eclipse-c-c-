/*
 * exercicio2.c
 *
 *  Created on: 21 de abr. de 2024
 *      Author: Bless
 */

#include <stdio.h>
void mensagemInicial();
char transformarLetraEmMaiscula(char);

int main(void){
	setbuf(stdout,NULL);

	char letra;
	char letraMaiscula;

	mensagemInicial();
	printf("\nDigite uma letra: \n");
	scanf("%c", &letra);
	letraMaiscula = transformarLetraEmMaiscula(letra);
	printf("Sua letra maiscula é %c", letraMaiscula);

	return 0;
}

void mensagemInicial(){
	printf("Ola! Selecione uma letra do alfabeto =) \n");
}

char transformarLetraEmMaiscula(char letra){
	char maisculo = (int)letra - 32;
	return maisculo;
}
