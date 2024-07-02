#include <stdio.h>
#include <stdlib.h>
typedef struct st_Lista Lista;

struct st_Lista{
    int valor;
	Lista *proximo;
};

Lista* criarNovoNoInicio(Lista *lista){
    Lista *novoNo = (Lista*) malloc (sizeof(Lista));
    if (novoNo == NULL){
        printf("Erro na alocação\n");
        exit(1);
    }
    novoNo->valor=rand();
   	novoNo->proximo = lista;
   	return novoNo;
}

void criarNovoNoFimPeloUltimo(Lista **ultimo){

	Lista *novoNo = (Lista*) malloc (sizeof(Lista));
    if (novoNo == NULL){
        printf("Erro na alocação\n");
        exit(1);
    }
	novoNo->valor=rand();
	novoNo->proximo=NULL;

	if(*ultimo != NULL){
		(*ultimo)->proximo=novoNo;
	}
	*ultimo = novoNo;
}

Lista* buscarRegistro(Lista *lista, int valor, Lista **anterior){
	while (lista != NULL){ //1 - se a lista for nula então nao tem nenhum registro
		if (lista->valor == valor){
			return lista; //2|5 - se encontrou retorna endereço
		} else {
			*anterior = lista; //3 - fora da funcao o anterior recebe o endereço do 1° registro, depois 2° e assim sucessivamente
			lista = lista->proximo; //4 - procurando no proximo registro
		}
	}
	printf("Não encontrado\n");
	return NULL; //6 - não encontrou
}

Lista* excluirRegistro(Lista *lista){
	int valor;
	printf("Digite valor: ");
	scanf("%d",&valor);
	Lista *anterior = NULL;
	Lista *excluir = buscarRegistro(lista,valor,&anterior);

	if(excluir != NULL){ //1- se for nulo, não achamos o registro
		if (anterior == NULL){
			lista = lista->proximo;//2- quer dizer que o excluir é o primeiro da fila, então precisamos mover o ponteiro para frente
		} else {
			anterior->proximo = excluir->proximo; //3 - o anterior (graças a funcao buscarRegistro) recebe o proximo do excluir
		}
		free (excluir); //4 - excluimos

	}
	return lista;
}

void imprimir(Lista *lista){
    if(lista!=NULL){
    	printf("Valor %d - Endereço %p - Proximo %p\n",lista->valor, lista, lista->proximo);
        imprimir(lista->proximo);
    }
    printf("\n");
}

int main(){
	setbuf(stdout,NULL);
    Lista *lista = NULL;
    Lista *ultimo = NULL;

    for(int i=0;i<3;i++){
        lista = criarNovoNoInicio(lista);
    }
    imprimir(lista);

    for(int i=0;i<3;i++){
    	lista = excluirRegistro(lista);
    }
    imprimir(lista);

//    for(int i=0;i<3;i++){
//		criarNovoNoFimPeloUltimo(&ultimo);
//		if (lista == NULL) {
//			lista = ultimo;
//		}
//    }
//	imprimir(lista);

    return 0;
}
