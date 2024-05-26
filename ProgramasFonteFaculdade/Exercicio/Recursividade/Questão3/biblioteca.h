//QUESTÃO 3
#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

// Inclusões de Bibliotecas Necessárias
#include <stdio.h>
#include <stdlib.h>
#include <math.h> // pow(variável, expoente)	potenciação

// Definições de Macros e Constantes

// Definições de Tipos (typedefs e enums)

// Declarações de Estruturas

// Prototipação de Funções
float calcularSerieIterativo(int n);
float calcularSerieRecursividade(int numero);
float calcularSerieRecursividadeDeCauda(int numero,int controlador);

#endif /* BIBLIOTECA_H_ */
