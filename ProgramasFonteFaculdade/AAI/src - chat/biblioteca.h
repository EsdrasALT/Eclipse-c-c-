#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PLACAS 5

typedef struct DataNascimento {
    int dia;
    int mes;
    int ano;
} DataNascimento;

typedef struct Carros {
    char placa[8]; // Suporta formatos LLLNNNN e LLLNLNN
    char codigo[10];
    char marcaModelo[30];
    int ano;
    struct Carros *prox; // Lista simplesmente encadeada
} Carros;

typedef struct Clientes {
    char nome[50];
    char codigo[10];
    DataNascimento dataNascimento;
    char tipoContrato;
    int qtdePlacas;
    Carros *carros; // Ponteiro para a lista de carros
    struct Clientes *prox; // Lista duplamente encadeada
    struct Clientes *ant;
} Clientes;

// Prototipação de Funções

// MENU
void menuPrincipal();
void menuInserir(Clientes **inicio, Clientes **fim, int *codigoSequencial);
void inserirCliente(Clientes **inicio, Clientes **fim, int *numeroSequencial);
void inserirPlaca(Clientes **inicio, int *numeroSequencial);
void menuExcluir(Clientes **inicio);
void menuRelatorios();

// INSERIR CLIENTE
Clientes* criarCliente(Clientes **inicio, Clientes **fim, int *codigo);

// INSERIR CARRO
Carros* criaCarro(Clientes *cliente, int *codigo);

// LISTAR TODOS CLIENTES
void listarTodosClientes(Clientes *inicio);
void imprimeCliente(Clientes *cliente, int numCliente);

// FUNCOES DE BUSCA
char* buscarCodigo(char* mensagem);
Clientes* buscarClientePorCodigo(Clientes *inicio, char *codigoCliente);
Carros* buscarCarroPorCodigo(Clientes *inicio, char *placaCarro, Clientes **anterior);

// LISTAR CLIENTE POR CODIGO
void listarClientePorCodigo(Clientes *inicio);

// LISTAR CLIENTES POR CONTRATO
void listarClientesPorContrato(Clientes *inicio);

// EXCLUIR CLIENTE
void excluirCliente(Clientes **inicio);
void excluirPlaca(Clientes **inicio);

// NOME
void receberNomePreenchido(Clientes *cliente);
void formatarNomeRecursiva(char *nome, int indice, int caractereDeveSerPego);

// DATA
void solicitarDataDeNascimento(Clientes *cliente);
DataNascimento converterData(char *data_str);
int verificarIdade(int ano);
int isAnoBissexto(int ano);
int isDataValida(int dia, int mes, int ano);

// FUNCAO CODIGO
void gerarCodigoSequencial(Clientes *cliente, int numeroSequencial);

// TIPO DE CONTRATO
void verificarTipoContrato(Clientes *cliente);

// FUNCAO QTDE PLACA
void quantidadePlacas(Clientes *cliente);

// PLACAS
void chamarFuncoesPlacas();
void validarPlacaAntiga();
void validarPlacaNova();

// FUNCAO CODIGO
void gerarCodigoSequencialCarro(Carros *carro, Clientes *cliente, int numeroSequencial);

// FUNCAO MODELO
void receberMarcaModeloCarro(Carros *carro);

// FUNCAO ANO
void receberAnoCarro(Carros *carro);

#endif // BIBLIOTECA_H
