#include <stdio.h>
#include <stdlib.h>

//CALLOC

/*
 * quantidade 3
 *
 * MALLOC
 * [XPTO][ZPT][EITX]
 * MALLOC NÃO REMOVE LIXO DA MEMORIA
 *
 * CALLOC
 * [][][]
 *
 */

int main (){
	setbuf(stdout,NULL);

	int quantidade, *ponteiro, *ponteiroCalloc;

	printf("Informe pra gente quantas declarações voce fará: ");
	scanf("%d", &quantidade);

	ponteiro = (int*) malloc (quantidade * sizeof(int));
	for(int i=0;i<quantidade;i++){
		printf("Verificando as posições usando Malloc: %d\n", ponteiro[i]);
	}

	ponteiroCalloc = (int*) calloc (quantidade, sizeof(int));
	for(int i=0;i<quantidade;i++){
		printf("Verificando as posições usando Calloc: %d\n", ponteiroCalloc[i]);
	}

	//ponteiro = (int*) calloc (quantidade,sizeof(int));

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

	return 0;
}
