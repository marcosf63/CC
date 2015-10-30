#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;
  
int main() {
  int i, j, k, n, *v;

  do {
    printf("Digite a quantidade de elementos: ");
    scanf("%d", &n);
  } while (n < 0);

  v = (int *) calloc(n, sizeof(int));
  srand(time(NULL));
  printf("Vetor gerado:  ");

  for (i = 0; i < n; i++)
    printf(" %d", v[i] = rand() % 10 + 1);

  printf("\n");

  for (i = 0; i < n - 1; i++) {
    j = i + 1;

    for (k = j + 1; k < n; k++)
      if (v[k] < v[j])
        j = k;

    if (v[j] < v[i])
      swap(v[i], v[j]);
  }

  printf("Vetor ordenado:");

  for (i = 0; i < n; i++)
    printf(" %d", v[i]);

  printf("\n");
  return 0;
}
