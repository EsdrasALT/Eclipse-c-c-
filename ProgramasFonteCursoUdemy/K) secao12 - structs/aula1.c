#include <stdio.h>
#include <string.h>

struct st_aluno {
	char matricula[10];
	char nome[100];
	char curso[50];
	int ano_nascimento;
};

/* Outras formas de declarar uma struct

2°)
struct st_aluno {
	char matricula[10];
	char nome[100];
	char curso[50];
	int ano_nascimento;
}aluno1;

3°)
struct st_aluno {
	char matricula[10];
	char nome[100];
	char curso[50];
	int ano_nascimento;
}aluno[5];


*/


int main (){
	setbuf(stdout,NULL);

	struct st_aluno aluno1;

	printf("Informe a matricula do aluno: ");
	fgets(aluno1.matricula, 10, stdin); // variavel + tamanho do char + stdin

	printf("Informe o nome do aluno: ");
	fgets(aluno1.nome, 100, stdin);

	printf("Informe o curso do aluno: ");
	fgets(aluno1.curso, 50, stdin);

	printf("Informe o ano de nascimento do aluno: ");
	scanf("%d", &aluno1.ano_nascimento);

	printf("==================Dados do Aluno====================\n");
	printf("Matricula: %s\n", aluno1.matricula);
	printf("Nome: %s\n", aluno1.nome);
	printf("Curso: %s\n", aluno1.curso);
	printf("Ano de nascimento: %d\n", aluno1.ano_nascimento);

	return 0;
}
