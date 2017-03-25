#include <stdio.h>
#include <stdlib.h>

int main(void){

    int matriz[3][4], i, j;

    for(i = 0; i < 3; i++){
        for(j = 0; j < 4; j++){
            printf("Digite o valor da matriz[%i][%i]\n", i,j);
            scanf("%i", &matriz[i][j]);
        }
    }
    for(i = 0; i < 3; i++){
        for(j = 0; j < 4; j++){
            printf("%i ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
