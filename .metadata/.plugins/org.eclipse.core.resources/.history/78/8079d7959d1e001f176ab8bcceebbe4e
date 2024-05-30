// BIBLIOTECA - biblioteca.h = https://codeshare.io/64xkqp

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

// -------------Inclusões de Bibliotecas Necessárias-------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// -------------Definições de Macros e Constantes-------------

// -------------Definições de Tipos (typedefs e enums)-------------

// -------------Declarações de Estruturas-------------
typedef struct {
	int mes;
	int dia;
	int ano;
} DataNascimento;

typedef struct {
	char nome[50];
	char codigo;
	int quantidade;
	char tpContrato;
	int quantidadePlacas;

} cadastroClientes;

typedef struct {
	char placa[7];
	char *codigoSequencial;
	char marcaModelo[30];
	int ano;

} cadastroPlacas;

//-------------Prototipação de Funções-------------
void menuPrincipal();
void menuInserir();
void menuExcluir();
void menuRelatorios();
int validarData(int dia, int mes, int ano);


#endif /* BIBLIOTECA_H_ */
