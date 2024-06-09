/*
 * funcoesLista.c
 *
 *  Created on: 27 de mai. de 2024
 *      Author: 1P1226
 */
#include "bibliotecaLista.h"


listaSimples* inserirInicio(listaSimples *inicioLista){
	//Criar o novo elemento - Ainda não faz parte da lista
	listaSimples *novo = (listaSimples*) malloc (sizeof(listaSimples));
	novo->codigo = ALEATORIO(100);
	//carro = chamarTodasAsFuncoes()

	//Aqui estamos conectando o registro à lista.
	novo->proximo = inicioLista;

	//Atualizar, externamente, o início da lista
	return novo;
}

listaSimples* inserirFim(listaSimples *inicioLista) {
	//Criar o novo elemento - Ainda não faz parte da lista
	listaSimples *novo = (listaSimples*) malloc (sizeof(listaSimples));
	novo->codigo = ALEATORIO(100);

	novo->proximo = NULL; //Depois do novo não tem ninguém.
	//Aqui estamos conectando o registro à lista.
	if (inicioLista == NULL) { //if (!inicioLista) {
		return novo; //O novo é o primeiro.
	} else {
		listaSimples *tmp = inicioLista; //Esse ponteiro vai deslocar.
		//Encontrar o registro que aponta para NULL
		while (tmp->proximo != NULL) {
			tmp = tmp->proximo;
		}

		//Conecetar o último atual ao novo
		tmp->proximo = novo;

		return inicioLista; //O primeiro não muda.
	}
}

void inserirFimUltimo(listaSimples **ultimoLista){
	//Criar o novo elemento - Ainda não faz parte da lista
	listaSimples *novo = (listaSimples*) malloc (sizeof(listaSimples));
	novo->codigo = ALEATORIO(100);
	novo->proximo = NULL;

	if (*ultimoLista != NULL) {//Já existe registro na lista.
		(*ultimoLista)->proximo = novo;
	}

	(*ultimoLista) = novo;
}

listaSimples* buscarRegistro(listaSimples* atual, int cod,
							listaSimples **anterior) {
	while(atual != NULL){ //while(atual)
		if (atual->codigo == cod) {//Encontrei
			return atual;
		} else {//Não encontrei.
			*anterior = atual;
			atual = atual->proximo;
		}
	}
	printf("\nRegistro não encontrado.\n");
	return NULL;
}

listaSimples* excluirRegistro(listaSimples *inicio){
	int codigo = buscarCodigo("\nDigite o código do registro a "
								"ser excluído: \n");
	listaSimples *anterior = NULL;
	listaSimples *excluir = buscarRegistro(inicio, codigo, &anterior);

	if (excluir != NULL) { //if (excluir) {
		if (anterior == NULL) { //if (!anterior) {
			inicio = inicio->proximo;
		} else {
			anterior->proximo = excluir->proximo;
		}
		free(excluir);
	}
	return inicio;
}

void impressao(listaSimples *lista){
	if (lista != NULL) { 	// if (lista) {
		printf("\nEndereço %p - Código %d - Próximo %p\n",
				lista, lista->codigo, lista->proximo);
		impressao(lista->proximo);
	}
}

int buscarCodigo(char *frase){
	int codigo;
	do{
		printf("\n%s", frase);
		scanf("%d", &codigo);

		if (codigo < 0) {
			printf("\nCódigo inválido.");
		}
	} while (codigo < 0);
	return codigo;
}
