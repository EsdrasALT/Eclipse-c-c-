//QUESTÃO 1
#include "biblioteca.h"

int main (void){
	setbuf(stdout,NULL);

	printf("Iterativa: %d\n\n", iterativa(5,7));
	printf("Recursiva Comum: %d\n\n", recursivaComum(5,7));
	printf("Recursiva de Cauda: %d\n\n", recursivaDeCauda(5,7,0));

	return 0;
}

