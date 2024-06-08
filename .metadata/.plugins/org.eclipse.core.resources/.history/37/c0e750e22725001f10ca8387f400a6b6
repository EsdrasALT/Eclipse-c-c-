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

// -------------Declarações de Estruturas-------------
typedef struct {
	int mes;
	int dia;
	int ano;
} DataNascimento;

typedef struct {
	//Dados Simples
	char placa[PLACA_LENGTH+1]; // +1 para o caractere \0
	char *codigoSequencial;
	char marcaModelo[30];
	int ano;

  //TODO Declaracao Listas

} Carros;

typedef struct {
	//Dados Simples
	char nome[50];
	char codigo;
	int quantidade;
	char tipoContrato;
	int quantidadePlacas;
	Carros *carros[MAX_CARROS];

  //TODO Declaracao Listas

} Clientes;

//-------------Prototipação de Funções-------------
//MENU
void menuPrincipal();

void menuInserir();
	void inserirCliente();
	void inserirPlaca();

void menuExcluir();
void menuRelatorios();

//NOME
void receberNomePreenchido(Clientes *cliente);
void formatarNomeRecursiva(char *nome); // TODO IMPLEMENTAR

//FUNCAO CODIGO - TODO

//DATA
int validarData(int dia, int mes, int ano);
DataNascimento converterData( char *data_str);
DataNascimento solicitarDataDeNascimento();
int verificarIdade(DataNascimento data_nascimento); //TODO IMPLEMENTAR

//TIPO DE CONTRATO
void verificarTipoContrato();

//FUNCAO QTDE PLACA - TODO

//PLACAS
void chamarFuncoesPlacas();
void validarPlacaAntiga();
void validarPlacaNova();

//FUNCAO CODIGO - TODO
//FUNCAO MODELO - TODO
//FUNCAO ANO - TODO

#endif /* BIBLIOTECA_H_ */
