#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

// -------------Inclusões de Bibliotecas Necessárias-------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <ctype.h>

// -------------Definições de Macros e Constantes-------------
#define MAX_NOME 50
#define MAX_CODIGO 7
#define MAX_CARROS 5
#define MAX_PLACA 8
#define MAX_MARCA_MODELO 30

// -------------Definições de Tipos (typedefs e enums)-------------

// -------------Declarações de Estruturas-------------
typedef struct DataNascimento {
    int dia;
    int mes;
    int ano;
} DataNascimento;

typedef struct Carros {
    char placa[MAX_PLACA];
    char codigoSequencial[MAX_CODIGO+2];
    char marcaModelo[MAX_MARCA_MODELO];
    int ano;
    struct Carros *proximo;
} Carros;

typedef struct Clientes {
    char nome[MAX_NOME];
    DataNascimento *dataNascimento;
    char codigo[MAX_CODIGO];
    char tipoContrato;
    int quantidadePlacas;
    Carros *carros;
    struct Clientes *proximo;
    struct Clientes *anterior;
} Clientes;

//-------------Prototipação de Funções-------------

//MENU

void cadastrarCliente(Clientes **inicio, int *numeroSequencial);

void criarCarro(Clientes *cliente, int *numeroSequencial);
Carros* alocarNovoCarro();

//
void inserirPlaca(Clientes **inicio, int *numeroSequencial);

//IMPRESSAO
void imprimeCliente(Clientes *cliente, int numCliente);

//BUSCAS
Clientes* buscarClientePorCodigo(Clientes *inicio, char *codigoCliente);
Carros* buscarCarroPorCodigo(Clientes *inicio, char *placaCarro, Carros **anterior);
char* buscarCodigo(char* mensagem);

//LISTAR POR
void listarTodosClientes(Clientes *inicio);
void listarClientePorCodigo(Clientes *inicio);
void listarClientesPorContrato(Clientes *inicio);

//EXCLUSAO
void excluirCliente(Clientes **inicio);
void excluirPlaca(Clientes **inicio);

//FUNCAO PLACA CARRO
void receberPlacaPreenchida(Carros *carro);
int validarPlaca(char *placa);

//FUNCAO NOMES CLIENTES
void receberNomePreenchido(Clientes *cliente);
void formatarNomeRecursiva(char *nome, int indice, int caractereDeveSerPego);

//FUNCAO DATA CLIENTES
void solicitarDataDeNascimento(Clientes *cliente);
DataNascimento converterData(char *data_string);
int verificarIdade(int ano);
int isDataValida(int dia, int mes, int ano);

//FUNCAO CODIGO CLIENTES
void receberCodigoPreenchido(Clientes *cliente, int *numeroSequencial);

//FUNCAO TIPOS CONTRATOS CLIENTES
void receberTipoDeContrato(Clientes *cliente);

//FUNCAO CODIGO CARROS
void receberCodigoSequencialCarro(Carros *carro, Clientes *cliente, int numeroSequencial);
//void receberCodigoSequencialCarro(Carros *carro, int *numeroSequencial);

//FUNCAO MARCA MODELO CARROS
void receberMarcaModeloCarro(Carros *carro);

//FUNCAO ANO CARRO
void receberAnoCarro(Carros *carro);

#endif /* BIBLIOTECA_H_ */
