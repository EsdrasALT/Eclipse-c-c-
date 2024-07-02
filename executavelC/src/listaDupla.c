#include <stdio.h>
#include <stdlib.h>

typedef struct st_Lista Lista;

struct st_Lista{
    int valor;
	Lista *anterior;
    Lista *proximo;
};

Lista* criarNovoNoPeloInicio(Lista *lista){
	Lista *novoNo = (Lista*) malloc (sizeof(Lista));

	novoNo->valor = rand();
	novoNo->anterior = NULL;
	novoNo->proximo = NULL;

	if(lista == NULL){
		lista = novoNo;
		return novoNo;
	}

	novoNo->proximo = lista;
	lista->anterior = novoNo;

	return novoNo;
}

void criarNovoNoPeloFimUltimo(Lista **ultimo){
	Lista *novoNo = (Lista*) malloc (sizeof(Lista));

	novoNo->valor=rand();
	novoNo->anterior=NULL;
	novoNo->proximo=NULL;

	if(*ultimo != NULL){
		(*ultimo)->proximo = novoNo;
		novoNo->anterior = (*ultimo);
	}
	*ultimo = novoNo;
}

Lista* buscarRegistro(Lista *lista, int valor){
	while(lista!=NULL){
		if(lista->valor==valor){
			return lista;
		}
		lista=lista->proximo;
	}
	printf("Não encontrado\n");
	return NULL;
}

Lista* excluirRegistro(Lista *lista){
	int valor;
	printf("Digite valor: ");
	scanf("%d",&valor);
	Lista *excluir = buscarRegistro(lista,valor);

	if(excluir!=NULL){

		Lista *anterior = excluir->anterior;
		Lista *proximo = excluir->proximo;

		if(anterior == NULL){
			lista = lista->proximo;
			if(proximo != NULL){
				proximo->anterior=NULL;
			}
		}

		free(excluir);
	}
	return lista;
}

void imprimir(Lista *lista){
	if (lista != NULL){
		printf("Valor %d - Anterior %p - Endereço %p - Proximo %p\n",
				lista->valor, lista->anterior, lista, lista->proximo);
		imprimir(lista->proximo);
	}
}

int main(void){
	setbuf(stdout,NULL);

	Lista *lista = NULL;
	Lista *ultimo = NULL;

	for(int i=0;i<3;i++){
		lista = criarNovoNoPeloInicio(lista);
	}
	imprimir(lista);

	for(int i=0;i<3;i++){
		criarNovoNoPeloFimUltimo(&ultimo);
		if(lista == NULL){
			lista=ultimo;
		}
	}
	imprimir(lista);

	return 0;
}
