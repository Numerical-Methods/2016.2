#include<stdio.h>
#include <locale.h>
double M[10][10], X[10], multiplier;
int n;

void read_elements(){
  printf("Insira a quantidade de linhas da matriz aumentada: \n");
  scanf("%d",&n);
  printf("Insira os elementos da matriz aumentada:\n");
  for(int i = 1; i <= n; i++){
    printf("Elementos da %da linha\n", i);
    for(int j = 1; j <= (n + 1); j++){
      scanf("%lf",&M[i][j]);
    }
  }
}
void diagonalize_matrix(){
  for(int j = 1; j <= n; j++){
    for(int i = 1; i <= n; i++){
      if(i != j){
        multiplier = M[i][j] / M[j][j];
        for(int k = 1; k <= (n + 1); k++){
          M[i][k] = M[i][k] - multiplier * M[j][k];
        }
      }
    }
  }
}
void show_results(){
  printf("Os coeficientes que satisfazem o sistema são: \n");
    X[1] = M[1][n+1] / M[1][1];
    printf("A = %.10lf\n",X[1]);
    X[2] = M[2][n+1] / M[2][2];
    printf("B = %.10lf\n",X[2]);
    X[3] = M[3][n+1] / M[3][3];
    printf("C = %.10lf\n",X[3]);
}

int main()
{
  setlocale(LC_ALL,"");
  read_elements();
  diagonalize_matrix();
  show_results();
  return(0);
}
