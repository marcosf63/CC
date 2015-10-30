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

  for (i = 1; i < n; i++) {
    k = v[i];

    for (j = i - 1; j >= 0 && v[j] > k; j--)
      v[j+1] = v[j];

    v[j+1] = k;
  }

  printf("Vetor ordenado:");

  for (i = 0; i < n; i++)
    printf(" %d", v[i]);

  printf("\n");
  return 0;
}
