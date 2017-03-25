#include <stdio.h>
#include <stdlib.h>
int main(void){

    int *vetor, n, i;
    vetor = (int *) malloc(21*sizeof(int));

    printf("Digite a quantidade de elementos que deseja digitar \n");
    scanf("%i", &n);

    for (i = 0; i < n; i++){
        printf("Digite o valor do vetor[%i]", i);
        scanf("%i", &vetor[i]);
    }

    for (i = 0; i < n; i++){
        printf("O valor do vetor[%i] e: %i \n", i, vetor[i]);
    }

    return 0;
}
