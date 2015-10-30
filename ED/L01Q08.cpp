#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

int main() {
  int i, j, n, x, k, l, **ma, **mb;

  do {
    printf("Digite a ordem da matriz: ");
    scanf("%d", &n);
  } while (n < 0 || n > 99);

  do {
    printf("Digite digite o numero x (1 a ordem da matriz): ");
    scanf("%d", &x);
  } while (x < 0 || x > n);

  ma = (int **) calloc(n, sizeof(int*));
  mb = (int **) calloc(x, sizeof(int*));

  for (i = 0; i < n; i++)
    ma[i] = (int *) calloc(n, sizeof(int));

  for (i = 0; i < n - 1; i++)
    mb[i] = (int *) calloc(n, sizeof(int));

  srand(time(0));

  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
        ma[i][j] = rand() % 10 + 1;



   for (i = 0 ; i < n; i++){
    if (i == x - 1){
      i++;
      k = i - 1;
    }
    else
      k = i < x - 1 ?  i :  i - 1 ;
    for (j = 0; j < n; j ++){
      if (j == x - 1) {
         j++;
         l = j - 1;
      }
      else
        l = j < x - 1 ? j : j - 1;
      mb[k][l] = ma[i][j];
    }
  }

  printf("\n Matriz A \n\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++)
      printf(" %02d",  ma[i][j]);
    printf("\n");
  }

  printf("\n Matriz B \n\n");
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - 1; j++)
      printf(" %02d",  mb[i][j]);
    printf("\n");
  }

  return 0;
}
