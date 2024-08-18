#include <stdio.h>
#include <stdlib.h>


/*
 * quantidade 3
 *
 * MALLOC
 * [XPTO][ZPT][EITX]
 * MALLOC NÃO REMOVE LIXO DA MEMORIA
 */

int main (){
	setbuf(stdout,NULL);

	int quantidade, *ponteiro;

	ponteiro = (int*) malloc (3 * sizeof(int));

	if(ponteiro){
		printf("Informe pra gente quantas declarações voce fará: ");
		scanf("%d", &quantidade);

		if(quantidade > 3){
			ponteiro = (int*) realloc (ponteiro, quantidade * sizeof(int));
		}

		for(int i=0;i<quantidade;i++){
				printf("Informe os valores aqui bonitão, da %d° possição: ", i);
				scanf("%d", &ponteiro[i]);
		}

		for(int i=0;i<quantidade;i++){
			printf("O Vetor 'queNãoFoiDeclarado[%d]' está o valor %d\n", i, ponteiro[i]);
		}

		printf("A variavel 'ponteiro' ocupa %d bytes na memoria", quantidade * sizeof(int));

		//Liberar a memoria (desalocar)
		free(ponteiro);
		ponteiro = NULL;
		//Medida de segurança

	} else {
		printf("Erro, Memoria insuficiente");
	}


	return 0;
}
