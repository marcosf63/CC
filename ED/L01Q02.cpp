#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

int main() {
  int i, j, n, *v;
  bool existe;

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

  printf("Vetor final: %d", v[0]);

  for (i = 1; i < n ; i++) {
    for (j = 0; j < i; j++)
      if (v[j] == v[i])
        break;

      if (j == i)
        printf(" %d", v[i]);
  }

    
      
   

  
  printf("\n");
  return 0;
}
