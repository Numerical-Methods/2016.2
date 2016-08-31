#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define precision 0.00000000001

int calc_k(double a, double b){
  double k;
  k = (log(b - a) - log(precision)) / log(2);
  return (int)ceil(k);
}

double calc_ponto_medio(double a, double b){
  double x;
  x = (a + b) / 2;
  return x;
}

double calc_fx(double x){
  double fx;
  fx = -0.2 * sin(x) + x - 0.5;
  return fx;
}

double calc_fa(double a){
  double fa;
  fa = -0.2 * sin(a) + a - 0.5;
  return fa;
}

int existence(double a, double b){
  double fa = calc_fx(a);
  double fb = calc_fx(b);
  if (fa * fb < 0)
    return 1;
  else
    return 0;

}

int main(){
  double a, b;
  printf("Digite o primeiro valor do intervalo: \n");
  scanf("%lf", &a);
  printf("Digite o segundo valor do intervalo: \n");
  scanf("%lf", &b);

  if(existence(a, b) == 1){
    int k = calc_k(a, b);
    double x = 0.0;
    double fx = 0.0;
    double fa = 0.0;

    for(int i = 0; i < k; i++){
      x = calc_ponto_medio(a, b);
      fx = calc_fx(x);
      fa = calc_fa(a);
      if (fx * fa > 0){
        a = x;
      }
      else{
        b = x;
      }
    }

    printf("%.11lf \n", x);
  }
  else{
    printf("Nao existe raiz neste Ponto\n");
  }
  return 0;
}
