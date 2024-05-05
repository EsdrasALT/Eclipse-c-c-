/*
 * exercicio3.c
 *
 *  Created on: 21 de abr. de 2024
 *      Author: Bless
 */
#include <stdio.h>
void geradorDeExclamacao (int total);

int main(void){
	setbuf(stdout,NULL);

	int exclamacoes= 5;
	geradorDeExclamacao(exclamacoes);

	return 0;
}

void geradorDeExclamacao (int total){

	for(int i=0;i<=total;i++){
		for (int j=0;j<i;j++){
			printf("!");
		}
		printf("\n");
	}
}


