// MAIN - programaPrincipal.c = https://codeshare.io/jALdkP

#include "biblioteca.h"

//Daniel Ribeiro Costa
//Danilo Augusto
//Esdras Altivo

int main(void) {
	setbuf(stdout, NULL);

	//DataNascimento dataNascimento;
	//dataNascimento = solicitarDataDeNascimento();
	CadastroClientes *Clientes;
	receberNomePreenchido(Clientes);

	//menuPrincipal();


	return EXIT_SUCCESS;
}
