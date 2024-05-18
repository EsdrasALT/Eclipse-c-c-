/*
 * aula.c
 *
 *  Created on: 17 de mai. de 2024
 *      Author: Bless
 */
#include <stdio.h>

int sequenciaFibonacci (int);

int main(){
	setbuf(stdout, NULL);

	int quantidade;

	//	printf("Informe a quantidade que deseja calcular: \n");
	//	scanf("%d", &quantidade);

	for(int i=0;i<quantidade;i++){
		printf("%d ", sequenciaFibonacci(i + 1));
	}

	return 0;

}

int sequenciaFibonacci (int numero){

	if (numero == 0){
		return 0;
	}

	if (numero == 1){
		return 1;
	}

	return sequenciaFibonacci(numero - 1) + sequenciaFibonacci(numero - 2);

}
