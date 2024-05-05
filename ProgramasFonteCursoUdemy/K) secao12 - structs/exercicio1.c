#include <stdio.h>
#include <string.h>

struct st_pessoa{
		char nome[100];
		int idade;
		char endereco[100];
};

int main(){
	setbuf(stdout,NULL);

	struct st_pessoa Pessoa[2];

	for(int i=0; i<2; i++){
			printf("Informe o seu nome: ");
			fgets(Pessoa[i].nome, 100, stdin);

			printf("Informe a sua idade: ");
			scanf("%d", &Pessoa[i].idade);
			getchar();

			printf("Informe o seu endereço: ");
			fgets(Pessoa[i].endereco, 100, stdin);
		}

	printf("==================Pessoas Listadas====================\n");
		for(int i=0; i<2; i++){
			printf("==================Pessoa %d====================\n", (i+1));
			printf("Nome: %s\n", strtok(Pessoa[i].nome, "\n"));
			printf("Idade: %d\n", Pessoa[i].idade);
			printf("Endereço: %s\n", strtok(Pessoa[i].endereco, "\n"));
		}


	return 0;
}

