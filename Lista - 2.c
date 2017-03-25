#include <stdio.h>
#include <math.h>

float desvio_padrao(float n[], int tamanho){
  int i;
  float total, media, somatorio;
  total = 0;
  for (i = 0; i < 5; i++){
    scanf("%f", &n[i]);
    total = total + n[i];
  }
  media = total/5;
  somatorio = 0;
  for (i = 0; i < 5; i++){
    somatorio = somatorio + pow((n[i]-media),2);
  }
  return sqrt(somatorio/5);

}

int main(void){

  int tamanho = 5;
  float n[5], desvio;

  desvio = desvio_padrao(n, tamanho);
  printf("Desvio padrao: %.2f\n", desvio);




  return 0;
}
