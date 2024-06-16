#include "biblioteca.h"

int main() {
	setbuf(stdout, NULL);
    Clientes *inicio = NULL;
    int numeroSequencial = 1;
    int opcao;

    do {
        printf("\nEscolha uma opção:\n");
        printf("1. Cadastrar Cliente\n");
        printf("2. Inserir Placa em Cliente Existente\n");
        printf("3. Listar Todos os Clientes\n");
        printf("4. Listar Cliente por Código\n");
        printf("5. Listar Clientes por Tipo de Contrato\n");
        printf("6. Excluir Cliente\n");
        printf("7. Excluir Placa de Cliente\n");
        printf("8. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        getchar();  // Limpar o buffer do stdin

        switch (opcao) {
            case 1:
                cadastrarCliente(&inicio, &numeroSequencial);
                break;
            case 2:
                inserirPlaca(&inicio, &numeroSequencial);
                break;
            case 3:
                listarTodosClientes(inicio);
                break;
            case 4:
                listarClientePorCodigo(inicio);
                break;
            case 5:
                listarClientesPorContrato(inicio);
                break;
            case 6:
                excluirCliente(&inicio);
                break;
            case 7:
                excluirPlaca(&inicio);
                break;
            case 8:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (opcao != 8);

    return 0;
}
