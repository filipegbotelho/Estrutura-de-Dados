#include <stdio.h>

int main(){

	int vet[10], i;

	for (i = 0; i < 10; i++){
		printf("Digite o %io do vetor: ", i+1);
		scanf("%i", &vet[i]);
	}

	printf("Numeros do vetor: ");
	for (i = 0; i < 10; i++){
		printf("%i", vet[i]);
	}

	return 0;
}
