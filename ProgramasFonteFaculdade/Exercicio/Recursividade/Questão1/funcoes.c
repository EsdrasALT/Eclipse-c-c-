int iterativa(int numero, int multiplicador){
	int resultado=0;
	for (int i=0;i<multiplicador;i++){
		resultado = resultado + numero;

	}
	return resultado;
}

int recursivaComum(int numero, int multiplicador){
	if (multiplicador > 0){
		return numero + recursivaComum(numero, multiplicador-1);
	}
	return 0;
}

int recursivaDeCauda(int numero, int multiplicador, int parcial){
	if (multiplicador == 0) {
		return parcial;
	}
	return recursivaDeCauda(numero, multiplicador - 1, numero+ parcial);
}
