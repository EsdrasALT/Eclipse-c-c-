/*
 ============================================================================
 Name        : exercicio1_nivelamento.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);
	char opcao;
	int valorMinimo;

	do{
		printf("\nSelecione uma das opções abaixo\n"
				"\nA - Sequencia de Fibonacci\n"
				"\nB - Fatorial\n"
				"\nC - Somar Pares\n"
				"\nD - Sair\n"
				"Digite uma das opções abaixo:\n");
		scanf(" %c", &opcao);
		switch (opcao) {
			case 'A':
		    case 'a':
		    case 'B':
		    case 'b':
		    case 'C':
		    case 'c':

		    	valorMinimo = (opcao == 'B' || opcao == 'b') ? 0 : 1;
		    	int numero;
					do {
						printf("Digite um número inteiro maior ou igual a %d: ", valorMinimo);
						scanf("%d", &numero);

						if (numero < valorMinimo) {
							printf("Número inválido! Por favor, digite novamente.\n");
						}
					} while (numero < valorMinimo);

					switch(opcao){
						case 'A':
						case 'a':
							calcularFibonacci(numero);
							break;
						case 'B':
						case 'b':
							printf("\Fatorial:\n");
							break;
						case 'C':
						case 'c':
							printf("\Somar Pares:\n");
							break;
					}
					break;
			case 'D':
			case 'd':
				printf("\nEncerrando o sistema");
				break;
			default:
				printf("\n Opção invalida, escolha A,B ou C (D para sair)");

		}
	} while (opcao != 'D' && opcao != 'd');

	return 0;
}

void calcularFibonacci(int termos) {
    int primeiro = 0, segundo = 1, proximo, i;

    printf("Sequência de Fibonacci com %d termos: ", termos);

    for (i = 0; i < termos; i++) {
        if (i <= 1) {
            proximo = i;
        } else {
            proximo = primeiro + segundo;
            primeiro = segundo;
            segundo = proximo;
        }
        printf("%d ", proximo);
    }
    printf("\n");
}