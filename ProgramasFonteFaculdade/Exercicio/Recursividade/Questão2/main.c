//QUESTÃO 2
#include "biblioteca.h"

int main (void){
	setbuf(stdout,NULL);

	int numero=5, contador=6;

	printf("---INICIO iterativo----\n");
	iterativo(numero,contador);
	printf("----FIM iterativo-----\n\n");

	printf("---INICIO recursivaComum----\n");
	recursivaComum(numero,contador);
	printf("----FIM recursivaComum-----\n\n");

	printf("---INICIO recursivaDeCauda----\n");
	recursivaDeCauda(numero,contador);
	printf("----FIM recursivaDeCauda-----\n");

	return 0;
}

