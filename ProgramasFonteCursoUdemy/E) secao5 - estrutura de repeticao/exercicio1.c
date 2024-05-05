/*
 ============================================================================
 Name        : programa4_estrutras_de_repeticao.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);

	int numero = 1;
	int contador = 0;

	printf("Os 5 primeiros multiplos de 4: \n");
	while(contador < 5){
		if (numero % 3 == 0){
			printf("O numero %d é multiplo de 3\n", numero);
			contador++;
		}
		numero++;
	}
	return 0;
}
