#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

int main() {
  /*
  tipo **nome;

ex: int **m, i, j, l, c // l = linhas, c = colunas

m = (int **)calloc(l, sizeof(int *))
for (i = 0; i < l; i++)
  m[i] = (int*)calloc(c, sizeof(int));

  */


  int i, j, n, *v;

  do {
    printf("Digite a quantidade de digitos no numero: ");
    scanf("%d", &n);
  } while (n < 0 || n > 10);

  v = (int *) calloc(n, sizeof(int));
  srand(time(NULL));

  for (i = 0; i < n;) {
    v[i] = rand() % 10;
    
    if
    

  }
  
  printf("Numero pandigital: ");
  for (i = 0; i < n; i++)
    printf("%d",v[i]);

  printf("\n");
  return 0;
}
