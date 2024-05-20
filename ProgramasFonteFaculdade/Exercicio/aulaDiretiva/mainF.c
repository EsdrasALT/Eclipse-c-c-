/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(void){
    setbuf(stdout, NULL);
    int numero = 7;
    
    printf("\n%i",TAMANHO);
    
    printf("\nMaior numero entre 12 e 5: %i", MAIOR(12, 5));
    
    printf("\n%i * %i = %i",numero, numero, SQR(numero));

    printf("\n3 + 5 = %i",somar(3,5));

    return 0;
}
