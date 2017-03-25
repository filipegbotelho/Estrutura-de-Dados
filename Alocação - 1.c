#include <stdio.h>
#include <stdlib.h>
int main(void){

    int vetor[10], i;

    for (i = 0; i < 10; i++){
        printf("Digite o %io valor \n", i+1);
        scanf("%i", &vetor[i]);
    }
    for (i = 0; i < 10; i++){
        printf("O %io valor: %i\n", i+1, vetor[i]);
    }

    return 0;
}
