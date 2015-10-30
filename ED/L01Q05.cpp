#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;
  
int main() {
  int i, j, n, *v;

  do {
    printf("Digite a quantidade de digitos do numero: ");
    scanf("%d", &n);
  } while (n < 0 || n > 10);

  v = (int *) calloc(n, sizeof(int));
  srand(time(NULL));

  v[0] = rand() % 9 + 1;

  for (i = 1; i < n ; i++) {
    v[i] = rand() % 10;
    for (j = 0; j < i ; j++)
      if (v[i] == v[j]) {
        i--;
        break;
      }
  }
  
  
  printf("Numero pandigital: ");
  for (i = 0; i < n; i++)
    printf("%d",v[i]);

  printf("\n");
  return 0;
}
