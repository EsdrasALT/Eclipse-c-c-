//QUESTÃO 4
#include "biblioteca.h"

int main (void){
	setbuf(stdout,NULL);

	int vetor[] = {5, 10, 20, 40};
	printf("\nSoma dos elementos é %d\n", vetorRecursivoIterativo(vetor, 4));
	printf("\nSoma dos elementos é %d\n", vetorRecursivoIndice(vetor, 4));
	printf("\nSoma dos elementos é %d\n", vetorRecursivoDeCauda(vetor, 4,0));

	return 0;
}

