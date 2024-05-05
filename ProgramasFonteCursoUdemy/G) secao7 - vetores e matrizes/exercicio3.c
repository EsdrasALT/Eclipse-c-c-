/*
 * exercicio3.c
 *
 *  Created on: 20 de abr. de 2024
 *      Author: Bless
 */

#include <stdio.h>
#include <stdlib.h>

int main(void){
	setbuf(stdout,NULL);

	int vetor[] = {-5,-4,-3,-2,-1,0,1,2,3,4};

	for (int i=0;i<10;i++){
		if(vetor[i] < 0){
			vetor[i] = 0;
		}
		printf("%d\n", vetor[i]);
	}


	return 0;
}
