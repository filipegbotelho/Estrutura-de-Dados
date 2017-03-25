#include <stdio.h>
#include <math.h>

int main(void){

  int i;
  float n[10], media, total, somatorio, variancia, desvio;

  total = 0;
  // Leitura dos dados
  for(i = 0; i < 10; i++){
    scanf("%f", &n[i]);
    total = total + n[i];
  }

  media = total/10;

  somatorio = 0;
  for (i = 0; i < 10; i++){
    somatorio = somatorio + pow((n[i] - media),2);
  }

  desvio = sqrt(somatorio/10);
  printf("Desvio padrao = %.2f", desvio);



  return 0;
}
