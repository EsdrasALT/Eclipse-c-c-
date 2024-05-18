#include <stdio.h>
#include <stdlib.h>

int main() {
    setbuf(stdout, NULL);

    int tamanho;
    char *string;

    printf("\nQual o tamanho da sua maturidade? (1 a 10): \n");
    scanf("%d", &tamanho);

    // Allocate memory for the string plus the null terminator
    string = (char*) malloc((tamanho + 1) * sizeof(char));
    if (string == NULL) {
        printf("Erro ao alocar a memoria\n");
        return 1;
    }

    printf("Digite a string: \n");
    // Use "%s" with a width specifier to prevent overflow
    scanf("%s", string);

    // Print the original string with vowels
    printf("Sua string COM vogais: %s\n", string);

    // Print the string without vowels
    printf("Sua string SEM vogais: ");
    for (int i = 0; i < tamanho; i++) {
        if (string[i] != 'a' && string[i] != 'A' && string[i] != 'e' && string[i] != 'E' &&
            string[i] != 'i' && string[i] != 'I' && string[i] != 'o' && string[i] != 'O' &&
            string[i] != 'u' && string[i] != 'U') {
            putchar(string[i]);
        }
    }
    printf("\n");

    free(string);

    return 0;
}
