/*
 * exercicio2.c
 *
 *  Created on: 20 de abr. de 2024
 *      Author: Bless
 */

#include <stdio.h>
#include <stdlib.h>

int main(void){
	setbuf(stdout,NULL);

	int vetor[] = {1,2,3,4,5,6,7,8,9,10};

	int somaDePares=0;
	for(int i=0;i<10;i++){
		if (vetor[i] % 2 == 0){
			printf("%d\n",vetor[i]);
			somaDePares++;
		}
	}
	printf("O total de pares somados foi %d", somaDePares);

	return 0;
}
