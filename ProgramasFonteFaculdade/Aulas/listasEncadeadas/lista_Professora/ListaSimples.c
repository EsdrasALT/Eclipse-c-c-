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
	listaSimples *lista = NULL;
	listaSimples *ultimo = NULL;

	for (int i = 1; i <= 5; i++) {
		lista = inserirInicio(lista);
		//lista = inserirFim(lista);

		inserirFimUltimo(&ultimo);
		if (lista == NULL) {
			lista = ultimo;
		}
		impressao(lista);
		printf("\n\n\n");

	}

	//Buscar registro
//	listaSimples *anterior = NULL;
//	listaSimples *buscar = buscarRegistro(lista, 34, &anterior);
//	printf("\nO registro está no endereço %p com anterior %p\n",
//				buscar, anterior);

	for (int i = 1; i <= 6; i++) {
		lista = excluirRegistro(lista);
		impressao(lista);
		printf("\n\n\n");
	}

	return EXIT_SUCCESS;
}
