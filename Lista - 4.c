#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int i, j, tam[2];

    int *matriz;
    matriz = (int *) malloc(21*sizeof(int));

    printf("Entre com o tamanho de M e N da matriz M x N \n");
    scanf("%i %i", &tam[0], &tam[1]);
    srand( (unsigned)time(NULL) );
    for (i = 0; i < tam[0]; i++){
        for(j = 0; j < tam[1]; j++){
            matriz[i*tam[0]+j] = rand();
        }
    }
    free(matriz);
    for (i = 0; i < tam[0]; i++){
            for(j = 0; j < tam[1]; j++){
                    printf("%i ", matriz[i*tam[0]+j]);
            }
            printf("\n");
    }


    return 0;
}
