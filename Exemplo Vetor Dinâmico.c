#include <stdio.h>

int main(){

    int tam, med, res, i;

    printf("Qual o tamanho do vetor: ");
    scanf("%i", &tam);

    int *vet = (int*) malloc(tam*sizeof(int));

    res = 0;
    for (i = 0; i < tam; i++){
        printf("Digite um valor ");

        scanf("%i", &vet[i]);
        res += vet[i];
    }
    res /= tam;

    printf("%i\n", res);

    free(vet);


    return 0;
}
