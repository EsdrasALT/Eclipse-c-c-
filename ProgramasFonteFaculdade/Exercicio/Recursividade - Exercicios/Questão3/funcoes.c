//QUESTÃO 3

// pow(variável, expoente)

float calcularSerieIterativo(int numero) {
	float soma = 0.0;

    for (int i = 1; i <= numero; ++i) {
    	soma += pow(i, 3) / pow(10, i - 1);
    }
    return soma;
}

float calcularSerieRecursividade(int numero){
	if (numero > 1) {
		return pow(numero, 3) / pow(10, numero-1) +	calcularSerieRecursividade(numero-1);
	} else {
		return 1;
	}
}

float calcularSerieRecursividadeDeCauda(int numero, int controlador){
	if (controlador > 1) {
		return controlador;
	}
	return calcularSerieRecursividadeDeCauda(pow(numero, 3) / pow(10, numero - 1),controlador-1);
}
