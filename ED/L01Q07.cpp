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

  for (i = 0; i < n; i++)
  for (j = 0; j < n; j++){
    if (i + j < n - 1 && i < j)
        m[i][j] = 1;
    if (i + j < n - 1 && i > j)
        m[i][j] = 4;
    if (i + j > n - 1 && i < j)
        m[i][j] = 2;
    if (i + j > n - 1 && i > j)
        m[i][j] = 3;
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++)
      printf(" %d",  m[i][j]);
    printf("\n");
  }


  return 0;
}
