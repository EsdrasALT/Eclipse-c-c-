#include <stdio.h>
#include <stdlib.h>

void removeVogais(char *);

int main (){
	setbuf(stdout,NULL);

	int tamanho;
	char *string;

	printf("\nQual o tamanho da sua maturidade? (1 a 10): \n");
	scanf("%d", &tamanho);

	string = (char*) malloc ((tamanho + 1) * sizeof(char*));

	if (string == NULL){
		printf("Erro ao alocar a memoria\n");
		return 1;
	}

	printf("Digite a string: \n");
	fgets(string[tamanho], tamanho, stdin);

	printf("Sua string COM vogais: %s", string);
	removerVogais(string);
	printf("Sua string SEM vogais: %s", string);

	free(string);

	return 0;
}

void removeVogais(char *str) {
    int i, j = 0;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u' &&
            str[i] != 'A' && str[i] != 'E' && str[i] != 'I' && str[i] != 'O' && str[i] != 'U') {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}
