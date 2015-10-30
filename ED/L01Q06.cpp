#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

int main() {
  int i, j, n, d, valor, **m;
  
  do {
    printf("Digite a ordem da matriz: ");
    scanf("%d", &n);
  } while (n < 0 || n > 99);

  m = (int **) calloc(n, sizeof(int*));
  
  for (i = 0; i < n; i++)
    m[i] = (int *) calloc(n, sizeof(int));
  
  i = 0;
  j = 0;
  valor = 1;


  while (valor <= n*n) {
    m[i][j] = valor;

    if (j == n - 1) {
      j = i + 1;
      i = n - 1; 
    } else {
      if (i > 0) {
        i--;
        j++;
      } else {
        i = j + 1;
        j = 0;
      }
    }

    valor++;
  }

  

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++)
      printf(" %3d",  m[i][j]);
    printf("\n");
  }
  
  return 0;
}
