/*
 * exercicio1.c
 *
 *  Created on: 17 de mai. de 2024
 *      Author: Bless
 */

#include <stdio.h>

int main(){
	setbuf(stdout,NULL);

	int numero = 5;

	printf("%d", somatorioDe1AN(numero));

	return 0;
}

int somatorioDe1AN (int numero){

	int somatorio;
	for (int i=1; i<numero;i++){
		somatorio = somatorio + i;
		printf("%d\n", somatorio);
	}
	return somatorio + numero;
}
