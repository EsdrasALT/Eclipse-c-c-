int receberValor (int *vetor, int tamanho);

int main() {
    int tamanho = 5;
    int vetor[5];

    receberValor(&vetor, tamanho);

    printf("\nValores digitados:");
    for (int i = 0; i < tamanho; i++) {
        printf("\n%d", vetor[i] * 2);
    }

    return 0;
}

int receberValor (int *vetor, int tamanho){
    
    for(int i=0;i<tamanho;i++){
        printf("\nDigite os valores %d/5: \n", i);
        scanf("%d", &vetor[i]);
    }
}


