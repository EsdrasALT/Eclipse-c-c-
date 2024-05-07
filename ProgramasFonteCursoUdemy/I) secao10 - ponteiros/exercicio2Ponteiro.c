/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int variavelA;
	int variavelB;

	printf("\nDigite o 1° numero:\n", variavelA);
	scanf("%d", &variavelA);
	printf("\nDigite o 2° numero:\n", variavelB);
	scanf("%d", &variavelB);

	int *ponteiroA = &variavelA;
	int *ponteiroB = &variavelB;

    
	if (ponteiroA > ponteiroB){
	    printf("\nValor da 1° variavel: %d", *ponteiroA);
	} else {
	    printf("\nValor da 2° variavel: %d", *ponteiroB);
	}

	return 0;
}

