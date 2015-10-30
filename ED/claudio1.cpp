#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

int main() {
  int i, j, pi, pj, n, d, valor, **m;

  do {
    printf("Digite a ordem impar da matriz: ");
    scanf("%d", &n);
  } while (n < 1 || n % 2 == 0);

  m = (int **) calloc(n, sizeof(int*));
  
  for (i = 0; i < n; i++)
    m[i] = (int *) calloc(n, sizeof(int));
  
  i = 0;
  j = n / 2;
  valor = 1;


  while (valor <= n*n) {
    m[i][j] = valor;

    if (i == 0)
      pi = n - 1;
    else
      pi = i - 1;

    if (j < n - 1)
      pj = j + 1;
    else
      pj = 0;

    if (m[pi][pj] )
      i++;
    else {
      i = pi;
      j = pj;
    }


    valor++;
  }

  

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++)
      printf(" %2d",  m[i][j]);
    printf("\n");
  }
  
  return 0;
}