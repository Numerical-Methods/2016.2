#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MAX_SIZE 10

int main(){

  int qtd_pontos;

  printf("Insira a quantidade de pontos conhecidos da função a ser interpolada: ");
  scanf("%d",&qtd_pontos);

  assert(qtd_pontos <= MAX_SIZE);

  double temperatura[MAX_SIZE], ro[MAX_SIZE];

  printf("Valores de x pré existentes: \n");

  for(int i = 0; i < qtd_pontos; i++){
    printf("Insira o valor de x_%d :", i);
    scanf("%lf", &temperatura[i]);
  }

  printf("Valores de f(x) pré existentes: \n");

  for(int i = 0; i < qtd_pontos; i++){
    printf("Insira o valor de x_%d :", i);
    scanf("%lf", &ro[i]);
  }

  double x;

  printf("Insira o valor de x para o qual deseja obter f(x): ");
  scanf("%lf", &x);

  double l[MAX_SIZE];

  for (int i = 0; i < MAX_SIZE; i++){
    l[i] = 0.0;
  }

  for (int i = 0; i < qtd_pontos; i++){
    double num = 1.0, den = 1.0;
    for (int j = 0; j < qtd_pontos; j++){
      if (i != j){
        num *= (x - temperatura[j]);
        den *= (temperatura[i] - temperatura[j]);
      }
    }
    l[i] += num/den;
  }

  double p = 0.0;

  for (int i = 0; i < qtd_pontos; i++){
    p += ro[i] * l[i];
  }

  printf("O valor de f(x) é: %lf\n", p);

  return EXIT_SUCCESS;
}
