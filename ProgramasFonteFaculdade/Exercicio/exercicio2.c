/*
 * exercicio2.c
 *
 *  Created on: 14 de abr. de 2024
 *      Author: Bless
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);

	int linha=2,coluna=5;
	int vetorDezPosicoes[linha][coluna];
	int soma = 0;

	int contador = 0;
	for(int i=0; i<linha;i++){
		for(int j=0;j<coluna;j++){
			vetorDezPosicoes[i][j] = contador++;
			if (vetorDezPosicoes[i][j] % 2 == 0){
				soma = vetorDezPosicoes[i][j];
			}
		}
	}

	for(int i=0; i<linha; i++){
		for(int j=0; j<coluna; j++){
			printf("Numeros[%d][%d] valores %d\n", i,j,vetorDezPosicoes[i][j]);
		}
	}
	printf("\n O valor somado foi de: %d", soma);


	return 0;
}
