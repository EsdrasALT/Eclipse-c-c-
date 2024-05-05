/*
 * exercicio2.c
 *
 *  Created on: 14 de abr. de 2024
 *      Author: Bless
 */

#include <stdio.h>
#include <stdlib.h>

int main (void){
	setbuf(stdout,NULL);

	int numero = 0;
	int contador = 0;

	do {
		numero = numero + 100;
		contador++;
	}while(numero < 100000);
	printf("O numero devera ser 100000 : %d\n E o total de vezes adicionando foi: %d", numero, contador);

	return 0;
}
