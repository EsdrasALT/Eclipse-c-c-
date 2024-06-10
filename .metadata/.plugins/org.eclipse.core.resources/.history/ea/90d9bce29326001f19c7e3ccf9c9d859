#include "biblioteca.h"

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
