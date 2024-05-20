#ifndef biblioteca_h_
#define biblioteca_h_

// Inclusões de Bibliotecas Necessárias
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definições de Macros e Constantes
#define MAX_VALUE 50

// Declarações de Estruturas
typedef struct {
	char nome[40];
	int codigo;
	float preco;
	int quantidade;
} Produto;

// Prototipação de Funções
void menu();
int solicitarQuantidadeTotalProdutos();
void excluirEstruturaCriada(Produto *produtos);
Produto *criarEstruturaDinamicamente(int tamanho);
void gerarCodigoProduto(int *produtos, int quantidade);
void cadastrarNome(Produto *produtos, int quantidade);
void cadastrarPreco(float *valor, int quantidade);
void cadastrarQuantidade(Produto *produtos, int quantidade);
void chamarFuncoesDePreenchimento();
void exibirProdutosZerados(Produto *produtos, int quantidade);
void listarProdutosCadastrados(Produto *produtos, int quantidade);

#endif /* biblioteca_h_ */
