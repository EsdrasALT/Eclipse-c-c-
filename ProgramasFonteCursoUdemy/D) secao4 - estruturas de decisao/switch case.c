#include <stdio.h>

int main() {
    int opcao;

    printf("Digite um número de 1 a 5: ");
    scanf("%d", &opcao);

    switch(opcao) {
        case 1:
            printf("Você escolheu a opção 1.\n");
            break;
        case 2:
            printf("Você escolheu a opção 2.\n");
            break;
        case 3:
            printf("Você escolheu a opção 3.\n");
            break;
        case 4:
            printf("Você escolheu a opção 4.\n");
            break;
        case 5:
            printf("Você escolheu a opção 5.\n");
            break;
        default:
            printf("Opção inválida!\n");
            break;
    }

    return 0;
}
