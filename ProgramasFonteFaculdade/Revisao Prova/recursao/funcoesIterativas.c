/*
 * main.c
 *
 *  Created on: 29 de jun. de 2024
 *      Author: Bless
 */

#include <stdio.h>
#include <stdlib.h>

void numeroDeUmADez(){
	for(int i=1; i<=10; i++){
		printf("Numero: %d\n", i);
	}
}

void somaDosPrimeirosNumero(){
	int valorDigitado=0, valoresSomados=0;

	do{
		printf("Digite um numero positivo: \n");
		scanf("%d",&valorDigitado);
	}while(valorDigitado <= 0);

	for(int i=1;i<valorDigitado;i++){
		valoresSomados = i + valoresSomados;
		printf("%d° Soma | Valor da Soma %d\n", i, valoresSomados);
	}
}

void fatorialDeUmNumero(){
	int numero, fatorial=1;

	printf("Digite o numero fatorial: ");
	scanf("%d",&numero);

	for(int i=1;i<=numero;i++){
		fatorial *= i;
	}
	printf("Fatorial de %d é %d\n", numero, fatorial);
}

void tabuadaNumerica(){
	int numeroDigitado;

	printf("Digite um numero para ver a tabuada: ");
	scanf("%d",&numeroDigitado);

	for(int i=1;i<=10;i++){
		printf("%d * %d = %d\n", i, numeroDigitado, numeroDigitado * i);
	}
}

int ePrimo(int numero) {
    if (numero <= 1) return 0;
    for (int i = 2; i * i <= numero; i++) {
        if (numero % i == 0) return 0;
    }
    return 1;
}

void numerosPrimos(int valor){
    if (valor < 2) return;

    for (int i = 2; i <= valor; i++) {
        if (ePrimo(i)) {
            printf("%d\n", i);
        }
    }
}

int main(void){
	setbuf(stdout,NULL);

	printf("1° Função\n");
	numeroDeUmADez();

	printf("\n\n");
	printf("2° Função\n");
	somaDosPrimeirosNumero();

	printf("\n\n");
	printf("3° Função\n");
	fatorialDeUmNumero();

	printf("\n\n");
	printf("4° Função\n");
	tabuadaNumerica();

	printf("\n\n");
	printf("5° Função\n");
	numerosPrimos(15);

	return 0;
}


