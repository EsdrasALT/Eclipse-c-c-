#include <stdio.h>
#include <string.h>

struct st_aluno{
		char nome[100];
		int matricula;
		char curso[100];
};

struct st_salaAula{
	struct st_aluno Alunos[100];
}salaDeAula;

int main(){
	setbuf(stdout,NULL);

	for(int i=0; i<3; i++){
			printf("Informe o seu nome: ");
			scanf("%s", salaDeAula.Alunos[i].nome);

			printf("Informe a sua idade: ");
			scanf("%d", &salaDeAula.Alunos[i].matricula);
			getchar();

			printf("Informe o seu curso: ");
			fgets(salaDeAula.Alunos[i].curso, 100, stdin);
		}

	printf("==================Pessoas Listadas====================\n\n");
		for(int i=0; i<3; i++){
			printf("==================Pessoa %d====================\n", (i+1));
			printf("Nome: %s\n", salaDeAula.Alunos[i].nome);
			printf("Idade: %d\n", salaDeAula.Alunos[i].matricula);
			printf("Curso: %s\n", strtok(salaDeAula.Alunos[i].curso, "\n"));
		}


	return 0;
}

