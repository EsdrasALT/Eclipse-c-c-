#include <stdio.h>
#include <string.h>

struct st_vetor {
	float x;
	float y;
	float z;

}vetores[3];

int main (){
	setbuf(stdout,NULL);

	for(int i=0; i<2; i++){
		printf("Informe os valore para o vetor %d\n", i+1);

		printf("Informe o valor para x: ");
		scanf("%f", &vetores[i].x);

		printf("Informe o valor para y: ");
		scanf("%f", &vetores[i].y);

		printf("Informe o valor para z: ");
		scanf("%f", &vetores[i].z);
	}

	vetores[2].x = vetores[0].x + vetores[1].x;
	vetores[2].y = vetores[0].y + vetores[1].y;
	vetores[2].z = vetores[0].z + vetores[1].z;

	printf("A soma dos pontos dos vetores é\n"
			"x: %.2f\n"
			"y: %.2f\n"
			"z: %.2f\n"
			,vetores[2].x,vetores[2].y,vetores[2].z);


	return 0;
};
