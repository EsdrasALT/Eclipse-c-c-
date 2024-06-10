// BIBLIOTECA - biblioteca.h = https://codeshare.io/64xkqp

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
	//Dados Simples
	char placa[PLACA_LENGTH+1]; // +1 para o caractere \0
	char *codigoSequencial[8];
	char marcaModelo[30];
	int ano;

  //TODO Declaracao Listas
	Carros *proximoDaLista;
};

struct dadosCliente{
	//Dados Simples
	char nome[50];
	char codigo[7];
	char tipoContrato;
	int quantidadePlacas;
	Carros *carros[MAX_CARROS];

  //TODO Declaracao Listas

};

//-------------Prototipação de Funções-------------
//MENU
void menuPrincipal();
void menuInserir();
	void inserirCliente();
	void inserirPlaca();

void menuExcluir();
void menuRelatorios();

//LISTAS
void inserirFimUltimo(Carros **ultimoLista);

//NOME
void receberNomePreenchido(Clientes *cliente);
void formatarNomeRecursiva(char *nome, int indice, int caractereDeveSerPego);

//DATA
void solicitarDataDeNascimento(DataNascimento *dataNascimento);
DataNascimento converterData(char *data_str);
int verificarIdade(int ano);
int isAnoBissexto(int ano);
int isDataValida(int dia, int mes, int ano);

//FUNCAO CODIGO
void gerarCodigoSequencial(Clientes *cliente, DataNascimento *dataNascimento, int *numeroSequencial);

//TIPO DE CONTRATO
void verificarTipoContrato(Clientes *cliente);

//FUNCAO QTDE PLACA
void quantidadePlacas(Clientes *cliente);

//PLACAS
void chamarFuncoesPlacas();
	void validarPlacaAntiga();
	void validarPlacaNova();

//FUNCAO CODIGO - TODO
void gerarCodigoSequencialCarro(Carros *carro,Clientes *cliente, int *numeroSequencial);

//FUNCAO MODELO - TODO
//FUNCAO ANO - TODO

#endif /* BIBLIOTECA_H_ */
