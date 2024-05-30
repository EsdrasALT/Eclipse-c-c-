//AAI
#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

// Inclusões de Bibliotecas Necessárias
#include <stdio.h>
#include <stdlib.h>

// Definições de Macros e Constantes

// Definições de Tipos (typedefs e enums)

// Declarações de Estruturas

#include <stdio.h>

struct Cliente {
    char nome[51];
    char codigo[9];
    struct DataNascimento {
        int dia;
        int mes;
        int ano;
    } dataNascimento;
    char tipoContrato;
    int qtdePlacas;
    struct Placa *placas;
    struct Cliente *prox;
};

struct Placa {
    char placa[8];
    char codigo[11];
    char marcaModelo[31];
    int ano;
    struct Placa *prox;
};


// Prototipação de Funções
void menuPrincipal();
void menuInserir();
void menuExcluir();
void menuRelatorios();

#endif /* BIBLIOTECA_H_ */
