//QUESTÃO 3
#include "biblioteca.h"

int main (void){
	setbuf(stdout,NULL);

	//printf("\n%.3f\n", calcularSerieIterativo(5));
	//printf("\n%.3f\n", calcularSerieRecursividade(5));
	printf("\n%.3f\n", calcularSerieRecursividadeDeCauda(5,5));


	return 0;
}

