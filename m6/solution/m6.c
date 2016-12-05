#include <stdio.h>
#include <stdlib.h>

char file_name[]="in.dat";
FILE *file;
double m = 1.0, g = 10.0, k = 1e-2;

double f(double v) {
  return g - k / m * v;
}

int main() {
  double v = 0, t = 0, dt = 1e-2;
  file = fopen(file_name, "w");

  if(file == NULL){
    printf("Erro, nao foi possivel abrir o arquivo\n");
    return EXIT_FAILURE;
  }
  else{
    while(t <= 10) {
      double k1 = f(v), k2 = f(v + k1 * dt / 2), k3 = f(v - k1 * dt + 2 * k2 * dt);
      printf("%.2lf %.15lf\n", t, v);
      fprintf(file, "%.2lf %.15lf\n", t, v);
      v += (k1 + 4 * k2 + k3) * dt / 6;
      t += dt;
    }
    fclose(file);
  }
  return EXIT_SUCCESS;
}
