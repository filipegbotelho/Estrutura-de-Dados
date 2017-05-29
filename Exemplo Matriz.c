#include <stdio.h>

int main(){

	int matriz[5][5], i, j;

	for(i = 0; i < 5; i++){
		for( j = 0; j < 5; j++){
			printf("Digite o valor da matriz: ");
			scanf("%i", &matriz[i][j]);
		}
    }

	printf("Valores da matriz: \n");

	for(i = 0; i < 5; i++){
		for( j = 0; j < 5; j++){
			scanf("%i", &matriz[i][j]);
		}
		printf("%n");
    }
	return 0;
}
