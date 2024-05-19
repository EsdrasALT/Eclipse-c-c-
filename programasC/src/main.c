#include <stdio.h>
#include "biblioteca.h"

void menu();

struct st_cadastroProdutos{
	int nome[40];
	int codigo;
	float preco;
	int quantidade;
};

int main(){
	setbuf(stdout, NULL);
	//struct st_cadastroProdutos produtoA;

	menu();

	return 0;

}

void menu(){
	char opcao;

	printf("-----Bem vindo-----\n\n");
	printf("Escolha uma das opções abaixo:\n");
	do {
		printf("A - Criar estrutura para preenchimento\n");
		printf("B - Preencher dados\n");
		printf("C - Exibir produtos com estoque zerado\n");
		printf("D - Exibir produtos em estoque\n");
		printf("E - Finalizar\n");
		printf("Digite sua opção: \n");
		scanf("%c", &opcao);
		getchar();

		switch(opcao) {
			case 'A':
			case 'a':
				printf("Você escolheu a opção A.\n");
				break;
			case 'B':
			case 'b':
				printf("Você escolheu a opção B.\n");
				break;
			case 'C':
			case 'c':
				printf("Você escolheu a opção C.\n");
				break;
			case 'D':
			case 'd':
				printf("Você escolheu a opção D.\n");
				break;
			case 'E':
			case 'e':
				printf("Você escolheu a opção E.\n");
				break;
			default:
				printf("Opção inválida!\n\n");
				break;
		}
	} while (opcao != 'E' && opcao != 'e');

	printf("\n\n-----Fim do Programa-----");


}
