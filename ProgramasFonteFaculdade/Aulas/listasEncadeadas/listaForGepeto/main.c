#include "biblioteca.h"

int main(void) {
    setbuf(stdout, NULL);
    Cliente *inicioClientes = NULL;
    Cliente *fimClientes = NULL;
    int opcao;
    int codigoCliente = 1;
    int codigoCarro;

    do {
        printf("Menu:\n");
        printf("1. Adicionar Cliente\n");
        printf("2. Adicionar Carro a um Cliente\n");
        printf("3. Listar Clientes e seus Carros\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                char nome[50];
                printf("Digite o nome do cliente: ");
                scanf("%s", nome);
                Cliente *novoCliente = criaCliente(codigoCliente++, nome);
                insereClienteFim(&inicioClientes, &fimClientes, novoCliente);
                break;
            }
            case 2: {
                int clienteCodigo;
                printf("Digite o codigo do cliente: ");
                scanf("%d", &clienteCodigo);
                Cliente *cliente = encontraCliente(inicioClientes, clienteCodigo);
                if (cliente != NULL) {
                    char placa[10];
                    printf("Digite a placa do carro: ");
                    scanf("%s", placa);
                    Carro *novoCarro = criaCarro(cliente->quantidadeDeCarros + 1, placa);
                    insereCarroInicio(cliente, novoCarro);
                } else {
                    printf("Cliente com codigo %d nao encontrado.\n", clienteCodigo);
                }
                break;
            }
            case 3:
                imprimeTodosClientes(inicioClientes);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
