//1
#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_
//a bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//b macros e const
#define MAX_NAME 50
//c typedef e enum
typedef struct st_Funcionario Funcionario;

//d structs
struct st_Funcionario{
	float salario;
	char nome[MAX_NAME];
	int id;
	struct Funcionario *anterior;
	struct Funcionario *proximo;
};

//e prototipos das funcoes
void menu();
Funcionario* criarFuncionario(Funcionario **inicio, Funcionario **fim, int **id);
float recebeSalario();
int valorInteiro();
float valorReal();
float calcularNovoSalario(float salario);
float receberSalario();

#endif /* BIBLIOTECA_H_ */
