/*
 ============================================================================
 Name        : exercicioPonteiro.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

char alteracaoDeValorChar(char *umChar);
int alteracaoDeValorInteiro(int *umInteiro);
float alteracaoDeValorFloat(float *umFloat);

int main(void) {
	setbuf(stdout,NULL);

	char umChar='a';
	int umInteiro=10;
	float umFloat=10.0;

	char *ponteiroChar;
	int *ponteiroInt;
	float *ponteiroFloat;

	ponteiroChar = &umChar;
	ponteiroInt = &umInteiro;
	ponteiroFloat = &umFloat;

	printf("\nValor antes:\n"
			"%c\n"
			"%d\n"
			"%2f\n", *ponteiroChar, *ponteiroInt, *ponteiroFloat);

	alteracaoDeValorChar(&umChar);
	alteracaoDeValorInteiro(&umInteiro);
	alteracaoDeValorFloat(&umFloat);

	printf("\nValor antes:\n"
				"%c\n"
				"%d\n"
				"%2f\n", *ponteiroChar, *ponteiroInt, *ponteiroFloat);

	return 0;
}

char alteracaoDeValorChar(char *umChar){
	return ++(*umChar);
}

int alteracaoDeValorInteiro(int *umInteiro){
	return ++(*umInteiro);
}

float alteracaoDeValorFloat(float *umFloat){
	return ++(*umFloat);
}




