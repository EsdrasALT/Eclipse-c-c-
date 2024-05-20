#ifndef biblioteca_h_

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char nome[40];
	int codigo;
	float preco;
	int quantidade;
} Produto;

void menu();
int solicitarQuantidadeTotalProdutos();
void excluirEstruturaCriada(Produto *produtos);
Produto *criarEstruturaDinamicamente(int tamanho);
void cadastrarNome(Produto *produtos, int quantidade);
void cadastrarPreco(float *valor, int quantidade);

#endif /* biblioteca_h_ */
