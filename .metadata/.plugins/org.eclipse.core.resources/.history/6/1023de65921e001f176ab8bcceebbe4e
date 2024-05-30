#include <stdio.h>
#include "biblioteca.h"

void menuPrincipal() {
    char escolha;
    do {
        printf("Menu Principal:\n");
        printf("A - Inserir (cliente e placa)\n");
        printf("B - Excluir (cliente e placa)\n");
        printf("C - Relatórios\n");
        printf("D - Finalizar\n");
        printf("Escolha uma opção: ");
        scanf(" %c", &escolha);

        switch (escolha) {
            case 'A':
                menuInserir();
                break;
            case 'B':
                menuExcluir();
                break;
            case 'C':
                menuRelatorios();
                break;
            case 'D':
                printf("Finalizando o programa...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (escolha != 'D');
}

void menuInserir() {
    int escolha;
    printf("Submenu Inserir:\n");
    printf("1 - Inserção de cliente\n");
    printf("2 - Inserção de placa\n");
    printf("Escolha uma opção: ");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1:
            // Chamar função de inserção de cliente
            break;
        case 2:
            // Chamar função de inserção de placa
            break;
        default:
            printf("Opção inválida! Tente novamente.\n");
    }
}

void menuExcluir() {
    int escolha;
    printf("Submenu Excluir:\n");
    printf("1 - Exclusão de cliente\n");
    printf("2 - Exclusão de placa\n");
    printf("Escolha uma opção: ");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1:
            // Chamar função de exclusão de cliente
            break;
        case 2:
            // Chamar função de exclusão de placa
            break;
        default:
            printf("Opção inválida! Tente novamente.\n");
    }
}

void menuRelatorios() {
    int escolha;
    printf("Submenu Relatórios:\n");
    printf("1 - Listar todos os clientes cadastrados (e seus carros)\n");
    printf("2 - Listar dados do cliente por código (dados e carros)\n");
    printf("3 - Listar clientes por tipo de contrato\n");
    printf("Escolha uma opção: ");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1:
            // Chamar função de listar todos os clientes
            break;
        case 2:
            // Chamar função de listar dados do cliente por código
            break;
        case 3:
            // Chamar função de listar clientes por tipo de contrato
            break;
        default:
            printf("Opção inválida! Tente novamente.\n");
    }
}
