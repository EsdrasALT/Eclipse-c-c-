// BIBLIOTECA - biblioteca.h = https://codeshare.io/64xkqp

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

// -------------Inclusões de Bibliotecas Necessárias-------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// -------------Definições de Macros e Constantes-------------

// -------------Definições de Tipos (typedefs e enums)-------------

// -------------Declarações de Estruturas-------------
typedef struct {
	int mes;
	int dia;
	int ano;
} DataNascimento;

typedef struct {
	//Dados Simples
	char nome[50];
	char codigo;
	int quantidade;
	char tpContrato;
	int quantidadePlacas;

  //TO-DO Declaracao Listas

} CadastroClientes;

typedef struct {
	//Dados Simples
	char placa[7];
	char *codigoSequencial;
	char marcaModelo[30];
	int ano;

  //TO-DO Declaracao Listas

} CadastroPlacas;

//-------------Prototipação de Funções-------------
//MENU
void menuPrincipal();
void menuInserir();
void menuExcluir();
void menuRelatorios();

//DATA
int validarData(int dia, int mes, int ano);
DataNascimento converterData( char *data_str);
DataNascimento solicitarDataDeNascimento();
int verificarIdade(DataNascimento data_nascimento); //TO-DO IMPLEMENTAR

//NOME
void receberNomePreenchido(CadastroClientes *cliente);
void formatarNomeRecursiva(char *nome);

#endif /* BIBLIOTECA_H_ */
