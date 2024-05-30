#include "biblioteca.h"

listaSimples* inserirInicio (listaSimples *inicioLista){
    //Alocar novo espaço de memoria
    listaSimples *novo = (listaSimples*)malloc(sizeof(listaSimples));
    
    //Preencher dados basicos
    novo->codigo = ALEATORIO(100);
    
    //O novo elemento vai apontar para inicio da lista
    novo->proximo = inicioLista;
    
    //Atualizar a lista
    return novo;
}

void impressao(listaSimples *lista){
    if (lista != NULL) {
        printf("\nEndereço %p - Codigo %d - Proximo %p", lista, lista->codigo, lista->proximo);
        impressao(lista->proximo);
    }
}