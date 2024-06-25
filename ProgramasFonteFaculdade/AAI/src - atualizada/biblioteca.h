#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

// -------------Inclusões de Bibliotecas Necessárias-------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// -------------Definições de Macros e Constantes-------------
#define MAX_CARROS 5
#define PLACA_LENGTH 7

// -------------Definições de Tipos (typedefs e enums)-------------
typedef struct dadosDataDeNascimento DataNascimento;
typedef struct dadosCarro Carros;
typedef struct dadosCliente Clientes;

// -------------Declarações de Estruturas-------------
struct dadosDataDeNascimento{
	int mes;
	int dia;
	int ano;
};

struct dadosCarro{
	char placa[8];
	char codigoSequencial[10];
	char marcaModelo[31];
	int ano;
	Carros *proximo;
};

struct dadosCliente{
	char nome[50];
	char codigo[8];
	char tipoContrato;
	int quantidadePlacas;
	DataNascimento *dataNascimento;
	Carros *carros;
	Clientes *anterior;
	Clientes *proximo;
};

//-------------Prototipação de Funções-------------

//MENU
void menuPrincipal();
void menuInserir(Clientes **inicio, Clientes **fim, int *codigoSequencial);
void inserirCliente(Clientes **inicio, Clientes **fim, int *numeroSequencial);
void inserirPlaca(Clientes **inicio, int *numeroSequencial);
void menuExcluir(Clientes **inicio);
void menuRelatorios();

//INSERIR CLIENTE
Clientes* criarCliente(Clientes **inicio, Clientes **fim, int *codigo);

//INSERIR CARRO
Carros* criaCarro(Clientes *cliente, int *codigo);

//FUNCOES DE BUSCA
char* buscarCodigo(char* mensagem);
Clientes* buscarClientePorCodigo(Clientes *inicio, char *codigoCliente);
Carros* buscarCarroPorCodigo(Clientes *inicio, char *codigoCarro, Carros **anterior);

//FUNCOES DE IMPRESSAO
//void imprimeCliente(Clientes *cliente, int numCliente);
void imprimeCarroRecursivo(Carros *carro, int numCarro);
void imprimeClienteRecursivo(Clientes *cliente, int numCliente);

//LISTAR TODOS CLIENTES
void listarTodosClientes(Clientes *inicio);

//LSTAR CLIENTE POR CODIGO
void listarClientePorCodigo(Clientes *inicio);

//LISTAR CLIENTES POR CONTRATO
void listarClientesPorContrato(Clientes *inicio);

//EXCLUIR CLIENTE
void excluirCliente(Clientes **inicio);
void excluirPlaca(Clientes **inicio);

//NOME
void receberNomePreenchido(Clientes *cliente);
void formatarNomeRecursiva(char *nome, int indice, int caractereDeveSerPego);

//DATA
void solicitarDataDeNascimento(Clientes *cliente);
DataNascimento converterData(char *data_str);
int verificarIdade(int ano);
int isAnoBissexto(int ano);
int isDataValida(int dia, int mes, int ano);

//FUNCAO CODIGO
void gerarCodigoSequencial(Clientes *cliente, int numeroSequencial);

//TIPO DE CONTRATO
void verificarTipoContrato(Clientes *cliente);

//FUNCAO QTDE PLACA
void quantidadePlacas(Clientes *cliente);

//PLACAS
void chamarFuncoesPlacas();
void validarPlacaAntiga();
void validarPlacaNova();

//FUNCAO CODIGO
void gerarCodigoSequencialCarro(Carros *carro, Clientes *cliente, int numeroSequencial);

//FUNCAO MODELO
void receberMarcaModeloCarro(Carros *carro);

//FUNCAO ANO
void receberAnoCarro(Carros *carro);

#endif /* BIBLIOTECA_H_ */
