#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura do carro (lista simples encadeada)
typedef struct Carro {
	//dados simples
	int codigoSequencial;
    char placa[10];
    //lista
    struct Carro *proximo;
} Carro;

// Definição da estrutura do cliente (lista duplamente encadeada)
typedef struct Cliente {
    //dados simples
	int codigoSequencial;
    char nome[50];
    int quantidadeDeCarros;
    Carro *carros; // Lista simples encadeada de carros do cliente
    //lista
    struct Cliente *anterior;
    struct Cliente *proximo;
} Cliente;

// Função para criar um novo carro e inserir no início da lista de carros do cliente
Carro* criaCarro(int codigoSequencial, char placa[]) {
    Carro *carro = (Carro*)malloc(sizeof(Carro));
    carro->codigoSequencial = codigoSequencial;
    strcpy(carro->placa, placa);
    carro->proximo = NULL;
    return carro;
}

void insereCarroInicio(Cliente *cliente, Carro *carro) {
    carro->proximo = cliente->carros;
    cliente->carros = carro;
    cliente->quantidadeDeCarros++;
}

// Função para criar um novo cliente
Cliente* criaCliente(int codigoSequencial, char nome[]) {
    Cliente *cliente = (Cliente*)malloc(sizeof(Cliente));
    cliente->codigoSequencial = codigoSequencial;
    strcpy(cliente->nome, nome);
    cliente->quantidadeDeCarros = 0;
    cliente->carros = NULL;
    cliente->anterior = NULL;
    cliente->proximo = NULL;
    return cliente;
}

// Função para inserir um cliente no fim da lista duplamente encadeada
void insereClienteFim(Cliente **inicio, Cliente **fim, Cliente *novoCliente) {
    if (*fim == NULL) { // Lista vazia
        *inicio = novoCliente;
        *fim = novoCliente;
    } else {
        (*fim)->proximo = novoCliente;
        novoCliente->anterior = *fim;
        *fim = novoCliente;
    }
}

// Função para imprimir os dados de um cliente e seus carros
void imprimeCliente(Cliente *cliente) {
    printf("Cliente: %s (Codigo: %d)\n", cliente->nome, cliente->codigoSequencial);
    printf("Quantidade de Carros: %d\n", cliente->quantidadeDeCarros);
    Carro *carro = cliente->carros;
    while (carro != NULL) {
        printf("  Carro: %s (Codigo: %d)\n", carro->placa, carro->codigoSequencial);
        carro = carro->proximo;
    }
    printf("\n");
}

// Função para imprimir todos os clientes e seus carros
void imprimeTodosClientes(Cliente *inicio) {
    Cliente *cliente = inicio;
    while (cliente != NULL) {
        imprimeCliente(cliente);
        cliente = cliente->proximo;
    }
}

// Função para encontrar um cliente pelo código sequencial
Cliente* encontraCliente(Cliente *inicio, int codigoSequencial) {
    Cliente *cliente = inicio;
    while (cliente != NULL) {
        if (cliente->codigoSequencial == codigoSequencial) {
            return cliente;
        }
        cliente = cliente->proximo;
    }
    return NULL;
}

// Função principal
int main(void) {
	setbuf(stdout,NULL);
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
                 (&inicioClientes, &fimClientes, novoCliente);
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
