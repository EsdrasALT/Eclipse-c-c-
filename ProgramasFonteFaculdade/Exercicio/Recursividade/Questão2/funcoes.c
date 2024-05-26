//QUESTÃO 2
void iterativo(int numero, int contador){
	int total=0;
	for(int i=1;i<=contador;i++){
		total = total + numero;
		printf("%d° - %d x %d = %d\n",i,numero,i,total);
	}
}

void recursivaComum(int numero, int contador){
	if (contador > 1){
		recursivaComum(numero, contador-1);
	}
	printf("%d° - %d * %d = %d\n",contador,numero,contador,numero*contador);
}

void recursivaDeCauda(int numero, int contador) {
    if (contador <= 1) {
        printf("%d° - %d * %d = %d\n", contador, numero, contador, numero * contador);
        return;
    }
    printf("%d° - %d * %d = %d\n", contador, numero, contador, numero * contador);
    recursivaDeCauda(numero, contador - 1);
}
