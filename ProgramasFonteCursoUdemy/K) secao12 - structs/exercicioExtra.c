#include <stdio.h>
#include <string.h>

struct st_vetor {
	float x;
	float y;
	float z;

}vetor[3];

int main (){
	setbuf(stdout,NULL);

	printf("Digite o valor de x: ");
	scanf("%f", &Vetor.x);

	printf("Digite o valor de y: ");
	scanf("%f", &Vetor.y);

	printf("Digite o valor de z: ");
	scanf("%f", &Vetor.z);

	printf("A soma dos valores x e y = %2f\n", (Vetor.x + Vetor.y));
	printf("A soma dos valores y e z = %2f\n", (Vetor.y + Vetor.z));
	printf("A soma dos valores x e z = %2f\n", (Vetor.x + Vetor.z));

	return 0;
}
