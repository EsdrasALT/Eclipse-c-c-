#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura do carro (lista simples encadeada)
typedef struct Carro {
    int codigoSequencial;
    char placa[10];
    struct Carro *proximo;
} Carro;

// Definição da estrutura do cliente (lista duplamente encadeada)
typedef struct Cliente {
    int codigoSequencial;
    char nome[50];
    int quantidadeDeCarros;
    Carro *carros;
    struct Cliente *anterior;
    struct Cliente *proximo;
} Cliente;

// Declaração das funções
Carro* criaCarro(int codigoSequencial, char placa[]);
void insereCarroInicio(Cliente *cliente, Carro *carro);

Cliente* criaCliente(int codigoSequencial, char nome[]);
void insereClienteFim(Cliente **inicio, Cliente **fim, Cliente *novoCliente);

void imprimeCliente(Cliente *cliente);
void imprimeTodosClientes(Cliente *inicio);
Cliente* encontraCliente(Cliente *inicio, int codigoSequencial);

#endif // BIBLIOTECA_H
