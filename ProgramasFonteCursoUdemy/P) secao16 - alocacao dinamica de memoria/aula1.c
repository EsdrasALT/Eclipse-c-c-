#include <stdio.h>
#include <stdlib.h>

int main (){
	setbuf(stdout,NULL);

	int quantidade, *ponteiro;

	printf("Informe pra gente quantas declarações voce fará: ");
	scanf("%d", &quantidade);

	ponteiro = (int*) malloc (quantidade * sizeof(int));

	for(int i=0;i<quantidade;i++){
		printf("Informe os valores aqui bonitão, da %d° possição: ", i);
		scanf("%d", &ponteiro[i]);
	}

	for(int i=0;i<quantidade;i++){
		printf("O Vetor 'queNãoFoiDeclarado[%d]' está o valor %d\n", i, ponteiro[i]);
	}

	printf("A variavel 'ponteiro' ocupa %ld bytes na memoria", quantidade * sizeof(int));

	//Liberar a memoria (desalocar)
	free(ponteiro);
	ponteiro = NULL;
	//Medida de segurança

	return 0;
}
