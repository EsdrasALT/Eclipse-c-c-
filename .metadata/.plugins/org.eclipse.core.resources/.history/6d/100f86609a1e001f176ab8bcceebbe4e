//AAI
#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

// Inclusões de Bibliotecas Necessárias
#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

// Definições de Macros e Constantes

// Definições de Tipos (typedefs e enums)
typedef struct st_DataDeNascimento Data;
typedef struct st_DadosDeCadastroClientes Clientes;
typedef struct st_DadosDeCadastrosPlacas Placas;


// Declarações de Estruturas
struct st_DataDeNascimento{
	int dia;
	int mes;
	int ano;
};

struct st_DadosDeCadastroClientes {
    //Dados Basicos
	char nome[51];
    char codigo[9];
    char tipoContrato;
    int qtdePlacas;

    //Listas
    Clientes *proximosClientes; //lista duplamente encadeada + inserção pelo fim da lista
};

struct st_DadosDeCadastrosPlacas {
	//Dados basicos
    char placa[8];
    char codigo[11];
    char marcaModelo[31];
    int ano;

    //Listas
    Placas *proximaPlaca; //lista simplesmentes encadeada + inserção pelo fim da lista
};


// Prototipação de Funções
void menuPrincipal();
void menuInserir();
void menuExcluir();
void menuRelatorios();

#endif /* BIBLIOTECA_H_ */
