#include <stdio.h>
#include <math.h>

int main(void){

  int i, tam;
  float *n;
  n = (float *) malloc(21*sizeof(float));
  float media, total, somatorio, variancia, desvio;
  printf("Qual o tamanho do vetor? \n");
  scanf("%i", &tam);
  total = 0;
  // Leitura dos dados
  for(i = 0; i < tam; i++){
    scanf("%f", &n[i]);
    total = total + n[i];
  }
  free(n);
  media = total/tam;
  somatorio = 0;
  for (i = 0; i < tam; i++){
    somatorio = somatorio + pow((n[i] - media),2);
  }

  desvio = sqrt(somatorio/tam);
  printf("Desvio padrao = %.2f", desvio);



  return 0;
}
