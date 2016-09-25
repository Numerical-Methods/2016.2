#include<stdio.h>
#include <locale.h>

double M[20][20], X[10], multiplier;
int n;

void read_elements(){
  printf("Insira a quantidade de linhas da matriz aumentada: \n");
  scanf("%d",&n);
  printf("Insira os elementos da matriz aumentada:\n");
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= (n + 1); j++){
      printf("M[%d][%d]:", i,j);
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
  printf("A solução para o sistemas de equações lineares é: \n");
  for(int i = 1; i <= n; i++){
    X[i] = M[i][n+1] / M[i][i];
    printf("Corrente I%d = %.10lf\n",i,X[i]);
  }
}

int main()
{

  setlocale(LC_ALL,"");
  read_elements();
  diagonalize_matrix();
  show_results();

  return(0);
}
