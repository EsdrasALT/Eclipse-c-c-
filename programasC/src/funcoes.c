#include "biblioteca.h"

void menu() {
	char opcao;
	Produto *produtos = NULL;
	int quantidadeTotalProdutos = 0;

	printf("-------------Bem vindo-------------------\n");

	do {
		printf("\nEscolha uma das opções abaixo:\n");
		printf("A - Criar estrutura para preenchimento\n");
		printf("B - Preencher dados\n");
		printf("C - Exibir produtos com estoque zerado\n");
		printf("D - Exibir produtos em estoque\n");
		printf("E - Finalizar\n");
		printf("Digite sua opção: ");
		scanf(" %c", &opcao);
		getchar();

		switch (opcao) {
		case 'A':
			printf("Você escolheu a opção A.\n\n");
			if (produtos == NULL) {
				quantidadeTotalProdutos = solicitarQuantidadeTotalProdutos();
				produtos = criarEstruturaDinamicamente(quantidadeTotalProdutos);
			}
			//To-do: Implementação de apagar struct antiga e criar uma nova
			break;
		case 'B':
			printf("Você escolheu a opção B.\n\n");
			//cadastrarNome(produtos,quantidadeTotalProdutos);
			cadastrarPreco(&produtos->preco,quantidadeTotalProdutos);
			break;
		case 'C':
			printf("Você escolheu a opção C.\n\n");
			break;
		case 'D':
			printf("Você escolheu a opção D.\n\n");
			break;
		case 'E':
			printf("Você escolheu a opção E.\n\n");
			break;
		default:
			printf("Opção inválida!\n\n");
			break;
		}
	} while (opcao != 'E');

	printf("\n----------------Fim do Programa------------------");
}

int solicitarQuantidadeTotalProdutos() {
	int qtde;

	do {
		printf("Informe a quantidade total dos produtos que irá cadastrar\n"
			   "Minimo de 1 | Maximo de 10:  ");
		scanf("%d", &qtde);
		getchar();
		printf("\nQuantidade informada: %d", qtde);
		if (qtde <= 0 || qtde > 10) {
			printf("\nQuantidade inválida!\n");
		}
	} while (qtde <= 0 || qtde > 10);

	return qtde;
}

void excluirEstruturaCriada(Produto *produtos) {
	if (produtos != NULL) {
		free(produtos);
		produtos = NULL;
	}
}

Produto *criarEstruturaDinamicamente(int tamanho) {
	Produto *produtos = (Produto *)malloc(tamanho * sizeof(Produto));
	return produtos;
}

void cadastrarNome(Produto *produtos, int quantidade){ //To-do: Limitar o preenchimento apenas do nome

	for(int i=0; i<quantidade;i++){
		printf("Informe o nome do(s) produto(s) abaixo.\n");
		fgets(produtos[i].nome, 40, stdin);
	}

	for(int i=0; i<quantidade;i++){
		printf("Nomes cadastrados %s", produtos[i].nome);
	}
}

void cadastrarPreco(float *valor, int quantidade){

	for(int i=0; i<quantidade;i++){
		printf("Digite o preço do produto: ");
		scanf("%2f", &valor[i]);
	}

	for(int i=0; i<quantidade;i++){
		printf("Valores cadastrados %2f\n", valor[i]);
	}
}

