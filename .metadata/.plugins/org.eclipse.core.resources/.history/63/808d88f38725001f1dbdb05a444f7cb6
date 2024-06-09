/*
 * bibliotecaLista.h
 *
 *  Created on: 27 de mai. de 2024
 *      Author: 1P1226
 */

#ifndef BIBLIOTECALISTA_H_
#define BIBLIOTECALISTA_H_
//Bibliotecas
#include <stdio.h>
#include <stdlib.h>

//Criar uma macro que gera um número randômico
#define ALEATORIO(x) rand() % (x)

//Criar uma estrutura com um campo inteiro chamado codigo.
typedef struct dadosListaSimples listaSimples;
struct dadosListaSimples{
	//Dados básicos
	int codigo;

	//Apontamentos
	listaSimples *proximo;
};

//struct dadosListaSimples{
//	int codigo;
//	struct dadosListaSimples *proximo;
//};
//typedef struct dadosListaSimples listaSimples;

//typedef struct dadosListaSimples{
//	int codigo;
//	struct dadosListaSimples *proximo;
//} listaSimples;


listaSimples* inserirInicio(listaSimples *inicioLista);
listaSimples* inserirFim(listaSimples *inicioLista);
void inserirFimUltimo(listaSimples **ultimoLista);

void impressao(listaSimples *lista);
int buscarCodigo(char *frase);

listaSimples* buscarRegistro(listaSimples* atual, int cod,
							listaSimples **anterior);
listaSimples* excluirRegistro(listaSimples *inicio);
#endif /* BIBLIOTECALISTA_H_ */
