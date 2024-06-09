/*
 ============================================================================
 Name        : ListaSimples.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "bibliotecaLista.h"

int main(void) {
	setbuf(stdout, NULL);

//	listaSimples *lista = NULL;
//	listaSimples *ultimo = NULL;
//
//	listaSimples *lista = NULL;
//	for (int i = 1; i <= 5; i++) {
//		lista = inserirInicio(lista);
//		impressao(lista);
//		printf("\n\n");
//	}
//
////	listaSimples *lista = NULL;
//	for (int i = 1; i <= 5; i++) {
//		lista = inserirFim(lista);
//		impressao(lista);
//		printf("\n\n");
//	}

	listaSimples *lista = NULL;
	listaSimples *ultimo = NULL;
	for (int i = 1; i <= 5; i++) {
		inserirFimUltimo(&ultimo);
		if (lista == NULL) {
			lista = ultimo;
		}
//		impressao(lista);
//		printf("\n\n");
	}



	//Buscar registro
	listaSimples *anterior = NULL;
	listaSimples *buscar = buscarRegistro(lista, 34, &anterior);
	printf("\nO registro está no endereço %p com anterior %p\n",
				buscar, anterior);

	for (int i = 1; i <= 6; i++) {
		lista = excluirRegistro(lista);
		impressao(lista);
		printf("\n\n\n");
	}

	return EXIT_SUCCESS;
}
