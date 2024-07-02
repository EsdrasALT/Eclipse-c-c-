#include "biblioteca.h"

void menu(){

    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr; // ponteiro para o início do array

    // Acessando elementos usando aritmética de ponteiros
    for (int i = 0; i < 5; i++) {
        printf("%d - %p | ", *(ptr + i), *(ptr + i));
    }
    printf("\n");

    for (int i = 0; i < 5; i++) {
        printf("%d - %p | ", (ptr + i),(ptr + i));
    }
    printf("\n");

    for (int i = 0; i < 5; i++) {
        printf("%d - %p | ", (ptr )+ i, (ptr )+ i);
    }
    printf("\n");

    for (int i = 0; i < 5; i++) {
        printf("%d - %p | ", *(ptr)+ i,*(ptr)+ i);
    }
    printf("\n");

    for (int i = 0; i < 5; i++) {
        printf("%d - %p | ", (&ptr + i),(&ptr + i));
    }
    printf("\n");

    for (int i = 0; i < 5; i++) {
        printf("%d - %p | ", (&ptr) + i,(&ptr) + i);
    }
    printf("\n");














	int op;
	float media;

	Funcionario *inicio = NULL;
	Funcionario *fim = NULL;
	int valorId = 1;
	printf("variavel valorID: Conteudo %d - Endereço %p\n\n",valorId,&valorId);

	int *id = &valorId;
	printf("variavel *id: Conteudo %d - Endereço %p - %p\n\n",id,&id,*id);

	Funcionario *novoFuncionario = criarFuncionario(&inicio,&fim,&id);

	do {
		printf("Digite uma das opçõe\n");
		printf("1 - Cadastrar salario\n");
		printf("2 - Cadastrar nome\n");
		printf("3 - Sair\n");
		printf("Opção: ");
		scanf("%d",&op);

		switch(op){
			case 1:
				printf("\nTeste 1");
				media = recebeSalario();
				printf("Valor medio dos novos salario é %f",media);
				break;
			case 2:
				printf("\nTeste 2");
				break;
			case 3:
				printf("\nEncerrando programa...");
				break;
			default:
				printf("\nOpção invalida\n\n");
				break;
		}
	} while (op != 3);
}

Funcionario* criarFuncionario(Funcionario **inicio, Funcionario **fim, int **id){

	Funcionario *novoFuncionario = (Funcionario*) malloc (sizeof(Funcionario));

	if (novoFuncionario != NULL) {
		printf("Memoria alocada\n");
	} else {
		printf("Erro de memoria\n");
		exit(1);
	}

	printf("===========ANTES DO ++ ==============\n\n");

	printf("%d\n",**id); // conteudo da variavel apontada
	printf("%p\n\n",*id); //endereço da variavel

	printf("%d\n",*id); //conteudo do ponteiro
	printf("%p\n\n",id); // endereço do ponteiro


//	(**id)++ == **id+=1 == **(id)+=1 //// 1° acessar o o conteudo de valorID -> 2° acrescentar valor ++
//	*(id)+=1; ////// == altera o conteudo do ponteiro, apontado para nada ou lixo

	printf("=============DEPOIS DO ++ ===========\n\n");

//	(**id)++; Acrescenta o valor no conteudo da variavel
	printf("%d\n",**id); // conteudo da variavel apontada

//	(*id)++ acrescenta um valor no endereço da variavel
	printf("%p\n\n",*id); //endereço da variavel


	printf("%d\n",*id); //conteudo do ponteiro

//	(id)++; acrescenta um valor no endereço do ponteiro
	printf("%p\n\n",id); // endereço do ponteiro

	novoFuncionario->id = **id;
	novoFuncionario->nome[0] = '\0';
	novoFuncionario->salario = 0;
	novoFuncionario->anterior = NULL;
	novoFuncionario->proximo = NULL;

	printf("Funcionario criado");

	return novoFuncionario;
}


int valorInteiro(){
	int inteiro;

	do{
		printf("Digite quantos salarios serao preenchidos (0 a 50): ");
		scanf("%d",&inteiro);

		if (inteiro <= 0 || inteiro >= 50){
			printf("\nValor incorreto");
		} else {
			printf("\nValor correto");
		}
	}while(inteiro < 0 || inteiro > 50);

	return inteiro;
}

float valorReal(){
	float valorReal;

	do{
		printf("Digite um valor maior que 0: ");
		scanf("%2f",&valorReal);

		if (valorReal <= 0){
			printf("Valor incorreto\n");
		} else {
			printf("Valor correto\n");
		}
	}while(valorReal <= 0);

	return valorReal;
}

float calcularNovoSalario(float salario){
	float novoSalario=0;

	do{
		printf("Digite o salario: ");
		scanf("%f",&salario);

		if (salario <= 0){
			printf("Valor incorreto\n");
		} else {
			printf("Valor correto\n");
		}
	}while(salario <= 0);

		if (salario <= 2500){
			novoSalario = salario * 1.15;
		} else if (salario <= 7000){
			novoSalario = salario * 1.075;
		} else {
			novoSalario = salario;
		}

	return novoSalario;
}

//float receberSalario(){
//	int tamanho = valorInteiro();
//	float salarios[tamanho], novoSalario[tamanho];
//
//	for (int i=0;i < tamanho;i++){
//		salarios[i] = valorReal();
//		novoSalario[i] = calcularNovoSalario(salarios[i]);
//	}
//
//	for(int i=0;i<tamanho;i++){
//		printf("%d° salario\n",i);
//		printf("Valor salario: %f\n", salarios[i]);
//		printf("Valor do aumento: %f\n", novoSalario[i]-salarios[i]);
//		printf("Valor final: %f\n", novoSalario[i]);
//		printf("\n\n");
//	}
//
//	float media = novoSalario[tamanho] / (float)tamanho;
//	return media;
//}

float recebeSalario(){

	float valor = 1;
	return valor;

}
