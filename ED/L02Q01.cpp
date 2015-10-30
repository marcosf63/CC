#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include "slist.h"

using namespace std;

int main() {
  int i, j, k, n;
  TList l;

  do {
    printf("Digite a quantidade de elementos da lista: ");
    scanf("%d", &n);
  } while (n < 0);

  srand(time(0));

  for (i = 1; l.size() < n; i++) {
    k = rand() % (2 * n) + 1;
    if (i == 1)
      l.insert(k, i);
    else {
      if (k >= l.getkey(i - 1))
        l.insert(k, i);
      else
        i--;
     }
  }

  l.print("Lista gerada: ");

  return 0;
}
