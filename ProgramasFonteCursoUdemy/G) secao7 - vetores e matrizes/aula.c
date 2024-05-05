/*
 ============================================================================
 Name        : programasC.c
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

	float valores[5][5];

	int contador = 0;
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			valores[i][j] = contador++;
		}
	}

	for(int i=0; i<5; i++){
			for(int j=0; j<5; j++){
				printf("Numeros[%d][%d] valores %f\n", i,j,valores[i][j]);
			}
		}

	return 0;
}
