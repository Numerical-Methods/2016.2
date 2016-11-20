#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#define QTD_POINTS 100

int main(int argc, char *argv[]){

  double upper_limit, below_limit = 0.00000000001;;
  double x[QTD_POINTS], f[QTD_POINTS];
  double I;
  char file_name[]="in.dat";
  FILE *file;

  sscanf(argv[1], "%lf", &upper_limit);
  double h = upper_limit / QTD_POINTS;

  file = fopen(file_name, "w");
  if(file == NULL)
    printf("Erro, nao foi possivel abrir o arquivo\n");
  else{
    for(int i = 1; i <= QTD_POINTS + 1; i++){
      x[i] = below_limit;
      below_limit += h;
      f[i] = sin(x[i])/x[i];
      fprintf(file, "%lf %lf\n", x[i], f[i]);
    }
    fclose(file);
  }

  double even_sum = 0.0;
  for(int i = 2; i < QTD_POINTS + 1; i += 2){
    even_sum += f[i];
  }

  double odd_sum = 0.0;
  for(int i = 3; i < QTD_POINTS + 1; i += 2){
    odd_sum+= f[i];
  }

  I = (h/2)*(f[1]+(2*(odd_sum + even_sum)+f[QTD_POINTS + 1]));
  printf("I=%lf\n", I);
  return EXIT_SUCCESS;
}
