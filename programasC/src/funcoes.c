//FUNÇÕES - funcoes.c = https://codeshare.io/4YPo1d

#include "biblioteca.h"

void menuPrincipal(){
    char opcao;
    do {
        printf("\nMenu Principal:\n");
        printf("A - Inserir (cliente e placa)\n");
        printf("B - Excluir (cliente e placa)\n");
        printf("C - Relatórios\n");
        printf("D - Finalizar\n");
        printf("Escolha uma opção: ");
        scanf(" %c", &opcao);
        getchar(); // Limpar buffer

        switch(opcao) {
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
                printf("Opção inválida!\n");
                break;
        }
    } while(opcao != 'D');
}

void menuInserir(){
    int opcao;
    printf("\nMenu Inserir:\n");
    printf("1 - Inserção de cliente\n");
    printf("2 - Inserção de placa\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch(opcao) {
        case 1:
          //  inserir_cliente();
            break;
        case 2:
            //inserir_placa();
            break;
        default:
            printf("Opção inválida!\n");
            break;
    }
}

void menuExcluir(){
    int opcao;
    printf("\nMenu Excluir:\n");
    printf("1 - Exclusão de cliente\n");
    printf("2 - Exclusão de placa\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch(opcao) {
        case 1:
            //excluir_cliente();
            break;
        case 2:
            //excluir_placa();
            break;
        default:
            printf("Opção inválida!\n");
            break;
    }
}

void menuRelatorios(){
    int opcao;
    printf("\nMenu Relatórios:\n");
    printf("1 - Listar todos os clientes cadastrados (e seus carros)\n");
    printf("2 - Listar dados do cliente por código (dados e carros)\n");
    printf("3 - Listar clientes por tipo de contrato\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch(opcao) {
        case 1:
            //listar_todos_clientes();
            break;
        case 2:
            //listar_cliente_por_codigo();
            break;
        case 3:
            //listar_clientes_por_contrato();
            break;
        default:
            printf("Opção inválida!\n");
            break;
    }
}

//int validarData(int dia, int mes, int ano) {
//    if (ano < 1924 || ano > 2006)
//        return 0;
//    if (mes < 1 || mes > 12)
//        return 0;
//    if (dia < 1 || dia > 31)
//        return 0;
//    if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30)
//        return 0;
//    if (mes == 2) {
//        int bissexto = (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0));
//        if (dia > (bissexto ? 29 : 28))
//            return 0;
//    }
//    return 1;
//}


void validarNome(){
}
//Funcao recursiva
//Primeira letraas maisculas, restantes minuscula
