#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <dlist.h>

using namespace std;

int main() {
  int i, j, n;
  TList l[20];

  do {
    printf("Digite o tamanho do triangulo de pascal: ");
    scanf("%d", &n);
  } while (n < 0 || n > 20);


  //l = (TList *) malloc(n * sizeof(TList));

  for (i = 0 ; i < n; i++) {
    l[i].insert(1, 1);

    for (j = 2; j <= i + 1; j ++) {
        if (j <= i)
          l[i].insert(l[i - 1].getkey(j) + l[i - 1].getkey(j - 1), j);
        else
          l[i].insert(1, i + 1);
    }

  }

  for (i = 0 ; i < n; i++)
    l[i].print("");


  return 0;
}
