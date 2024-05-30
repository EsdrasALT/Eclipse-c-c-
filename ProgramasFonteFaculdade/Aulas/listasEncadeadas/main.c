#include "biblioteca.h"

int main (void){
	setbuf(stdout,NULL);
    listaSimples *lista = NULL;
    
    for (int i=0; i<=3; i++){
        lista = inserirInicio(lista);
    }    
    
	return 0;
}

