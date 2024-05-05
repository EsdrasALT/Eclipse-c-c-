/*
 ============================================================================
 Name        : teste.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main() {
    int num1, num2, soma;

    // Solicita os números ao usuário
    printf("Digite o primeiro numero: ");
    scanf("%d", &num1);

    printf("Digite o segundo numero: ");
    scanf("%d", &num2);

    // Calcula a soma
    soma = num1 + num2;

    // Exibe o resultado
    printf("A soma? é a soma! de %d e %d eh: %d\n", num1, num2, soma);

    return 0;
}

