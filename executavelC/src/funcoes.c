/*
 * funcoes.c
 *
 *  Created on: 24 de jun. de 2024
 *      Author: Bless
 */

void menu(){

	int op;
	float media;

	printf("Digite a opção(1 ou 2): ");
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
		default:
			printf("\nOpção invalida");
			break;
	}

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
