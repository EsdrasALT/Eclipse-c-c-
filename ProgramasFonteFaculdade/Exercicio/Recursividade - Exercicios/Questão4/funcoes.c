//QUESTÃO 4

int vetorRecursivoIterativo(int *vetor, int tam){
	int soma = 0;
	for(int i=0;i<tam;i++){
		soma = vetor[i] + soma;
	}
	return soma;
}

int vetorRecursivoIndice(int *vetor, int tam){
	if (tam > 1){
		return vetor[tam-1] + vetorRecursivoIndice(vetor, tam-1);
	} else {
		return vetor[tam-1];
	}
}

int vetorRecursivoDeCauda (int *vetor, int tam, int parcial){
	if (tam < 1){
		return parcial;
	}
	return vetorRecursivoDeCauda(vetor,tam-1,vetor[tam-1]+parcial);
}
